#include <stdio.h>

#include "section3_3.h"

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high) {
        if (x < v[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }

    if (x == v[mid]) {
        return mid;
    }
    else {
        return -1;
    }
}