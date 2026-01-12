# Working Explanation – Automatic Toll Gate System

The Automatic Toll Gate System operates by detecting vehicles using an IR sensor placed near the toll gate.

## Step-by-Step Operation:
1. The IR sensor continuously monitors for obstacles.
2. When a vehicle comes in front of the sensor, it sends a signal to the Arduino.
3. The Arduino processes this signal and displays "Vehicle Detected" on the LCD.
4. The servo motor rotates to open the toll gate.
5. After a fixed delay, the gate closes automatically.
6. The system resets and waits for the next vehicle.

## Optional Enhancements:
- RFID-based vehicle identification
- Cloud-based toll payment
- Camera-based number plate recognition
