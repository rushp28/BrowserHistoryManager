#ifndef BROWSERHISTORYMANAGER_BROWSERHISTORYITEM_H
#define BROWSERHISTORYMANAGER_BROWSERHISTORYITEM_H

#include "date.h"
#include "webPage.h"

// BrowserHistoryItem struct

/*
 * @brief BrowserHistoryItem struct to represent a browser history item
 *
 * @var browserHistoryItemId - the ID of the browser history item
 * @var pWebPage             - the web page of the browser history item
 * @var visitedDate          - the visited date of the browser history item
 * @var pNext                - a pointer to the next browser history item
 * @var pPrevious            - a pointer to the previous browser history item
 */
typedef struct BrowserHistoryItem {
    unsigned int browserHistoryItemId;
    WebPage* pWebPage;
    Date* visitedDate;
    struct BrowserHistoryItem* pNext;
    struct BrowserHistoryItem* pPrevious;
} BrowserHistoryItem;


// BrowserHistoryItem function prototypes

/*
 * @brief creates a BrowserHistoryItem object with the given web page and date visited
 *
 * @param pWebPage     - the web page of the browser history item
 * @param pVisitedDate - the date visited of the browser history item
 *
 * @returns a BrowserHistoryItem object pointer if the browser history item is valid, otherwise NULL
 */
BrowserHistoryItem* createBrowserHistoryItem(WebPage* pWebPage, Date* pVisitedDate);

/*
 * @brief destroys the given BrowserHistoryItem object
 *
 * @param pBrowserHistoryItem - the pointer to the BrowserHistoryItem object to destroy
 */
void destroyBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem);

/*
 * @brief prints the given BrowserHistoryItem object
 *
 * @param pBrowserHistoryItem - the pointer to the BrowserHistoryItem object to print
 */
void printBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem);

#endif //BROWSERHISTORYMANAGER_BROWSERHISTORYITEM_H
