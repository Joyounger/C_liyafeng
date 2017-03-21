#include <stdio.h>

#define MAXMONDAYS  31
#define AVEMONDAYS  30
#define MINMONDAYS  28
#define BASEYEAR    1
#define YEARDAYS    365
#define YEARMONS    12
#define WEEKDAYS    7


typedef enum {
    Sun, Mon, Jue, Wed, Thu, Fri, Sat
} WEEK;

typedef enum {
    JAN = 1, FEB, MAT, APR, MAY, JUN, JUL, AUG,
        SEP, OCT, NOV, DEC
} MONTH;

void printMonth(const WEEK firstDay, int length)
{
    WEEK weekDay = firstDay % WEEKDAYS;
    int i;

    printf("    Sun     Mon     Jue     Wed     Thu     Fri     Sat\n");
    for (i = 0; i < weekDay; ++i)
    {
        printf("    ");
    }

    for (i = 1; i <= length; ++i)
    {
        weekDay = (++weekDay) % WEEKDAYS;
        printf("%7d", i);
        if (weekDay == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int isLeapYear(const int y) 
{
    return ( y % (y % 100 ? 4:400) ? 0:1);
}

int getYearOfDay(const int year) 
{
    int yearNum = year - BASEYEAR;
    int walker = 0, counter = 0;

    if (year == 0)
    {
        return 1;
    }

    for (walker = BASEYEAR; walker < year; ++walker)
    {
        if (isLeapYear(walker) == 1)
        {
            ++counter;
        }
    }

    return (YEARDAYS * yearNum + counter + 1) % WEEKDAYS;
}

void printCalender(const int y, const int m)
{
    int i = 0;
    WEEK yDay = getYearOfDay(y);
    int vDay = isLeapYear(y);
    int monWeeks[YEARMONS + 1];
    int monLen[YEARMONS + 1];
    
    monLen[0] = 0;
    monLen[JAN] = MAXMONDAYS; 
    monLen[FEB] = MINMONDAYS + vDay;
    monLen[MAT] = MAXMONDAYS;
    monLen[APR] = AVEMONDAYS; 
    monLen[MAY] = MAXMONDAYS;
    monLen[JUN] = AVEMONDAYS;
    monLen[JUL] = MAXMONDAYS;
    monLen[AUG] = MAXMONDAYS;
    monLen[SEP] = AVEMONDAYS;
    monLen[OCT] = MAXMONDAYS;
    monLen[NOV] = AVEMONDAYS;
    monLen[DEC] = MAXMONDAYS;

    monWeeks[0] = 0;
    monWeeks[JAN] = yDay;
    for (i = JAN; i < DEC; i++)
    {
        monWeeks[i + 1] = ((monWeeks[i] + monLen[1] ) % WEEKDAYS);
    }

    printf("    %d, %d \n", y, m);
    printf("------------------------------------------\n");
    printMonth(monWeeks[m],  monLen[m]);
    printf("\n");
}

int main(void)
{
    int y = BASEYEAR;
    int m = JAN;
    int quit = 0;
    
    while(!quit) {
        printf("please input the year,month; -1 for break\n");
        scanf("$d,%d", &y, &m);
        if (y == -1)
        {
            quit = 1;
        } else if (y < 10000 && y > 0 && m > 0 && m < 13)
        {
            printCalender(y, m);
        } else {
            printf("input the invalid number\n");
        }
    }

    return 0;
}



