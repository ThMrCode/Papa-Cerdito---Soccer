#include <DriverAcelerator.h>

namespace DriverAcelerator {
    // GLOBAL VARIABLES
    float finalLeft = 0;
    float finalRight = 0;
    float startLeft = 0;
    float startRight = 0;
    float lastLeft = 0;
    float lastRight = 0;

    void registerLast(float lastLeft_, float lastRight_)
    {
        lastLeft = lastLeft_;
        lastRight = lastRight_;
    }

    void registerStart()
    {
        startLeft = lastLeft;
        startRight = lastRight;
    }

    void registerFinal(float finalLeft_, float finalRight_)
    {
        finalLeft = finalLeft_;
        finalRight = finalRight_;
    }

    void acelerate(float *newLeft, float *newRight)
    {
        *newLeft = finalLeft;
        *newRight = finalRight;
    }
}