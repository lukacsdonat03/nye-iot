# DHT22 + LCD Hőmérséklet és Páratartalom Mérő

Ez a projekt egy **DHT22 hőmérséklet és páratartalom szenzort** használ, és az adatokat egy **LCD** kijelzőn jeleníti meg Arduino  alapú fejlesztőlapon.

## Szükséges alkatrészek

- DHT22 hőmérséklet és páratartalom szenzor
- 16x2 I2C LCD kijelző
- Arduino UNO / kompatibilis fejlesztőlap
- Jumper vezetékek
- Breadboard (opcionális)

## Bekötés

| Eszköz | Pin | Arduino / ESP32 Pin |
|--------|-----|-------------------|
| DHT22 VCC | 3.3V / 5V | 3.3V / 5V |
| DHT22 GND | GND | GND |
| DHT22 DATA | SDA | 2 (vagy bármely szabad digitális pin) |
| LCD VCC | 5V | 5V |
| LCD GND | GND | GND |
| LCD SDA | SDA | A4 (Arduino UNO) / 21 (ESP32) |
| LCD SCL | SCL | A5 (Arduino UNO) / 22 (ESP32) |

## Projekt elérhetőség
**https://wokwi.com/projects/451599922999454721**

## Telepítés

1. Másold a projektet a számítógépedre.
2. Nyisd meg az **Arduino IDE-ben**.
3. Telepítsd a szükséges könyvtárakat:
   - [DHT sensor library](https://github.com/adafruit/DHT-sensor-library)
   - [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C)
4. Ellenőrizd, hogy a **DHTPIN** és az **I2C pin-ek** helyesen vannak beállítva a kódban.
5. Töltsd fel a kódot a fejlesztőlapra.

## 🔧 Kód használata

```cpp
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);

float hum;
float temp;

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  delay(2000);
  hum = dht.readHumidity();
  temp= dht.readTemperature();

  lcd.setCursor(0,0);
  lcd.print("Paratartalom: ");
  lcd.print(hum);
  lcd.print(" % ");

  lcd.setCursor(0,1);
  lcd.print(" Homerseklet: ");
  lcd.print(temp);
  lcd.println(" C");

  delay(5000);
}