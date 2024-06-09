#ifndef BROWSERHISTORYMANAGER_BROWSERHISTORY_H
#define BROWSERHISTORYMANAGER_BROWSERHISTORY_H

#include "browserHistoryItem.h"

// Constants

/*
 * @brief the maximum length of the browser history
 */
#define MAX_BROWSER_HISTORY_LENGTH 100

// BrowserHistory struct

/*
 * @brief a BrowserHistory struct to represent a browser history
 *
 * @var pHead          - a pointer to the head of the browser history
 * @var pTail          - a pointer to the tail of the browser history
 * @var numberOfItems  - the number of items in the browser history
 */
typedef struct BrowserHistory {
    BrowserHistoryItem* pHead;
    BrowserHistoryItem* pTail;
    int numberOfItems;
} BrowserHistory;

// BrowserHistory function prototypes

/*
 * @brief creates a BrowserHistory object
 *
 * @returns a pointer to the BrowserHistory object
 */
BrowserHistory* createBrowserHistory();

/*
 * @brief destroys the given BrowserHistory object
 *
 * @param pBrowserHistory - pointer to the BrowserHistory object to destroy
 */
void destroyBrowserHistory(BrowserHistory* pBrowserHistory);

/*
 * @brief pushes the given BrowserHistoryItem object to the given BrowserHistory object
 *
 * @param pBrowserHistory      - pointer to the BrowserHistory object
 * @param pBrowserHistoryItem  - pointer to the BrowserHistoryItem object
 */
void pushBrowserHistoryItem(BrowserHistory* pBrowserHistory, BrowserHistoryItem* pBrowserHistoryItem);

/*
 * @brief deletes the BrowserHistoryItem object with the given ID from the given BrowserHistory object
 *
 * @param pBrowserHistory      - pointer to the BrowserHistory object
 * @param browserHistoryItemId - the ID of the BrowserHistoryItem object to delete
 */
void deleteBrowserHistoryItem(BrowserHistory* pBrowserHistory, int browserHistoryItemId);

/*
 * @brief prints the given BrowserHistory object
 *
 * @param pBrowserHistory - pointer to the BrowserHistory object to print
 * @param reversed        - whether to print the browser history in reverse order
 * @param bookmarkedOnly  - whether to print only bookmarked items
 */
void printBrowserHistory(BrowserHistory* pBrowserHistory, bool reversed, bool bookmarkedOnly);

#endif //BROWSERHISTORYMANAGER_BROWSERHISTORY_H
