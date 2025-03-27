#ifndef __REPORT_H__
#define __REPORT_H__

/* Add any function signatures you need here but do not modify the existing ones */

/**
 * @brief Convert temperature in Celsius to Fahrenheit
 * 
 * @param celsius Temperature in degrees Celsius
 * @return Temperature in degrees Fahrenheit
 */
float celsius_to_fahrenheit(float celsius);

/**
 * @brief Convert temperature in Fahrenheit to Celsius
 * 
 * @param fahrenheit Temperature in degrees Fahrenheit
 * @return Temperature in degrees Celsius
 */
float fahrenheit_to_celsius(float fahrenheit);

/**
 * @brief Convert temperature in Celsius to Kelvin
 * 
 * @param celsius Temperature in degrees Celsius
 * @return Temperature in Kelvin
 */
float celsius_to_kelvin(float celsius);

/**
 * @brief Convert temperature in Kelvin to Celsius
 * 
 * @param kelvin Temperature in Kelvin
 * @return Temperature in degrees Celsius
 */
float kelvin_to_celsius(float kelvin);

#endif /* __REPORT_H__ */
