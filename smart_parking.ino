#include "esp_camera.h"
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo gateServo;

#define SERVO_PIN 13
#define IR_ENTRY 14
#define IR_SLOT1 2
#define IR_SLOT2 4

#define TOTAL_SLOTS 2

// AI Thinker ESP32-CAM camera pins
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

void setupCamera()
{
    camera_config_t config;

    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;

    config.pin_d0 = Y2_GPIO_NUM;
    config.pin_d1 = Y3_GPIO_NUM;
    config.pin_d2 = Y4_GPIO_NUM;
    config.pin_d3 = Y5_GPIO_NUM;
    config.pin_d4 = Y6_GPIO_NUM;
    config.pin_d5 = Y7_GPIO_NUM;
    config.pin_d6 = Y8_GPIO_NUM;
    config.pin_d7 = Y9_GPIO_NUM;

    config.pin_xclk = XCLK_GPIO_NUM;
    config.pin_pclk = PCLK_GPIO_NUM;
    config.pin_vsync = VSYNC_GPIO_NUM;
    config.pin_href = HREF_GPIO_NUM;
    config.pin_sscb_sda = SIOD_GPIO_NUM;
    config.pin_sscb_scl = SIOC_GPIO_NUM;
    config.pin_pwdn = PWDN_GPIO_NUM;
    config.pin_reset = RESET_GPIO_NUM;

    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_JPEG;
    config.frame_size = FRAMESIZE_VGA;
    config.jpeg_quality = 10;
    config.fb_count = 1;

    esp_err_t result = esp_camera_init(&config);

    if (result != ESP_OK)
    {
        Serial.println("Camera initialization failed");
        lcd.clear();
        lcd.print("Camera Error");
    }
}

void captureImage()
{
    camera_fb_t *fb = esp_camera_fb_get();

    if (fb == NULL)
    {
        Serial.println("Image capture failed");
        return;
    }

    Serial.print("Image captured. Size: ");
    Serial.print(fb->len);
    Serial.println(" bytes");

    // The image buffer can be sent to an external
    // ANPR/OCR server for number-plate recognition.

    esp_camera_fb_return(fb);
}

void setup()
{
    Serial.begin(115200);

    lcd.init();
    lcd.backlight();

    pinMode(IR_ENTRY, INPUT);
    pinMode(IR_SLOT1, INPUT);
    pinMode(IR_SLOT2, INPUT);

    gateServo.attach(SERVO_PIN);
    gateServo.write(0);

    lcd.setCursor(0, 0);
    lcd.print("Smart Parking");
    lcd.setCursor(0, 1);
    lcd.print("Initializing");
    delay(2000);

    setupCamera();

    lcd.clear();
    lcd.print("System Ready");
    delay(1000);
}

void loop()
{
    int occupied = 0;

    if (digitalRead(IR_SLOT1) == LOW)
        occupied++;

    if (digitalRead(IR_SLOT2) == LOW)
        occupied++;

    int available = TOTAL_SLOTS - occupied;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Available: ");
    lcd.print(available);

    if (available > 0)
        lcd.setCursor(0, 1), lcd.print("Parking Available");
    else
        lcd.setCursor(0, 1), lcd.print("Parking Full");

    if (digitalRead(IR_ENTRY) == LOW)
    {
        if (available > 0)
        {
            lcd.clear();
            lcd.print("Vehicle Detected");

            gateServo.write(90);
            delay(1500);

            captureImage();

            gateServo.write(0);
            delay(1500);
        }
        else
        {
            lcd.clear();
            lcd.print("Parking Full");
            lcd.setCursor(0, 1);
            lcd.print("Entry Denied");
            delay(1500);
        }
    }

    delay(500);
}
