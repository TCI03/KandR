#include <stdio.h>

#include "section2_11.h"

int lowerkr(int c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}