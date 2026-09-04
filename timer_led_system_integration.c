/*
 * Week 4 - System Integration and Final Testing
 * Project: Timer Interrupt Based LED Controller
 *
 * Integrates timer tick generation, interrupt handling,
 * LED control, and system-level validation.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define TIMER_PERIOD_TICKS 1000U
#define SIMULATION_TICKS    5000U

static volatile uint32_t timer_ticks = 0U;
static volatile bool led_state = false;
static volatile uint32_t interrupt_count = 0U;

static void LED_Set(bool state)
{
    if (led_state != state)
    {
        led_state = state;
        printf("LED -> %s\n", led_state ? "ON" : "OFF");
    }
}

static void LED_Toggle(void)
{
    LED_Set(!led_state);
}

static void Timer_ISR(void)
{
    interrupt_count++;
    printf("ISR Event %lu: Timer threshold reached\n",
           (unsigned long)interrupt_count);
    LED_Toggle();
}

static void Timer_Tick(void)
{
    if (++timer_ticks >= TIMER_PERIOD_TICKS)
    {
        timer_ticks = 0U;
        Timer_ISR();
    }
}

static void System_Init(void)
{
    timer_ticks = 0U;
    led_state = false;
    interrupt_count = 0U;

    printf("System initialized\n");
    printf("Timer period: %u ticks\n", TIMER_PERIOD_TICKS);
    printf("Simulation length: %u ticks\n", SIMULATION_TICKS);
    printf("Initial LED state: OFF\n\n");
}

/* Test 1: one interrupt at one complete timer period. */
static bool Test_TimerPeriod(void)
{
    timer_ticks = 0U;
    interrupt_count = 0U;

    for (uint32_t i = 0U; i < TIMER_PERIOD_TICKS; i++)
    {
        Timer_Tick();
    }

    return (interrupt_count == 1U && timer_ticks == 0U);
}

/* Test 2: five interrupts during 5000 simulated ticks. */
static bool Test_FiveInterrupts(void)
{
    timer_ticks = 0U;
    interrupt_count = 0U;
    led_state = false;

    for (uint32_t i = 0U; i < SIMULATION_TICKS; i++)
    {
        Timer_Tick();
    }

    return (interrupt_count == 5U);
}

/* Test 3: five interrupts cause five LED toggles: OFF -> ON. */
static bool Test_LEDState(void)
{
    timer_ticks = 0U;
    interrupt_count = 0U;
    led_state = false;

    for (uint32_t i = 0U; i < SIMULATION_TICKS; i++)
    {
        Timer_Tick();
    }

    return (interrupt_count == 5U && led_state == true);
}

int main(void)
{
    System_Init();

    printf("=== Integrated System Run ===\n");

    for (uint32_t i = 0U; i < SIMULATION_TICKS; i++)
    {
        Timer_Tick();
    }

    printf("\n=== Final System State ===\n");
    printf("Interrupts generated: %lu\n",
           (unsigned long)interrupt_count);
    printf("Final LED state: %s\n", led_state ? "ON" : "OFF");

    printf("\n=== Final Test Results ===\n");

    bool test1 = Test_TimerPeriod();
    bool test2 = Test_FiveInterrupts();
    bool test3 = Test_LEDState();

    printf("Test 1 - Timer period: %s\n", test1 ? "PASS" : "FAIL");
    printf("Test 2 - Five interrupts: %s\n", test2 ? "PASS" : "FAIL");
    printf("Test 3 - LED toggle/state: %s\n", test3 ? "PASS" : "FAIL");

    if (test1 && test2 && test3)
    {
        printf("\nOverall integration result: PASS\n");
        return 0;
    }

    printf("\nOverall integration result: FAIL\n");
    return 1;
}
