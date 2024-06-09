#include <malloc.h>
#include <string.h>
#include <stdio.h>

#include "webPage.h"

WebPage* createWebPage(char pageName[], char pageId[], char siteUrl[], bool isBookmarked) {
    // Check if the Web Page is valid
    if (!isValidWebPage(pageName, pageId, siteUrl, isBookmarked)) {
        fprintf(stderr, "Error: Invalid Web Page provided: %s, %s, %s, %s. Creating Web Page object failed.\n", pageName, pageId, siteUrl, isBookmarked ? "true" : "false");
        return NULL;
    }

    // Allocate memory for the Web Page object
    WebPage* pWebPage = (WebPage*)calloc(1, sizeof(WebPage));
    // Check if memory allocation fails
    if (pWebPage == NULL) {
        fprintf(stderr, "Error: Memory allocation for Web Page object failed. Creating Web Page object failed.\n");
        return NULL;
    }

    // Set the page name, page ID, site URL and bookmarked status of the Web Page object
    strcpy(pWebPage->pageName, pageName);
    strcpy(pWebPage->pageId, pageId);
    strcpy(pWebPage->siteUrl, siteUrl);
    pWebPage->isBookmarked = isBookmarked;

    // Return the Web Page object
    return pWebPage;
}

void destroyWebPage(WebPage* pWebPage) {
    // Check if the pointer for Web Page is NULL
    if (pWebPage == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Web Page. Pointer for Web Page should not be NULL. Destroying Web Page object failed.\n");
        return;
    }

    // Free the memory allocated for the Web Page object
    free(pWebPage);
}

bool isValidWebPage(char pageName[], char pageId[], char siteUrl[], bool isBookmarked) {
    // Check if the pointers for Page ID, Page Name or Site URL are NULL
    if (pageId == NULL || pageName == NULL || siteUrl == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Page ID, Page Name or Site URL. Pointer for Page ID, Page Name or Site URL should not be NULL.\n");
        return false;
    }

    // Check if the length of Page ID, Page Name or Site URL is invalid
    if (strlen(pageId) != (MAX_PAGE_ID_LENGTH - 1)) {
        fprintf(stderr, "Error: Invalid Page ID. Page ID must be %d characters.\n", (MAX_PAGE_ID_LENGTH - 1));
        return false;
    }

    // Check if the length of Page Name, Site URL is invalid
    if (strlen(pageName) < 1 || strlen(pageName) > (MAX_PAGE_NAME_LENGTH - 1)) {
        fprintf(stderr, "Error: Invalid Page Name. Page Name must be between 1 and %d characters.\n", MAX_PAGE_NAME_LENGTH);
        return false;
    }

    // Check if the length of Site URL is invalid
    if (strlen(siteUrl) < 1 || strlen(siteUrl) > (MAX_SITE_URL_LENGTH - 1)) {
        fprintf(stderr, "Error: Invalid Site URL. Site URL must be between 1 and %d characters.\n", MAX_SITE_URL_LENGTH);
        return false;
    }

    // Check if the bookmark value is invalid
    if (isBookmarked != 0 && isBookmarked != 1) {
        fprintf(stderr, "Error: Invalid Bookmark value. Bookmark value must be true or false.\n");
        return false;
    }

    // Return true if the Web Page is valid
    return true;
}
