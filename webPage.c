#include <malloc.h>
#include <string.h>
#include <stdio.h>

#include "webPage.h"

// WebPage function definitions

WebPage* createWebPage(char pageName[], char pageId[], char siteUrl[], bool isBookmarked) {
    // Check if the Web Page Details are valid
    if (!areValidWebPageDetails(pageName, pageId, siteUrl, isBookmarked)) {
        fprintf(stderr, "Error: Invalid Web Page provided: %s, %s, %s, %s. Creating Web Page object failed.\n", pageName, pageId, siteUrl, isBookmarked ? "true" : "false");
        return NULL;
    }

    // Allocate memory for the WebPage object
    WebPage* pWebPage = (WebPage*)calloc(1, sizeof(WebPage));
    // Check if memory allocation fails
    if (pWebPage == NULL) {
        fprintf(stderr, "Error: Memory allocation for Web Page object failed. Creating Web Page object failed.\n");
        return NULL;
    }

    // Set the page name, page ID, site URL and bookmarked status of the WebPage object
    strcpy(pWebPage->pageName, pageName);
    strcpy(pWebPage->pageId, pageId);
    strcpy(pWebPage->siteUrl, siteUrl);
    pWebPage->isBookmarked = isBookmarked;

    // Return the WebPage object pointer
    return pWebPage;
}

void destroyWebPage(WebPage* pWebPage) {
    // Check if the WebPage object pointer is NULL
    if (pWebPage == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Web Page. Pointer for Web Page should not be NULL. Destroying Web Page object failed.\n");
        return;
    }

    // Free the memory allocated for the WebPage object
    free(pWebPage);
}

bool areValidWebPageDetails(char pageName[], char pageId[], char siteUrl[], bool isBookmarked) {
    // Check if the Page ID, Page Name or Site URL are NULL
    if (pageId == NULL || pageName == NULL || siteUrl == NULL) {
        fprintf(stderr, "Error: NULL Page ID, Page Name or Site URL. Page ID, Page Name or Site URL should not be NULL.\n");
        return false;
    }

    // Check if the length of Page ID is invalid
    if (strlen(pageId) != (MAX_PAGE_ID_LENGTH - 1)) {
        fprintf(stderr, "Error: Invalid Page ID. Page ID must be %d characters.\n", (MAX_PAGE_ID_LENGTH - 1));
        return false;
    }

    // Check if the length of Page Name is invalid
    if (strlen(pageName) < 1 || strlen(pageName) > (MAX_PAGE_NAME_LENGTH - 1)) {
        fprintf(stderr, "Error: Invalid Page Name. Page Name must be between 1 and %d characters.\n", MAX_PAGE_NAME_LENGTH);
        return false;
    }

    // Check if the length of Site URL is invalid
    if (strlen(siteUrl) < 1 || strlen(siteUrl) > (MAX_SITE_URL_LENGTH - 1)) {
        fprintf(stderr, "Error: Invalid Site URL. Site URL must be between 1 and %d characters.\n", MAX_SITE_URL_LENGTH);
        return false;
    }

    // Check if the Bookmark value is invalid
    if (isBookmarked != 0 && isBookmarked != 1) {
        fprintf(stderr, "Error: Invalid Bookmark value. Bookmark value must be true or false.\n");
        return false;
    }

    // Return true if the Web Page Details are valid
    return true;
}
