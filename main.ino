// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "LittleFS.h"

// Replace with your network credentials
const char* ssid = "DNS";
const char* password = "01234567";

bool upState = 0;
bool downState = 0;
bool leftState = 0;
bool rightState = 0;

//define motor pins
const int enA = 14; // Enable pin for motor A
const int in1 = 26; // Input 1 for motor A
const int in2 = 25; // Input 2 for motor A
const int enB = 27; // Enable pin for motor B
const int in3 = 33; // Input 1 for motor B
const int in4 = 32; // Input 2 for motor B

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

String message = "";
String sliderValue1 = "0";
String sliderValue2 = "0";
String sliderValue3 = "0";
String sliderValue4 = "0";
String sliderValue5 = "0";
String sliderValue6 = "0";

int dutyCycle1;
int dutyCycle2;
int dutyCycle3;
int dutyCycle4;
int dutyCycle5;
int dutyCycle6;

// setting PWM properties
const int freq = 50;
const int resolution = 16;

//Define servo motor pins
#define SERVO_PIN1 16
#define SERVO_PIN2 17
#define SERVO_PIN3 18
#define SERVO_PIN4 19
#define SERVO_PIN5 21

uint32_t duty1;
uint32_t duty2;
uint32_t duty3;
uint32_t duty4;
uint32_t duty5;
uint32_t duty6;

//Json Variable to Hold Slider Values
JSONVar sliderValues;

//Get Slider Values
String getSliderValues(){
  sliderValues["sliderValue1"] = String(sliderValue1);
  sliderValues["sliderValue2"] = String(sliderValue2);
  sliderValues["sliderValue3"] = String(sliderValue3);
  sliderValues["sliderValue4"] = String(sliderValue4);
  sliderValues["sliderValue5"] = String(sliderValue5);
  sliderValues["sliderValue6"] = String(sliderValue6);

  String jsonString = JSON.stringify(sliderValues);
  return jsonString;
}

// Initialize LittleFS
void initFS() {
  if (!LittleFS.begin()) {
    Serial.println("An error has occurred while mounting LittleFS");
  }
  else{
   Serial.println("LittleFS mounted successfully");
  }
}

// Initialize WiFi
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}
/*
void notifyClients(String sliderValues) {
  ws.textAll(sliderValues);
}*/

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    message = (char*)data;
    if (message.indexOf("1s") >= 0) {
      sliderValue1 = message.substring(2);
      dutyCycle1 = map(sliderValue1.toInt(), 0, 180, 0, 180);
      Serial.println(dutyCycle1);
      Serial.print(getSliderValues());
      //notifyClients(getSliderValues());
    }
    if (message.indexOf("2s") >= 0) {
      sliderValue2 = message.substring(2);
      dutyCycle2 = map(sliderValue2.toInt(), 0, 180, 0, 180);
      Serial.println(dutyCycle2);
      Serial.print(getSliderValues());
      //notifyClients(getSliderValues());
    }    
    if (message.indexOf("3s") >= 0) {
      sliderValue3 = message.substring(2);
      dutyCycle3 = map(sliderValue3.toInt(), 0, 180, 0, 180);
      Serial.println(dutyCycle3);
      Serial.print(getSliderValues());
      //notifyClients(getSliderValues());
    }
    if (message.indexOf("4s") >= 0) {
      sliderValue4 = message.substring(2);
      dutyCycle4 = map(sliderValue4.toInt(), 0, 180, 0, 180);
      Serial.println(dutyCycle2);
      Serial.print(getSliderValues());
      //notifyClients(getSliderValues());
    }  
    if (message.indexOf("5s") >= 0) {
      sliderValue5 = message.substring(2);
      dutyCycle5 = map(sliderValue5.toInt(), 0, 180, 0, 180);
      Serial.println(dutyCycle2);
      Serial.print(getSliderValues());
      //notifyClients(getSliderValues());
    }
    if (message.indexOf("6s") >= 0) {
      sliderValue6 = message.substring(2);
      dutyCycle6 = map(sliderValue6.toInt(), 0, 180, 0, 180);
      Serial.println(dutyCycle2);
      Serial.print(getSliderValues());
      //notifyClients(getSliderValues());
    }      
    if (strcmp((char*)data, "getValues") == 0) {
      //notifyClients(getSliderValues());
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

String processor(const String& var){
  Serial.println(var);
  if(var == "up"){
      return upState ? "ON" : "OFF";
  } else if (var == "left"){
      return leftState ? "ON" : "OFF";
  } else if(var == "right"){
      return rightState ? "ON" : "OFF";
  } else if(var == "down"){
      return downState ? "ON" : "OFF";
  }
    return String();
}

void initFS() {
  if (!LittleFS.begin()) {
    Serial.println("An error has occurred while mounting LittleFS");
  }
  else{
   Serial.println("LittleFS mounted successfully");
  }
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  //set dc motor pins as output
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Initialize LittleFS
  initFS();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  initWebSocket();

  // Web Server Root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/index.html", "text/html");
  });
  
  server.serveStatic("/", LittleFS, "/");

  // Start server
  server.begin();
}

void loop() {
  ws.cleanupClients();

  if (upState == 1) { //forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 255);
    analogWrite(enB, 255);
  } else if (downState == 1) { //backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 255);
    analogWrite(enB, 255);
  } else if (leftState == 1) { //left
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 255);
    analogWrite(enB, 255);
  } else if (rightState == 1) { //right
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 255);
    analogWrite(enB, 255);
  } else{ //stop motors
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }
}