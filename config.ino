int trigpin = 4;
int echopin = 5;
int buzzer = 3;
long duration;
int distance;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 30) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
}
