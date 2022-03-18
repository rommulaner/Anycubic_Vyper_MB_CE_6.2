
#include "../../../../inc/MarlinConfigPre.h"

#if ENABLED(DGUS_LCD_UI_CREALITY_TOUCH)

#include "../DGUSDisplayDef.h"
#include "../DGUSDisplay.h"
#include "../DGUSScreenHandler.h"

#include "PIDHandler.h"

#include "../../ui_api.h"
#include "../../../marlinui.h"

#include "../../../../module/temperature.h"
#include "../../../../module/settings.h"
#include "../../../../module/planner.h"
#include "../../../../gcode/gcode.h"

// Storage init
uint16_t PIDHandler::cycles = 0;
celsius_t PIDHandler::calibration_temperature = 0;
bool PIDHandler::fan_on = false;
PGM_P PIDHandler::result_message = nullptr;

void PIDHandler::Init() {
    // Reset
    cycles = 3;

    fan_on = ExtUI::getTargetFan_percent(ExtUI::fan_t::FAN0) > 10;

    // Use configured PLA temps + 10 degrees
    calibration_temperature = ui.material_preset[0].hotend_temp + 15;

    // Welcome message
    SetStatusMessage(PSTR("Ready"));
}


void PIDHandler::HandleStartButton(DGUS_VP_Variable &var, void *val_ptr) {
    //static_assert(ADVANCED_PAUSE_PURGE_LENGTH == 0, "Assuming PURGE_LENGTH is 0 so we can use M701");
    // using temp we can tune PID for bed or hot end
    int8_t target = -1;  // default to BED

    // Validate
    if((calibration_temperature < BED_MINTEMP) || (calibration_temperature > HEATER_0_MAXTEMP)) {
        SetStatusMessage(PSTR("Invalid temperature set"));
        return;
    }

    if (calibration_temperature > BED_MAXTEMP) {
        target = 0;    // set to E0
    }

    if (cycles < 1) {
        SetStatusMessage(PSTR("Invalid number of cycles"));
        return;
    }

    // Synchronous operation - disable back button
    DGUSSynchronousOperation syncOperation;
    syncOperation.start();

    // Fan
    const auto prev_fan_percentage = ExtUI::getActualFan_percent(ExtUI::fan_t::FAN0);
    const uint8_t fan_speed = fan_on ? 255 : 0;

    // Set-up command
    if(0 == target) {
        SetStatusMessage(PSTR("E0 PID tuning. Please wait..."));
    } else {
        SetStatusMessage(PSTR("Bed PID tuning. Please wait..."));
    }

    char cmd[64]; // Add a G4 to allow the fan speed to take effect
    sprintf_P(cmd, PSTR("M106 S%d\nG4 S2\nM303 S%d C%d E%d U1"), fan_speed, calibration_temperature, cycles, target);
    SERIAL_ECHOLNPAIR("Executing: ", cmd);

    ExtUI::injectCommands(cmd);
    while (queue.has_commands_queued()) queue.advance();

    // Done
    ExtUI::setTargetFan_percent(prev_fan_percentage, ExtUI::fan_t::FAN0);

    ScreenHandler.Buzzer(0, 250);
    settings.save();
    syncOperation.done();

    SetStatusMessage(result_message);
}

void PIDHandler::SetStatusMessage(PGM_P statusMessage) {
    ScreenHandler.setstatusmessagePGM(statusMessage);
}

#endif