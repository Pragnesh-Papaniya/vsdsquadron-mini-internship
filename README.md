# Smart Home On CH32V003 Based RISC-V Board
## Overview
This project presents Smart Home solution by CH32V003 Based emerging RISC-V Board called VSDSquadron Mini. The board uses RV32EC ISA. It operates on 24 MHz and has 16KB Flash, 2KB SRAM, 15 GPIOs, 10-bit ADC and I2C, USART and SPI. The proposed system has sensors like IR, PIR, Gas and Soil Moisture whereas actuators like Relay, Buzzer and 16*2 I2C LCD. IR sensor will detect flame whereas PIR sensor will detect intruder and both will sound buzzer. Gas sensor will sense particular gas and soil moisture sensor with relay connected to mini DC motor will water plant automatically. LCD will print sensor data.

## Components
1. VSDSquadron Mini
2. IR sensor
3. PIR sensor
4. Soil Moisture sensor
5. Gas sensor
6. 16*2 LCD
7. Relay
8. DC motor
9. Buzzer
10. Breadboard
11. Jumper wires

Most of these sensors work at 5v whereas VSDSquadron Mini works at 1.8V to 3.6V.

## Pinout Diagram
![block_diagram](https://github.com/Pragnesh-Papaniya/vsdsquadron-mini-internship/assets/143833682/ac790370-6152-4979-8376-ca6498d97d08)

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
