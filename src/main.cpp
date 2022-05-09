#include <Arduino.h>
#include <WiFi.h>
#include <esp_sntp.h>

void ntpUpdated(struct timeval* tv) {
    Serial.printf("NTP updated system clock to %ld\n", tv->tv_sec);
}

void setup() {

    Serial.begin(115200);

    Serial.printf("Start time is %ld\n", time(nullptr));

    WiFi.begin("...", "...");
    Serial.print("Connecting...");
    while (!WiFi.isConnected()) {
        delay(100);
        Serial.print(".");
    }
    Serial.println(" connected.");

    sntp_set_time_sync_notification_cb(ntpUpdated);
    configTime(0, 0, "time.google.com");
}

void loop() {
    Serial.printf("Current time is %ld\n", time(nullptr));
    delay(1000);
}
