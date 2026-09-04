/*
 * Week 3: Debugging and Performance Optimization
 * Timer Interrupt Based LED Controller - Optimized Version
 *
 * Optimization:
 * - Removed interrupt flag because the simulated ISR can be called
 *   immediately when the period expires.
 * - LED output is logged only when the state changes.
 * - Used static functions and const configuration values.
 * - Kept the timer comparison safe with >=.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

static bool led_state = false;
static uint32_t timer_ticks = 0;

#define TIMER_PERIOD_TICKS 1000U
#define TOTAL_TICKS        5000U

static void LED_Toggle(void)
{
    led_state = !led_state;
    printf("ISR: LED = %s\n", led_state ? "ON" : "OFF");
}

static void Timer_ISR(void)
{
    LED_Toggle();
}

static void Timer_Tick(void)
{
    if (++timer_ticks >= TIMER_PERIOD_TICKS)
    {
        timer_ticks = 0;
        Timer_ISR();
    }
}

int main(void)
{
    for (uint32_t i = 0; i < TOTAL_TICKS; ++i)
        Timer_Tick();

    printf("Simulation completed: %u ticks, 5 interrupt events.\n",
           TOTAL_TICKS);
    printf("Final LED state: %s\n", led_state ? "ON" : "OFF");
    return 0;
}
