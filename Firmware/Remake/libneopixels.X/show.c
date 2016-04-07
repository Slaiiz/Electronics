/*
 * File:   show.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#include "libneopixels.h"

extern unsigned int  _leds[2];
extern unsigned int* _latch;
extern unsigned int  _pin;

/*
 * Considering a 8MHz MIPS microprocessor ...
 * Clock budget for 0 code: 10 IPS
 * Clock budget for 1 code: 10 IPS
 * T0H = 0.4us, T0L = 0.85us
 * T1H = 0.8US, T1L = 0.45us
 * RES = 50us+
 */

/*
 * TODO:
 * - Add proper configuration bits
 * - Fix NOPs
 */

void    neopixels_show(void)
{
    asm volatile("\n"
    "   .set    noreorder          \n"
    "   addiu   $t2, $t2,  2       \n"
    "   lw      $t0, %[pin]        \n"
    "   ori     $t1, $zero, 1      \n"
    "   sll     $t1, $t1, $t0      \n"
    "   lw      $t0, %[port]       \n"
    "   lui     $t3, %%hi(%[leds]) \n"
    "   addiu   $t3, %%lo(%[leds]) \n"
    "0:                            \n"
    "   lw      $t4, 0($t3)        \n"
    "   addiu   $t3, $t3, 1        \n"
    "   li      $t5, 24            \n"
    "1:                            \n"
    "   or      $t0, $t0, $t1      \n"
    "   sw      $t0, %[port]       \n"
    "   nop                        \n"
    "   andi    $t6, $t4, 1        \n"
    "   beq     $t6, $zero, 2f     \n"
    "   nop                        \n"
    "   nop                        \n"
    "   xor     $t0, $t0, $t1      \n"
    "   sw      $t0, %[port]       \n"
    "   b       3f                 \n"
    "   nop                        \n"
    "2:                            \n"
    "   xor     $t0, $t0, $t1      \n"
    "   sw      $t0, %[port]       \n"
    "   nop                        \n"
    "   nop                        \n"
    "   nop                        \n"
    "3:                            \n"
    "   addiu   $t5, $t5, -1       \n"
    "   bne     $t5, $zero, 1b     \n"
    "   srl     $t4, $t4, 1        \n"
    "   addiu   $t2, $t2, -1       \n"
    "   j       0b                 \n"
    :: [port] "o" (*_latch),
       [leds] "i" (_leds),
       [pin]  "m" (_pin));
}
