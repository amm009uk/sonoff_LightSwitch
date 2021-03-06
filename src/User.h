//#define SERIAL_DEBUG                                                 // Comment this to disable debugging

#define LED_PIN 	    				13																		 // WiFi LED indicator
#define RELAY_PIN							12																		 // Relay and LED for touch switch
#define TOUCH_PIN 					  00																		 // Touch button

#define UPDATE_PATH           "/firmware"                            // Firmware update URL (http://<IP>/firmware
#define WWW_USER              "admin"                                // User for web page
#define WWW_PASSWD            "esp8266ex"                            // Password for web page
#define CONFIGFILE            "/config.json"                         // Configuration file holding various values
#define STATEFILE             "/state.json"                          // State file holding Relay state
#define IP_REQUEST            "IP/Request"                           // MQTT IP Request Message
#define IP_REPLY              "IP/Reply/"                            // MQTT IP Reply Message