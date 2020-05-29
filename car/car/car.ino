//==== 接腳定義 ====
#define Buzzer 3   //蜂鳴器
#define MR2    5   //右馬達輸入2
#define MR1    6   //右馬達輸入1
#define B2     7   //按鈕2
#define B1     8   //按鈕1
#define ML1    10  //左馬達輸入1
#define ML2    11  //左馬達輸入2
#define B3     13  //按鈕3
#define VR     A0  //可變電阻
#define CDS_R  A1  //光敏電阻(右)
#define IR_RR  A2  //TCRT5000紅外線尋跡(最右)
#define IR_R   A3  //TCRT5000紅外線尋跡(右)
#define IR_L   A4  //TCRT5000紅外線尋跡(左)
#define IR_LL  A5  //TCRT5000紅外線尋跡(最左)
#define CDS_L  A6  //光敏電阻(左)
boolean RRv_IR, Rv_IR, Lv_IR, LLv_IR;
#define RRv 200 //最右邊尋跡紅外線數值,白底>黑線
#define Rv  200 //右邊尋跡紅外線數值,白底>黑線
#define Lv  200 //左邊尋跡紅外線數值,白底>黑線
#define LLv 200 //最左邊尋跡紅外線數值,白底>黑線
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
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
  LINE_FOLLOW();
  // put your main code here, to run repeatedly:
}

void LINE_FOLLOW() {
  while (true) {
    int a = analogRead(A2);
    int b = analogRead(A3);
    int c = analogRead(A4);
    int d = analogRead(A5);
    Serial.println("**********");
    Serial.println(a);
    Serial.println(b);
    Serial.println(c);
    Serial.println(d);
    delay(50);
    GetIR();
    if (!Lv_IR && !Rv_IR) {
      Forward();
    } else if (Lv_IR && !Rv_IR) {
      Left_LINE();
    } else if (!Lv_IR && Rv_IR) {
      Right_LINE();
    } else {
      Stop();
    }
  }
}

void GetIR() {
  if (analogRead(IR_RR) >= RRv)
    RRv_IR = false; //白底
  else
    RRv_IR = true; //黑線
  if (analogRead(IR_R) >= Rv)
    Rv_IR = false; //白底
  else
    Rv_IR = true; //黑線

  if (analogRead(IR_L) >= Lv)
    Lv_IR = false; //白底
  else
    Lv_IR = true; //黑線

  if (analogRead(IR_LL) >= LLv)
    LLv_IR = false; //白底
  else
    LLv_IR = true; //黑線
}
void Forward() {
  analogWrite(MR1, 255);
  digitalWrite(MR2, LOW);
  analogWrite(ML1, 255);
  digitalWrite(ML2, LOW);
}
void Stop() {
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, LOW);
}
void Right_LINE() {
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, LOW);
  analogWrite(ML1, 255);
  digitalWrite(ML2, LOW);
}

void Left_LINE() {
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, LOW);
  analogWrite(MR1, 255);
  digitalWrite(MR2, LOW);
}
