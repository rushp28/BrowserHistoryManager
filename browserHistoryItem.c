#include <malloc.h>
#include <stdio.h>

#include "browserHistoryItem.h"

BrowserHistoryItem* createBrowserHistoryItem(WebPage* pWebPage, Date* pDateVisited) {
    // Check if the Web Page or Visited Date is NULL
    if(pWebPage == NULL || pDateVisited == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Web Page or Visited Date. Pointer for Web Page or Visited Date should not be NULL. Creating Browser History Item object failed.\n");
        return NULL;
    }

    // Allocate memory for the Browser History Item object
    BrowserHistoryItem* pBrowserHistoryItem = (BrowserHistoryItem*)calloc(1, sizeof(BrowserHistoryItem));
    // Check if memory allocation fails
    if (pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Memory Allocation for Browser History Item Failed. Creating Browser History Item object failed.\n");

        // Free the memory allocated for the Web Page and Visited Date
        destroyWebPage(pWebPage);
        destroyDate(pDateVisited);

        return NULL;
    }

    // Set the Browser History Item ID, Web Page and Visited Date
    pBrowserHistoryItem->browserHistoryItemId = 0;
    pBrowserHistoryItem->pWebPage = pWebPage;
    pBrowserHistoryItem->dateVisited = pDateVisited;

    // Set the next and previous Browser History Item pointers to NULL
    pBrowserHistoryItem->pNext = NULL;
    pBrowserHistoryItem->pPrevious = NULL;

    // Return the Browser History Item object
    return pBrowserHistoryItem;
}

void destroyBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem) {
    // Check if the pointer for Browser History Item is NULL
    if (pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Browser History Item. Pointer for Browser History Item should not be NULL. Destroying Browser History Item object failed.\n");
        return;
    }

    // Free the memory allocated for the Web Page and Visited Date
    destroyDate(pBrowserHistoryItem->dateVisited);
    destroyWebPage(pBrowserHistoryItem->pWebPage);

    // Free the memory allocated for the Browser History Item object
    free(pBrowserHistoryItem);
}

void printBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem) {
    // Check if the pointer for Browser History Item is NULL
    if (pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Browser History Item. Pointer for Browser History Item should not be NULL. Printing Browser History Item failed.\n");
        return;
    }

    // Print the Browser History Item details
    printf("| %-3d | %-15s | %-10s | %02d/%02d/%d   | %-45s | %-10s |\n",
           pBrowserHistoryItem->browserHistoryItemId,
           pBrowserHistoryItem->pWebPage->pageName,
           pBrowserHistoryItem->pWebPage->pageId,
           pBrowserHistoryItem->dateVisited->day,
           pBrowserHistoryItem->dateVisited->month,
           pBrowserHistoryItem->dateVisited->year,
           pBrowserHistoryItem->pWebPage->siteUrl,
           pBrowserHistoryItem->pWebPage->isBookmarked ? "Yes" : "No");
}

