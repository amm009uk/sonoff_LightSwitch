# Sonoff Light Switch (1 gang)

### This project assumes you know what a "sonoff T1 UK" device is and how to upload code to it.

### I was forunate to get a version a version 1.0 board requiring no soldering. Then I followed [DrZzs](https://www.youtube.com/watch?v=yj3_6oKUh1w) video to learn how to enter flash mode. This takes some practice and I didn't bother with putty.

### Flashing through atom/platformio, everything is tied together nicely.

-------------------------------------------------------------------------------------------------------------
## Features

- Custom firmware to take greater control and integrate with an MQTT Broker. The Broker would typically integrate with your Home Automation system.

- Device will respond to an MQTT message and onboard touch switch.

- WiFi or MQTT drop outs are handled automatically.

- You can set a periodic reboot option to keep things fresh.

-------------------------------------------------------------------------------------------------------------
## Version
1.4 Initial testing completed.

-------------------------------------------------------------------------------------------------------------
## Setup device
1. Flash SPIFFs to upload the configuration file - sonoff_LightSwitch/data/*.json files. You may modify the contents prior to upload but not necessary.

2. Flash firmware.

3. Device will initially come up with its own *Access Point* called esp8266-xxxxxxx. Connect to this and configure WiFi parameters. Once saved, device will reboot and connect to your WiFi.<br/>  
   See section **Finding device IP Address**

4. Once device is connected to WiFi, connect to it using browser. 

5. Configure device parameters on web page and save.<br/>
   Once saved, device will reboot and reconnect to your WiFi.

6. Test device using MQTT messages and touch button. Once ok turn off debugging and upload new compiled firmware.<br/>
   See section **Debug - Serial/Telnet output**.

- Above steps above should be done over USB-->Serial interface until device is fully functioning.

- Future firmware updates can be performed over the air no need for USB-->Serial interface.

-------------------------------------------------------------------------------------------------------------
## Usage
1. Device will initially come up with its own *Access Point* called ITEAD-xxxxxxx. Connect to this and configure WiFi parameters. Once saved, device will reboot.

2. On bootup, device will connect to your WiFi. Find its IP address through your router and connect to it. Configure all parameters and once saved, device will reboot.

3. Device can be controlled with MQTT messages and onboard touch button.

4. Onboard LED:<br/>
		- If WiFi LED is on then light is off
		- Touch button LED will be on with light on

- An alternative method for finding your device is to scan your mDNS network

-------------------------------------------------------------------------------------------------------------
## Sample openHAB "item" for Broker/MQTT messages. 
	- Switch Power "Power" {mqtt=">[brk:cmnd/Light/LivingRoom:command:*:default], <[brk:stat/Light/LivingRoom:state:default]",autoupdate="false"}
The inbound "<" message helps to keep openHAB in sync with device status.

-------------------------------------------------------------------------------------------------------------
## OTA Updates
Once device is connected to your WiFi, find its IP and connect to it. User/Password are stored in sonoff_LightSwitch/src/User.h so you can always modify and flash new firmware easily.

-------------------------------------------------------------------------------------------------------------
- I am simply reusing other peoples amazing work for instance the following libraries PubSubClient and WifiManager.

- My development environment is Atom with its builtin PlatformIO toolset. Its a fantastic build and debug environment.