#include "date.h"

#include <stdio.h>
#include <malloc.h>

Date* createDate(short int day, short int month, short int year) {
    if (!isValidDate(day, month, year)) {
        if (!isValidDate(day, month, year)) {
            fprintf(stderr, "Error: Invalid date provided: %02d/%02d/%d\n", day, month, year);
            return NULL;
        }
    }

    Date* pDate = (Date*)calloc(1, sizeof(Date));
    if (pDate == NULL) {
        fprintf(stderr, "Error: Memory allocation for Date object failed!\n");
        return NULL;
    }

    pDate->day = day;
    pDate->month = month;
    pDate->year = year;

    return pDate;
}

void destroyDate(Date* pDate) {
    free(pDate);
}

bool isLeapYear(short int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool isValidDate(short int day, short int month, short int year) {
    if (day < 1) {
        fprintf(stderr, "Error: Invalid day. Day must be greater than 0.\n");
        return false;
    }

    if (year < 0 || year > 9999) {
        fprintf(stderr, "Error: Invalid year. Year must be between 0 and 9999.\n");
        return false;
    }

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day > 31) {
                fprintf(stderr, "Error: Invalid day for month %d. Day must be between 1 and 31.\n", month);
                return false;
            }

            return true;

        case 4: case 6: case 9: case 11:
            if (day > 30) {
                fprintf(stderr, "Error: Invalid day for month %d. Day must be between 1 and 30.\n", month);
                return false;
            }

            return true;

        case 2:
            if (isLeapYear(year)) {
                if (day > 29) {
                    fprintf(stderr, "Error: Invalid day for February in a leap year. Day must be between 1 and 29.\n");
                    return false;
                }
            }
            else {
                if (day > 28) {
                    fprintf(stderr, "Error: Invalid day for February in a non-leap year. Day must be between 1 and 28.\n");
                    return false;
                }
            }

            return true;

        default:
            fprintf(stderr, "Error: Invalid month. Month must be between 1 and 12.\n");
            return false;
    }
}


