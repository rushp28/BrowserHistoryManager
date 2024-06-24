#include <stdio.h>
#include <malloc.h>

#include "date.h"

// Date function definitions

Date* createDate(short int day, short int month, short int year) {
    // Check if the date is valid
    if (!isValidDate(day, month, year)) {
        fprintf(stderr, "Error: Invalid Date provided: %02d/%02d/%d. Creating Date object failed.\n", day, month, year);
        return NULL;
    }

    // Allocate memory for the Date object
    Date* pDate = (Date*)calloc(1, sizeof(Date));
    // Check if memory allocation fails
    if (pDate == NULL) {
        fprintf(stderr, "Error: Memory allocation for Date object failed. Creating Date object failed.\n");
        return NULL;
    }

    // Set the day, month and year of the Date object
    pDate->day = day;
    pDate->month = month;
    pDate->year = year;

    // Return the Date object pointer
    return pDate;
}

void destroyDate(Date* pDate) {
    // Check if the Date object pointer is NULL
    if (pDate == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Date. Pointer for Date should not be NULL. Destroying Date object failed.\n");
        return;
    }

    // Free the memory allocated for the Date object
    free(pDate);
}

bool isLeapYear(short int year) {
    // Check if the year is a leap year
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool isValidDate(short int day, short int month, short int year) {
    // Check if the day is less than 1
    if (day < 1) {
        fprintf(stderr, "Error: Invalid Day. Day must be greater than 0.\n");
        return false;
    }

    // Check if the year is valid
    if (year < 1 || year > 9999) {
        fprintf(stderr, "Error: Invalid Year. Year must be between 1 and 9999.\n");
        return false;
    }

    // Check if the month is valid
    switch (month) {
        // Check if the month is 1, 3, 5, 7, 8, 10 or 12
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            // Check if the day is greater than 31
            if (day > 31) {
                fprintf(stderr, "Error: Invalid Day for Month %d. Day must be between 1 and 31.\n", month);
                return false;
            }

            // Return true if the day is valid
            return true;

        // Check if the month is 4, 6, 9 or 11
        case 4: case 6: case 9: case 11:
            // Check if the day is greater than 30
            if (day > 30) {
                fprintf(stderr, "Error: Invalid Day for Month %d. Day must be between 1 and 30.\n", month);
                return false;
            }

            // Return true if the day is valid
            return true;

        case 2:
            // Check if the year is a leap year
            if (isLeapYear(year)) {
                // Check if the day is greater than 29
                if (day > 29) {
                    fprintf(stderr, "Error: Invalid Day for February in a leap year. Day must be between 1 and 29.\n");
                    return false;
                }
            }
            else {
                // Check if the day is greater than 28
                if (day > 28) {
                    fprintf(stderr, "Error: Invalid Day for February in a non-leap year. Day must be between 1 and 28.\n");
                    return false;
                }
            }

            // Return true if the day is valid
            return true;

        default:
            fprintf(stderr, "Error: Invalid Month. Month must be between 1 and 12.\n");
            return false;
    }
}


