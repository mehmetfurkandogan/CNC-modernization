// Define the digital pin for output
const int outputPin = 2;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set the output pin as an output
  pinMode(outputPin, OUTPUT);
  
  // Set initial state to LOW
  digitalWrite(outputPin, LOW);
}

void loop() {
  if (Serial.available()) {
    char receivedChar = Serial.read();
    
    // Check the received character
    if (receivedChar == 'H' || receivedChar == 'h') {
      digitalWrite(outputPin, HIGH);  // Set the output pin HIGH
      delayMicroseconds(100);
      digitalWrite(outputPin, LOW);   // Set the output pin LOW

  }
}