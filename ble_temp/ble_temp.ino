/*
  BLE Temperature Updates

  This example creates a BLE peripheral with the temperature service and
  reading characteristic. Grab temperature measurements from the BME280.

  The circuit:
  - SparkFun MicroMod nRF52840 Processor Board inserted into Sparkfun MicroMod 
  Weather Carrier Board.

  You can use a generic BLE central app, like LightBlue (iOS and Android) or
  nRF Connect (Android), to interact with the services and characteristics
  created in this sketch.
*/

#include <ArduinoBLE.h>
#include "SparkFunBME280.h"

BME280 tempSensor;

 // BLE Temperature Service
BLEService temperatureService("9feb1060-0814-11eb-adc1-0242ac120002");

// BLE Temperature Reading Characteristic
BLEIntCharacteristic temperatureReadingChar("9feb1060-0814-11eb-adc1-0242ac120002",  // standard 16-bit characteristic UUID
    BLERead | BLENotify); // remote clients will be able to get notifications if this characteristic changes

int oldTemperatureF = 0; //last temperature reading from BME280

void setup() {
  Serial.begin(115200);    // initialize serial communication
  while (!Serial);

  pinMode(LED_BUILTIN, OUTPUT); // initialize the built-in LED pin to indicate when a central is connected

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");

    while (1);
  }

  if (tempSensor.begin() == false) { //Connect to BME280
    Serial.println("BME280 did not respond.");
    while(1); //Freeze
  }

  /* Set a local name for the BLE device
     This name will appear in advertising packets
     and can be used by remote devices to identify this BLE device
     The name can be changed but maybe be truncated based on space left in advertisement packet
  */
  BLE.setLocalName("TemperatureReading");
  BLE.setAdvertisedService(temperatureService); // add the service UUID
  temperatureService.addCharacteristic(temperatureReadingChar); // add the temperature reading characteristic
  BLE.addService(temperatureService); // Add the temperature service

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

    // check the temperature every second
    // while the central is connected:
    while (central.connected()) {
        updateTemperature();
        delay(1000);
    }
    // when the central disconnects, turn off the LED:
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

void updateTemperature() {
  /* Read the current temperature from the BME280
  */
  int temperatureF = (int)tempSensor.readTempF();

  if (temperatureF != oldTemperatureF) {
    Serial.print("Temperature in F is now: "); // print it
    Serial.println(temperatureF);
    temperatureReadingChar.writeValue(temperatureF);  // and update the temperature reading characteristic
    oldTemperatureF = temperatureF;
  }
}
