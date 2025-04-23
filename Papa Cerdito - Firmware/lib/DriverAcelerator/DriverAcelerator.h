#pragma once
#include <PreCompile.h>

// Cambio gradual por diferencia de velocidades en vez de por tiempo, solo tiempo para el stop
// Ya que DriverAcelerator no conocera el tiempo, pero si debe cumplir con acelerar antes del tiempo umbral
// La cantidad de pasos que podra dar DriverAcelerator sera (TIME_UMBRAL / TIME_LAPSE)
// Se gradua una escala donde cada paso de acelerator sea MAX_DIF_POSIBLE / (TIME_UMBRAL / TIME_LAPSE)

namespace DriverAcelerator {
    // GLOBAL VARIABLES
    extern float finalLeft;
    extern float finalRight;
    extern float startLeft;
    extern float startRight;
    extern float lastLeft;
    extern float lastRight;

    // Guarda las ultimas velocidades
    void registerLast(float lastLeft_, float lastRight_);

    // Si ha habido un cambio de comando, actualiza start con el last
    void registerStart();

    // Registrar las maximas velocidades por estado al cambiar de estado
    void registerFinal(float finalLeft_, float finalRight_);
    
    void acelerate(float* newLeft, float* newRight);
}