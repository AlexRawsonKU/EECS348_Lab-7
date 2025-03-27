#include "temperature.h"
#include <stdio.h>

enum TemperatureUnit
{
    FAHRENHEIT,
    CELSIUS,
    KELVIN,
};

const char *UNIT_LABELS[] = {"°F", "°C", "K"};

int main(int argc, char *argv[])
{
    // read the initial temperature
    printf("Enter a temperature: ");
    float temperature;
    if (scanf("%f", &temperature) == EOF)
    {
        perror("failed to read temperature");
        return 1;
    }

    // print the helper/key
    printf("Temperature Units: FAHRENHEIT: %d, CELSIUS: %d, KELVIN:%d\n", FAHRENHEIT, CELSIUS, KELVIN);

    // get the initial temperature unit
    enum TemperatureUnit input_unit = -1;
    printf("Enter unit number corresponding to input unit: ");
    if (scanf("%d", &input_unit) == EOF)
    {
        perror("failed to read input unit");
        return 1;
    }
    if (input_unit < FAHRENHEIT || input_unit > KELVIN)
    {
        fprintf(stderr, "invalid input unit\n");
        return 1;
    }

    // get the output temperature unit
    enum TemperatureUnit output_unit = -1;
    printf("Enter unit number corresponding to output unit: ");
    if (scanf("%d", &output_unit) == EOF)
    {
        perror("failed to read output unit");
        return 1;
    }
    if (output_unit < FAHRENHEIT || output_unit > KELVIN)
    {
        fprintf(stderr, "invalid output unit\n");
        return 1;
    }

    // convert the input to celsius
    float degrees_celsius;
    switch (input_unit)
    {
    case FAHRENHEIT:
        degrees_celsius = fahrenheit_to_celsius(temperature);
        break;
    case CELSIUS:
        degrees_celsius = temperature;
        break;
    case KELVIN:
        degrees_celsius = kelvin_to_celsius(temperature);
        break;
    }

    // convert degrees celsius to the output unit
    float temperature_output;
    switch (output_unit)
    {
    case FAHRENHEIT:
        temperature_output = celsius_to_fahrenheit(degrees_celsius);
        break;
    case CELSIUS:
        temperature_output = degrees_celsius;
        break;
    case KELVIN:
        temperature_output = celsius_to_kelvin(degrees_celsius);
        break;
    }

    // print a helpful message
    printf("\nYour Temperature: %f%s - %s\n", temperature_output, UNIT_LABELS[output_unit], weather_advisory(degrees_celsius));

    // exit successfully
    return 0;
}
