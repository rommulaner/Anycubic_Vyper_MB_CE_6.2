#pragma once

#include <stdint.h>

class InputShapingHandler {
    public:
        static void Init();
        static void HandleInputShapingBackButton(DGUS_VP_Variable &var, void *val_ptr);

    public:
        static float set_freq_x;
        static float set_zeta_x;

        static float set_freq_y;
        static float set_zeta_y;

    private:
        static void SetStatusMessage(PGM_P statusMessage);
};

