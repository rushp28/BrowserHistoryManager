#include <stdio.h>
#include <malloc.h>

#include "date.h"

Date* createDate(short int day, short int month, short int year) {
    if (!isValidDate(day, month, year)) {
        if (!isValidDate(day, month, year)) {
            fprintf(stderr, "Error: Invalid Date provided: %02d/%02d/%d. Creating Date object failed.\n", day, month, year);
            return NULL;
        }
    }

    Date* pDate = (Date*)calloc(1, sizeof(Date));
    if (pDate == NULL) {
        fprintf(stderr, "Error: Memory allocation for Date object failed. Creating Date object failed.\n");
        return NULL;
    }

    pDate->day = day;
    pDate->month = month;
    pDate->year = year;

    return pDate;
}

void destroyDate(Date* pDate) {
    if (pDate == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Date. Pointer for Date should not be NULL. Destroying Date object failed.\n");
        return;
    }

    free(pDate);
}

bool isLeapYear(short int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool isValidDate(short int day, short int month, short int year) {
    if (day < 1) {
        fprintf(stderr, "Error: Invalid Day. Day must be greater than 0.\n");
        return false;
    }

    if (year < 1 || year > 9999) {
        fprintf(stderr, "Error: Invalid Year. Year must be between 1 and 9999.\n");
        return false;
    }

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day > 31) {
                fprintf(stderr, "Error: Invalid Day for Month %d. Day must be between 1 and 31.\n", month);
                return false;
            }

            return true;

        case 4: case 6: case 9: case 11:
            if (day > 30) {
                fprintf(stderr, "Error: Invalid Day for Month %d. Day must be between 1 and 30.\n", month);
                return false;
            }

            return true;

        case 2:
            if (isLeapYear(year)) {
                if (day > 29) {
                    fprintf(stderr, "Error: Invalid Day for February in a leap year. Day must be between 1 and 29.\n");
                    return false;
                }
            }
            else {
                if (day > 28) {
                    fprintf(stderr, "Error: Invalid Day for February in a non-leap year. Day must be between 1 and 28.\n");
                    return false;
                }
            }

            return true;

        default:
            fprintf(stderr, "Error: Invalid Month. Month must be between 1 and 12.\n");
            return false;
    }
}


