
 #include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
const char* ssid="Le 2";
const char* password="37c7ttta";
WiFiServer server(80);
SoftwareSerial ArduinoUno(D2,D3);
float x1;
float x2;
float x3;
 void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
 
    Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  // Start the server
  server.begin();
  Serial.println("Server started");
  // Print the IP address
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
   ArduinoUno.begin(4800);
  pinMode(D2,INPUT); //input or reciever
  pinMode(D3,OUTPUT); //output or transmitter
}
 void loop() {
  
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  int j=10;
 while(!ArduinoUno.available());
  //while(ArduinoUno.available()>0) //data recive from arduino
  {
  x1=ArduinoUno.parseFloat();//pass value to nodemcu and to val variable
  Serial.print("paracetamol: ");
  Serial.println(x1);
  }
  delay(17);
  /*ArduinoUno.println(j);
   while (!ArduinoUno.available()){
    ArduinoUno.println(j);
  }*/
   //while(ArduinoUno.available()>0) //data recive from arduino
  {
   x2=ArduinoUno.parseFloat();//pass value to nodemcu and to val variable
  
      Serial.print("cetrizine: ");
  Serial.println(x2);
     
  }
  delay(17);
 /*  ArduinoUno.println(j);
   while (!ArduinoUno.available()){
    ArduinoUno.println(j);
  }*/
   // while(ArduinoUno.available()>0) //data recive from arduino
  {
  x3=ArduinoUno.parseFloat();//pass value to nodemcu and to val variable
   Serial.print("No cold: ");
  Serial.println(x3);
     
  }
 
  
  delay(17);

   client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connnection: close");
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<meta http-equiv=\"refresh\" content=\"3\">");
  
  client.println("<head>");
  client.println("<title>\"AMDD Data\"</title>");

  client.println("</head>");
  
  client.println("<body>");
  client.println("<div>");
  client.println("<h1>Total number of medicines available in AMDD 1</h1>");
  client.println("<br />");
  client.println("<style>");
  client.println("h1{font-family: Georgia;  text-align: center;  color: blue; }");
  client.println("h3{font-family: Arial;  color: gray;  font-size: 18px; }");
 
  
  client.println("</style>");
  client.println("<i>");
  client.print("<h3>");
  client.println("<i>");
  client.print("&nbsp &nbsp &nbsp &nbsp &nbsp");
  client.print(" PARACETAMOL: ");
  client.println("</i>"); 
  
    client.println(x1);
 
  client.println("</h3>");
  client.print("<h3>");
  client.println("<i>");
  client.print("&nbsp &nbsp &nbsp &nbsp &nbsp");
  client.print(" CETIRIZIN: ");
  client.println("</i>"); 
 
    client.println(x2);
 
  
  client.println("</h3>");
  client.print("<h3>");
  client.println("<i>");
  client.print("&nbsp &nbsp &nbsp &nbsp &nbsp");
  client.print(" NO COLD:  ");
  client.println("</i>"); 
  client.println(x3);

  client.println("</h3>");
  client.println("</div>");
  client.println("</body>");
  client.println("</html>");
  delay(1000);
  Serial.println("Client disconnected");
 /*  ArduinoUno.print(j);
  ArduinoUno.println("\n");
  while (!ArduinoUno.available()){
    ArduinoUno.print(j);
    ArduinoUno.println("\n");
  }
 */
}
