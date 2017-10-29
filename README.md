# temperature-humidity-sensor
This script will measure the temperature and humidity using the DHT11 sensor with Arduino. The data loads up in a struct array during the measuring, then gets printed onto the LCD screen when the measuring is complete. There are 10 total measurements with a 3-second delay in between each measurement. The sensor itself is a basic, ultra low-cost digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air, and spits out a digital signal on the data pin. Its fairly simple to use, but requires careful timing to grab data.

## Preview:
Video: https://www.youtube.com/watch?v=G6UH2HAJyKI


![](https://i.imgur.com/d9zMDdJ.png)
![](https://i.imgur.com/ILitw69.jpg)
![](https://i.imgur.com/7bcjIxg.jpg)
![](https://i.imgur.com/bAfSiK2.jpg)
![](https://i.imgur.com/QuNvynX.jpg)
![](https://i.imgur.com/ZEEHjHJ.jpg)

## Library:
https://github.com/niesteszeck/idDHT11
