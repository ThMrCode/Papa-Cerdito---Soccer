#include <DriverMotor.h>

namespace DriverMotor {
    STATE state = STATE_LEFT;  // Definición
}

void DriverMotor::start()   {
    pinMode(PIN::LEFT_PWM, OUTPUT);   
    pinMode(PIN::LEFT_FORWARD, OUTPUT);
    pinMode(PIN::LEFT_BACKWARD, OUTPUT);
    pinMode(PIN::RIGHT_FORWARD, OUTPUT);
    pinMode(PIN::RIGHT_BACKWARD, OUTPUT);
}

void DriverMotor::controlMotor(bool left_F, bool left_B, bool right_F, bool right_B)  {
    // Definir las Direcciones (Front, Back, Stop, Free)
    digitalWrite(PIN::LEFT_FORWARD, left_F);
    digitalWrite(PIN::LEFT_BACKWARD, left_B);
    digitalWrite(PIN::RIGHT_FORWARD, right_F);
    digitalWrite(PIN::RIGHT_BACKWARD, right_B);
}

void DriverMotor::freeMotor()   {
    digitalWrite(PIN::LEFT_FORWARD, LOW);
    digitalWrite(PIN::LEFT_BACKWARD, LOW);
    digitalWrite(PIN::RIGHT_FORWARD, LOW);
    digitalWrite(PIN::RIGHT_BACKWARD, LOW);
    analogWrite(PIN::LEFT_PWM, 0);
    analogWrite(PIN::RIGHT_PWM, 0);
}

void DriverMotor::stopMotor()   {
    digitalWrite(PIN::LEFT_FORWARD, HIGH);
    digitalWrite(PIN::LEFT_BACKWARD, HIGH);
    digitalWrite(PIN::RIGHT_FORWARD, HIGH);
    digitalWrite(PIN::RIGHT_BACKWARD, HIGH);
    analogWrite(PIN::LEFT_PWM, 0);
    analogWrite(PIN::RIGHT_PWM, 0);
    delay(100);                 // Aplicar por lo menos 100 ms
}

void DriverMotor::stateLeft()
{
    controlMotor(LOW, HIGH, HIGH, LOW);
}

void DriverMotor::stateRight()
{
    controlMotor(HIGH,LOW, LOW, HIGH);
}

void DriverMotor::stateForward()
{
    controlMotor(HIGH, LOW, HIGH, LOW);
}

void DriverMotor::stateBackward()
{
    controlMotor(LOW, HIGH, LOW, HIGH);
}

void DriverMotor::controlVelocity(long long times)
{
    if(times == 0) {
        switch (state)
        {
        case STATE_FORWARD:
        case STATE_BACKWARD:
        case STATE_LEFT:
        case STATE_RIGHT:
            analogWrite(LEFT_PWM, 40);
            analogWrite(RIGHT_PWM,40);
            break;
        case STATE_FORWARD_LEFT:
        case STATE_BACKWARD_LEFT:
            analogWrite(LEFT_PWM, 40);
            analogWrite(RIGHT_PWM,120);
            break;
        case STATE_FORWARD_RIGHT:
        case STATE_BACKWARD_RIGHT:
            analogWrite(LEFT_PWM, 120);
            analogWrite(RIGHT_PWM,40);
            break;
        default:
            break;
        }
    }
}
