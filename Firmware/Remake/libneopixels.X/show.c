/*
 * File:   show.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#include "libneopixels.h"

extern unsigned int     _leds[2];
extern unsigned int     *_latch;
extern unsigned char    _pin;

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
    "   .set    noreorder       \n"
    "   lw      $t1, %[pin]     \n"
    "   li      $t0, 1          \n"
    "   sllv    $t1, $t0, $t1   \n"
    "   lw      $t3, %[port]    \n"
    "   la      $t0, %[leds]    \n"
    "   li      $t2, 2          \n"
    "0:                         \n"
    "   lw      $t5, 0($t0)     \n"
    "   addiu   $t0, $t0, 4     \n"
    "   li      $t4, 24         \n"
    "1:                         \n"
    "   sw      $t3, %[port]    \n"
    "   andi    $t6, $t5, 1     \n"
    "   srl     $t5, $t5, 1     \n"
    "   or      $t3, $t3, $t1   \n"
    "   sw      $t3, %[port]    \n"
    "   xor     $t3, $t3, $t1   \n"
    "   beql    $t6, $zero, .+8 \n"
    "   sw      $t3, %[port]    \n"
    "   bne     $t4, $zero, 1b  \n"
    "   nop                     \n"
    "   addiu   $t2, $t2, -1    \n"
    "   bne     $t2, $zero, 0b  \n"
    "   nop                     \n"
    :: [port] "o" (*_latch),
       [leds] "i" (_leds),
       [pin]  "m" (_pin));
}
