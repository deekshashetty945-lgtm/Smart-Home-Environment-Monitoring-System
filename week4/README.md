# Week 4 – System Integration and Final Testing

## Project Title

**Timer Interrupt Based LED Controller**

## Overview

This project implements a timer interrupt-based LED controller using Embedded C. The system integrates timer tick generation, interrupt/event detection, an interrupt service routine (ISR), and LED control into a complete embedded firmware simulation.

Week 4 focuses on system integration, final testing, debugging, and validation of the complete firmware flow.

## Objective

* Integrate all firmware modules into one working system.
* Implement timer-based interrupt generation.
* Control LED state through the timer ISR.
* Perform system-level testing and validation.
* Identify and resolve integration challenges.
* Verify the final system behavior using automated test cases.

## System Configuration

* Timer Period: 1000 ticks
* Simulation Duration: 5000 ticks
* Initial LED State: OFF
* Expected Interrupts: 5
* Expected LED Toggles: 5
* Expected Final LED State: ON

## Integrated Modules

1. System Initialization
2. Timer Tick Generator
3. Timer Interrupt/Event Detection
4. Timer Interrupt Service Routine (ISR)
5. LED Control
6. Automated Testing and Validation

## Testing

The integrated system was tested using multiple test cases covering timer period accuracy, interrupt generation, LED state changes, and final system behavior.

### Final Result

**Integration Testing: PASS**

The system successfully generated five timer interrupts during the 5000-tick simulation and produced the expected LED state transitions:

**OFF → ON → OFF → ON → OFF → ON**

## Tools Used

* Embedded C
* GCC Compiler
* GitHub
* Command-line execution environment

## Files in This Folder

* `README.md` – Project and Week 4 documentation
* `Week_4_System_Integration_Final_Testing_Report.docx` – Detailed integration and testing report
* `timer_led_system_integration.c` – Complete Embedded C source code

## Conclusion

The Week 4 implementation successfully integrates the timer, interrupt, ISR, and LED control modules. Automated testing confirms that the integrated firmware behaves according to the defined system requirements.
