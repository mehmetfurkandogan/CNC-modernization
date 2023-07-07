#define QRD1114_PIN  2 // Sensor output voltage
float hiz = 0;
int arachiz = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(QRD1114_PIN, INPUT);

  //TIMER INTERRUPT
  cli(); //Stop Interrupts

  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  OCR1A = 6249; // Interrupt Frequency -> 10 Hz, [16*10^6 / (10*256)]-1
  // Alternative -> 15624,[(16*10^6) / (1*1024)] - 1 (1Hz)

  TCCR1A |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);

  sei(); //Enable Interrupts

  attachInterrupt(digitalPinToInterrupt(QRD1114_PIN), hizokuma, CHANGE); // External Interrupt
}

void hizokuma() {
  hiz++;
}

ISR(TIMER1_COMPA_vect){
     arachiz = hiz/100*60; //Teker devri, rpm
     hiz = 0;
}

void loop()
{
  Serial.println(arachiz);
}










//const int QRD1114_PIN = 4; // Sensor output voltage
//
//void setup()
//{
//  Serial.begin(9600);
//  pinMode(QRD1114_PIN, INPUT);
//}
//
//void loop()
//{
//  // Read in the ADC and convert it to a voltage:
//  int proximityADC = digitalRead(QRD1114_PIN);
//
//  Serial.println(proximityADC);
//  delay(100);
//}
