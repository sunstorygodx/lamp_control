#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
  
  int core = 0;
  float r1 = 96000.0; // 100k
  float r2 = 9700.0; // 10k
  float vout = 0.0;
  float vin = 0.0;
  float value = 0.0; 
  
LiquidCrystal_I2C lcd (0x27,16,2);
void setup() {
 
  Serial.begin(9600);
  pinMode(core, INPUT);
   
  lcd.init();                       
  lcd.backlight();               
  lcd.setCursor(0,0);              
  lcd.print("Hello");       
  lcd.setCursor(0,1);              

}

void loop() {

    value = analogRead(core);
    Serial.println(value);
    vout = (value * 4.95) / 1023.0; 
    vin = vout / (r2/(r1+r2));
     lcd.setCursor(0,0);
     lcd.print(vin);
     Serial.println(vin);
     delay(500);
    
  
}
