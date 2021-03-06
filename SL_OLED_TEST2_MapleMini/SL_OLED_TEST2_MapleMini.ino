#include "font5x7.h"

/*-- PIN CONFIGURE -----------------------------------*/
// OLED
#define OLED_PIN_PW   22
#define OLED_PIN_D7   21
#define OLED_PIN_D6   20
#define OLED_PIN_D5   19
#define OLED_PIN_D4   18
#define OLED_PIN_EN   17
#define OLED_PIN_RW   16
#define OLED_PIN_RS   15

#define PI_PWR_PIN    3
#define PI_O01_PIN    4
#define PI_O02_PIN    5
#define PI_O03_PIN    6
#define PI_O04_PIN    7
#define PI_I01_PIN    10
#define PI_I02_PIN    11
#define PI_I03_PIN    12
#define PI_I04_PIN    13

#define SW_PWR_PIN    30
#define SW_FUNC_PIN   31

#define LED_PIN       33



/*-- Constants -----------------------------------*/
// OLED
#define WIDTH    100
#define HEIGHT    16
#define GRAPHIC  200

int bmp[HEIGHT][WIDTH] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

byte graphic[GRAPHIC];


void write4bits(uint8_t value) {
  digitalWrite(OLED_PIN_D7, (value >> 3) & 0x01);
  digitalWrite(OLED_PIN_D6, (value >> 2) & 0x01);
  digitalWrite(OLED_PIN_D5, (value >> 1) & 0x01);
  digitalWrite(OLED_PIN_D4, value & 0x01);
  pulseEnable();
}

void write4bits_init(uint8_t value) {
  digitalWrite(OLED_PIN_D7, (value >> 3) & 0x01);
  digitalWrite(OLED_PIN_D6, (value >> 2) & 0x01);
  digitalWrite(OLED_PIN_D5, (value >> 1) & 0x01);
  digitalWrite(OLED_PIN_D4, value & 0x01);
  pulseEnable_init();
}

void send(uint8_t value, uint8_t modeRS , uint8_t modeRW) {
  digitalWrite(OLED_PIN_RS, modeRS);
  digitalWrite(OLED_PIN_RW, modeRW);
  write4bits(value >> 4);
  write4bits(value);
}

void command(uint8_t value) {
  busy();
  send(value, LOW, LOW);
}

void data_write(uint8_t value) {
  busy();
  send(value, HIGH, LOW);
}

void pulseEnable() {
  digitalWrite(OLED_PIN_EN, LOW);
  delayMicroseconds(1);
  digitalWrite(OLED_PIN_EN, HIGH);
  delayMicroseconds(1);
  digitalWrite(OLED_PIN_EN, LOW);
}

void pulseEnable_init() {
  digitalWrite(OLED_PIN_EN, LOW);
  delay(1);
  digitalWrite(OLED_PIN_EN, HIGH);
  delay(1);
  digitalWrite(OLED_PIN_EN, LOW);
  delay(1);
}

void pinModeAll(WiringPinMode value) {
  pinMode(OLED_PIN_PW, value);
  pinMode(OLED_PIN_RS, value);
  pinMode(OLED_PIN_RW, value);
  pinMode(OLED_PIN_EN, value);
  pinMode(OLED_PIN_D4, value);
  pinMode(OLED_PIN_D5, value);
  pinMode(OLED_PIN_D6, value);
  pinMode(OLED_PIN_D7, value);

  digitalWrite(OLED_PIN_PW, LOW);
  delay(500);
  digitalWrite(OLED_PIN_PW, HIGH);
  delay(500);
}

void busy() {
  pinMode(OLED_PIN_D7, INPUT);
  int busy = HIGH;
  while (busy) {
    digitalWrite(OLED_PIN_RS, LOW);
    digitalWrite(OLED_PIN_RW, HIGH);
    pulseEnable();
    busy = digitalRead(OLED_PIN_D7);
    pulseEnable();
  }
  pinMode(OLED_PIN_D7, OUTPUT);
}

void sync() {
  busy();
  digitalWrite(OLED_PIN_RS, LOW);
  digitalWrite(OLED_PIN_RW, LOW);
  write4bits_init(0x0);
  write4bits_init(0x0);
  write4bits_init(0x0);
  write4bits_init(0x0);
  write4bits_init(0x0);
}

void functionSet() {
  busy();
  digitalWrite(OLED_PIN_RS, LOW);
  digitalWrite(OLED_PIN_RW, LOW);
  write4bits(0x2);
  command(0x28);//Function Set[0 0 1 DL N F FT1 FT0]//
}

void displayOn() {
  command(0x0c);//Display ON/OFF Control [0 0 0 0 1 D C B]
}

void displayClear() {
  command(0x01);
}

void returnHome() {
  command(0x02);
}

void entryModeSet() {
  command(0x06); // Entry Mode Set [0 0 0 0 0 0 0 1 I/D S]
}

void graphicModeSet() {
  command(0x1f); // Cursor / Display Shift / Mode / Pwr[ 0 0 0 1 G/C PWR 1 1]

  //{I/D:INCREMENT/DECREMENT BIT [1:右 0:左]}カソールを動かす方向
  //{S:SHIFT ENTIRE DISPLAY CONTROL BIT [1:する 0:しない]}全体シフト
  //{D:DISPLAY ON/OFF BIT [1:ON 0:OFF]}ディスプレイの点灯
  //{C:CURSOR DISPLAY CONTROL BIT [1:ON 0:OFF]}カソールのありなし
  //{B:BLINKING CONTROL BIT [1:する 0:しない]}点滅するかどうか？
  //{S/C:[1:表示とカソール 0:カソール]}シフトするもの
  //{R/L:[1:右 0:左]}右左
  //{G/C:GRAPHIC MODE / CHARACTER MODE SELECTION [1:グラフィック 0:キャラクタ]}モード選択
  //{PWR:ENABLE/DISABLE INTERNAL POWER [1:ON 0:OFF]}DCDCコンバータのON・OFF
  //{DL:INTERFACE DATA LENGTH CONTROL BIT [1:8bit 0:4bit]}インタフェイス選択
  //{N:NUMBER OF DISPLAY LINE [1:2行 0:1行]}行数 //グラフィックモードの時は２行にしないと11×100ドットになるらしい。
  //{F:CHARACTER FONT SET [1:5×10 0:5×8]}フォントセット
  //{FT1:FONT TABLE SELECTION [1: 0:]} テーブルデフォ0
  //{FT0:FONT TABLE SELECTION [1: 0:]} テーブルデフォ0
}

void OLED_init() {

  sync();
  functionSet();
  displayOn();
  entryModeSet();
  graphicModeSet();
  displayClear();
  returnHome();


}

void OLED_setup() {
  pinModeAll(OUTPUT);
  sync();
  functionSet();
  displayOn();
  entryModeSet();
  graphicModeSet();
  displayClear();
  returnHome();
}

void OLED_Cursor(int col, int row) {
  command((0x80 | col));
  command((0x40 | row));
}

void graphic_input(int col, byte *p) {
  for (int i = 1; i < 20; i = i + 2) {
    graphic[i + col] |= p[i];
  }
  for (int i = 0; i < 20; i = i + 2) {
    graphic[i + col] |= p[i];
  }
}

void OLED_display(byte *p) {
  returnHome();
  updateBmp();
  for (int i = 1; i < 200; i = i + 2) {
    data_write(p[i]);
  }
  for (int i = 0; i < 200; i = i + 2) {
    data_write(p[i]);
  }
}

void graphic_clear() {
  for (int i = 0; i < GRAPHIC; i++ )
  {
    graphic[i] = 0x00; //グラフィック変数のクリア
  }
}

void updateBmp() {
  byte b1 = 0x00;
  byte b2 = 0x00;
  for (int w = 0; w < WIDTH; w++) {
    b1 = 0x00;
    b2 = 0x00;
    for (int h = 0; h <= 7; h++) {
      if (bmp[h][w] == 1) {
        b1 |= 0x01 << h;
      }
    }
    graphic[(int)(w * 2 + 1) ] = b1;
    for (int h = 0; h <= 7; h++) {
      if (bmp[h + 8][w] == 1) {
        b2 |= 0x01 << h;
      }
    }
    graphic[(int)(w * 2) ] = b2;
  }
}

void clearBmp() {
  for (int w = 0; w < WIDTH; w++) {
    for (int h = 0; h < HEIGHT; h++) {
      bmp[h][w] = 0;
    }
  }
}

void OLD_print5x7(String S, int x, int y) {
  int fontWidth = 6;
  int fontHeight = 8;
  int c = 0;
  int count = 0;

  for (int i = 0 ; i < S.length(); i++) {
    c = S.charAt(i);
    _add5x7Char2Bmp(c, x + (int)(i * fontWidth), y);
  }
}

void _add5x7Char2Bmp(int c, int x, int y) {
  int fontWidth = 6;
  int fontHeight = 8;

  for (int w = 0; w < fontWidth ; w++) {
    for (int h = 0; h < fontHeight ; h++) {
      if ((h + y < HEIGHT) && (w + x < WIDTH)) {
        bmp[h + y][w + x] = (byte)((font5x7[c * fontWidth + w] >> h)  & 0x01);
      }
    }
  }
}


/* Varias */
void pinInit() {
  pinMode(PI_PWR_PIN, OUTPUT);
  pinMode(PI_O01_PIN, INPUT);
  pinMode(PI_O02_PIN, INPUT);
  pinMode(PI_O03_PIN, INPUT);
  pinMode(PI_O04_PIN, INPUT);
  pinMode(PI_I01_PIN, OUTPUT);
  pinMode(PI_I02_PIN, OUTPUT);
  pinMode(PI_I03_PIN, OUTPUT);
  pinMode(PI_I04_PIN, OUTPUT);
  pinMode(SW_PWR_PIN, INPUT_PULLDOWN);
  pinMode(SW_FUNC_PIN, INPUT_PULLDOWN);
  pinMode(LED_PIN, OUTPUT);
}

void polling() {
  static int sw_pwr = 0;
  static int sw_func = 0;
  

sw_pwr = digitalRead(SW_PWR_PIN);
digitalWrite(LED_PIN, sw_pwr);
digitalWrite(PI_PWR_PIN, sw_pwr);


}




/* =======================================================================================
 setup
=========================================================================================== */
void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  OLED_setup();
  clearBmp();

  pinInit();
}






/* =======================================================================================
 loop
=========================================================================================== */
void loop()
{
  static int count;
  String S;
  clearBmp();

  S = String(count);
  OLD_print5x7(S, 0, 9);
  OLED_display(graphic);
  count ++;

polling();





}
// -- END OF CODE ----------------------------------------------------------
