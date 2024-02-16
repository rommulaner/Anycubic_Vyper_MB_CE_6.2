
#include "../../../../inc/MarlinConfigPre.h"

#if ENABLED(DGUS_LCD_UI_CREALITY_TOUCH)
    #if EITHER(INPUT_SHAPING_X, INPUT_SHAPING_Y)

        #include "../DGUSDisplayDef.h"
        #include "../DGUSDisplay.h"
        #include "../DGUSScreenHandler.h"

        #include "InputShapingHandler.h"

        #include "../../ui_api.h"
        #include "../../../../module/stepper.h"

        // Storage init
        float InputShapingHandler::set_freq_x = 0;
        float InputShapingHandler::set_zeta_x = 0;
        float InputShapingHandler::set_freq_y = 0;
        float InputShapingHandler::set_zeta_y = 0;

        void InputShapingHandler::Init() {
            // get settings
            set_freq_x = stepper.get_shaping_frequency(X_AXIS);
            set_zeta_x = stepper.get_shaping_damping_ratio(Y_AXIS);
            set_freq_y = stepper.get_shaping_frequency(Y_AXIS);
            set_zeta_y = stepper.get_shaping_damping_ratio(Y_AXIS);

            SetStatusMessage(PSTR("Ready"));
        }

        void InputShapingHandler::HandleInputShapingBackButton(DGUS_VP_Variable &var, void *val_ptr) {
            // save settings and return to old screen
            stepper.set_shaping_frequency(X_AXIS, set_freq_x);
            stepper.set_shaping_damping_ratio(X_AXIS, set_zeta_x);
            stepper.set_shaping_frequency(Y_AXIS,set_freq_y);
            stepper.set_shaping_damping_ratio(Y_AXIS,set_zeta_y);

            settings.save();
            ScreenHandler.PopToOldScreen();

            SetStatusMessage(PSTR("New values saved"));
        }

        void InputShapingHandler::SetStatusMessage(PGM_P statusMessage) {
            ScreenHandler.setstatusmessagePGM(statusMessage);
        }
    #endif
#endif