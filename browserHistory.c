#include <stdio.h>
#include <malloc.h>

#include "browserHistory.h"

BrowserHistory* createBrowserHistory() {
    BrowserHistory* pBrowserHistory = (BrowserHistory*)calloc(1, sizeof(BrowserHistory));
    if (pBrowserHistory == NULL) {
        fprintf(stderr, "Memory Allocation for Browser History Failed. Creating Browser History object failed.\n");
        return NULL;
    }

    pBrowserHistory->pHead = NULL;
    pBrowserHistory->pTail = NULL;
    pBrowserHistory->numberOfItems = 0;

    return pBrowserHistory;
}

void destroyBrowserHistory(BrowserHistory* pBrowserHistory) {
    if (pBrowserHistory == NULL) {
        fprintf(stderr, "Error: NULL Pointer Browser History. Pointer for Browser History should not be NULL. Destroying Browser History object failed.\n");
        return;
    }

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
        fprintf(stderr, "Error: NULL Pointer Browser History or Browser History Item. Pointer for Browser History or Browser History Item should not be NULL. Pushing Browser History Item failed.\n");
        return;
    }

    if (pBrowserHistory->pHead == NULL) {
        pBrowserHistory->pHead = pBrowserHistoryItem;
        pBrowserHistory->pTail = pBrowserHistoryItem;
    }
    else {
        if (pBrowserHistory->numberOfItems >= MAX_BROWSER_HISTORY_LENGTH) {
            fprintf(stderr, "Error: Browser History is Full. Browser History should not exceed %d items. Pushing Browser History Item failed.\n", MAX_BROWSER_HISTORY_LENGTH);

            destroyWebPage(pBrowserHistoryItem->pWebPage);
            destroyDate(pBrowserHistoryItem->dateVisited);

            return;
        }

        pBrowserHistoryItem->pNext = pBrowserHistory->pHead;
        pBrowserHistory->pHead->pPrevious = pBrowserHistoryItem;
        pBrowserHistory->pHead = pBrowserHistoryItem;
    }
    pBrowserHistory->numberOfItems++;
    pBrowserHistoryItem->browserHistoryItemId = pBrowserHistory->numberOfItems;
}

void deleteBrowserHistoryItem(BrowserHistory* pBrowserHistory, int browserHistoryItemId) {
    if (pBrowserHistory == NULL) {
        fprintf(stderr, "Error: NULL Pointer Browser History. Pointer for Browser History should not be NULL. Deleting Browser History Item failed.\n");
        return;
    }

    if (browserHistoryItemId < 1 || browserHistoryItemId >= pBrowserHistory->numberOfItems) {
        fprintf(stderr, "Error: Invalid Browser History Item ID. Browser History Item ID should be between 0 and %d. Deleting Browser History Item failed.\n", pBrowserHistory->numberOfItems);
        return;
    }

    if (pBrowserHistory->pHead == NULL) {
        fprintf(stderr, "Error: Empty Browser History. Browser History should be not be empty. Deleting Browser History Item failed.\n");
        return;
    }

    BrowserHistoryItem* pCurrentBHItem = NULL;
    int stepsFromHead = pBrowserHistory->numberOfItems - browserHistoryItemId;
    int stepsFromTail = browserHistoryItemId - 1;

    if (stepsFromHead <= stepsFromTail) {

        pCurrentBHItem = pBrowserHistory->pHead;
        for (int steps = 0; steps < stepsFromHead; steps++) {
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

        BrowserHistoryItem* pToBeUpdatedBHItem = pCurrentBHItem->pPrevious;

        destroyBrowserHistoryItem(pCurrentBHItem);
        pBrowserHistory->numberOfItems--;

        while (pToBeUpdatedBHItem != NULL) {
            pToBeUpdatedBHItem->browserHistoryItemId--;
            pToBeUpdatedBHItem = pToBeUpdatedBHItem->pPrevious;
        }
    }
}

void printBrowserHistory(BrowserHistory* pBrowserHistory, bool reversed, bool bookmarkedOnly) {
    if (pBrowserHistory == NULL) {
        fprintf(stderr, "Error: NULL Pointer Browser History. Pointer for Browser History should not be NULL. Printing Browser History failed.\n");
        return;
    }

    if (pBrowserHistory->pHead == NULL) {
        fprintf(stderr, "Error: Empty Browser History. Browser History should not be empty. Printing Browser History failed.\n");
        return;
    }

    if (reversed) {
        fprintf(stdout, "REVERSED\n");
        fflush(stdout);
    }
    else {
        fprintf(stdout, "NORMAL\n");
        fflush(stdout);
    }
    if (bookmarkedOnly) {
        fprintf(stdout, "BOOKMARKED ONLY\n");
        fflush(stdout);
    }

    fprintf(stdout, "| %-3s | %-15s | %-10s | %-10s | %-45s | %-10s |\n",
           "ID",
           "Page Name",
           "Page ID",
           "Date Visited",
           "Site URL",
           "Bookmarked");
    fflush(stdout);

    BrowserHistoryItem* pCurrentBHItem = NULL;
    if (reversed) {
        pCurrentBHItem = pBrowserHistory->pTail;
    }
    else {
        pCurrentBHItem = pBrowserHistory->pHead;
    }

    while (pCurrentBHItem != NULL) {
        if (bookmarkedOnly) {
            if (pCurrentBHItem->pWebPage->isBookmarked) {
                printBrowserHistoryItem(pCurrentBHItem);
            }
        }
        else {
            printBrowserHistoryItem(pCurrentBHItem);
        }

        if (reversed) {
            pCurrentBHItem = pCurrentBHItem->pPrevious;
        }
        else {
            pCurrentBHItem = pCurrentBHItem->pNext;
        }
    }
}

