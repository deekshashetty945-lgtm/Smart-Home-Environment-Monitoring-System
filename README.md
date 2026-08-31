# YuvaIntern – Week 2 Task

## Firmware Development and Implementation

### Project: Timer Interrupt Based LED Controller

This project demonstrates a simple embedded firmware application developed using Embedded C.

The firmware simulates a timer interrupt based LED controller. A simulated timer generates a periodic interrupt, and the interrupt service routine toggles the LED state.

## Objectives

- Understand firmware development using Embedded C
- Understand timer-based interrupts
- Implement an interrupt service routine
- Simulate GPIO/LED control
- Practice firmware testing and debugging
- Document the implementation clearly

## Files

- `timer_led_controller.c` – Main Embedded C firmware source code
- `README.md` – Project documentation
- `Week_2_Firmware_Development_Report.docx` – Detailed project report

## Firmware Operation

The simulated timer counts ticks. When the counter reaches 1000 ticks, a timer interrupt is generated. The interrupt service routine toggles the LED state. The simulation runs for 5000 ticks, allowing the interrupt and LED behavior to be verified.

## Testing

The firmware was tested using a software simulation. The timer period was configured as 1000 ticks and the simulation was executed for 5000 ticks.

The LED changes state whenever the simulated timer interrupt occurs.

## Compilation

Using GCC:

```bash
gcc timer_led_controller.c -o timer_led_controller
```

## Run

Linux/macOS:

```bash
./timer_led_controller
```

Windows:

```text
timer_led_controller.exe
```

## Learning Outcomes

This task improved understanding of Embedded C, timer interrupts, interrupt service routines, GPIO control, firmware structure, testing, debugging, and documentation.

## Note

This is a hardware-independent simulation. For a real microcontroller, the simulated timer and GPIO functions can be replaced with device-specific timer registers, GPIO registers, and interrupt-vector configuration.
