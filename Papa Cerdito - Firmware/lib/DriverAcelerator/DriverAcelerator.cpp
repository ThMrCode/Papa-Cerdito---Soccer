#include <DriverAcelerator.h>

namespace DriverAcelerator {
    // GLOBAL VARIABLES
    float finalLeft = 0;
    float finalRight = 0;
    float lastLeft = 0;
    float lastRight = 0;

    void registerLast(float lastLeft_, float lastRight_)
    {
        lastLeft = lastLeft_;
        lastRight = lastRight_;
    }

    void registerFinal(float finalLeft_, float finalRight_)
    {
        finalLeft = finalLeft_;
        finalRight = finalRight_;
    }

    void acelerate(float *newLeft, float *newRight, int steps)
    {
        // Puede que ciertos movimientos requieran una aceleracion mas lenta
        // Cuando se haya completado el tiempo de aceleracion, recibiremos una bandera de steps 0
        if(steps > 0) {
            // Graduamos la nueva velocidad para que acelere en los steps provistos
            float difLeft = finalLeft - lastLeft;
            float difRight = finalRight - lastRight;
            *newLeft = lastLeft + difLeft / steps;
            *newRight = lastRight + difRight / steps;
        }
        else {
            // Ante la bandera de 0, debemos asegurarnos de tener la velocidad correcta
            *newLeft = finalLeft;
            *newRight = finalRight;
        }
    }
}