#define IR_RR  A2  //TCRT5000紅外線尋跡(最右)
#define IR_R   A3  //TCRT5000紅外線尋跡(右)
#define IR_L   A4  //TCRT5000紅外線尋跡(左)
#define IR_LL  A5  //TCRT5000紅外線尋跡(最左)
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR_RR, INPUT);
  pinMode(IR_R, INPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_LL, INPUT);
}
void loop() {
  int a = analogRead(IR_RR);
  int b = analogRead(IR_R);
  int c = analogRead(IR_L);
  int d = analogRead(IR_LL);
  Serial.println("**********");
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  Serial.println(d);
  delay(50);
  // put your main code here, to run repeatedly:
}
