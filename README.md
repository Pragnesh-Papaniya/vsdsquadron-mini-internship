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

##Video Demonstration
https://drive.google.com/drive/u/1/folders/1_U6dP5Mxgn7eanhBTM3j54Smm3Wepmg-

##Fault Injection
Fault injection is a technique used to evaluate the resilience and security of microcontroller-based systems by deliberately introducing faults or errors into the system during operation. This approach helps in identifying vulnerabilities and weaknesses that malicious attackers might exploit. Here's an overview of fault injection in the context of microcontrollers:

### Purpose of Fault Injection:
1. **Security Testing**: Fault injection is primarily used for security testing to assess how a microcontroller-based system behaves under abnormal or manipulated conditions.
  
2. **Reliability Testing**: It's also used for reliability testing to understand how the system handles faults, which can occur due to environmental conditions, aging, or deliberate attacks.

### Types of Fault Injection:
1. **Electrical Faults**: Injecting faults by manipulating power supply voltages (e.g., voltage spikes, brownouts) or injecting electromagnetic interference. In this board, voltage regulator and pairs of decoupling capacitors ensure that it gets enough supply voltage. Power ON/Down Reset from software ensure that when supply is back on or cut off, the code execution starts from first instruction and not skipping anything.

2. **Clock and Timing Faults**: Manipulating clock signals to disrupt the timing of operations within the microcontroller. By an external frequency generator or tampering internal osciallator, a faulty clock can be given to core and peripherals.

3. **Memory Faults**: Introducing faults in memory operations by altering data during read/write operations.

4. **Environmental Faults**: Exposing the microcontroller to extreme temperatures, humidity, or radiation to assess its robustness. Ther is a relevant veritasium video on this topic: https://youtu.be/AaZ_RSt0KP8?feature=shared

5. **Software Faults**: Modifying firmware or injecting unexpected inputs to cause buffer overflows, stack corruptions, or unexpected program behavior. If the system is running RTOS then there can be some nasty faults like deadlock, starvation, livelock etc. Another bug of RTOS called priority inversion almost put an end to NASA's MARS mission: https://www.rapitasystems.com/blog/what-really-happened-software-mars-pathfinder-spacecraft. In this system, a higher priority task can be inserted which could starve other tasks if there is no watchdog timer safeguard. 

### Techniques for Fault Injection:
1. **Power/Glitch Attacks**: Manipulating the power supply to induce faults. This can involve varying voltage levels, sudden drops or spikes, or clock glitches.

2. **EMI/EMC Testing**: Exposing the microcontroller to electromagnetic interference (EMI) to evaluate its susceptibility to such disturbances.

3. **Clock Manipulation**: Introducing clock jitter, frequency changes, or stopping the clock momentarily to disrupt timing-dependent operations.

4. **Hardware Trojan Injection**: Modifying the microcontroller's hardware by inserting trojans or altering circuit elements to induce specific faults. Intense light sources such as LASER can cause faults in the system's normal work flow.

5. **Side-Channel Attacks**: Leveraging unintentional emanations (e.g., power consumption, electromagnetic radiation) from the microcontroller during specific operations to gain insights or inject faults.

6. **System Reset**: System reset can be connected such that it continuously resets the microcontroller. Similarly in software, tampering of watchdog timer can also lead to continuous resets.
   
### Tools for Fault Injection:
1. **Power Supply Modulation Equipment**: Devices that can vary voltage levels, inject noise, or induce power glitches.

2. **Electromagnetic Generators**: Instruments capable of emitting controlled electromagnetic interference.

3. **Specialized Software Tools**: Tools that automate fault injection through firmware modifications or controlled inputs.

### Mitigation Strategies:
To counteract fault injection attacks, microcontroller designers can employ various strategies:
- Implementing error detection and correction mechanisms (e.g., ECC for memory).
- Hardening against power/glitch attacks through power supply filtering or regulation.
- Adding redundancy in critical circuits to tolerate faults.
- Utilizing secure boot mechanisms and cryptographic protections to prevent unauthorized firmware modifications.
