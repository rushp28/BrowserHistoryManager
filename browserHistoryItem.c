#include <malloc.h>
#include <stdio.h>

#include "browserHistoryItem.h"

// BrowserHistoryItem function definitions

BrowserHistoryItem* createBrowserHistoryItem(WebPage* pWebPage, Date* pVisitedDate) {
    // Check if the WebPage or VisitedDate object pointers are NULL
    if(pWebPage == NULL || pVisitedDate == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Web Page or Visited Date. Pointer for Web Page or Visited Date should not be NULL. Creating Browser History Item object failed.\n");
        return NULL;
    }

    // Allocate memory for the BrowserHistoryItem object
    BrowserHistoryItem* pBrowserHistoryItem = (BrowserHistoryItem*)calloc(1, sizeof(BrowserHistoryItem));
    // Check if memory allocation fails
    if (pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Memory Allocation for Browser History Item Failed. Creating Browser History Item object failed.\n");

        // Free the memory allocated for the WebPage and VisitedDate objects
        destroyWebPage(pWebPage);
        destroyDate(pVisitedDate);

        return NULL;
    }

    // Set the Browser History Item ID, Web Page and Visited Date of the BrowserHistoryItem object
    pBrowserHistoryItem->browserHistoryItemId = 0;
    pBrowserHistoryItem->pWebPage = pWebPage;
    pBrowserHistoryItem->visitedDate = pVisitedDate;

    // Set the next and previous Browser History Item pointers of the BrowserHistoryItem object to NULL
    pBrowserHistoryItem->pNext = NULL;
    pBrowserHistoryItem->pPrevious = NULL;

    // Return the BrowserHistoryItem object pointer
    return pBrowserHistoryItem;
}

void destroyBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem) {
    // Check if the BrowserHistoryItem object pointer is NULL
    if (pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Browser History Item. Pointer for Browser History Item should not be NULL. Destroying Browser History Item object failed.\n");
        return;
    }

    // Free the memory allocated for the WebPage and VisitedDate objects
    destroyDate(pBrowserHistoryItem->visitedDate);
    destroyWebPage(pBrowserHistoryItem->pWebPage);

    // Free the memory allocated for the BrowserHistoryItem object
    free(pBrowserHistoryItem);
}

void printBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem) {
    // Check if the BrowserHistoryItem object pointer is NULL
    if (pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Browser History Item. Pointer for Browser History Item should not be NULL. Printing Browser History Item failed.\n");
        return;
    }

    // Print the BrowserHistoryItem object details
    printf("| %-3d | %-15s | %-10s | %02d/%02d/%d   | %-45s | %-10s |\n",
           pBrowserHistoryItem->browserHistoryItemId,
           pBrowserHistoryItem->pWebPage->pageName,
           pBrowserHistoryItem->pWebPage->pageId,
           pBrowserHistoryItem->visitedDate->day,
           pBrowserHistoryItem->visitedDate->month,
           pBrowserHistoryItem->visitedDate->year,
           pBrowserHistoryItem->pWebPage->siteUrl,
           pBrowserHistoryItem->pWebPage->isBookmarked ? "Yes" : "No");
}

