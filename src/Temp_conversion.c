//Celsius to Fahrenheit Conversion Table
#include<stdio.h>
int main()
{
    printf("Celsius \tFahrenheit\n");
    for(float cel=0;cel<300;cel=cel+20)
        printf("%f\t%f\n",cel,((1.8*cel)+32));
    return 0;
}
