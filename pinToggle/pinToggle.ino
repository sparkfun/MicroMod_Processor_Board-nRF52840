/*
 * Toggle example
 */
 
void setup() {
  pinMode(G0, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(G3, OUTPUT);
  pinMode(G4, OUTPUT);
  pinMode(G5, OUTPUT);
  pinMode(G6, OUTPUT);
  pinMode(G7, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_WIRE_INT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(G0, HIGH);
  digitalWrite(G1, HIGH);
  digitalWrite(G2, HIGH);
  digitalWrite(G3, HIGH);
  digitalWrite(G4, HIGH);
  digitalWrite(G5, HIGH);
  digitalWrite(G6, HIGH);
  digitalWrite(G7, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(PIN_WIRE_INT, HIGH);
  delay(1000);
  digitalWrite(G0, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(G3, LOW);
  digitalWrite(G4, LOW);
  digitalWrite(G5, LOW);
  digitalWrite(G6, LOW);
  digitalWrite(G7, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(PIN_WIRE_INT, LOW);
  delay(1000);
}
