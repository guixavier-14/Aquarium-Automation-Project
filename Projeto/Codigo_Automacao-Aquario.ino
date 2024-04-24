#include <WiFi.h> 
#include <PubSubClient.h>

#define LED1 23
#define LED2 22
#define LED3 21
#define LED4 18
 
WiFiClient wifiClient;       

const char* SSID = "";
const char* PASSWORD = "";
const char* BROKER_MQTT = "mqtt.eclipseprojects.io";
int BROKER_PORT = 1883;                   

#define ID_MQTT  "XavierESP"  
#define TOPIC_PUBLISH1 "XavierESP/LED1"
#define TOPIC_PUBLISH2 "XavierESP/LED2"
#define TOPIC_PUBLISH3 "XavierESP/LED3"
#define TOPIC_PUBLISH4 "XavierESP/LED4"
PubSubClient MQTT(wifiClient);        

void mantemConexoes();  
void conectaWiFi();     
void conectaMQTT();     
void enviaPacote();  
void recebePacote(char* topic, byte* payload, unsigned int length);   


void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);        

  Serial.begin(115200);

  conectaWiFi();
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);  
  MQTT.setCallback(recebePacote);

}

void loop() {

  mantemConexoes();
  enviaValores();
  MQTT.loop();

}



void mantemConexoes() {
    if (!MQTT.connected()) {
       conectaMQTT(); 
    }
    
    conectaWiFi(); //se não há conexão com o WiFI, a conexão é refeita
}


void conectaWiFi() {

  if (WiFi.status() == WL_CONNECTED) {
     return;
  }
        
  Serial.print("Conectando-se na rede: ");
  Serial.print(SSID);
  Serial.println("  Aguarde!");

  WiFi.begin(SSID, PASSWORD); // Conecta na rede WI-FI  
  while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Conectado com sucesso, na rede: ");
  Serial.print(SSID);  
  Serial.print("  IP obtido: ");
  Serial.println(WiFi.localIP()); 
}


void conectaMQTT() { 
    while (!MQTT.connected()) {
        Serial.print("Conectando ao Broker MQTT: ");
        Serial.println(BROKER_MQTT);
        if (MQTT.connect(ID_MQTT)) {
            Serial.println("Conectado ao Broker com sucesso!");
            MQTT.subscribe(TOPIC_PUBLISH1);
            MQTT.subscribe(TOPIC_PUBLISH2);
            MQTT.subscribe(TOPIC_PUBLISH3);
            MQTT.subscribe(TOPIC_PUBLISH4);
        } 
        else {
            Serial.println("Nao foi possivel se conectar ao broker.");
            Serial.println("Nova tentatica de conexao em 10s");
            delay(10000);
        }
    }
}


void enviaValores() {
  
}


void recebePacote(char* topic, byte* payload, unsigned int length) 
{
    String msg;

    Serial.print("Message arrived ");
    Serial.print(topic);
    Serial.println();

    //obtem a string do payload recebido
    for(int i = 0; i < length; i++) 
    {
       char c = (char)payload[i];
       msg += c;
    }

    if(strcmp(topic, TOPIC_PUBLISH1) == 0)
    {
      if (msg == "false") {
        digitalWrite(LED1, LOW);
      }

      if (msg == "true") {
        digitalWrite(LED1, HIGH);
      }
    }
    

    if(strcmp(topic, TOPIC_PUBLISH2) == 0)
    {
      if (msg == "false") {
        digitalWrite(LED2, LOW);
      }

      if (msg == "true") {
        digitalWrite(LED2, HIGH);
      }
    }


    if(strcmp(topic, TOPIC_PUBLISH3) == 0)
    {
      if (msg == "false") {
        digitalWrite(LED3, LOW);
      }

      if (msg == "true") {
        digitalWrite(LED3, HIGH);
      }
    }


    if(strcmp(topic, TOPIC_PUBLISH4) == 0)
    {
      if (msg == "false") {
        digitalWrite(LED4, LOW);
      }

      if (msg == "true") {
        digitalWrite(LED4, HIGH);
      }
    }

}

