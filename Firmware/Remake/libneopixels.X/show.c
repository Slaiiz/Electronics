/*
 * File:   show.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#include <xc.h>
#include "libneopixels.h"

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
 * - Fix timings
 */

void    neopixels_show(void)
{
    asm volatile(               "\n"
    "   .set    noreorder"      "\n"
    "   li      $t0,1"          "\n"
    "   sllv    $t0,$t0,%3"     "\n"
    "   move    %3,$t0"         "\n"
    "   b       2f"             "\n"
    "   lh      $t1,%0"         "\n"
    "0:"                        "\n"
    "   lw      $t2,0(%2)"      "\n"
    "   addiu   %2,%2,4"        "\n"
    "   li      $t0,24"         "\n"
    "1:"                        "\n"
    "   or      $t1,$t1,%3"     "\n"
    "   sh      $t1,%0"         "\n"
    "   xor     $t1,$t1,%3"     "\n"
    "   andi    $t3,$t2,1"      "\n"
    "   beqzl   $t3,.+4"        "\n"
    "   sh      $t1,%0"         "\n"
    "   sh      $t1,%0"         "\n"
    "   addiu   $t0,$t0,-1"     "\n"
    "   bnez    $t0,1b"         "\n"
    "   srl     $t2,$t2,1"      "\n"
    "2:"                        "\n"
    "   bnez    %1,0b"          "\n"
    "   addiu   %1,%1,-1"       "\n"
    : "=m" (*_latch)
    : "r"  (_nleds),
      "r" (_leds),
      "r"  (_pin)
    : "t0","t1","t2","t3"
    );
//    asm volatile(                "\n"
//    "   .set    noreorder"       "\n"
//    "   lw      $t1, %[pin]"     "\n"
//    "   li      $t0, 1"          "\n"
//    "   sllv    $t1, $t0, $t1"   "\n"
//    "   lw      $t3, %[port]"    "\n"
//    "   la      $t0, %[leds]"    "\n"
//    "   li      $t2, 2"          "\n"
//    "0:"                         "\n"
//    "   lw      $t5, 0($t0)"     "\n"
//    "   addiu   $t0, $t0, 4"     "\n"
//    "   li      $t4, 24"         "\n"
//    "1:"                         "\n"
//    "   sw      $t3, %[port]"    "\n"
//    "   andi    $t6, $t5, 1"     "\n"
//    "   srl     $t5, $t5, 1"     "\n"
//    "   or      $t3, $t3, $t1"   "\n"
//    "   sw      $t3, %[port]"    "\n"
//    "   xor     $t3, $t3, $t1"   "\n"
//    "   beql    $t6, $zero, .+8" "\n"
//    "   sw      $t3, %[port]"    "\n"
//    "   bne     $t4, $zero, 1b"  "\n"
//    "   nop"                     "\n"
//    "   addiu   $t2, $t2, -1"    "\n"
//    "   bne     $t2, $zero, 0b"  "\n"
//    "   nop"                     "\n"
//    :: [port] "o" (*_latch),
//       [leds] "i" (_leds),
//       [pin]  "m" (_pin));
//    asm volatile(              "\n" // This pulses HIGH for 1us, LOW for 2us
//    "   .set    noreorder"     "\n" // Freqency is 16MHz, Port is RB5
//    "   lw      $t0, %0"       "\n"
//    "0:"                       "\n"
//    "   or      $t0, $t0, %1"  "\n"
//    "   sw      $t0, %0"       "\n"
//    "   xor     $t0, $t0, %1"  "\n"
//    "   sw      $t0, %0"       "\n"
//    "   b       0b"            "\n"
//    "   nop"                   "\n"
//    : "=m" (*_latch)
//    : "r"  (1 << _pin)
//    : "t0"
//    );
//    asm volatile(              "\n" // This pulses HIGH for 1us, LOW for 1us
//    "   .set    noreorder"     "\n" // Freqency is 16MHz, Port is RB5
//    "0:"                       "\n"
//    "   b       0b"            "\n"
//    "   sw      %1, %0"        "\n"
//    : "=m" (LATBINV)
//    : "r"  (1 << _pin)
//    );
}
