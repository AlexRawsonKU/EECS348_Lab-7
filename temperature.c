#include "temperature.h"
// temperature conversions adapted from https://en.wikipedia.org/wiki/Conversion_of_scales_of_temperature

float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius)
{
    return celsius + 273.15;
}

float kelvin_to_celsius(float celsius)
{
    return celsius - 273.15;
}
