YuvaIntern – Week 3 Task

Debugging and Performance Optimization

Project

Timer Interrupt Based LED Controller

This week extends the Week 2 Embedded C simulation by introducing a common timer-event bug, tracing the fault, applying a correction, and simplifying the firmware for better execution efficiency.

Files

timer_led_controller_buggy.c – version containing the simulated timer comparison issue.

timer_led_controller_debugged.c – corrected version.

timer_led_controller_optimized.c – optimized implementation.

Week_3_Debugging_Performance_Optimization_Report.docx – detailed report.

Debugging

The timer event condition was reviewed and changed from an equality check to >=. This is safer for timer logic because an event is not lost when the counter moves beyond the configured period.

Optimization

The optimized version removes the separate interrupt flag in this hardware-independent simulation because the interrupt service routine can be invoked immediately when the timer period expires. The timer update and comparison are also combined into a compact operation.

Validation

The simulation uses a 1000-tick timer period and runs for 5000 ticks. Therefore, five timer interrupt events are expected. Each interrupt toggles the LED, so the final state returns to OFF after five transitions from an initial OFF state.

Compilation

gcc timer_led_controller_buggy.c -o buggy
gcc timer_led_controller_debugged.c -o debugged
gcc timer_led_controller_optimized.c -o optimized

Run

Windows:

optimized.exe

Linux/macOS:

./optimized
