#pragma once
#include <PreCompile.h>

namespace DriverMotor {

    // STATE
    enum STATE {
        STATE_FORWARD_FORWARD,
        STATE_BACKWARD_BACKWARD,
        STATE_FORWARD_BACKWARD,
        STATE_BACKWARD_FORWARD,
        STATE_FREE,
        STATE_STOP,
    };

    // PIN OUT CONFIG 27 26 25 33 32 12
    enum PIN {
        LEFT_PWM =                  27,
        LEFT_FORWARD =              26,
        LEFT_BACKWARD =             25,
        RIGHT_FORWARD =             33,
        RIGHT_BACKWARD =            32,
        RIGHT_PWM =                 12,
    };

    // GLOBAL VARIABLES
    extern STATE state;

    // FUNCIONES DE CONTROL DIRECTO - LOW LEVEL

    // Start Driver
    void start();

    // Motores Libres
    void freeMotor();
  
    // Motores Frenado Activo
    void stopMotor();
    
    // Mapeo de estados
    STATE mapState(float valueLeft, float valueRight);
    
    // Config de estados
    void configState(STATE state);

    // Control directo de motores
    void writeMotor(float valueLeft, float valueRight);

}