#include <malloc.h>
#include <string.h>
#include <stdio.h>

#include "webPage.h"

WebPage* createWebPage(char pageName[], char pageId[], char siteUrl[], bool isBookmarked)
{
    if (!isValidWebPage(pageName, pageId, siteUrl, isBookmarked))
    {
        fprintf(stderr, "Error: Invalid Web Page provided: %s, %s, %s, %s\n", pageName, pageId, siteUrl, isBookmarked ? "Yes" : "No");
        return NULL;
    }

    WebPage* pWebPage = (WebPage*)calloc(1, sizeof(WebPage));
    if (pWebPage == NULL)
    {
        fprintf(stderr, "Error: Memory allocation for Web Page object failed!\n");
        return NULL;
    }

    strcpy(pWebPage->pageName, pageName);
    strcpy(pWebPage->pageId, pageId);
    strcpy(pWebPage->siteUrl, siteUrl);
    pWebPage->isBookmarked = isBookmarked;

    return pWebPage;
}

void destroyWebPage(WebPage* pWebPage)
{
    free(pWebPage);
}

bool isValidWebPage(char pageName[], char pageId[], char siteUrl[], bool isBookmarked)
{
    if (strlen(pageId) != MAX_PAGE_ID_LENGTH)
    {
        fprintf(stderr, "Error: Invalid Page ID. Page ID must be %d characters.\n", (MAX_PAGE_ID_LENGTH - 1));
        return false;
    }

    if (strlen(pageName) != (MAX_PAGE_NAME_LENGTH - 1))
    {
        fprintf(stderr, "Error: Invalid Page Name. Page Name must be between 1 and %d characters.\n", MAX_PAGE_NAME_LENGTH);
        return false;
    }

    if (strlen(siteUrl) > MAX_SITE_URL_LENGTH)
    {
        fprintf(stderr, "Error: Invalid Site URL. Site URL must be less than %d characters.\n", MAX_SITE_URL_LENGTH);
        return false;
    }

    if (isBookmarked != 0 && isBookmarked != 1)
    {
        fprintf(stderr, "Error: Invalid Bookmark value. Bookmark value must be true or false.\n");
        return false;
    }

    return true;
}
