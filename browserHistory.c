#include <stdio.h>
#include <malloc.h>

#include "browserHistory.h"

// BrowserHistory function definitions

BrowserHistory* createBrowserHistory() {
    // Allocate memory for the BrowserHistory object
    BrowserHistory* pBrowserHistory = (BrowserHistory*)calloc(1, sizeof(BrowserHistory));
    // Check if memory allocation fails
    if (pBrowserHistory == NULL) {
        fprintf(stderr, "Memory Allocation for Browser History Failed. Creating Browser History object failed.\n");
        return NULL;
    }

    // Set the head and tail pointers of the BrowserHistory object to NULL
    pBrowserHistory->pHead = NULL;
    pBrowserHistory->pTail = NULL;
    pBrowserHistory->numberOfItems = 0;

    // Return the BrowserHistory object pointer
    return pBrowserHistory;
}

void destroyBrowserHistory(BrowserHistory* pBrowserHistory) {
    // Check if the BrowserHistory object pointer is NULL
    if (pBrowserHistory == NULL) {
        fprintf(stderr, "Error: NULL Pointer Browser History. Pointer for Browser History should not be NULL. Destroying Browser History object failed.\n");
        return;
    }

    // Destroy all the BrowserHistoryItem objects in the BrowserHistory object
    BrowserHistoryItem* pCurrent = pBrowserHistory->pHead;
    while (pCurrent != NULL) {
        BrowserHistoryItem* pNext = pCurrent->pNext;
        destroyBrowserHistoryItem(pCurrent);
        pCurrent = pNext;
    }

    // Free the memory allocated for the BrowserHistory object
    free(pBrowserHistory);
}

void pushBrowserHistoryItem(BrowserHistory* pBrowserHistory, BrowserHistoryItem* pBrowserHistoryItem) {
    // Check if the BrowserHistory or BrowserHistoryItem object pointers are NULL
    if (pBrowserHistory == NULL || pBrowserHistoryItem == NULL) {
        fprintf(stderr, "Error: NULL Pointer Browser History or Browser History Item. Pointer for Browser History or Browser History Item should not be NULL. Pushing Browser History Item failed.\n");
        return;
    }

    // Check if the BrowserHistory object is empty
    if (pBrowserHistory->pHead == NULL) {
        // Set the head and tail pointers to the BrowserHistoryItem object
        pBrowserHistory->pHead = pBrowserHistoryItem;
        pBrowserHistory->pTail = pBrowserHistoryItem;
    }
    else {
        // Check if the Browser History is full
        if (pBrowserHistory->numberOfItems >= MAX_BROWSER_HISTORY_LENGTH) {
            fprintf(stderr, "Error: Browser History is Full. Browser History should not exceed %d items. Pushing Browser History Item failed.\n", MAX_BROWSER_HISTORY_LENGTH);

            // Free the memory allocated for the BrowserHistoryItem object
            destroyWebPage(pBrowserHistoryItem->pWebPage);
            destroyDate(pBrowserHistoryItem->visitedDate);
            destroyBrowserHistoryItem(pBrowserHistoryItem);

            return;
        }

        // Set the next pointer of the BrowserHistoryItem object to the head of the BrowserHistory object
        pBrowserHistoryItem->pNext = pBrowserHistory->pHead;
        // Set the previous pointer of the head of the BrowserHistory object to the BrowserHistoryItem object
        pBrowserHistory->pHead->pPrevious = pBrowserHistoryItem;
        // Set the head pointer of the BrowserHistory object to the BrowserHistoryItem object
        pBrowserHistory->pHead = pBrowserHistoryItem;
    }

    // Increment the number of items in the BrowserHistory object
    pBrowserHistory->numberOfItems++;
    // Set the Browser History Item ID
    pBrowserHistoryItem->browserHistoryItemId = pBrowserHistory->numberOfItems;
}

void deleteBrowserHistoryItem(BrowserHistory* pBrowserHistory, int browserHistoryItemId) {
    // Check if the BrowserHistory object pointer is NULL
    if (pBrowserHistory == NULL) {
        fprintf(stderr, "Error: NULL Pointer Browser History. Pointer for Browser History should not be NULL. Deleting Browser History Item failed.\n");
        return;
    }

    // Check if the Browser History Item ID is invalid
    if (browserHistoryItemId < 1 || browserHistoryItemId >= pBrowserHistory->numberOfItems) {
        fprintf(stderr, "Error: Invalid Browser History Item ID. Browser History Item ID should be between 0 and %d. Deleting Browser History Item failed.\n", pBrowserHistory->numberOfItems);
        return;
    }

    // Check if the BrowserHistory object is empty
    if (pBrowserHistory->pHead == NULL) {
        fprintf(stderr, "Error: Empty Browser History. Browser History should be not be empty. Deleting Browser History Item failed.\n");
        return;
    }

    // Calculate the steps from the head and tail of the BrowserHistory object
    BrowserHistoryItem* pCurrentBHItem = NULL;
    int stepsFromHead = pBrowserHistory->numberOfItems - browserHistoryItemId;
    int stepsFromTail = browserHistoryItemId - 1;

    // Find the BrowserHistoryItem object to delete
    if (stepsFromHead <= stepsFromTail) {
        // Find the BrowserHistoryItem object from the head
        pCurrentBHItem = pBrowserHistory->pHead;
        for (int steps = 0; steps < stepsFromHead; steps++) {
            if (pCurrentBHItem != NULL) {
                pCurrentBHItem = pCurrentBHItem->pNext;
            }
        }
    }
    else {
        // Find the BrowserHistoryItem object from the tail
        pCurrentBHItem = pBrowserHistory->pTail;
        for (int steps = 0; steps < stepsFromTail; steps++) {
            if (pCurrentBHItem != NULL) {
                pCurrentBHItem = pCurrentBHItem->pPrevious;
            }
        }
    }

    // Check if the BrowserHistoryItem object is found
    if (pCurrentBHItem != NULL && pCurrentBHItem->browserHistoryItemId == browserHistoryItemId) {
        // Check if the BrowserHistoryItem object is the head of the BrowserHistory object
        if (pCurrentBHItem->pPrevious != NULL) {
            // Set the next pointer of the previous BrowserHistoryItem object of the BrowserHistoryItem object to be deleted to the next BrowserHistoryItem object of the BrowserHistoryItem object to be deleted
            pCurrentBHItem->pPrevious->pNext = pCurrentBHItem->pNext;
        }
        else {
            // Set the head pointer of the BrowserHistory object to the next BrowserHistoryItem object of the BrowserHistoryItem object to be deleted
            pBrowserHistory->pHead = pCurrentBHItem->pNext;
        }

        // Check if the BrowserHistoryItem object is the tail of the BrowserHistory object
        if (pCurrentBHItem->pNext != NULL) {
            // Set the previous pointer of the next BrowserHistoryItem object of the BrowserHistoryItem object to be deleted to the previous BrowserHistoryItem object of the BrowserHistoryItem object to be deleted
            pCurrentBHItem->pNext->pPrevious = pCurrentBHItem->pPrevious;
        }
        else {
            // Set the tail pointer of the BrowserHistory object to the previous BrowserHistoryItem object of the BrowserHistoryItem object to be deleted
            pBrowserHistory->pTail = pCurrentBHItem->pPrevious;
        }

        // Get the BrowserHistoryItem object to update the Browser History Item ID
        BrowserHistoryItem* pToBeUpdatedBHItem = pCurrentBHItem->pPrevious;

        // Free the memory allocated for the BrowserHistoryItem object
        destroyBrowserHistoryItem(pCurrentBHItem);
        // Decrement the number of items in the BrowserHistory object
        pBrowserHistory->numberOfItems--;

        // Update the Browser History Item IDs
        while (pToBeUpdatedBHItem != NULL) {
            pToBeUpdatedBHItem->browserHistoryItemId--;
            pToBeUpdatedBHItem = pToBeUpdatedBHItem->pPrevious;
        }
    }
}

void printBrowserHistory(BrowserHistory* pBrowserHistory, bool reversed, bool bookmarkedOnly) {
    // Check if the BrowserHistory object pointer is NULL
    if (pBrowserHistory == NULL) {
        fprintf(stderr, "Error: NULL Pointer Browser History. Pointer for Browser History should not be NULL. Printing Browser History failed.\n");
        return;
    }

    // Check if the BrowserHistory object is empty
    if (pBrowserHistory->pHead == NULL) {
        fprintf(stderr, "Error: Empty Browser History. Browser History should not be empty. Printing Browser History failed.\n");
        return;
    }

    // Print the title for the Browser History
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

    // Print the Browser History Table Header
    fprintf(stdout, "| %-3s | %-15s | %-10s | %-10s | %-45s | %-10s |\n",
           "ID",
           "Page Name",
           "Page ID",
           "Date Visited",
           "Site URL",
           "Bookmarked");
    fflush(stdout);

    BrowserHistoryItem* pCurrentBHItem = NULL;
    // Check if the Browser History is to be printed in reverse order
    if (reversed) {
        pCurrentBHItem = pBrowserHistory->pTail;
    }
    else {
        pCurrentBHItem = pBrowserHistory->pHead;
    }

    // Print the Browser History Items
    while (pCurrentBHItem != NULL) {
        // Check if only bookmarked items are to be printed
        if (bookmarkedOnly) {
            // Check if the Web Page is bookmarked
            if (pCurrentBHItem->pWebPage->isBookmarked) {
                printBrowserHistoryItem(pCurrentBHItem);
            }
        }
        else {
            printBrowserHistoryItem(pCurrentBHItem);
        }

        // Check if the Browser History is to be printed in reverse order
        if (reversed) {
            pCurrentBHItem = pCurrentBHItem->pPrevious;
        }
        else {
            pCurrentBHItem = pCurrentBHItem->pNext;
        }
    }
}

