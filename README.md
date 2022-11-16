# Harsh Weather Monitoring Using Arduino MKR 1300 With Hammond

![alt text](https://hackster.imgix.net/uploads/attachments/1518040/_YpEV1ELHnE.blob?auto=compress%2Cformat&w=900&h=675&fit=min)

In this project, I have made a Weather Sensing device that is based on Arduino and is loaded with sensors that are capable in sensing several different parameters of the nearby environment. This device is designed in such a manner that it can also withstand harsh weather quite easily and can wirelessly transmit the data recorded to the receiving section. This project has two sections, the Transmitter section, and the Receiver section for Harsh Weather Monitoring Using Arduino MKR 1300 and Blynk.
I have used Blynk App in order to visualize and record the data sent by the Transmitter section and received by the receiver section.

![alt text](https://hackster.imgix.net/uploads/attachments/1518042/image_3YSYibN1yG.png?auto=compress%2Cformat&w=740&h=555&fit=max)

The Transmitter section contains The Temperature, Humidity sensor, Light sensor, Mems Microphone, and Mems Accelerometer sensor. These sensors are interfaced with the Arduino MKR 1300 Board along with The external antenna. A lithium battery is used to power all the sensors and Microcontroller, this battery is able to standby for up to 7 days in this project. To protect the circuit from the harsh weather I have used Hammond Enclosure Case 1554UGY Water Tight ABS 200x120x90 Enclosure. The sensor details are collected and transmitted Over LoRa Using Arduino MKR 1300.

![alt text](https://hackster.imgix.net/uploads/attachments/1518044/image_unnPvaDv3l.png?auto=compress%2Cformat&w=740&h=555&fit=max)

The receiver part contains the Arduino MKR 1300 And Wi-Fi Module To receive the LoRa Data and Transmit the data again to the cloud Using the Internet, I call It has Gateway. The LoRa Data is received And The Sensor details are collected Using the Arduino MKR 1300, if there is any severe variation in the environment data and its crosses the threshold values, The details are displayed on the app parallel shown on the LCD display. If the temperature of the surrounding environment is high, The Buzzer will be ON in the receiver section and The LCD Turns RED, To notify the user, and Pop-up Notification displayed on the mobile. 

![alt text](https://hackster.imgix.net/uploads/attachments/1518046/image_m9QcmXNYPJ.png?auto=compress%2Cformat&w=740&h=555&fit=max)

When the box is opened or it broke the light intensity data of the sensor is high, then it will be finalized as the Box Opened and the Pop-Up Notification is displayed on the mobile.
During The operation when the transmitter is moved or if any high wind is detected a "Movement Detected" notification is displayed on the Mobile and in the receiver part Buzzer is activated with a different tone. This tone is different from The High-Temperature Alert.

![alt text](https://hackster.imgix.net/uploads/attachments/1518136/8_tJuwoRM3dI.JPG?auto=compress%2Cformat&w=740&h=555&fit=max)

You must check out [PCBWAY](https://www.pcbway.com/) for ordering PCBs online for cheap!

You get 10 good-quality PCBs manufactured and shipped to your doorstep for cheap. You will also get a discount on shipping on your first order. Upload your Gerber files onto PCBWAY to get them manufactured with good quality and quick turnaround time. [PCBWay](https://www.pcbway.com/) now could provide a complete product solution, from design to enclosure production. Check out their online Gerber viewer function. With reward points, you can get free stuff from their gift shop.
