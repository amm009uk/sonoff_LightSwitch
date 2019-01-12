# Sonoff Light Switch (1 gang)

### This project assumes you know what a "sonoff T1 UK" device is and how to upload code to it.

### I was forunate to get a version a version 1.0 board requiring no soldering. Then I followed [DrZzs](https://www.youtube.com/watch?v=yj3_6oKUh1w) video to learn how to enter flash mode. This takes some practice and I didn't bother with putty.

### Flashing through atom/platformio, everything is tied together nicely.

-------------------------------------------------------------------------------------------------------------
## Features

- Custom firmware to integrate with an MQTT Broker. The Broker would typically integrate with your Home Automation system

- Device will respond to MQTT messages and onboard Touch Switch

- WiFi or MQTT drop outs are handled automatically

- You can set a periodic reboot option to keep things fresh

-------------------------------------------------------------------------------------------------------------
## Version
1.4 Initial testing completed.

-------------------------------------------------------------------------------------------------------------
## Setup device
1. Flash SPIFFs to upload the configuration file - sonoff_LightSwitch/data/*.json files. You may modify the contents prior to upload but not necessary

2. Flash firmware

3. Device will initially come up with its own *Access Point* called esp8266-xxxxxxx. Connect to this and configure WiFi parameters. Once saved, device will reboot and connect to your WiFi  
   See section **Finding device IP Address**

4. Once device is connected to WiFi, connect to it using browser

5. Configure device parameters on web page and save  
   Once saved, device will reboot and reconnect to your WiFi

6. Test device using MQTT messages and touch button. Once ok turn off debugging and upload new compiled firmware  
   See section **Debug - Serial/Telnet output**

- Above steps above should be done over USB-->Serial interface until device is fully functioning

- Future firmware updates can be performed over the air no need for USB-->Serial interface

-------------------------------------------------------------------------------------------------------------
## Sample openHAB "item" for Broker/MQTT messages  
Switch LivingRoomLight "Living Room Light" {mqtt=">[brk:cmnd/Light/LivingRoom:command:*:default], <[brk:stat/Light/LivingRoom:state:default]",autoupdate="false"}  
The inbound "<" message helps to keep openHAB in sync with device status

-------------------------------------------------------------------------------------------------------------
## Finding device IP Address
	To get the device IP address you have the following options:
	1. Look at the Serial output where it will show on startup (assuming you have debug output turned on)
	2. Look in your router
	3. Try an mDNS browser app but this often takes time to get the ESP showing up

	4. If already connected to WiFi and MQTT Broker, you can send a blank MQTT message as defined in user.h at "IP_REQUEST".  
     Each device will respond with a MQTT message such as defined with "IP/REPLY/<deviceID>" with the IP address in the payload.

-------------------------------------------------------------------------------------------------------------
## Debug - Serial/Telnet output
	You have two options after turning on SERIAL_DEBUG within sonoff_LightSwitch\src\User.h:
		- Serial USB if connected
		- Telnet if connected

**Do not leave SERIAL_DEBUG enabled for normal use**

-------------------------------------------------------------------------------------------------------------
## OTA Firmware Updates
Once device is connected to your WiFi, find its IP and connect to it through using a Browser. User/Password are stored in sonoff_LightSwitch/src/User.h and you can always modify and flash new firmware to change it. Follow on screen firmware update instructions to flash new firmware.

-------------------------------------------------------------------------------------------------------------
- I am simply reusing other peoples amazing work for instance the following libraries:
	- [PubSubClient](https://github.com/knolleary/pubsubclient)
	- [WifiManager](https://github.com/tzapu/WiFiManager)
	- [RemoteDebug](https://github.com/JoaoLopesF/RemoteDebug)
	- [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
	- [Adafruit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor)
	- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library)

- My development environment is Atom with its builtin PlatformIO toolset. Its a fantastic build and debug environment.