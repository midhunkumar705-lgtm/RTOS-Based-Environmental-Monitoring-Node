//multi sensor code
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>

#define DHTPIN 4
#define DHTTYPE DHT22

#define LDR_PIN 34
#define GAS_PIN 35
#define RAIN_PIN 32
#define PIR_PIN 27

#define SDA_PIN 21
#define SCL_PIN 22

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_BMP280 bmp;

float temperature = 0;
float humidity = 0;
float pressure = 0;
float altitude = 0;

int lightLevel = 0;
int gasLevel = 0;
int rainLevel = 0;
int motionStatus = 0;

void SensorTask(void *pvParameters)
{
  while (1)
  {
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();

    pressure = bmp.readPressure() / 100.0;
    altitude = bmp.readAltitude(1013.25);

    lightLevel = analogRead(LDR_PIN);
    gasLevel = analogRead(GAS_PIN);
    rainLevel = analogRead(RAIN_PIN);
    motionStatus = digitalRead(PIR_PIN);

    Serial.println("------ SENSOR DATA ------");
    Serial.print("Temp: "); Serial.print(temperature); Serial.println(" C");
    Serial.print("Hum : "); Serial.print(humidity); Serial.println(" %");
    Serial.print("Pres: "); Serial.print(pressure); Serial.println(" hPa");
    Serial.print("Alt : "); Serial.print(altitude); Serial.println(" m");
    Serial.print("Light: "); Serial.println(lightLevel);
    Serial.print("Gas  : "); Serial.println(gasLevel);
    Serial.print("Rain : "); Serial.println(rainLevel);
    Serial.print("Motion: ");
    Serial.println(motionStatus ? "Detected" : "No Motion");
    Serial.println();

    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

void DisplayTask(void *pvParameters)
{
  while (1)
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.println("RTOS ENV NODE");

    display.setCursor(0, 12);
    display.print("T:");
    display.print(temperature);
    display.print(" H:");
    display.print(humidity);

    display.setCursor(0, 24);
    display.print("P:");
    display.print(pressure);
    display.print("hPa");

    display.setCursor(0, 36);
    display.print("L:");
    display.print(lightLevel);
    display.print(" G:");
    display.print(gasLevel);

    display.setCursor(0, 48);
    display.print("R:");
    display.print(rainLevel);
    display.print(" M:");
    display.print(motionStatus ? "YES" : "NO");

    display.display();

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup()
{
  Serial.begin(115200);

  Wire.begin(SDA_PIN, SCL_PIN);
  dht.begin();

  pinMode(PIR_PIN, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED Initialization Failed!");
    while (1);
  }

  if (!bmp.begin(0x76))
  {
    Serial.println("BMP280 Initialization Failed!");
    while (1);
  }

  xTaskCreate(SensorTask, "Sensor Task", 4096, NULL, 1, NULL);
  xTaskCreate(DisplayTask, "Display Task", 4096, NULL, 1, NULL);
}

void loop()
{
}
