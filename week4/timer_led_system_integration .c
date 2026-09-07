#include <stdio.h>
#include <stdbool.h>

#define TIMER_PERIOD_TICKS 1000U
#define SIMULATION_TICKS 5000U

static volatile unsigned int timer_ticks = 0U;
static volatile bool led_state = false;
static volatile unsigned int interrupt_count = 0U;

static void LED_Set(bool state)
{
    led_state = state;
}

static void LED_Toggle(void)
{
    led_state = !led_state;
}

static void Timer_ISR(void)
{
    interrupt_count++;
    printf("ISR Event %u: Timer interrupt generated\n", interrupt_count);
    LED_Toggle();
    printf("LED State: %s\n", led_state ? "ON" : "OFF");
}

static void Timer_Tick(void)
{
    timer_ticks++;

    if (timer_ticks >= TIMER_PERIOD_TICKS)
    {
        timer_ticks = 0U;
        Timer_ISR();
    }
}

static void System_Init(void)
{
    timer_ticks = 0U;
    interrupt_count = 0U;
    LED_Set(false);

    printf("System initialized\n");
    printf("Timer period: %u ticks\n", TIMER_PERIOD_TICKS);
    printf("Simulation length: %u ticks\n", SIMULATION_TICKS);
    printf("Initial LED state: OFF\n\n");
}

static bool Test_TimerPeriod(void)
{
    timer_ticks = 0U;
    interrupt_count = 0U;

    for (unsigned int i = 0U; i < TIMER_PERIOD_TICKS; i++)
        Timer_Tick();

    return (interrupt_count == 1U && timer_ticks == 0U);
}

static bool Test_FiveInterrupts(void)
{
    timer_ticks = 0U;
    interrupt_count = 0U;
    LED_Set(false);

    for (unsigned int i = 0U; i < SIMULATION_TICKS; i++)
        Timer_Tick();

    return (interrupt_count == 5U);
}

static bool Test_LEDState(void)
{
    timer_ticks = 0U;
    interrupt_count = 0U;
    LED_Set(false);

    for (unsigned int i = 0U; i < SIMULATION_TICKS; i++)
        Timer_Tick();

    return (led_state == true);
}

int main(void)
{
    bool test1, test2, test3;

    System_Init();

    printf("Starting integrated system simulation...\n\n");

    for (unsigned int i = 0U; i < SIMULATION_TICKS; i++)
        Timer_Tick();

    printf("\nSimulation completed.\n");
    printf("Interrupts generated: %u\n", interrupt_count);
    printf("Final LED state: %s\n\n", led_state ? "ON" : "OFF");

    printf("Running automated tests...\n");

    test1 = Test_TimerPeriod();
    test2 = Test_FiveInterrupts();
    test3 = Test_LEDState();

    printf("Test 1 - Timer Period: %s\n", test1 ? "PASS" : "FAIL");
    printf("Test 2 - Five Interrupts: %s\n", test2 ? "PASS" : "FAIL");
    printf("Test 3 - LED Final State: %s\n", test3 ? "PASS" : "FAIL");

    if (test1 && test2 && test3)
    {
        printf("\nOverall Integration Result: PASS\n");
        return 0;
    }

    printf("\nOverall Integration Result: FAIL\n");
    return 1;
}
