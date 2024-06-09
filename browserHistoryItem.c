#include <malloc.h>
#include <stdio.h>

#include "browserHistoryItem.h"

BrowserHistoryItem* createBrowserHistoryItem(WebPage* pWebPage, Date* pDateVisited) {
    if(pWebPage == NULL || pDateVisited == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Web Page or Visited Date. Pointer for Web Page or Visited Date should not be NULL. Creating Browser History Item object failed.\n");
        return NULL;
    }

    BrowserHistoryItem* pBrowserHistoryItem = (BrowserHistoryItem*)calloc(1, sizeof(BrowserHistoryItem));
    if (pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Memory Allocation for Browser History Item Failed. Creating Browser History Item object failed.\n");

        destroyWebPage(pWebPage);
        destroyDate(pDateVisited);

        return NULL;
    }

    pBrowserHistoryItem->browserHistoryItemId = 0;
    pBrowserHistoryItem->pWebPage = pWebPage;

    pBrowserHistoryItem->dateVisited = pDateVisited;

    pBrowserHistoryItem->pNext = NULL;
    pBrowserHistoryItem->pPrevious = NULL;

    return pBrowserHistoryItem;
}

void destroyBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem) {
    if (pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Browser History Item. Pointer for Browser History Item should not be NULL. Destroying Browser History Item object failed.\n");
        return;
    }

    destroyDate(pBrowserHistoryItem->dateVisited);
    destroyWebPage(pBrowserHistoryItem->pWebPage);
    free(pBrowserHistoryItem);
}

void printBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem) {
    if (pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Browser History Item. Pointer for Browser History Item should not be NULL. Printing Browser History Item failed.\n");
        return;
    }

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

