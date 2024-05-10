# Health Monitoring System

This project is a health monitoring system that measures heart rate and oxygen percentage. It also checks if the position you are setting is correct. The system utilizes an Arduino Uno and an ultrasonic sensor for position detection. For measuring heart rate and oxygen percentage, it employs the MAX30102 Pulse Oximeter sensor.

## Overview

The system integrates Arduino with Node.js using Express to pass data from the serial port of the Arduino to the terminal of Express. The frontend is developed using HTML and CSS, making it a real-time application using WebSocket for communication.

## Requirements

- Arduino Uno
- Ultrasonic sensor
- MAX30102 Pulse Oximeter sensor
- Node.js
- Express.js
- HTML
- CSS
- WebSocket

## Installation

1. Clone the repository:
   ```
   git clone <repository_url>
   ```
2. Connect the Arduino Uno and sensors as per the wiring diagram provided.
3. Install Node.js if not already installed on your system.
4. Install dependencies:
   ```
   npm install
   ```

## Usage

1. Upload the Arduino sketch provided (`arduino_code.ino`) to the Arduino Uno.
2. Start the Node.js server:
   ```
   npm start
   ```
3. Open the web browser and navigate to `http://localhost:3000` to access the frontend.

## Wiring Diagram

[//]: # (Add a wiring diagram here if available)

## Team

- **Project Lead:** Suhila tharwat
- **Developer:** Abdlrhman Reda khalaf
- **Developer:** mai mahmoud
- - **Developer:** zeyad ashraf
  - - - **Developer:** Momen Mohamed

## Acknowledgements

This project was developed as part of the subject "Medical Physics" under the supervision of Dr. Sherif Elgohry in the first Biomedical Engineering program.

## License

[License Name, e.g., MIT License]
