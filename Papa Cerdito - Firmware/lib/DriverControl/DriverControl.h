#pragma once
#include <PreCompile.h>
#include <DriverMotor.h>
#include <DriverAcelerator.h>

namespace DriverControl {
    // STATE
    enum STATE {
        STATE_FORWARD,
        STATE_BACKWARD,
        STATE_LEFT,
        STATE_RIGHT,
        STATE_FORWARD_LEFT,
        STATE_FORWARD_RIGHT,
        STATE_BACKWARD_LEFT,
        STATE_BACKWARD_RIGHT,
        STATE_STOP,
    };

    // CONFIG
    enum CONFIG {
        TIME_UMBRAL = 30,
        TIME_LAPSE = 3,
    };

    // GLOBAL VARIABLES
    extern STATE state;
    extern long long times;

    // Cambia el estado y maximas velocidades
    // Las maximas velocidades son definidas para cada estado, un modulo acelerator puede graduar el ascenso a ellas
    void updateState(char command);

    void updateLoop(char command);
}