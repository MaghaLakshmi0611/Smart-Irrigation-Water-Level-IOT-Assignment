// Define pins for sensors and components
#define SOIL_MOISTURE_PIN A0 // Soil moisture sensor pin
#define PUMP_PIN 5           // Water pump pin (simulated with LED)
#define BUZZER_PIN 4         // Buzzer pin

// Variables to store sensor readings
int soilMoistureValue;

void setup() {
  Serial.begin(9600);  // Start serial communication
  
  pinMode(PUMP_PIN, OUTPUT);   // Set water pump pin as output (simulated with LED)
  pinMode(BUZZER_PIN, OUTPUT); // Set buzzer pin as output
  
  digitalWrite(PUMP_PIN, LOW);  // Ensure water pump is off initially
  digitalWrite(BUZZER_PIN, LOW); // Ensure buzzer is off initially
}

void loop() {
  // Read soil moisture value
  soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);

  // Print the soil moisture value to the serial monitor
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);

  // Soil moisture logic
  if (soilMoistureValue < 300) {  // If soil is dry (threshold can be adjusted)
    digitalWrite(BUZZER_PIN, HIGH);  // Turn on the buzzer to alert about dry soil
    Serial.println("Buzzer ON: Soil is too dry!");
    
    digitalWrite(PUMP_PIN, HIGH);  // Turn on the water pump to water the plants
    Serial.println("Pump ON: Watering the plants...");
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Turn off the buzzer
    digitalWrite(PUMP_PIN, LOW);     // Turn off the water pump
    Serial.println("Pump OFF: No need to water.");
  }

  delay(2000);  // Delay for 2 seconds before the next reading
}
