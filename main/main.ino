// DFDP1100-1 17H Digitale systemer og programmering | Lab 8, Oppgave 4:
#include <LiquidCrystal.h>
#include <idDHT11.h>

int idDHT11pin = 2;
int idDHT11intNumber = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void dht11_wrapper();
idDHT11 DHT11(idDHT11pin,idDHT11intNumber,dht11_wrapper);
void dht11_wrapper() { DHT11.isrCallback(); }

struct data{
  float temperature;
  float humidity;
};
data measure[10];

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  Serial.println("\n---------------------------------------------------");
  DHT11.acquire();
  while(DHT11.acquiring());
  Serial.println("[LOG] Script launched.");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Measuring data!");
  lcd.setCursor(0, 1);
  lcd.print("Please wait...");
  
  for(int i = 0; i < 10; i++){
    measure[i].temperature = DHT11.getCelsius();
    measure[i].humidity = DHT11.getHumidity();
    Serial.print("[LOG] Stored data into array (");
    Serial.print(i + 1);
    Serial.println("/10)");
    delay(3000);
  }
  Serial.println("[LOG] Successfully stored all data.");
  delay(1500);
  Serial.println("[LOG] Getting results from array.");
  delay(1000);

  Serial.println("\n- RESULTS:");
  Serial.print("Temperature:  ");
  for(int i = 0; i < 10; i++){
    Serial.print(measure[i].temperature, 1);
    Serial.print("C");
    Serial.print("    ");
  }

  Serial.print("\nHumidity:     ");
  for(int i = 0; i < 10; i++){
    Serial.print(measure[i].humidity, 1);
    Serial.print("%");
    Serial.print("    ");
  }

  Serial.print("\n\nAverage temperature:  ");
  float totalTemperature = 0, averageTemperature = 0;
  for(int i = 0; i < 10; i++){
    totalTemperature = totalTemperature + measure[i].temperature;
    averageTemperature = totalTemperature / 10;    
  }
  Serial.print(averageTemperature, 1);
  Serial.println("C");

  Serial.print("Average humidity:     ");
  float totalHumidity = 0, averageHumidity = 0;
  for(int i = 0; i < 10; i++){
    totalHumidity = totalHumidity + measure[i].humidity;
    averageHumidity = totalHumidity / 10;    
  }
  Serial.print(averageHumidity, 1);
  Serial.print("%");
  Serial.println("\n---------------------------------------------------");

  int count = 1;
  for(int i = 0; i < 10; i++){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Measure ");
    lcd.print(count);
    lcd.print(":");
    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(measure[i].temperature, 1);
    lcd.print("C  ");
    lcd.print("H:");
    lcd.print(measure[i].humidity, 1);
    lcd.print("%");
    delay(2000);
    count++;
  }

  while(true){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Average temp:");
    lcd.setCursor(0, 1);
    lcd.print(averageTemperature, 1);
    lcd.print("C");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Average hum:");
    lcd.setCursor(0, 1);
    lcd.print(averageHumidity, 1);
    lcd.print("%");
    delay(2500);
  }
}

