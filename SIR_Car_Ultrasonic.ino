#define trig A0
const byte echo[] = {A1, A2, A3};

void setup() {
  pinMode(trig, OUTPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(echo, INPUT);
  }
  Serial.begin(9600);

}

void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long t = pulseIn(echo[i], HIGH);
    //long inches = t / 74 / 2;
    long cm = t / 29 / 2;

    Serial.print(cm); // 6in    15cm
    Serial.print("cm: ");
    Serial.print('\t');
    delay(100);
  }
  Serial.println(" ");
}
