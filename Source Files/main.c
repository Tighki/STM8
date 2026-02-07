#include <stdint.h>
#include "stm8s003_beep.h"

static void delay_cycles(uint32_t n)
{
    volatile uint32_t i = n;
    while (i--) { (void)0; }
}

static void beep_on(uint8_t freq_khz)
{
    uint8_t sel = BEEPSEL_2KHZ;
    if (freq_khz == 1) sel = BEEPSEL_1KHZ;
    if (freq_khz == 4) sel = BEEPSEL_4KHZ;
    BEEP_CSR = sel | BEEPEN;
}

static void beep_off(void)
{
    BEEP_CSR = 0;
}

int main(void)
{
    /* Включить LSI (128 кГц) для BEEP */
    CLK_ICKR |= LSIEN;
    while (!(CLK_ICKR & LSIRDY))
        ;

    /* PD4 — выход под пищалку (BEEP) */
    PD_DDR  |= PD4;
    PD_CR1  |= PD4;
    PD_CR2  &= (uint8_t)~PD4;

    /* Короткий писк при старте: 2 кГц, ~0.3 с */
    beep_on(2);
    delay_cycles(400000u);
    beep_off();

    for (;;) {
        /* Повторяем два коротких писка каждые ~2 с (как "BeBe") */
        delay_cycles(800000u);
        beep_on(2);
        delay_cycles(80000u);
        beep_off();
        delay_cycles(200000u);
        beep_on(2);
        delay_cycles(80000u);
        beep_off();
    }
}
