# Smart Tank Monitoring System with IoT

Welcome to the Smart Tank Monitoring System repository! This project utilizes an ESP8266 microcontroller to monitor water levels in a tank and sends data to ThingSpeak, an IoT platform, for real-time tracking. The following information will guide you through the project details and code.

## Code Overview

- **File:** `SmartTank.ino`

  This Arduino sketch monitors water levels using an ultrasonic sensor, controls LEDs based on the water level, and sends the data to ThingSpeak for remote monitoring.

## Hardware Components

1. **ESP8266 Microcontroller**
2. **Ultrasonic Sensor (HC-SR04)**
3. **LEDs (Red and Green)**
4. **Resistors**
5. **Jumpers and Breadboard**

## Configuration

- **WiFi Connection:**
  - Replace `ssid` and `pass` with your WiFi network credentials.

- **ThingSpeak:**
  - Replace `ch_no` with your ThingSpeak channel number.
  - Replace `write_api` with your ThingSpeak write API key.

## Pin Configuration

- **Ultrasonic Sensor:**
  - `trigPin1` - Trigger pin connected to D1.
  - `echoPin1` - Echo pin connected to D2.

- **LEDs:**
  - `redled` - Red LED connected to D3.
  - `grnled` - Green LED connected to D4.

## Usage

1. **Setup:**
   - Connect the hardware components based on the provided pin configuration.
   - Upload the code to your ESP8266 using the Arduino IDE.

2. **Monitor:**
   - Power up the system.
   - The ultrasonic sensor measures water level.
   - LEDs indicate the water status (red for low, green for normal).

3. **ThingSpeak Integration:**
   - Data is sent to ThingSpeak every 10 seconds.
   - Monitor the tank's water level remotely using the ThingSpeak channel.

## Additional Information

- The system checks water levels and sends updates to ThingSpeak periodically.
- Adjust the threshold (`if (distance1 <= 5)`) based on your tank configuration.
- LEDs provide a quick visual indication of water status.

## Contributions

Feel free to contribute to the project by improving the code, enhancing functionality, or adding features. Create a pull request with your changes.

If you encounter issues or have questions, please open an issue on GitHub.

Happy tank monitoring! 🚰📊
