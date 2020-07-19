<p>Montaje de un hexapodo con esp32 driver de servos con PCA9685 
<p>programable por OTA
<p>Uso de Asyncwebserver
<p>Uso de spiff


<p>Editor de texto y programacion geany 1.33

<p align="center">
  <img src="https://github.com/pablinn/alexa-fauxmoesp-light/blob/master/img/geany.png" width="350" title="hover text">  
</p>

<p>Agregar comando de compilacion a geany 
<p align="center">
  <img src="https://github.com/pablinn/alexa-fauxmoesp-light/blob/master/img/geany-pio.png" width="350" title="hover text">  
</p>

<p>Ide de programaicon Platformio


<p>Desde la terminal crear el proyecto o usar Visual estudio code
<p>platformio project init --board esp32


<p>lib dependencias dentro de la carpeta o usar platformio para la gestion de librerias
<p>ESPAsyncTCP
<p>https://github.com/me-no-dev/AsyncTCP.git

<p>ESPAsyncWebserver
<p>https://github.com/me-no-dev/ESPAsyncTCP.git

<ESP32Servo>
https://github.com/jkb-git/ESP32Servo.git

<p>Adafruit PCA9685 PWM Servo Driver Library 
<p>https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library.git

<p>

<p>Dentro de source colocar main.cpp y pass.h
<p>src ->main.cpp
<p>src ->pass.h

<p>#define WIFI_SSID         "tu router"    
<p>#define WIFI_PASS         "tu password"

<p>Ejemplo de aplicacion</p>
<center>

[![](http://img.youtube.com/vi/JsiOjVanotw/0.jpg)](http://www.youtube.com/watch?v=JsiOjVanotw "Hexapodo programable por OTA y con spiff")

[![](http://img.youtube.com/vi/HGx5StsD-g4/0.jpg)](http://www.youtube.com/watch?v=HGx5StsD-g4 "Hexapodo programable por OTA y con spiff")
