#define MR2 5
#define MR1 6
#define ML1 10
#define ML2 11
void setup() {
  // put your setup code here, to run once:
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  analogWrite(ML1, 0);
  analogWrite(ML2, 0);
  analogWrite(MR1, 0);
  analogWrite(MR2, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ML1, 150);
}
