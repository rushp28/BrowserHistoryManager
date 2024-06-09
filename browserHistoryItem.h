#ifndef BROWSERHISTORYMANAGER_BROWSERHISTORYITEM_H
#define BROWSERHISTORYMANAGER_BROWSERHISTORYITEM_H

#include "date.h"
#include "webPage.h"

// BrowserHistoryItem struct

/*
 * @brief a BrowserHistoryItem struct to represent a browser history item
 *
 * @var browserHistoryItemId - the ID of the browser history item
 * @var pWebPage             - the web page of the browser history item
 * @var dateVisited          - the date visited of the browser history item
 * @var pNext                - a pointer to the next browser history item
 * @var pPrevious            - a pointer to the previous browser history item
 */
typedef struct BrowserHistoryItem {
    unsigned int browserHistoryItemId;
    WebPage* pWebPage;
    Date* dateVisited;
    struct BrowserHistoryItem* pNext;
    struct BrowserHistoryItem* pPrevious;
} BrowserHistoryItem;


// BrowserHistoryItem function prototypes

/*
 * @brief creates a BrowserHistoryItem object with the given web page and date visited
 *
 * @param pWebPage     - the web page of the browser history item
 * @param pDateVisited - the date visited of the browser history item
 *
 * @returns a pointer to the BrowserHistoryItem object if the browser history item is valid, otherwise NULL
 */
BrowserHistoryItem* createBrowserHistoryItem(WebPage* pWebPage, Date* pDateVisited);

/*
 * @brief destroys the given BrowserHistoryItem object
 *
 * @param pBrowserHistoryItem - pointer to the BrowserHistoryItem object to destroy
 */
void destroyBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem);

/*
 * @brief prints the given BrowserHistoryItem object
 *
 * @param pBrowserHistoryItem - pointer to the BrowserHistoryItem object to print
 */
void printBrowserHistoryItem(BrowserHistoryItem* pBrowserHistoryItem);

#endif //BROWSERHISTORYMANAGER_BROWSERHISTORYITEM_H
