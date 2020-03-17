/*
   ICAN2020
   QSHP制御コード
*/
#include <Wire.h>
#include <SSD1306.h>
#if defined ( ESP32 )
HardwareSerial  GpsSerial( 2 );
#else
#define  GpsSerial  Serial1;
#endif

#define MMA8452_ADRS 0x1D
#define MMA8452_OUT_X_MSB 0x01
#define MMA8452_XYZ_DATA_CFG 0x0E
#define MMA8452_CTRL_REG1 0x2A
#define MMA8452_CTRL_REG1_ACTV_BIT 0x01
#define MMA8452_G_SCALE 2

SSD1306  display(0x3c, 23, 22);

typedef struct {
  float x;
  float y;
  float z;
} vec3;

void setup() {
  display.init();
  display.setFont(ArialMT_Plain_16);
  accelInit();
  printDisplay("Initializing...");
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(1000);
  printDisplay("Initialized!");
  display.clear();
}

void loop() {
  float temp;
  vec3 headAccel, wristAccel;
  
  /*センサの値を取得*/
  temp = getTemp();
  headAccel = getHeadAcclerelation();
  wristAccel = getWristAcclerelation();
  
}