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

#endif //BROWSERHISTORYMANAGER_BROWSERHISTORY_H
