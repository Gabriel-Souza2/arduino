
const int LED = 15;
const int SENSOR = 14;

int signal;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);

}

void loop() {
  signal = digitalRead(SENSOR);
  if(signal == HIGH) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }

  delay(500);
}
