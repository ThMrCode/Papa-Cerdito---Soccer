#include <BTControl.h>

namespace BTControl {
    String Name = "Heisenberg";
    BluetoothSerial BT = BluetoothSerial();

    void start() {
      	BT.begin(Name); 	// Inicializa el Bluetooth , con este nombre aparecera en su celular
    }

    void loop() {
        if (BT.available()) {   		// Verifica si hay datos desde Bluetooth
      	    char command = BT.read();  	// Lee el comando
	  	    DriverControl::updateLoop(command);
        }
    }
}

