
#include <LiquidCrystal.h>
static int MejorPuntaje=0;
LiquidCrystal lcd(12,11,10,9,8,7);
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  
}
void loop() {
  
  lcd.setCursor(0,0);
  lcd.print("MaxPuntos: ");
  lcd.print(MejorPuntaje);
  if(Serial.available()){
    lcd.setCursor(0,1);
    int dato=Serial.parseInt();
    lcd.print("Puntaje : ");  
    lcd.print(dato);  
    if (dato>MejorPuntaje){
       MejorPuntaje=dato;
    }
    }
  
}
