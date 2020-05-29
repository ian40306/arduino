#define VR A0
#define CDS_R A1
#define CDS_L A6
void setup() {
  // put your setup code here, to run once:
  pinMode(VR, INPUT);
  pinMode(CDS_R, INPUT);
  pinMode(CDS_L, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = 0, b = 0, c = 0;
  a = analogRead(VR);
  b = analogRead(CDS_R);
  c = analogRead(CDS_L);
  Serial.print("The VR is : ");
  Serial.println(a);
  Serial.print("The CDS_R is : ");
  Serial.println(b);
  Serial.print("The CDS_L is : ");
  Serial.println(c);
  delay(500);
}
