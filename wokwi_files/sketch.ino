#include <DHT.h>; // DHT SEND LIB
#include <LiquidCrystal_I2C.h> //LCD LIB

#define DHTPIN 2     // Pin connected to the DHT
#define DHTTYPE DHT22   // DHT sensor (DHT22)
DHT dht(DHTPIN, DHTTYPE); //// DHT sensor inicializálás
LiquidCrystal_I2C lcd(0x27,16,2); // LCD display inicializálás

// Variables
int chk;
float hum;  //páratart.
float temp; //homerseklet

void setup()
{
  dht.begin(); // dht init
  lcd.init(); // lcd init
  lcd.backlight(); // lcd hattervilagitas
}

void loop()
{
    delay(2000);
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    lcd.setCursor(0,0); // cursor LCD elso soraba
    lcd.print("Paratartalom: ");
    lcd.print(hum);
    lcd.print(" % ");
    lcd.setCursor(0,1); // LCD cursor masodik sor
    lcd.print(" Homerseklet: ");
    lcd.print(temp);
    lcd.println(" C");
    delay(5000); // Delay 10sec
}


