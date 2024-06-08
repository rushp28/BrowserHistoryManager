#ifndef BROWSERHISTORYMANAGER_WEBPAGE_H
#define BROWSERHISTORYMANAGER_WEBPAGE_H

#include <stdbool.h>

#define MAX_PAGE_ID_LENGTH (4 + 1)
#define MAX_PAGE_NAME_LENGTH (50 + 1)
#define MAX_SITE_URL_LENGTH (200 + 1)

typedef struct WebPage
{
    char pageId[MAX_PAGE_ID_LENGTH];
    char pageName[MAX_PAGE_NAME_LENGTH];
    char siteUrl[MAX_SITE_URL_LENGTH];
    bool isBookmarked;
} WebPage;

WebPage* createWebPage(char pageName[], char pageId[], char siteUrl[], bool isBookmarked);

void destroyWebPage(WebPage* pWebPage);

bool isValidWebPage(char pageName[], char pageId[], char siteUrl[], bool isBookmarked);

#endif //BROWSERHISTORYMANAGER_WEBPAGE_H
