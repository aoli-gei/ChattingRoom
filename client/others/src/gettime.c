#include "../../include/myhead.h"

void get_time(char *tmc)
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);

    p->tm_year = p->tm_year + 1900;
    p->tm_mon = p->tm_mon + 1;
    p->tm_hour = p->tm_hour + 8;          

    *tmc = '0' + (p->tm_hour / 10);
    *(tmc+1) = '0' + (p->tm_hour % 10);
    *(tmc+2) = ':';

    *(tmc+3) = '0' + (p->tm_min / 10);
    *(tmc+4) = '0' + (p->tm_min % 10); 
    *(tmc+5) = ':';

    *(tmc+6) = '0' + (p->tm_sec / 10);
    *(tmc+7) = '0' + (p->tm_sec % 10);
    *(tmc+8) = '\0';
}
 