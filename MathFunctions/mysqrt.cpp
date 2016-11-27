//
// Created by David Curylo on 11/26/16.
//

#include <stdio.h>
#include <math.h>

float mysqrt(float x)
{
    if(x < 0)
        return NAN;
    int prev,k = 0;
    int kmax = 1000;
    float s = 1;
    for(k=0;k<kmax;k++)
    {
        prev = s;
        s = (s + x/s)/2;
        if(prev == s)
        {
            break;
        }
    }
    fprintf(stdout, "Calculated sqrt!\n");
    return s;
}