# LED-to-smartphone-VLC-system

Visible light communication is a state-of-the-art technology to address the spectrum congestion and be insusceptible to interference. 

Nowadays, a lot of connected products are embedded with LED to facilitate the development of VLC. Previous works already have revealed the feasibility of smartphone to receive information from visible light source. 

In this project, a LED-to-Smartphone VLC system are designed and implemented to transmit text information. The system proposed used LED configured in Arduino as transmitter and a smartphone camera as a receiver. Text information are encoded and sent out via visible light in transmitter. 
Exploiting smartphone camera to extract the text information from visible light signal was the technique to implement the receiver. 
The design of the VLC system was proved to be feasible. The result achieved a throughput of 10 bit/s and communication distance of 20 cm without data loss. The design was found to facilitate the user to utilize smartphone to receive light signal as a replacement of photoreceiver which promote the communication between LED-embedded products and smartphone.

# System Overview

The VLC system is designed for text transmission in which LED and Smartphone camera were exploited to be light source and sensor to implement camera-based VLC link. 
This combination of light source and sensor constructing VLC link is likely to offer the most convenient VLC link in real world because it is adaptive and fit in existing infrastructure The communication channel was configured in Direct LOS in the VLC system such that the receiver is directly facing the transmitter. 
The Direct LOS configuration ensures there is enough light intensity received by the smartphone camera to create stable communication for indoor use even though there is limited mobility of transmitter and receiver.

![image](https://user-images.githubusercontent.com/48129546/94846764-3fdacd00-0454-11eb-8ce3-ae4df6417302.png)

# Transmitter

The transmitter incorporates a microcontroller mounted on Arduino DUE and LED driver circuit with a low power 3mm diameter white LED, PN2222 transistor and other electronic components.

![image](https://user-images.githubusercontent.com/48129546/94847156-cabbc780-0454-11eb-901c-a90f6570cfc6.png)

# Receiver

The VLC receiver application is able to utilize the smartphone camera to capture consecutive frames to extract the transmitted data in light signal in each frame by using OpenCV Library.

An app created with OpenCV to analyse data emitted from a LED light bulb. This app can use the devices camera to convert the data from the LED light bulb into text.

![image](https://user-images.githubusercontent.com/48129546/94847412-21c19c80-0455-11eb-9d70-31c4d219b888.png)
![image](https://user-images.githubusercontent.com/48129546/94851147-9ea34500-045a-11eb-98b2-f42e07434ea7.png)
