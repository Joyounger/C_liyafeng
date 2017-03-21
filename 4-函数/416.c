#include <stdio.h>
#include <math.h>

#define PI 3.14

int main()
{
    float R, SA, CA;
    scanf("%f", &CA);
    R = sqrt(CA/PI);
    SA = 2 * R * R;
    printf("R = %5.2f\n", R);
    printf("SA = %5.2f\n", SA);

    return 0;
}