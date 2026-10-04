// Define constants
const int ledPin = 12;
const int freq = 5000;
const int resolution = 8;
// Channel is no longer explicitly defined or passed to setup function

void setup() {
  // Use ledcAttach to set up the pin with freq and resolution
  ledcAttach(ledPin, freq, resolution);
}

void loop() {
  // Use ledcWrite(pin, dutyCycle); - notice pin instead of channel
  ledcWrite(ledPin, 128); // Example duty cycle (50% for 8-bit resolution)
}
