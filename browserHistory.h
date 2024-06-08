#ifndef BROWSERHISTORYMANAGER_BROWSERHISTORY_H
#define BROWSERHISTORYMANAGER_BROWSERHISTORY_H

#include "browserHistoryItem.h"

typedef struct BrowserHistory {
    BrowserHistoryItem* pHead;
    BrowserHistoryItem* pTail;
    int numberOfItems;
} BrowserHistory;

BrowserHistory* createBrowserHistory();

void destroyBrowserHistory(BrowserHistory* pBrowserHistory);

void pushBrowserHistoryItem(BrowserHistory* pBrowserHistory, BrowserHistoryItem* pBrowserHistoryItem);

void deleteBrowserHistoryItem(BrowserHistory* pBrowserHistory, int browserHistoryItemId);

void printBrowserHistory(BrowserHistory* pBrowserHistory, bool reversed, bool bookmarkedOnly);

#endif //BROWSERHISTORYMANAGER_BROWSERHISTORY_H
