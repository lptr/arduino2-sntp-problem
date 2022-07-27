#include <Arduino.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include <esp_sntp.h>

void ntpUpdated(struct timeval* tv) {
    Serial.printf("NTP updated system clock to %ld\n", tv->tv_sec);
}

WiFiManager wm;

void setup() {
    Serial.begin(115200);

    Serial.printf("Start time is %ld\n", time(nullptr));

    // wm.resetSettings();
    wm.setHostname("sntp-test");
    wm.setWiFiAutoReconnect(true);
    if (wm.autoConnect("sntp-test")) {
        Serial.println("Connected.");
    } else {
        Serial.println("Not connected.");
    }

    sntp_set_time_sync_notification_cb(ntpUpdated);

    // This works, but passing String.c_str() fails to update:
    // configTime(0, 0, "time.google.com");
    String timeServer = "time.google.com";
    configTime(0, 0, timeServer.c_str());
}

void loop() {
    Serial.printf("Current time is %ld\n", time(nullptr));
    delay(1000);
}
