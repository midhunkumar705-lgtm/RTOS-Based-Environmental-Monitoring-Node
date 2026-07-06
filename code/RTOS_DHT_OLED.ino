#include <Arduino.h>
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 4
#define DHTTYPE DHT22

#define SDA_PIN 21
#define SCL_PIN 22

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

float temperature = 0;
float humidity = 0;

void SensorTask(void *pvParameters)
{
  while (1)
  {
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();

    Serial.println("========== SENSOR TASK ==========");
    Serial.print("Temperature : ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity    : ");
    Serial.print(humidity);
    Serial.println(" %");
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

    display.setCursor(0,0);
    display.println("RTOS ENV NODE");

    display.setCursor(0,18);
    display.print("Temp : ");
    display.print(temperature);
    display.println(" C");

    display.setCursor(0,36);
    display.print("Hum  : ");
    display.print(humidity);
    display.println(" %");

    display.setCursor(0,54);
    display.println("Task Running");

    display.display();

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup()
{
  Serial.begin(115200);

  dht.begin();

  Wire.begin(SDA_PIN, SCL_PIN);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED Initialization Failed!");
    while (1);
  }

  xTaskCreate(
      SensorTask,
      "Sensor Task",
      2048,
      NULL,
      1,
      NULL);

  xTaskCreate(
      DisplayTask,
      "Display Task",
      4096,
      NULL,
      1,
      NULL);
}

void loop()
{
}
