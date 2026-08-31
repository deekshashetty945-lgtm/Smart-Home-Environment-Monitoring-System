/*
 * Week 2: Firmware Development and Implementation
 * Project: Timer Interrupt Based LED Controller
 *
 * Description:
 * This is a portable Embedded-C simulation of a timer-interrupt-driven
 * LED controller. A simulated timer generates a periodic interrupt.
 * The interrupt service routine toggles the LED state.
 *
 * Note:
 * The hardware registers are simulated with variables so that the
 * firmware logic can be compiled and tested on a normal computer.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

/* -------------------- Simulated Hardware -------------------- */

volatile bool LED_STATE = false;       // Simulated GPIO output
volatile uint32_t timer_ticks = 0;     // Simulated timer tick counter
volatile bool timer_interrupt = false; // Simulated interrupt flag

#define TIMER_PERIOD_TICKS 1000U

/* -------------------- Function Prototypes -------------------- */

void GPIO_Init(void);
void Timer_Init(void);
void LED_Set(bool state);
void LED_Toggle(void);
void Timer_ISR(void);
void Timer_Tick(void);
void System_Init(void);

/* -------------------- GPIO Functions -------------------- */

void GPIO_Init(void)
{
    LED_STATE = false;
    printf("GPIO initialized: LED = OFF\n");
}

void LED_Set(bool state)
{
    LED_STATE = state;
    printf("LED = %s\n", LED_STATE ? "ON" : "OFF");
}

void LED_Toggle(void)
{
    LED_Set(!LED_STATE);
}

/* -------------------- Timer Functions -------------------- */

void Timer_Init(void)
{
    timer_ticks = 0;
    timer_interrupt = false;
    printf("Timer initialized: period = %u ticks\n", TIMER_PERIOD_TICKS);
}

/*
 * Timer interrupt service routine.
 * In a real microcontroller, this function would be called by
 * the processor when the hardware timer reaches its configured period.
 */
void Timer_ISR(void)
{
    timer_interrupt = false;
    LED_Toggle();
}

/*
 * Simulate one timer tick.
 */
void Timer_Tick(void)
{
    timer_ticks++;

    if (timer_ticks >= TIMER_PERIOD_TICKS)
    {
        timer_ticks = 0;
        timer_interrupt = true;
    }

    /* Process the simulated interrupt immediately. */
    if (timer_interrupt)
    {
        Timer_ISR();
    }
}

/* -------------------- System Initialization -------------------- */

void System_Init(void)
{
    GPIO_Init();
    Timer_Init();
}

/* -------------------- Main Application -------------------- */

int main(void)
{
    uint32_t total_ticks = 5000U;

    printf("========================================\n");
    printf(" Timer Interrupt Based LED Controller\n");
    printf("========================================\n");

    System_Init();

    /*
     * Main loop simulation.
     * Each iteration represents one timer tick.
     */
    for (uint32_t i = 0; i < total_ticks; i++)
    {
        Timer_Tick();
    }

    printf("Simulation completed.\n");
    printf("Final LED state: %s\n", LED_STATE ? "ON" : "OFF");

    return 0;
}

