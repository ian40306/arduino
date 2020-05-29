#define B2 7
#define B1 8
void setup() {
  // put your setup code here, to run once:
  pinMode(B2, INPUT);
  pinMode(B1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = 0;
  a = digitalRead(B2);
  Serial.println(a);
}
