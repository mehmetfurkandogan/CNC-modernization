// Define the digital pin for output
const int outputPin = 4;
int step_pulse_time = 100;
int step_idle_delay = 25;
int number_of_pulses = 100;

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
      for (int i = 0 ; i < number_of_pulses; i++) {
        digitalWrite(outputPin, HIGH);  // Set the output pin HIGH
        delayMicroseconds(step_pulse_time);
        digitalWrite(outputPin, LOW);   // Set the output pin LOW
        delay(step_idle_delay);
      }
    }
  }
}
