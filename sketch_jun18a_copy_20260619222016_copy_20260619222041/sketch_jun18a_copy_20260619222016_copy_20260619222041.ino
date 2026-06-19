int startValue = 5;   // Set the countdown starting number
int ledPin = 13;      // The onboard LED pin for the Arduino Uno

void flashLED(int times) {
  // A simple for loop to blink the LED the specified number of times
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);  // Set pin 13 as an output
  Serial.begin(9600);       // Initialize serial communication at 9600 baud
  
  Serial.println("=== Smart Countdown Starting ===");
  
  int count = startValue;   // Initialize the counter with our starting value
  
  // Keep looping as long as count is greater than 0
  while (count > 0) {
    Serial.print("Count: ");
    Serial.println(count);
    
    flashLED(count);        // Blink the LED 'count' times (5 times, then 4, etc.)
    
    delay(1000);            // Wait 1 second between countdown steps
    count = count - 1;      // Decrement the counter
  }
  
  Serial.println("=== Countdown Complete ===");
}

void loop() { 
  // Left empty because the countdown only needs to run once at startup
}
