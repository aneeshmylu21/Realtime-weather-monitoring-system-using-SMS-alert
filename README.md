# Realtime-weather-monitoring-system-using-SMS-alert
Overview

A real-time embedded weather monitoring system developed using the ARM7 LPC2129 microcontroller. The system continuously monitors environmental temperature, displays real-time data on an LCD, and sends SMS alerts using a GSM module when abnormal temperature conditions are detected.

The project integrates multiple peripherals such as RTC, ADC, LCD, GSM, and sensors using I2C, SPI, and UART communication protocols.

Problem Statement

Environmental conditions such as extreme temperature variations can affect industrial systems, agriculture, and sensitive equipment.

Manual monitoring is inefficient and may lead to delayed response during critical conditions. A real-time automated monitoring system is required for continuous tracking and instant alert generation.

Solution

This project provides an embedded solution that continuously measures temperature and displays real-time values on an LCD.

When temperature exceeds safe limits, the system automatically:

Sends SMS alerts via GSM module
Activates cooling system (motor/fan)
Triggers buzzer for warning conditions

This ensures immediate response to environmental changes without human intervention.

Features

Real-time temperature monitoring
Real-time clock display using RTC
GSM-based SMS alert system
LCD display interface
High temperature alert system
Low temperature warning system
Motor/Fan automatic control
Buzzer alarm system
I2C, SPI, UART communication support
Continuous monitoring system

Hardware Components

LPC2129 ARM7 Microcontroller
DS1307 RTC Module
Temperature Sensor (LM35 or equivalent)
SPI ADC (MCP3208)
GSM Module (SIM900)
16x2 LCD Display
DC Motor / Fan
Buzzer
Power Supply Unit

Software Tools

Embedded C
Keil µVision IDE
Flash Magic

Implementation

Temperature sensor reads environmental data through ADC.
LPC2129 processes data and converts it into temperature values.
RTC module provides real-time clock data using I2C communication.
LCD displays temperature and time continuously.
GSM module sends SMS alerts when temperature exceeds limits.
Motor/Fan activates during high temperature conditions (value>15).
Buzzer activates during low temperature conditions (value<10).
System continuously monitors and updates values in real time.

Concepts Used

Embedded C Programming
ARM7 Microcontroller (LPC2129)
I2C Communication (RTC Interface)
SPI Communication (ADC Interface)
UART Communication (GSM Module)
LCD Interfacing
Sensor Data Acquisition
Real-Time Embedded System Design
Automation and Control Systems

Applications

Weather Monitoring Stations
Smart Agriculture Systems
Greenhouse Monitoring
Industrial Temperature Monitoring
Cold Storage Monitoring
Server Room Safety Systems
Environmental Monitoring Systems
Remote Alert Systems

Author

Aneesh Mylu 
Electronics and Communication Engineering
