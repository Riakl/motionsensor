const int sensorpin = A0;        // Pin for the sensor
const int sensorMin = 0;         // Minimum sensor value
const int sensorMax = 100;       // Maximum sensor value
const int relayPin = 3;          // Pin for the relay
int sensorreading = 0;           // Variable to store the sensor reading

void setup() {
  //  relay pin as output
  pinMode(relayPin, OUTPUT);
  // serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the sensor value
  sensorreading = analogRead(sensorpin);
  
  // show the sensor reading 
  Serial.println(sensorreading);
  
  // Check if the sensor reading is below the minimum
  if (sensorreading <= sensorMin) {
    digitalWrite(relayPin, LOW); // Turn off relay
  }
  // Check if the sensor reading is above the minimum 
  else if (sensorreading >= sensorMin) {
    digitalWrite(relayPin, HIGH); // Turn on relay
  }

  // delay for bulb
  delay(1100);
}