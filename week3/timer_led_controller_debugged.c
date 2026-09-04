/*
 * Week 3: Debugging and Performance Optimization
 * Timer Interrupt Based LED Controller - Debugged Version
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

volatile bool LED_STATE = false;
volatile uint32_t timer_ticks = 0;
volatile bool timer_interrupt = false;

#define TIMER_PERIOD_TICKS 1000U

static void LED_Set(bool state)
{
    LED_STATE = state;
    printf("LED = %s\n", LED_STATE ? "ON" : "OFF");
}

static void LED_Toggle(void)
{
    LED_Set(!LED_STATE);
}

static void Timer_ISR(void)
{
    timer_interrupt = false;
    LED_Toggle();
}

static void Timer_Tick(void)
{
    timer_ticks++;

    /* Fixed: >= prevents the event from being missed. */
    if (timer_ticks >= TIMER_PERIOD_TICKS)
    {
        timer_ticks = 0;
        timer_interrupt = true;
    }

    if (timer_interrupt)
        Timer_ISR();
}

int main(void)
{
    const uint32_t total_ticks = 5000U;

    for (uint32_t i = 0; i < total_ticks; i++)
        Timer_Tick();

    printf("Simulation completed.\n");
    printf("Final LED state: %s\n", LED_STATE ? "ON" : "OFF");
    return 0;
}
