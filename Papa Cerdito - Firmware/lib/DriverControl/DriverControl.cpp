#include <DriverControl.h>

namespace DriverControl {
    STATE state = STATE_STOP;
    long long times = 0;

    void updateState(char command)
    {
        // En caso se lea un comando que no cambie el estado, este contara como si se repitiese el estado
        STATE new_state = state;
        switch (command) {
            case 'F': 
                new_state = STATE_FORWARD;
                DriverAcelerator::registerFinal(1.0,1.0);
                break;
            case 'B': 
                new_state = STATE_BACKWARD;
                DriverAcelerator::registerFinal(-1.0,-1.0);
                break;
            case 'L':
                new_state = STATE_LEFT;
                DriverAcelerator::registerFinal(-1.0,1.0);
                break;
            case 'R':
                new_state = STATE_RIGHT;
                DriverAcelerator::registerFinal(1.0,-1.0);
                break;
            case 'I': 
                new_state = STATE_FORWARD_LEFT;
                DriverAcelerator::registerFinal(0.5,1.0);
                break;
            case 'G': 
                new_state = STATE_FORWARD_RIGHT;
                DriverAcelerator::registerFinal(1.0,0.5);
                break;
            case 'J':
                new_state = STATE_BACKWARD_LEFT;
                DriverAcelerator::registerFinal(-0.5,-1.0);
                break;
            case 'H':
                new_state = STATE_BACKWARD_RIGHT;
                DriverAcelerator::registerFinal(-1.0,-0.5);
                break;
            case 'S':
                new_state = STATE_STOP;
                DriverAcelerator::registerFinal(0.0,0.0);
                break;
            default:
                break;
        }
        // Cuenta las veces que se repite el mismo estado
        if(new_state != state) {
            // Cuando hay un cambio de estado, se registran las ultimas velocidades como el start
            DriverAcelerator::registerStart();
            state = new_state;
            times = 0;
        }
        else times++;
    }

    void updateLoop(char command)
    {
        updateState(command);
        if(state != STATE_STOP) {
            // Iterando el modulo acelerator, cada cierto tiempo hasta llegar al tiempo umbral
            // Asegurarse de llegar a final antes del tiempo umbral
            if(times < CONFIG::TIME_UMBRAL) {
                if(times % TIME_LAPSE == 0) {
                    float newLeft; float newRight;
                    DriverAcelerator::acelerate(&newLeft, &newRight);
                    DriverMotor::writeMotor(newLeft,newRight);
                    DriverAcelerator::registerLast(newLeft, newRight);
                }
            }
        }
        else {
            if(times == 0) DriverMotor::writeMotor(0,0);
            else if (times == TIME_UMBRAL) DriverMotor::stopMotor();
        }
    }
}