/*
  Battery Monitor

  This example creates a BLE peripheral with the standard battery service and
  level characteristic. The A0 pin is used to calculate the battery level.

  The circuit:
  - Arduino MKR WiFi 1010, Arduino Uno WiFi Rev2 board, Arduino Nano 33 IoT,
    Arduino Nano 33 BLE, or Arduino Nano 33 BLE Sense board.

  You can use a generic BLE central app, like LightBlue (iOS and Android) or
  nRF Connect (Android), to interact with the services and characteristics
  created in this sketch.

  This example code is in the public domain.
*/

#include <ArduinoBLE.h>
#include "SparkFunBME280.h"

BME280 tempSensor;

 // BLE Battery Service
BLEService temperatureService("180F");

// Temperature Characteristic
BLEUnsignedCharCharacteristic temperatureChar("2A19",  // standard 16-bit characteristic UUID
    BLERead | BLENotify); // remote clients will be able to get notifications if this characteristic changes

//int oldBatteryLevel = 0;  // last battery level reading from analog input
//long previousMillis = 0;  // last time the battery level was checked, in ms

void updateTemperatureReading() {
  /* Read the current voltage level on the A0 analog input pin.
     This is used here to simulate the charge level of a battery.
  */
  int temperature = (int)tempSensor.readTempF();
  
  Serial.print("Temperature is now: "); // print it
  Serial.println(temperature);
  temperatureChar.writeValue(temperature);  // and update the battery level characteristic
}

void setup() {
  Serial.begin(115200);    // initialize serial communication
  while (!Serial);

  pinMode(LED_BUILTIN, OUTPUT); // initialize the built-in LED pin to indicate when a central is connected

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");

    while (1);
  }

  /* Set a local name for the BLE device
     This name will appear in advertising packets
     and can be used by remote devices to identify this BLE device
     The name can be changed but maybe be truncated based on space left in advertisement packet
  */
  BLE.setLocalName("TemperatureMonitor");
  BLE.setAdvertisedService(temperatureService); // add the service UUID
  temperatureService.addCharacteristic(temperatureChar); // add the battery level characteristic
  BLE.addService(temperatureService); // Add the battery service
  // Set initial value for this characteristic
  int currentTemp = (int)tempSensor.readTempF();
  temperatureChar.writeValue(currentTemp); // set initial value for this characteristic

  /* Start advertising BLE.  It will start continuously transmitting BLE
     advertising packets and will be visible to remote BLE central devices
     until it receives a new connection */

  // start advertising
  BLE.advertise();

  Serial.println("Bluetooth device active, waiting for connections...");
}

void loop() {
  // wait for a BLE central
  BLEDevice central = BLE.central();

  // if a central is connected to the peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's BT address:
    Serial.println(central.address());
    // turn on the LED to indicate the connection:
    digitalWrite(LED_BUILTIN, HIGH);

    // check the battery level every 200ms
    // while the central is connected:
    while (central.connected()) {
        updateTemperatureReading();
        delay(1000);
      }
    }
    
    // when the central disconnects, turn off the LED:
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
}
