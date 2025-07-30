const int trig = 12;   
const int echo = 11;
const int LED1 = 7;
const int LED2 = 6;
const int LED3 = 5;
const int LED4 = 4;

long duration;
int distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  digitalWrite(LED1, distance <= 7 ? HIGH : LOW);
  digitalWrite(LED2, distance <= 14 ? HIGH : LOW);
  digitalWrite(LED3, distance <= 21 ? HIGH : LOW);
  digitalWrite(LED4, distance <= 28 ? HIGH : LOW);

  delay(200);
}
