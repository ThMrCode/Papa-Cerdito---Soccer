#include <Arduino.h>
#include <BluetoothSerial.h>
#include <DriverMotor.h>

namespace BTControl {
    extern String Name;
    extern BluetoothSerial BT;
    extern char LastCommand;
    extern long times;

    // Start BT CONTROL;
    void start();

    void menu(char command);

    void loop();
}