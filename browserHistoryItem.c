#include <malloc.h>
#include <stdio.h>

#include "browserHistoryItem.h"

BrowserHistoryItem* createBrowserHistoryItem(WebPage* pWebPage, Date* pDateVisited) {
    if(pWebPage == NULL || pDateVisited == NULL) {
        fprintf(stderr, "Error: NULL Pointer for Web Page or Visited Date. Pointer for Web Page or Visited Date should not be NULL.\n");
        return NULL;
    }

    BrowserHistoryItem* pBrowserHistoryItem = (BrowserHistoryItem*)calloc(1, sizeof(BrowserHistoryItem));
    if (pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Memory Allocation for Browser History Item Failed.\n");
        return NULL;
    }

    pBrowserHistoryItem->browserHistoryItemId = 0;
    pBrowserHistoryItem->pWebPage = pWebPage;

    pBrowserHistoryItem->dateVisited.day = pDateVisited->day;
    pBrowserHistoryItem->dateVisited.month = pDateVisited->month;
    pBrowserHistoryItem->dateVisited.year = pDateVisited->year;

    pBrowserHistoryItem->pNext = NULL;
    pBrowserHistoryItem->pPrevious = NULL;

    return pBrowserHistoryItem;
}

void destroyBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem) {
    destroyDate(&pBrowserHistoryItem->dateVisited);
    destroyWebPage(pBrowserHistoryItem->pWebPage);
    free(pBrowserHistoryItem);
}

