/*
 * Week 3: Debugging and Performance Optimization
 * Timer Interrupt Based LED Controller - Buggy Version
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

volatile bool LED_STATE = false;
volatile uint32_t timer_ticks = 0;
volatile bool timer_interrupt = false;

#define TIMER_PERIOD_TICKS 1000U

void LED_Toggle(void)
{
    LED_STATE = !LED_STATE;
    printf("LED changed: %s\n", LED_STATE ? "ON" : "OFF");
}

void Timer_ISR(void)
{
    timer_interrupt = false;
    LED_Toggle();
}

void Timer_Tick(void)
{
    timer_ticks++;

    /* Intentional debugging issue: equality can miss an event
       if the timer counter is advanced by more than one tick. */
    if (timer_ticks == TIMER_PERIOD_TICKS)
    {
        timer_ticks = 0;
        timer_interrupt = true;
    }

    if (timer_interrupt)
        Timer_ISR();
}

int main(void)
{
    uint32_t total_ticks = 5000U;

    for (uint32_t i = 0; i < total_ticks; i++)
        Timer_Tick();

    printf("Final LED state: %s\n", LED_STATE ? "ON" : "OFF");
    return 0;
}
