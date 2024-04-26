# Smart Home On CH32V003 Based RISC-V Board
## Overview
This project presents Smart Home solution by CH32V003 Based emerging RISC-V Board called VSDSquadron Mini. The board uses RV32EC ISA. It operates on 24 MHz and has 16KB Flash, 2KB SRAM, 15 GPIOs, 10-bit ADC and I2C, USART and SPI. The proposed system has sensors like IR, PIR, Gas and Soil Moisture whereas actuators like Relay, Buzzer and 16*2 I2C LCD. IR sensor will detect flame whereas PIR sensor will detect intruder and both will sound buzzer. Gas sensor will sense particular gas and soil moisture sensor with relay connected to mini DC motor will water plant automatically. LCD will print sensor data.

## Components
VSDSquadron Mini
IR sensor
PIR sensor
Soil Moisture sensor
Gas sensor
16*2 LCD
Relay
DC motor
Buzzer
Breadboard
Jumper wires

Most of these sensors work at 5v whereas VSDSquadron Mini works at 1.8V to 3.6V.

## Pinout Diagram
![block_diagram](https://github.com/Pragnesh-Papaniya/vsdsquadron-mini-internship/assets/143833682/bf1c0e21-d0af-4808-9fc6-cfd6227b00ed)
)

## Table for Pin connection
| Sensor        | Board Pin     |
| ------------- | ------------- |
| IR            | PD0           |
| PIR           | PD1           |
| Soil          | PD2           |
| Gas           | PD3           |
| Buzzer        | PD4           |
| Relay         | PD5           |
| LCD-SDA       | PC1           |
| LCD-SCL       | PC2           |
