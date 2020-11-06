/*
  Tests the various ADC pins including the VIN/3 pin.
  Use a trimpot to vary the voltage on the A0/A1 pins.
  Use a variable bench supply to input voltage into the
  VIN rail. Be sure to remove the PTC or otherwise isolate
  the USB VIN from the bench supply.
*/

#define ANALOG_REFERENCE 3.3
#define ANALOG_RESOLUTION 10

int maxADCValue = pow(2, ANALOG_RESOLUTION);

void setup()
{
  Serial.begin(115200);
  Serial.println("Analog conversion example");

  pinMode(LED_BUILTIN, OUTPUT);

  analogReadResolution(ANALOG_RESOLUTION); //Set resolution. Default is 10 bit.
}

void loop()
{
  int myAnalog0 = analogRead(A2);
  float myVoltage0 = myAnalog0 * ANALOG_REFERENCE / maxADCValue;
  Serial.print("A2 voltage: ");
  Serial.print(myVoltage0, 3);

//  int myAnalog1 = analogRead(A3); //DOES NOT work
//  int myAnalog1 = analogRead(A4); //DOES NOT work
  int myAnalog1 = analogRead(A5); //Works

  float myVoltage1 = myAnalog1 * ANALOG_REFERENCE / maxADCValue;
  Serial.print("\tA3 voltage: ");
  Serial.print(myVoltage1, 3);

  Serial.println();

  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}
