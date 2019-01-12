boolean MQTTconnect() {

#ifdef SERIAL_DEBUG
  debugln("Running MQTTconnect()");
  debug("..Attempting MQTT connection to "); debug(mqtt_server); debug("::"); debug((String)mqtt_port); debug("("); debug(mqtt_user); debug("/"); debug(mqtt_password); debugln(")");
#endif

  if (MQTTclient.connect(deviceID, mqtt_user, mqtt_password)) {   
  	MQTTclient.subscribe(mqtt_inTopic);
  	MQTTclient.subscribe(IP_REQUEST);
  	
#ifdef SERIAL_DEBUG
   debug("..MQTT connected and subscribed to "); debugln(mqtt_inTopic);
#endif
  } else {
#ifdef SERIAL_DEBUG
    debugln("..MQTT connection failed");
#endif
  }

  delay(10);
  return MQTTclient.connected();
  
} // MQTTconnect()

void callback(char* topic, byte* payload, unsigned int length) {

#ifdef SERIAL_DEBUG
  debugln("In MQTT Callback()");
  debug("..Message arrived ["); debug(topic); debugln("] ");
#endif

  if (strcmp(topic, IP_REQUEST) == 0) {                                // Check if we want this message

  	String replyMessage = IP_REPLY;                                  // Build the MQTT reply messsage name
  	replyMessage.concat(deviceID);                                   // ...

  	String Msg = WiFi.localIP().toString();                          // Build MQTT message payload contents

#ifdef SERIAL_DEBUG
	debugAln("MQTT Publish %s with payload %s", replyMessage.c_str(), Msg.c_str());
#endif

		MQTTclient.publish(replyMessage.c_str(), Msg.c_str());		       // Publish message to Broker
		return;
	}

	String msgContents;
	
  if (strcmp(topic, mqtt_inTopic)==0) {                              // Check if we want this message if so get the payload
    for (int i = 0; (i < (int)length); i++) {
			char receivedChar = (char)payload[i];
			msgContents.concat(receivedChar);			
    } 
  } else {                                                           // Not interested in this message
  		debugln("..Message ignored");
  	return;
	}

#ifdef SERIAL_DEBUG
	debugln("..Payload: " + msgContents);
#endif

	//
	// Take appropriate action depending on message contents
	//

	if (msgContents == "ON") {
		relayOn();
	}
	
	if (msgContents == "OFF") {
		relayOff();
	}

	if (msgContents == "TOGGLE") {
		relayToggle();
	}
  delay(10);

} // callback()