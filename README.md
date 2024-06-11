AQUARIUM AUTOMATION PROJECT BASED ON A IOT WITH MQTT 

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

For visual display of project data and remote parameter control, a dashboard implemented in Node-RED will be used. This dashboard will connect to an Eclipse IoT broker. The same broker will be connected to the ESP32, which will access the broker via a Wi-Fi connection. The following figure provides a detailed overview of the project's architecture.

    
![Esquema-Projeto_IoT](https://github.com/guixavier-14/Automacao-Aquario/assets/117041423/3c038a2e-c2ef-49c3-9850-174e5476abb9)

