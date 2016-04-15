/*
 * File:   show.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

/*
 * Notice:
 * 
 * This library was designed for the PIC32MX340F512H microcontroller for a
 * clock frequency of 8MHz. Its successful use on other devices is not
 * guaranteed.
 */

#include "libneopixels.h"

/*
 * Considering a 8MHz MIPS microprocessor ...
 * Clock budget for 0 code: 10 IPS
 * Clock budget for 1 code: 10 IPS
 * T0H = 0.4us, T0L = 0.85us
 * T1H = 0.8US, T1L = 0.45us
 * RES = 50us+
 */

void    neopixels_show(void)
{
    asm volatile(                 "\n"
    "    .set    noreorder"       "\n"
    "    li      $t0, 1"          "\n"
    "    sllv    $t0, $t0, %3"    "\n"
    "    move    %3, $t0"         "\n"
    "    b       2f"              "\n"
    "    lh      $t1, %0"         "\n"
    "0:"                          "\n"
    "    lw      $t2, 0(%2)"      "\n"
    "    addiu   %2, %2, 4"       "\n"
    "    li      $t0, 24"         "\n"
    "1:"                          "\n"
    "    or      $t1, $t1, %3"    "\n"
    "    sh      $t1, %0"         "\n"
    "    ext     $t3, $t2, 31, 1" "\n"
    "    xor     $t1, $t1, %3"    "\n"
    "    beqzl   $t3, .+8"        "\n"
    "    sh      $t1, %0"         "\n"
    "    addiu   $t0, $t0, -1"    "\n"
    "    sh      $t1, %0"         "\n"
    "    bnez    $t0, 1b"         "\n"
    "    sll     $t2, $t2, 1"     "\n"
    "2:"                          "\n"
    "    bnez    %1, 0b"          "\n"
    "    addiu   %1, %1, -1"      "\n"
    : "=m" (*_latch)
    : "r"  (_nleds),
      "r" (_leds),
      "r"  (_pin)
    : "t0","t1","t2","t3"
    );
}
