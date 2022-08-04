#define pin A7//A6
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin, LOW);
  Serial.print("a");
  Serial.println(analogRead(A7));
  delay(1000);
  digitalWrite(pin, HIGH);
  Serial.print("b");
  Serial.println(analogRead(A7));
  delay(1000);
}
