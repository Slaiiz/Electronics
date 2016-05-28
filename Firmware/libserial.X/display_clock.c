#include "libserial.h"

void    libserial_display_clock(UINT32 y, UINT32 M, UINT32 d, UINT32 wd, UINT32 h, UINT32 m, UINT32 s)
{
    char *days[7];
    days[0] = "Dimanche";
    days[1] = "Lundi";
    days[2] = "Mardi";
    days[3] = "Mercredi";
    days[4] = "Jeudi";
    days[5] = "Vendredi";
    days[6] = "Samedi";

    char *mouth[12];
    mouth[0] = "Janvier";
    mouth[1] = "Fevrier";
    mouth[2] = "Mars";
    mouth[3] = "Avril";
    mouth[4] = "Mai";
    mouth[5] = "Juin";
    mouth[6] = "Juillet";
    mouth[7] = "Aout";
    mouth[8] = "Septembre";
    mouth[8] = "Octobre";
    mouth[10] = "Novembre";
    mouth[11] = "Decembre";

    libserial_putstr("*h");
    libserial_putchr('0' + h / 10);
    libserial_putchr('0' + h % 10);
    libserial_putchr(':');
    libserial_putchr('0' + m / 10);
    libserial_putchr('0' + m % 10);
    libserial_putchr(':');
    libserial_putchr('0' + s / 10);
    libserial_putchr('0' + s % 10);
    libserial_putchr('\n');

    libserial_putstr("*d");
    libserial_putstr(days[wd]);
    libserial_putchr(' ');
    libserial_putchr('0' + d / 10);
    libserial_putchr('0' + d % 10);
    libserial_putchr(' ');
    libserial_putstr(mouth[M - 1]);
    libserial_putchr(' ');
    libserial_putchr('2');
    libserial_putchr('0');
    libserial_putchr('0' + y / 10);
    libserial_putchr('0' + y % 10);
    libserial_putchr('\n');
}