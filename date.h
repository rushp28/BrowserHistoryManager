#ifndef BROWSERHISTORYMANAGER_DATE_H
#define BROWSERHISTORYMANAGER_DATE_H

#include <stdbool.h>

typedef struct {
    short int day;
    short int month;
    short int year;
} Date;

Date* createDate(short int day, short int month, short int year);

void destroyDate(Date* pDate);

bool isLeapYear(short int year);

bool isValidDate(short int day, short int month, short int year);

#endif //BROWSERHISTORYMANAGER_DATE_H
