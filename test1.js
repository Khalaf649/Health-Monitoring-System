const SerialPort = require('serialport');
const parsers = SerialPort.parsers;
const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const path = require('path');
const parser = new parsers.Readline({ delimiter: '\r\n' });
const port = new SerialPort('COM4', {
    baudRate: 115200,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false
});
app.use(express.static(path.join(__dirname,'public')));

port.pipe(parser);

// Socket.IO setup
const server = require('http').createServer(app);
const io = require('socket.io')(server);

// Event listener for incoming data
// parser.on('data', function (data) {
//   //  console.log('Received data:', data); // Add this line to log the received data

//     // Split the data by tab character '\t' to separate posture and heart rate
//     const dataArray = data.split('\t');
//     const heartRateData = dataArray[0]; // Data for posture
//     const postureData = dataArray[1]; // Data for heart rate
//  //   console.log(heartRateData+" "+postureData);
//      let posturestate=postureData.split(':');
//      let heartRatedata=heartRateData.split(':');
//     //  console.log(posturestate[1]);
//     //  console.log(heartRatedata[1]);

//     // // Emit posture and heart rate data to clients
//      io.emit('posture', posturestate[1]); 
//       io.emit('heartRate', heartRatedata[1]);
// });



// Listen for connection event


// Route handler for serving the HTML file
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'views', 'index.html'));
});

// Error handling for serial port
port.on('error', function (err) {
    console.error('Error: ', err.message);
});

// Start the server
const PORT = 8080;
server.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
