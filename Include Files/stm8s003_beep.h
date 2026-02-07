#ifndef STM8S003_BEEP_H
#define STM8S003_BEEP_H

/* Часы */
#define CLK_ICKR   (*(volatile unsigned char*)0x50C0)  /* bit3=LSIEN, bit2=LSIRDY */

/* BEEP */
#define BEEP_CSR   (*(volatile unsigned char*)0x50F3)  /* bit0=BEEPEN, bit5:4=BEEPSEL */

/* Порт D (PD4 = BEEP на UBEC DUO) */
#define PD_DDR     (*(volatile unsigned char*)0x5011)
#define PD_CR1     (*(volatile unsigned char*)0x5012)
#define PD_CR2     (*(volatile unsigned char*)0x5013)

#define BEEPEN        (1u << 0)
#define BEEPSEL_1KHZ  (0u << 4)
#define BEEPSEL_2KHZ  (1u << 4)
#define BEEPSEL_4KHZ  (2u << 4)
#define LSIEN         (1u << 3)
#define LSIRDY        (1u << 2)
#define PD4           (1u << 4)

#endif /* STM8S003_BEEP_H */
