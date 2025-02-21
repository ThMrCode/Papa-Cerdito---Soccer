#include <BTControl.h>

namespace BTControl {
    String Name = "Papa Cerdito";\
    BluetoothSerial BT;
    char LastCommand = 'S';
    long times = 0;
}

void BTControl::start()
{
    BT.begin(Name); // Inicializa el Bluetooth , con este nombre aparecera en su celular
}

void BTControl::menu(char command)
{
  if(command != LastCommand) {
    LastCommand = command;
    switch (command) {
      case 'F': 
        DriverMotor::stateForward();
        DriverMotor::state = DriverMotor::STATE_FORWARD;
        break;
      case 'B': 
        DriverMotor::stateBackward();
        DriverMotor::state = DriverMotor::STATE_BACKWARD;
        break;
      case 'L':
        DriverMotor::stateLeft();
        DriverMotor::state = DriverMotor::STATE_LEFT;
        break;
      case 'R':
        DriverMotor::stateRight();
        DriverMotor::state = DriverMotor::STATE_RIGHT;
        break;
      case 'G': 
        DriverMotor::stateForward();
        DriverMotor::state = DriverMotor::STATE_FORWARD_LEFT;
        break;
      case 'I': 
        DriverMotor::stateForward();
        DriverMotor::state = DriverMotor::STATE_FORWARD_RIGHT;
        break;
      case 'H':
        DriverMotor::stateBackward();
        DriverMotor::state = DriverMotor::STATE_BACKWARD_LEFT;
        break;
      case 'J':
        DriverMotor::stateBackward();
        DriverMotor::state = DriverMotor::STATE_BACKWARD_RIGHT;
        break;
      default:
        break; // Comando no reconocido
    }
    times = 0;
  }
  else times++;
  DriverMotor::controlVelocity(times);
}

void BTControl::loop()
{
    if (BT.available()) {   // Verifica si hay datos desde Bluetooth
      char rc = BT.read();  // Lee el comando
      menu(rc);             // Ejecuta la función correspondiente al comando
    }
}
