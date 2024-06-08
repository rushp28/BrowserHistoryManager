#include <stdio.h>
#include <malloc.h>

#include "browserHistory.h"

BrowserHistory* createBrowserHistory() {
    BrowserHistory* pBrowserHistory = (BrowserHistory*)calloc(1, sizeof(BrowserHistory));
    if (pBrowserHistory == NULL) {
        fprintf(stderr, "Memory Allocation for Browser History Failed.\n");
        return NULL;
    }

    pBrowserHistory->pHead = NULL;
    pBrowserHistory->pTail = NULL;
    pBrowserHistory->numberOfItems = 0;

    return pBrowserHistory;
}

void destroyBrowserHistory(BrowserHistory* pBrowserHistory) {
    BrowserHistoryItem* pCurrent = pBrowserHistory->pHead;

    while (pCurrent != NULL) {
        BrowserHistoryItem* pNext = pCurrent->pNext;
        destroyBrowserHistoryItem(pCurrent);
        pCurrent = pNext;
    }
    free(pBrowserHistory);
}

void pushBrowserHistoryItem(BrowserHistory* pBrowserHistory, BrowserHistoryItem* pBrowserHistoryItem) {
    if (pBrowserHistory == NULL || pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Error: NULL Pointer Browser History or Browser History Item. Pointer for Browser History or Browser History Item should not be NULL.\n");
        return;
    }

    if (pBrowserHistory->pHead == NULL) {
        pBrowserHistory->pHead = pBrowserHistoryItem;
        pBrowserHistory->pTail = pBrowserHistoryItem;
    }
    else {
        pBrowserHistoryItem->pNext = pBrowserHistory->pHead;
        pBrowserHistory->pHead->pPrevious = pBrowserHistoryItem;
        pBrowserHistory->pHead = pBrowserHistoryItem;
    }
    pBrowserHistory->numberOfItems++;
    pBrowserHistoryItem->browserHistoryItemId = pBrowserHistory->numberOfItems;
}

void deleteBrowserHistoryItem(BrowserHistory* pBrowserHistory, int browserHistoryItemId) {
    if (pBrowserHistory == NULL) {
        fprintf(stderr, "Error: NULL Pointer Browser History. Pointer for Browser History should not be NULL\n");
        return;
    }

    if (browserHistoryItemId < 1 || browserHistoryItemId >= pBrowserHistory->numberOfItems) {
        fprintf(stderr, "Error: Invalid Browser History Item ID. Browser History Item ID should be between 0 and %d\n", pBrowserHistory->numberOfItems - 1);
        return;
    }

    if (pBrowserHistory->pHead == NULL) {
        fprintf(stderr, "Error: Empty Browser History. Browser History should be empty for deletion.\n");
        return;
    }

    BrowserHistoryItem* pCurrentBHItem = NULL;
    int stepsFromHead = browserHistoryItemId - 1;
    int stepsFromTail = pBrowserHistory->numberOfItems - 1 - browserHistoryItemId;

    if (stepsFromHead <= stepsFromTail) {
        pCurrentBHItem = pBrowserHistory->pHead;
        for (int steps = 0; steps < browserHistoryItemId; steps++) {
            if (pCurrentBHItem != NULL) {
                pCurrentBHItem = pCurrentBHItem->pNext;
            }
        }
    }
    else {
        pCurrentBHItem = pBrowserHistory->pTail;
        for (int steps = 0; steps < stepsFromTail; steps++) {
            if (pCurrentBHItem != NULL) {
                pCurrentBHItem = pCurrentBHItem->pPrevious;
            }
        }
    }

    if (pCurrentBHItem != NULL && pCurrentBHItem->browserHistoryItemId == browserHistoryItemId) {
        if (pCurrentBHItem->pPrevious != NULL) {
            pCurrentBHItem->pPrevious->pNext = pCurrentBHItem->pNext;
        }
        else {
            pBrowserHistory->pHead = pCurrentBHItem->pNext;
        }

        if (pCurrentBHItem->pNext != NULL) {
            pCurrentBHItem->pNext->pPrevious = pCurrentBHItem->pPrevious;
        }
        else {
            pBrowserHistory->pTail = pCurrentBHItem->pPrevious;
        }

        BrowserHistoryItem* pToBeUpdatedBHItem = pCurrentBHItem->pNext;

        destroyBrowserHistoryItem(pCurrentBHItem);
        pBrowserHistory->numberOfItems--;

        while (pToBeUpdatedBHItem != NULL) {
            pToBeUpdatedBHItem->browserHistoryItemId--;
            pToBeUpdatedBHItem = pToBeUpdatedBHItem->pNext;
        }
    }
}


