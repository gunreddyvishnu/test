// #include <ESP8266WiFi.h>
// #include <ESP8266HTTPClient.h>
// #include <ESP8266WebServer.h>
// #include <EEPROM.h>

// //Variables
// int i = 0;
// int statusCode;
// const char* ssid = "TP-Link_E1FA";
// const char* passphrase = "a123g2madhu";
// String st;
// String content;


// //Function Decalration
// bool testWifi(void);
// void launchWeb(void);
// void setupAP(void);

// //Establishing Local server at port 80 whenever required
// ESP8266WebServer server(80);

// void setup()
// {

//   Serial.begin(115200); //Initialising if(DEBUG)Serial Monitor
//   Serial.println();
//   Serial.println("Disconnecting current wifi connection");
//   WiFi.disconnect();
//   EEPROM.begin(512); //Initialasing EEPROM
//   delay(10);
//   pinMode(LED_BUILTIN, OUTPUT);
//   Serial.println();
//   Serial.println();
//   Serial.println("Startup");

//   //---------------------------------------- Read eeprom for ssid and pass
//   Serial.println("Reading EEPROM ssid");

//   String esid;
//   for (int i = 0; i < 32; ++i)
//   {
//     esid += char(EEPROM.read(i));
//   }
//   Serial.println();
//   Serial.print("SSID: ");
//   Serial.println(esid);
//   Serial.println("Reading EEPROM pass");

//   String epass = "";
//   for (int i = 32; i < 96; ++i)
//   {
//     epass += char(EEPROM.read(i));
//   }
//   Serial.print("PASS: ");
//   Serial.println(epass);


//   WiFi.begin(esid.c_str(), epass.c_str());
//  launchWeb();
//     setupAP();

//   Serial.println();
//   Serial.println("Waiting.");

//   while ((WiFi.status() != WL_CONNECTED))
//   {
//     // Serial.print(".");
//     delay(100);
//     server.handleClient();
//   }

// }
// void loop() {
//   if ((WiFi.status() == WL_CONNECTED))
//   {

//     for (int i = 0; i < 10; i++)
//     {
//       digitalWrite(LED_BUILTIN, HIGH);
//       delay(1000);
//       digitalWrite(LED_BUILTIN, LOW);
//       delay(1000);
//     }

//   }
//   else
//   {
//   }

// }


// //----------------------------------------------- Fuctions used for WiFi credentials saving and connecting to it which you do not need to change
// bool testWifi(void)
// {
//   int c = 0;
//   Serial.println("Waiting for Wifi to connect");
//   while ( c < 20 ) {
//     if (WiFi.status() == WL_CONNECTED)
//     {
//       return true;
//     }
//     delay(500);
//     Serial.print("*");
//     c++;
//   }
//   Serial.println("");
//   Serial.println("Connect timed out, opening AP");
//   return false;
// }

// void createWebServer()
// {
//   {
//     // server.on("/", []() {

//     //   IPAddress ip = WiFi.softAPIP();
//     //   String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
//     //   content = "<!DOCTYPE HTML>\r\n<html>Welcome to Wifi Credentials Update page";
//     //   content += "<form action=\"/scan\" method=\"POST\"><input type=\"submit\" value=\"scan\"></form>";
//     //   content += ipStr;
//     //   content += "<p>";
//     //   content += st;
//     //   content += "</p><form method='get' action='setting'><label>SSID: </label><input name='ssid' length=32><input name='pass' length=64><input type='submit'></form>";
//     //   content += "</html>";
//     //   server.send(200, "text/html", content);
//     // });
//     server.on("/getboardinfo", []() {
//       //setupAP();
//       IPAddress ip = WiFi.softAPIP();
//     //   String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);

//       content = "<!DOCTYPE HTML>\r\n<html>go back";
//       server.send(200, "text/html", "{\r\n\"model\":\"xpmodel1\",\r\n\"UEI\":\"XMP2893\"\r\n}");
//     });
    

//     server.on("/saveinfo", []() {
//       String hid = server.arg("HID");
//     //   String qpass = server.arg("pass");
//       if (hid.length() > 0 ) {
//         Serial.println("clearing eeprom");
//         for (int i = 0; i < 96; ++i) {
//           EEPROM.write(i, 0);
//         }
//         Serial.println(hid);
//         Serial.println("");
    
//         Serial.println("");

//         Serial.println("writing eeprom ssid:");
//         for (int i = 0; i < hid.length(); ++i)
//         {
//           EEPROM.write(i, hid[i]);
//           Serial.print("Wrote: ");
//           Serial.println(hid[i]);
//         }
       
//         EEPROM.commit();

//         content = "{\"Success\":\"saved to eeprom... reset to boot into new wifi\"}";
//         statusCode = 200;
//         // ESP.reset();
//       } else {
//         content = "{\"Error\":\"404 not found\"}";
//         statusCode = 404;
//         Serial.println("Sending 404");
//       }
//       server.sendHeader("Access-Control-Allow-Origin", "*");
//       server.send(statusCode, "application/json", content);

//     });
//   }
// }
// void launchWeb()
// {
//   Serial.println("");
//   if (WiFi.status() == WL_CONNECTED)
//     Serial.println("WiFi connected");
//   Serial.print("Local IP: ");
//   Serial.println(WiFi.localIP());
//   Serial.print("SoftAP IP: ");
//   Serial.println(WiFi.softAPIP());
//   createWebServer();
//   // Start the server
//   server.begin();
//   Serial.println("Server started");
// }

// void setupAP(void)
// {
//   WiFi.mode(WIFI_STA);
//   WiFi.disconnect();
//   delay(100);
//   int n = WiFi.scanNetworks();
//   Serial.println("scan done");
//   if (n == 0)
//     Serial.println("no networks found");
//   else
//   {
//     Serial.print(n);
//     Serial.println(" networks found");
//     for (int i = 0; i < n; ++i)
//     {
//       // Print SSID and RSSI for each network found
//       Serial.print(i + 1);
//       Serial.print(": ");
//       Serial.print(WiFi.SSID(i));
//       Serial.print(" (");
//       Serial.print(WiFi.RSSI(i));
//       Serial.print(")");
//       Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
//       delay(10);
//     }
//   }
//   Serial.println("");
//   st = "<ol>";
//   for (int i = 0; i < n; ++i)
//   {
//     // Print SSID and RSSI for each network found
//     st += "<li>";
//     st += WiFi.SSID(i);
//     st += " (";
//     st += WiFi.RSSI(i);

//     st += ")";
//     st += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
//     st += "</li>";
//   }
//   st += "</ol>";
//   delay(100);
//   WiFi.softAP("ElectronicsInnovation", "");
//   Serial.println("Initializing_softap_for_wifi credentials_modification");
//   launchWeb();
//   Serial.println("over");
// }
// ss

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

int LED = 5; // Assign LED pin i.e: D1 on NodeMCU

void setup() {

// initialize GPIO 5 as an output

pinMode(LED, OUTPUT);

}

// the loop function runs over and over again forever

void loop() {

digitalWrite(LED, HIGH); // turn the LED on
delay(1000); // wait for a second
digitalWrite(LED, LOW); // turn the LED off
delay(1000); // wait for a second

}

happy


ssssfgsdfgsgsgsgsgggsdgddg