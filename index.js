// 'use strict';

// const {
//   EtherPortClient
// } = require('etherport-client');
// const five = require('johnny-five');
// const board = new five.Board({
//   port: new EtherPortClient({
//     host: '10.0.0.49',
//     port: 3030
//   }),
//   repl: false
// });

// const LED_PIN = 2;

// board.on('ready', () => {
//   board.pinMode(LED_PIN, five.Pin.OUTPUT);
//   // the Led class was acting hinky, so just using Pin here
//   const pin = five.Pin(LED_PIN);
//   let value = 0;
//   setInterval(() => {
//     if (value) {
//       pin.high();
//       value = 0;
//     } else {
//       pin.low();
//       value = 1;
//     }
//   }, 500);
// });

//// code 2

// var fs = require('fs')
// var replace = require("replace");
// fs.readFile("./file.cpp", 'utf8', function (err,data) {
//   if (err) {
//     return console.log(err);
//   }

//   console.log(data.search("TP-Link_E1FA"));
//   var username = data.replace(/wifi_address/g, 'TP-Link_E1FA');

//   fs.writeFile("./file.cpp", username, 'utf8', function (err) {
//      if (err) return console.log(err);
//   });





// });

// fs.close(1);


// fs.readFile("./file.cpp", 'utf8', function (err,data1) {
//   if (err) {
//     return console.log(err);
//   }
//   // var username = data.replace(/wifi_address/g, 'TP-Link_E1FA');
//   var password = data1.replace(/wifi_password/g, 'a123g2madhu');
 



//   fs.writeFile("./file.cpp", password, 'utf8', function (err) {
//     if (err) return console.log(err);
//  });

// });


/// code 3



// var replace = require("replace");
// const { exec } = require('node:child_process');
// var spawn = require('child_process');

// replace({
//   regex: "Default_SSID",
//   replacement: "TP-Link_E1FA",
//   paths: ['./src/main.cpp'],
//   recursive: true,
//   silent: true,
// });

// replace({
//   regex: "Default_Password",
//   replacement: "a123g2madhu",
//   paths: ['./src/main.cpp'],
//   recursive: true,
//   silent: true,
// });


// exec('pio run -e esp12e -t upload', (err, output) => {
//   // once the command has completed, the callback function is called
  
  
//   setTimeout(function(){

//     console.log("Press and Hold pins");

//   }, 5000)
//   if (err) {
//       // log and return if we encounter an error
//       // console.error("could not execute command: ", err.code);
// if(err.code==1){

//   console.log("XXXXXXXXX Please Connect Board XXXXXXXXX");

//   console.log(err);

// }

//       return
//   }
//   // log the output received from the command
//   console.log("Output: \n", output)





// });





// exec('pio run -e esp12e -t upload', (error, stdout, stderr) => {
//   if (error) {
//     console.error(`exec error: ${error}`);
//     return;
//   }
//   console.log(`stdout: ${stdout}`);
//   console.error(`stderr: ${stderr}`);
// });






//// code 4 

const { exec } = require('node:child_process');
var spawn = require('child_process');
const fs = require('fs');

const buttonPressesLogFile = './src/main.cpp';

console.log(`Watching for file changes on ${buttonPressesLogFile}`);

fs.watchFile(buttonPressesLogFile, (curr, prev) => {

// console.log(fs.readFileSync(buttonPressesLogFile).toString())


exec('git commit -am "make it better" && git push -u origin main', (error, stdout, stderr) => {
  if (error) {
    console.error(`exec error: ${error}`);
    return;
  }
  // console.log("update");
  // console.error(`stderr: ${stderr}`);
});
});
//pink
// ss