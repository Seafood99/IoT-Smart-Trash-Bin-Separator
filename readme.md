# IoT Smart Trash Bin Separator
This project is an IoT-based smart trash bin that automatically separates metal (non-organic) and non-metal (organic) waste. The system uses an ultrasonic sensor to detect the presence of an object, a capacitive proximity sensor to determine whether the object is metal or non-metal, and a servo motor to direct the object into the appropriate bin. An I2C LCD display shows whether the object is organic or inorganic.

# Components Used
- Arduino Uno
- Servo Motor
- HC-SR04 Ultrasonic Sensor (distance measurement)
- Capacitive Proximity Sensor (metal detection)
- LM016 I2C LCD Display (16x2)
- Breadboard and Jumper Wires

# Wiring Setup
 - Ultrasonic Sensor
    - Trig to Pin 2
    - Echo to Pin 3
    - VCC to 5V
    - GND to GND 
- Servo Motor
    - Signal to Pin 9
    - VCC to 5V
    - GND to GND

- Capacitive Proximity Sensor
    - Signal to Pin 10
    - VCC to 5V
    - GND to GND

- LM016 I2C LCD Display
    - SDA to SDA (A4 on Arduino Uno)
    - SCL to SCL (A5 on Arduino Uno)
    - VCC to 5V
    - GND to GND

# Code Explanation
The code controls the behavior of the smart trash bin based on sensor readings:

- Distance Measurement: The HC-SR04 sensor measures the distance of the object. If the object is within 5 cm, the system proceeds to identify its material.

- Material Detection: The capacitive proximity sensor detects whether the object is metallic or non-metallic. If metallic, the servo motor turns to 0° to direct the object to the inorganic bin. If non-metallic, the servo turns to 180° to direct it to the organic bin.

- Display Output: The LCD displays the type of waste (organic or inorganic) and the direction of the separator. This information is also printed to the Serial Monitor for debugging purposes.

# How to Use
- Upload the code to your Arduino Uno using the Arduino IDE.
- Connect all components according to the wiring setup mentioned above.
- Open the Serial Monitor in the Arduino IDE to observe real-time feedback and debugging information.
- Test the system with different objects to verify that the separation mechanism works correctly.

# Troubleshooting
- Ensure that all connections are secure and correctly placed.
- Verify that the I2C address of your LCD is 0x27. If not, you may need to adjust the address in the code.
- If the servo does not move, check the power supply and signal pin connection.

# Acknowledgments
- Thanks to the open-source community for the libraries and examples that helped shape this project.
https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/
https://www.arduino.cc/reference/en/libraries/capacitivesensor/