#ifndef BROWSERHISTORYMANAGER_DATE_H
#define BROWSERHISTORYMANAGER_DATE_H

#include <stdbool.h>

// Date struct

/*
 * @brief a Date struct to represent a date
 *
 * @var day   - the day of the date
 * @var month - the month of the date
 * @var year  - the year of the date
 */
typedef struct {
    short int day;
    short int month;
    short int year;
} Date;

// Date function prototypes

/*
 * @brief creates a Date object with the given day, month and year
 *
 * @param day   - the day of the date
 * @param month - the month of the date
 * @param year  - the year of the date
 *
 * @returns a pointer to the Date object if the date is valid, otherwise NULL
 */
Date* createDate(short int day, short int month, short int year);

/*
 * @brief destroys the given Date object
 *
 * @param pDate - the Date object to destroy
 */
void destroyDate(Date* pDate);

/*
 * @brief checks if the given year is a leap year
 *
 * @param year - the year to check
 *
 * @returns true if the year is a leap year, otherwise false
 */
bool isLeapYear(short int year);

/*
 * @brief checks if the given date is valid
 *
 * @param day   - the day of the date
 * @param month - the month of the date
 * @param year  - the year of the date
 *
 * @returns true if the date is valid, otherwise false
 */
bool isValidDate(short int day, short int month, short int year);

#endif //BROWSERHISTORYMANAGER_DATE_H
