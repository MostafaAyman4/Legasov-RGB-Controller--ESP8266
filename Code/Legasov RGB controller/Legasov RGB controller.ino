/*
 * *****************************************************************************************
 * *************************** Legasov RGB Controller -ESP8266******************************
 * ****************************AUTHOR: Mostafa Ayman   7/2021*******************************
 * **https://www.instructables.com/member/Mostafa+Ayman/**
 * this project is open source so, You may use or modify this code for any and all of your 
 * projects without any restrictions
 * if you use this project i will be happy if you tell me -->https://twitter.com/Mostafa__8
 * 
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "Bee"
#define STAPSK  "10122.ana"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

#define change_value  20
#define BRIGHT_CHANGE 100
#define delay_time 200
#define red D5
#define green D6
#define blue D7

int RED_value=0;
int GREEN_value=0;
int BLUE_value=0;

int blue_check_bool=0;
int smooth_check_bool=0;
int blinking_check_bool=0;

int bright_contrust=0;

char red_C=0;
char green_C=0;
char blue_C=0;
char white_C=0;
char clr_2_C=0;
char clr_3_C=0;
char clr_4_C=0;
char clr_5_C=0;
char clr_7_C=0;
char clr_8_C=0;
char clr_9_C=0;
char clr_10_C=0;
char clr_12_C=0;
char clr_13_C=0;
char clr_14_C=0;
char clr_15_C=0;
char off_c=0;

ESP8266WebServer server(80);

void delay_time_function(int );
void handleRoot() ;
void handleNotFound();
void blinking_fun();
void smooth_fun();

void setup(void) {

  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  //--------------RED CHANGE-------------------------------------
  server.on("/RED_ADD", []() {
    server.send(200, "text/plain", "RED+");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
    RED_value=RED_value+change_value;
    analogWrite(red,RED_value);
    Serial.print("RED");
    Serial.println(RED_value);
  });
  server.on("/RED_SUB", []() {
    server.send(200, "text/plain", "RED-");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
    RED_value=RED_value-change_value;
    analogWrite(red,RED_value);
    Serial.print("RED");
    Serial.println(RED_value);
  });
  //--------------GREEN CHANGE-------------------------------------
  server.on("/GREEN_ADD", []() {
    server.send(200, "text/plain", "GREEN+");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
    GREEN_value=GREEN_value+change_value;
    analogWrite(green,GREEN_value);
  });
  server.on("/GREEN_SUB", []() {
    server.send(200, "text/plain", "GREEN-");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
    GREEN_value=GREEN_value-change_value;
    analogWrite(green,GREEN_value);
  });
  //--------------BLUE CHANGE-------------------------------------
  server.on("/BLUE_ADD", []() {
    server.send(200, "text/plain", "BLUE+");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
    BLUE_value=BLUE_value+change_value;
    analogWrite(blue,BLUE_value);
  });
  server.on("/BLUE_SUB", []() {
    server.send(200, "text/plain", "BLUE-");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
    BLUE_value=BLUE_value-change_value;
    analogWrite(blue,BLUE_value);
  });
  //--------------RED-------------------------------------
  server.on("/RED", []() {
    server.send(200, "text/plain", "RED");
    smooth_check_bool=0;
    blinking_check_bool=0;
     red_C=1;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------GREEN-------------------------------------
  server.on("/GREEN", []() {
    server.send(200, "text/plain", "GREEN");
    smooth_check_bool=0;
    blinking_check_bool=0;
     red_C=0;
     green_C=1;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------BLUE-------------------------------------
  server.on("/BLUE", []() {
    server.send(200, "text/plain", "BLUE");
    smooth_check_bool=0;
    blinking_check_bool=0;
     red_C=0;
     green_C=0;
     blue_C=1;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------OFF-------------------------------------
  server.on("/OFF", []() {
    server.send(200, "text/plain", "OFF");
    smooth_check_bool=0;
    blinking_check_bool=0;
     red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
     off_c=1;
  });
  //--------------BLINKING-------------------------------------
  server.on("/BLINKING", []() {
    server.send(200, "text/plain", "BLINKING");
    blinking_check_bool=1;
    smooth_check_bool=0;
  });
  //--------------SMOOTH-------------------------------------
  server.on("/SMOOTH", []() {
    //while on void loop depend on a value
    server.send(200, "text/plain", "SMOOTH");
    smooth_check_bool=1;
    blinking_check_bool=0;
  });
  //--------------CLR_2-------------------------------------
  server.on("/CLR_2", []() {
    server.send(200, "text/plain", "CLR_2");
    smooth_check_bool=0;
    blinking_check_bool=0;
     red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=1;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------CLR_3-------------------------------------
  server.on("/CLR_3", []() {
    server.send(200, "text/plain", "CLR_3");
    smooth_check_bool=0;
    blinking_check_bool=0;
     red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=1;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------CLR_4-------------------------------------
  server.on("/CLR_4", []() {
    server.send(200, "text/plain", "CLR_4");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=1;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------CLR_5-------------------------------------
  server.on("/CLR_5", []() {
    server.send(200, "text/plain", "CLR_5");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=1;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------CLR_7-------------------------------------
  server.on("/CLR_7", []() {
    server.send(200, "text/plain", "CLR_7");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=1;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------CLR_8-------------------------------------
  server.on("/CLR_8", []() {
    server.send(200, "text/plain", "CLR_8");
    smooth_check_bool=0;
    blinking_check_bool=0;
     red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=1;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------CLR_9-------------------------------------
  server.on("/CLR_9", []() {
    server.send(200, "text/plain", "CLR_9");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=9;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------CLR_10-------------------------------------
  server.on("/CLR_10", []() {
    server.send(200, "text/plain", "CLR_10");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=1;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------CLR_12-------------------------------------
  server.on("/CLR_12", []() {
    server.send(200, "text/plain", "CLR_12");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=1;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------CLR_13-------------------------------------
  server.on("/CLR_13", []() {
    server.send(200, "text/plain", "CLR_13");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=1;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------CLR_14-------------------------------------
  server.on("/CLR_14", []() {
    server.send(200, "text/plain", "CLR_14");
    smooth_check_bool=0;
    blinking_check_bool=0;
    red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=1;
     clr_15_C=0;
  });
  //--------------CLR_15-------------------------------------
  server.on("/CLR_15", []() {
    server.send(200, "text/plain", "CLR_15");
    smooth_check_bool=0;
    blinking_check_bool=0;
     red_C=0;
     green_C=0;
     blue_C=0;
     white_C=0; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=1;
  });
  //--------------WHITE-------------------------------------
  server.on("/WHITE", []() {
    server.send(200, "text/plain", "WHITE");
    smooth_check_bool=0;
    blinking_check_bool=0;
     red_C=0;
     green_C=0;
     blue_C=0;
     white_C=1; 
     clr_2_C=0;
     clr_3_C=0;
     clr_4_C=0;
     clr_5_C=0;
     clr_7_C=0;
     clr_8_C=0;
     clr_9_C=0;
     clr_10_C=0;
     clr_12_C=0;
     clr_13_C=0;
     clr_14_C=0;
     clr_15_C=0;
  });
  //--------------BRIGHT UP-------------------------------------
  server.on("/BRIGHT_UP", []() {
    server.send(200, "text/plain", "BRIGHT_UP");
    bright_contrust=bright_contrust-BRIGHT_CHANGE;
    Serial.println(bright_contrust);
  });
  //--------------BRIGHT DOWN-----------------------------------
  server.on("/BRIGHT_DOWN", []() {
    server.send(200, "text/plain", "BRIGHT_DOWN");
    bright_contrust=bright_contrust+BRIGHT_CHANGE;
    Serial.println(bright_contrust);
  });
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  if(smooth_check_bool==1){
   smooth_fun();
  }
  else if(RED_value>=1023){
    RED_value=0;
  }
  else if(GREEN_value>=1023){
    GREEN_value=0;
  }
  else if(BLUE_value>=1023){
    BLUE_value=0;
  }
  else if(RED_value<0){
    RED_value=0;
  }
  else if(GREEN_value<0){
    GREEN_value=0;
  }
  else if(BLUE_value<0){
    BLUE_value=0;
  }
  //
  else if(bright_contrust>=1023){
    bright_contrust=0;
  }
  else if(bright_contrust<0){
    bright_contrust=0;
  }
  else if(blinking_check_bool==1){
    blinking_fun();
  }
  else if(red_C==1){
    analogWrite(red,1023-bright_contrust);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
  }
  else if(green_C==1){
    digitalWrite(red,LOW);
    analogWrite(green,1023-bright_contrust);
    digitalWrite(blue,LOW);
  }
  else if(blue_C==1){
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    analogWrite(blue,1023-bright_contrust);
  }
  else if(white_C==1){
    analogWrite(red,1023-bright_contrust);
    analogWrite(green,1023-bright_contrust);
    analogWrite(blue,1023-bright_contrust);
  }
  else if(clr_2_C==1){
    analogWrite(red,1023-bright_contrust);
    analogWrite(green,(0.35*1023)-bright_contrust);
    digitalWrite(blue,LOW);
  }
  else if(clr_3_C==1){
    analogWrite(red,1023-bright_contrust);
    analogWrite(green,(0.55*1023)-bright_contrust);
    digitalWrite(blue,LOW);
  }
  else if(clr_4_C==1){
    analogWrite(red,1023-bright_contrust);
    analogWrite(green,(0.75*1023 -bright_contrust);
    digitalWrite(blue,LOW);
  }
  else if(clr_5_C==1){
    analogWrite(red,1023-bright_contrust);
    analogWrite(green,1023-bright_contrust);
    digitalWrite(blue,LOW);
  }
  else if(clr_7_C==1){
    digitalWrite(red,LOW);
    analogWrite(green,1023-bright_contrust);
    analogWrite(blue,(0.55*1023)-bright_contrust);
  }
  else if(clr_8_C==1){
    digitalWrite(red,LOW);
    analogWrite(green,1023-bright_contrust);
    analogWrite(blue,(0.75*1023)-bright_contrust);
  }
  else if(clr_9_C==1){
    digitalWrite(red,LOW);
    analogWrite(green,(0.75*1023)-bright_contrust);
    analogWrite(blue,1023-bright_contrust);
  }
  else if(clr_10_C==1){
    digitalWrite(red,LOW);
    analogWrite(green,(0.55*1023)-bright_contrust);
    analogWrite(blue,1023-bright_contrust);
  }
  else if(clr_12_C==1){
    analogWrite(red,(0.35*1023)-bright_contrust);
    digitalWrite(green,LOW);
    analogWrite(blue,1023-bright_contrust);
    }
    else if(clr_13_C==1){
    analogWrite(red,(0.55*1023)-bright_contrust);
    digitalWrite(green,LOW);
    analogWrite(blue,1023-bright_contrust);
    }
    else if(clr_14_C==1){
    analogWrite(red,(0.75*1023)-bright_contrust);
    digitalWrite(green,LOW);
    analogWrite(blue,1023-bright_contrust);
    }
    else if(clr_15_C==1){
     analogWrite(red,1023-bright_contrust);
    digitalWrite(green,LOW);
    analogWrite(blue,1023-bright_contrust);
    }
    else if(off_c){
    analogWrite(red,LOW);
    digitalWrite(green,LOW);
    analogWrite(blue,LOW);
    }
  server.handleClient();
  MDNS.update(); 
}
void smooth_fun(){
  for(int i=0;i<=255;i++){
      //server.handleClient();
      //MDNS.update();
      analogWrite(red,i-bright_contrust);
      if(blue_check_bool==1){
      analogWrite(blue,255-i-bright_contrust);}
      delay_time_function(2);
    }
    for(int i=0;i<=255;i++){
      //server.handleClient();
      //MDNS.update();
      analogWrite(green,i-bright_contrust);
      analogWrite(red,255-i-bright_contrust);
      delay_time_function(2);
    }
    blue_check_bool=1;
    for(int i=0;i<=255;i++){
      //server.handleClient();
      //MDNS.update();
      analogWrite(blue,i-bright_contrust);
      analogWrite(green,255-i-bright_contrust);
      delay_time_function(2);
    }
  
}
void blinking_fun(){
    analogWrite(red,1023-bright_contrust);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    delay_time_function(delay_time);
    digitalWrite(red,LOW);
    analogWrite(green,1023-bright_contrust);
    digitalWrite(blue,LOW);
    delay_time_function(delay_time);
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    analogWrite(blue,1023-bright_contrust);
    delay_time_function(delay_time);
    }
void delay_time_function(int d){
  for(int i=0;i<=d;i++){
    server.handleClient();
    MDNS.update(); 
    delay(1);
  }
}
void handleRoot() {
  server.send(200, "text/plain", "hello from esp8266!");
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
