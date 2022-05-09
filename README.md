# SNTP timing problem

Using Arduino 1, WIFI connection takes longer (each `.` is 100 ms), but after that `time.google.com` always returns practically immediately:

```text
$ pio run --target upload --target monitor --environment arduino1
...
Start time is 0
Connecting................................. connected.
Current time is 3
NTP updated system clock to 1652133442
Current time is 1652133443
Current time is 1652133444
```

Using Arduino 2 the WIFI connection is almost immediate, but then it takes several seconds to configure NTP, altogether slower than with Arduino 1:

```text
$ pio run --target upload --target monitor --environment arduino2
...
Start time is 0
Connecting.......... connected.
Current time is 0
Current time is 1
Current time is 2
Current time is 3
Current time is 4
NTP updated system clock to 1652133475
Current time is 1652133475
Current time is 1652133476
```
