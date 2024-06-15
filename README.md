AQUARIUM AUTOMATION PROJECT BASED ON IOT WITH MQTT COMMUNICATION 

--------------------------------------------------------------------------------------------------------------------------

**Project Motivation:**
In the world of aquaristics, planted aquariums require a combination of fauna and flora that necessitate specific and stable parameters. Key parameters include temperature, water level, lighting, feeding, among others. Proper maintenance of these parameters mandates regular monitoring and control of these variables. This project aims to implement a system that enables the monitoring and remote control of aquarium parameters via the internet. By automating these processes, the system will significantly simplify aquarium maintenance, ensuring optimal conditions in a practical and efficient manner.

--------------------------------------------------------------------------------------------------------------------------

**Project Objective:**
The objective of this project is to automate an aquarium for the remote monitoring and control of various parameters, such as water temperature, fish feeding, and lighting. Additionally, the project aims to implement a system that allows for the remote addition of water to the aquarium to normalize these parameters.

--------------------------------------------------------------------------------------------------------------------------

**Components:**
- 1 ESP32
- 1 Temperature Sensor - DHT11
- 1 Light Sensor - LDR
- 1 Water Pump
- 1 Servo Motor
- 4 Relays
- 1 Lamp
- 1 10W Aquarium Heater
- 1 5V DC Motor - Fan
  
--------------------------------------------------------------------------------------------------------------------------

**Project Details:**
For data acquisition and parameter control, temperature and light sensors will be used. A servo motor will be employed to manage fish feeding. To regulate the aquarium's temperature, a heater and a fan for cooling will be utilized. A water pump will be used to replenish the aquarium with treated water from an external reservoir. The ESP32 will serve as the control unit.

For visual display of project data and remote parameter control, a dashboard implemented in Node-RED will be used. This dashboard will connect to an Public Eclipse IoT broker. The same broker will be connected to the ESP32, which will access the broker via a Wi-Fi connection. The following figure provides a detailed overview of the project's architecture.

To facilitate remote access to the broken application on Node-RED, the Remote-RED smartphone application was used. This allows monitoring and control of delay settings from anywhere, with internet access available.


![image](https://github.com/guixavier-14/Aquarium-Automation-Project/assets/163915909/1251bca4-ac49-4893-bfcd-14890428c60d)

Na figura a seguir, é apresentado um esquemático de montagem do circuito implementado, com a indicação dos pinos utilizados da ESP32 e as conexões realizadas entre os dispositivos.

![image](https://github.com/guixavier-14/Aquarium-Automation-Project/assets/163915909/877cb1a9-8296-428d-8ed9-44f7af619e42)

