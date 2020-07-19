#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include "pass.h"

//librerias para servos pca9685 y esp32 servo  agregado SPP
#include <Wire.h>  //i2c esp32
#include <Adafruit_PWMServoDriver.h> // Multiplexor pca9685 para arduino o esp8266 expansor de salidas analogicas
#include <ESP32Servo.h> // libreria para servos en esp32
//


/*Definiciones para el hexapodo agregado SPP*/
Servo servo;
Servo servo1;  //creamos un objeto servo 

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)


//pines conectados a las patas
#define pata_1 0
#define pata_2 1
#define pata_3 2
#define pata_4 3
#define pata_5 4
#define pata_6 5

//pines conectados codos - articulaciones

#define codo_1 6
#define codo_2 7
#define codo_3 8
#define codo_4 9
#define codo_5 10
#define codo_6 11

//pines conectados a mano

#define mano_1 12
#define mano_2 13
#define mano_3 14
#define mano_4 15
#define mano_5 18
#define mano_6 19

int t1=300000;


unsigned int contador = 0;
void espera(int valor){
 contador = millis()+valor;
 do{

 }while (contador <= millis()); 

}

int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

void configurar_servos()
{ 
  int t1=10000;
    pwm.setPWM(pata_1, 0, angleToPulse(50)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_2, 0, angleToPulse(50)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_3, 0, angleToPulse(50)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_4, 0, angleToPulse(120)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_5, 0, angleToPulse(120)) ;
   delayMicroseconds(t1);

   pwm.setPWM(pata_6, 0, angleToPulse(120)) ;
   delayMicroseconds(t1);
   
    } 
  
  
  void configurar_servos(int t1)
{
  int i;

  

  for (i=0;i<=15;i++) // 0  a 16 pines del pca9685
  {
  pwm.setPWM(i, 0, angleToPulse(90) );
  delayMicroseconds(t1);
  }
  
  // 2 servos esp32
  servo.write(90);
  delayMicroseconds(t1);
  servo1.write(90);
  delayMicroseconds(t1);
     
}
void bajar(){
    
  pwm.setPWM(codo_1, 0, angleToPulse(130)) ;  //  0 90 180
   espera(t1);
  pwm.setPWM(mano_1, 0, angleToPulse(130)) ;
    delayMicroseconds(t1);
  pwm.setPWM(pata_1, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);

  pwm.setPWM(codo_2, 0, angleToPulse(130)) ;  //  0 90 180
    delayMicroseconds(t1);
  pwm.setPWM(mano_2, 0, angleToPulse(130)) ;
    delayMicroseconds(t1);
  pwm.setPWM(pata_2, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);

  pwm.setPWM(codo_3, 0, angleToPulse(130)) ;
    delayMicroseconds(t1);
  pwm.setPWM(mano_3, 0, angleToPulse(130)) ;
    delayMicroseconds(t1);
  pwm.setPWM(pata_3, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);

  pwm.setPWM(codo_4, 0, angleToPulse(130)) ;
    delayMicroseconds(t1);
  pwm.setPWM(mano_4, 0, angleToPulse(130)) ;
    delayMicroseconds(t1);
  pwm.setPWM(pata_4, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);

 pwm.setPWM(codo_5, 0, angleToPulse(130)) ;  //  0 90 180
    delayMicroseconds(t1);
  pwm.setPWM(mano_5, 0, angleToPulse(130)) ;
    delayMicroseconds(t1);
  pwm.setPWM(pata_5, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);

  pwm.setPWM(codo_6, 0, angleToPulse(130)) ;
    delayMicroseconds(t1);
  pwm.setPWM(mano_6, 0, angleToPulse(130)) ;
    delayMicroseconds(t1);
  pwm.setPWM(pata_6, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);

  
  
  }

void bajar2(){

  pwm.setPWM(pata_1, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);
  pwm.setPWM(codo_1, 0, angleToPulse(90)) ;  //  0 90 180
    delayMicroseconds(t1);
  pwm.setPWM(mano_1, 0, angleToPulse(70)) ;
    delayMicroseconds(t1);
  
  pwm.setPWM(pata_2, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);
  pwm.setPWM(codo_2, 0, angleToPulse(90)) ;  //  0 90 180
    delayMicroseconds(t1);
  pwm.setPWM(mano_2, 0, angleToPulse(70)) ;
    delayMicroseconds(t1);
  

  pwm.setPWM(pata_3, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);
  pwm.setPWM(codo_3, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);
  pwm.setPWM(mano_3, 0, angleToPulse(70)) ;
    delayMicroseconds(t1);
  
  pwm.setPWM(pata_4, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);
  pwm.setPWM(codo_4, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);
  pwm.setPWM(mano_4, 0, angleToPulse(70)) ;
    delayMicroseconds(t1);
  
  pwm.setPWM(pata_5, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);
  pwm.setPWM(codo_5, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);
  
  servo.write(70);
    delayMicroseconds(t1);
  
  
  pwm.setPWM(pata_6, 0, angleToPulse(90)) ;
    delayMicroseconds(t1);    

  pwm.setPWM(codo_6, 0, angleToPulse(90)) ;   
    delayMicroseconds(t1);
  servo1.write(70);
    delayMicroseconds(t1);
    
  }

void adelante_A()
{
  //configurar_servos();
   
   pwm.setPWM(pata_1, 0, angleToPulse(115)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_5, 0, angleToPulse(70)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_3, 0, angleToPulse(120)) ;
   delayMicroseconds(t1);
  }

void adelante_B()
{
  //configurar_servos();
    pwm.setPWM(pata_6, 0, angleToPulse(60)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_2, 0, angleToPulse(120)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_4, 0, angleToPulse(60)) ;
   delayMicroseconds(t1);
  
  
  }

 void empuje()
 {
  int t1=10000;
    pwm.setPWM(pata_1, 0, angleToPulse(50)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_2, 0, angleToPulse(50)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_3, 0, angleToPulse(50)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_4, 0, angleToPulse(120)) ;
   delayMicroseconds(t1);
    
   pwm.setPWM(pata_5, 0, angleToPulse(120)) ;
   delayMicroseconds(t1);

   pwm.setPWM(pata_6, 0, angleToPulse(120)) ;
   delayMicroseconds(t1);
   
    } 
/* fin agregados*/



AsyncWebServer server(80);

boolean wifiConnect(char* host) {
#ifdef MYSSID
  WiFi.begin(MYSSID,PASSWD);
  WiFi.waitForConnectResult();
#else
  WiFi.begin();  
  WiFi.waitForConnectResult();
#endif
  Serial.println(WiFi.localIP());
  return (WiFi.status() == WL_CONNECTED);
}

void handleRoot(AsyncWebServerRequest *request) {
  request->redirect("/update");
}

void handleUpdate(AsyncWebServerRequest *request) {
  char* html = "<form method='POST' action='/doUpdate' enctype='multipart/form-data'><input type='file' name='update'><input type='submit' value='Update'></form>";
  request->send(200, "text/html", html);
}

void handleDoUpdate(AsyncWebServerRequest *request, const String& filename, size_t index, uint8_t *data, size_t len, bool final) {
  if (!index){
    log_i("Update");
    // if filename includes spiffs, update the spiffs partition
    int cmd = (filename.indexOf("spiffs") > -1) ? U_SPIFFS : U_FLASH;
    if (!Update.begin(UPDATE_SIZE_UNKNOWN, cmd)) {
      Update.printError(Serial);
    }
  }

  if (Update.write(data, len) != len) {
    Update.printError(Serial);
  }

  if (final) {
    AsyncWebServerResponse *response = request->beginResponse(302, "text/plain", "Please wait while the switch reboots");
    response->addHeader("Refresh", "20");  
    response->addHeader("Location", "/");
    request->send(response);
    if (!Update.end(true)){
      Update.printError(Serial);
    } else {
      Serial.println("Update complete");
      Serial.flush();
      ESP.restart();
    }
  }
}

boolean webInit() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {request->redirect("/update");});
  server.on("/update", HTTP_GET, [](AsyncWebServerRequest *request){handleUpdate(request);});
  server.on("/doUpdate", HTTP_POST,
    [](AsyncWebServerRequest *request) {},
    [](AsyncWebServerRequest *request, const String& filename, size_t index, uint8_t *data,
                  size_t len, bool final) {handleDoUpdate(request, filename, index, data, len, final);}
  );
  server.onNotFound([](AsyncWebServerRequest *request){request->send(404);});
  server.begin();
  return 0;
}

//Modificaciones al programa original OTA para hexapodo

//

void setup() {
  Serial.begin(115200);
  char host[16];
  snprintf(host, 16, "ESP%012llX", ESP.getEfuseMac());
  if(!wifiConnect(host)) {
    Serial.println("Connection failed");
    return;
  }
  MDNS.begin(host);
  if(webInit()) MDNS.addService("http", "tcp", 80);
  Serial.printf("Ready! Open http://%s.local in your browser\n", host);

/*Agregados para el hexapodo SPP */
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  servo.setPeriodHertz(60);    // standard 50 hz servo
  servo.attach(mano_5, 1000, 2000); // attaches the servo on pin 18 to the servo object

  servo1.setPeriodHertz(60);    // standard 50 hz servo
  servo1.attach(mano_6, 1000, 2000); // attaches the servo on pin 18 to the servo object
  configurar_servos();
  bajar2();

}

void loop() 
{
 adelante_A();
 delay(300);
 empuje();
 delay(300);
 adelante_B();
 delay(300);

 //vTaskDelete(NULL);
}
