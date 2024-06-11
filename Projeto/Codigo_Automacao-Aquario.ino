#include <WiFi.h> 
#include <PubSubClient.h>
#include <DHT.h>

#define LED1 23
#define LED2 22
#define LED3 21
#define LED4 18
#define LDR 33
#define DHT11_PIN 32
#define Alimentador 19


int valorsensor;
int i;
int temperatura;
float temperaturaSensor;
char temperaturaPublish[22];
float temperaturaAnt;
int nivelTemperatura;
int control;

WiFiClient wifiClient;       

DHT dht11(DHT11_PIN, DHT11);

const char* SSID = " ";
const char* PASSWORD = " ";
const char* BROKER_MQTT = " ";
int BROKER_PORT = 1883;                   

#define ID_MQTT  "XavierESP"  
#define TOPIC_PUBLISH1 "XavierESP/LED1"
#define TOPIC_PUBLISH2 "XavierESP/LED2"
#define TOPIC_PUBLISH3 "XavierESP/LED3"
#define TOPIC_PUBLISH4 "XavierESP/LED4"
#define TOPIC_PUBLISH5 "XavierESP/NivelTemperatura"
#define TOPIC_PUBLISH6 "XavierESP/Temperatura"
#define TOPIC_PUBLISH7 "XavierESP/Alimentador"

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
  pinMode(LDR, INPUT); 
  pinMode(Alimentador, OUTPUT);

  dht11.begin();   

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
            MQTT.subscribe(TOPIC_PUBLISH5);
            MQTT.subscribe(TOPIC_PUBLISH6);
            MQTT.subscribe(TOPIC_PUBLISH7);
        } 
        else {
            Serial.println("Nao foi possivel se conectar ao broker.");
            Serial.println("Nova tentatica de conexao em 10s");
            delay(10000);
        }
    }
}


void enviaValores() {

  valorsensor = analogRead(LDR);

  if (valorsensor < 500) { 

    digitalWrite(LED1, LOW);

    if (i == 1){
      MQTT.publish(TOPIC_PUBLISH1, "true");
    }

    i = 0;
    
  } else {
    
    digitalWrite(LED1, HIGH);

    if (i == 0){
      MQTT.publish(TOPIC_PUBLISH1, "false");
    }

    i = 1;
  }


  temperaturaSensor = dht11.readTemperature();
  dtostrf(temperaturaSensor,2,2,temperaturaPublish);

  if(temperaturaSensor != temperaturaAnt)
  {
      MQTT.publish(TOPIC_PUBLISH6, temperaturaPublish);
      temperaturaAnt = temperaturaSensor;
  }
    
    
  if(control == 1)
  {
      if (nivelTemperatura >= temperatura) {
        digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);

        MQTT.publish(TOPIC_PUBLISH2, "true");
        MQTT.publish(TOPIC_PUBLISH3, "false");
      }

      if (nivelTemperatura < temperatura) {
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
            
        MQTT.publish(TOPIC_PUBLISH2, "false");
        MQTT.publish(TOPIC_PUBLISH3, "true");
      }

      control = 0;
  }

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
        digitalWrite(LED1, HIGH);
      }

      if (msg == "true") {
        digitalWrite(LED1, LOW);
      }
    }


    if(strcmp(topic, TOPIC_PUBLISH4) == 0)
    {
      if (msg == "false") {
        digitalWrite(LED4, HIGH);
      }

      if (msg == "true") {
        digitalWrite(LED4, LOW);
      }
    }

    if(strcmp(topic, TOPIC_PUBLISH5) == 0)
    {
      nivelTemperatura = msg.toInt();
      control = 1;

    }


    if(strcmp(topic, TOPIC_PUBLISH6) == 0)
    {
        temperatura = msg.toInt();

        if (nivelTemperatura >= temperatura) {
          digitalWrite(LED3, HIGH);
          digitalWrite(LED2, LOW);

          MQTT.publish(TOPIC_PUBLISH2, "true");
          MQTT.publish(TOPIC_PUBLISH3, "false");
        }

        if (nivelTemperatura < temperatura) {
          digitalWrite(LED2, HIGH);
          digitalWrite(LED3, LOW);
              
          MQTT.publish(TOPIC_PUBLISH2, "false");
          MQTT.publish(TOPIC_PUBLISH3, "true");
        }
    }


    if(strcmp(topic, TOPIC_PUBLISH7) == 0)
    {
      digitalWrite(Alimentador, HIGH);
      delay(100);
      digitalWrite(Alimentador, LOW);
    }

  
}
