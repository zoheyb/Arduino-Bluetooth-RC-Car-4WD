// -----------------------------
// Bluetooth RC Car (HC-05/06)
// -----------------------------

// Motor Pins (Same as before)
#define motorA1 5 // Left Motor IN1
#define motorA2 6 // Left Motor IN2
#define motorB1 9 // Right Motor IN1
#define motorB2 10 // Right Motor IN2

#define ENA 3  // PWM Left
#define ENB 11 // PWM Right

// Speed (0-255)
// Bluetooth often needs full power to start moving
int speedCar = 255; 
char command; // Variable to store incoming data

void setup() {
  // Start Serial Communication for Bluetooth
  Serial.begin(9600); 

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Initialize motors stopped
  stopCar();
}

void loop() {
  // Check if data is available from Bluetooth
  if (Serial.available() > 0) {
    command = Serial.read(); // Read the character
    
    // Execute command
    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
      case 'S': stopCar(); break;
      
      // Optional: Speed control logic (0-9)
      case '0': speedCar = 100; break;
      case '1': speedCar = 120; break;
      case '2': speedCar = 140; break;
      case '3': speedCar = 160; break;
      case '4': speedCar = 180; break;
      case '5': speedCar = 200; break;
      case '6': speedCar = 220; break;
      case '7': speedCar = 235; break;
      case '8': speedCar = 245; break;
      case '9': speedCar = 255; break;
    }
  }
}

// --- Movement Functions ---

void forward() {
  analogWrite(ENA, speedCar);
  analogWrite(ENB, speedCar);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void backward() {
  analogWrite(ENA, speedCar);
  analogWrite(ENB, speedCar);
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnLeft() {
  analogWrite(ENA, speedCar);
  analogWrite(ENB, speedCar);
  // Left wheels backward, Right wheels forward (Spin turn)
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void turnRight() {
  analogWrite(ENA, speedCar);
  analogWrite(ENB, speedCar);
  // Left wheels forward, Right wheels backward (Spin turn)
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void stopCar() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
