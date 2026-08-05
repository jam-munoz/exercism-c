#include "clock.h"

clock_t clock_add(clock_t clock, int minute_add)
{
    int hour = atoi(clock.text);
    int minute = atoi(&clock.text[3]);

    minute += minute_add;
    return clock_create(hour, minute);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    int hour = atoi(clock.text);
    int minute = atoi(&clock.text[3]);

    minute -= minute_subtract;
    return clock_create(hour, minute);
}

bool clock_is_equal(clock_t a, clock_t b)
{
    if (strcmp(a.text, b.text) == 0)
        return true;
    else
        return false;
}

clock_t clock_create(int hour, int minute)
{
    clock_t time;
    int i = MAX_STR_LEN - 1;

    while (minute >= 60)
    {
        hour++;
        minute -= 60;
    }
    while (minute < 0)
    {
        hour--;
        minute += 60;
    }
    while (hour >= 24)
        hour -= 24;
    while (hour < 0)
        hour += 24;
    
    time.text[i--] = '\0';
    while (i >= 3)
    {
        time.text[i] = (minute % 10) + '0';
        minute /= 10;
        i--;
    }
    time.text[i--] = ':';
    while (i >= 0)
    {
        time.text[i] = (hour % 10) + '0';
        hour /= 10;
        i--;
    }
    return time;
}