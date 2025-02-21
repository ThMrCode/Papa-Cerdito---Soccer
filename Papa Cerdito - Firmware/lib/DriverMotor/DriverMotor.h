#pragma once
#include <Arduino.h>

namespace DriverMotor {

    // STATE
    enum STATE {
        STATE_LEFT,
        STATE_RIGHT,
        STATE_FORWARD,
        STATE_BACKWARD,
        STATE_FORWARD_LEFT,
        STATE_FORWARD_RIGHT,
        STATE_BACKWARD_LEFT,
        STATE_BACKWARD_RIGHT,
        STATE_STOP
    };
    // Pines del driver (a left, b right)
    enum PIN {
        LEFT_PWM =                  18,
        LEFT_FORWARD =              33,
        LEFT_BACKWARD =             32,
        RIGHT_FORWARD =             26,
        RIGHT_BACKWARD =            25,
        RIGHT_PWM =                 27
    };

    // GLOBAL VARIABLES
    extern STATE state;

    // Start Driver
    void start();

    // Control directo de motores
    void controlMotor(bool left_F, bool left_B, bool right_F, bool right_B);

    // Motores Libres
    void freeMotor();
  
    // Motores Frenado Activo
    void stopMotor();

    // Select State 
    void stateLeft();

    void stateRight();

    void stateForward();
    
    void stateBackward();
    
    // Actualizar Velocidades segun State
    void controlVelocity(long long times);
}