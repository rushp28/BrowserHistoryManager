#include <stdio.h>

#include "date.h"
#include "webPage.h"
#include "browserHistoryItem.h"
#include "browserHistory.h"

int main() {
    BrowserHistory* pBrowserHistory = createBrowserHistory();
    if (pBrowserHistory == NULL)
    {
        return 1;
    }

    BrowserHistoryItem* pItem1 = createBrowserHistoryItem(createWebPage("Stackoverflow", "003D", "https://stackoverflow.com/", false), createDate(5, 8, 2023));
    BrowserHistoryItem* pItem2 = createBrowserHistoryItem(createWebPage("Tutorialspoint", "012C", "https://www.tutorialspoint.com/index.htm", true), createDate(6, 8, 2023));
    BrowserHistoryItem* pItem3 = createBrowserHistoryItem(createWebPage("GeeksforGeeks", "011B", "https://www.geeksforgeeks.org/", true), createDate(9, 8, 2023));
    BrowserHistoryItem* pItem4 = createBrowserHistoryItem(createWebPage("YouTube", "001A", "https://www.youtube.com/", false), createDate(10, 8, 2023));

    if(pItem1 == NULL || pItem2 == NULL || pItem3 == NULL || pItem4 == NULL)
    {
        return 1;
    }

    pushBrowserHistoryItem(pBrowserHistory, pItem1);
    pushBrowserHistoryItem(pBrowserHistory, pItem2);
    pushBrowserHistoryItem(pBrowserHistory, pItem3);
    pushBrowserHistoryItem(pBrowserHistory, pItem4);

    printBrowserHistory(pBrowserHistory, false, false);

    printBrowserHistory(pBrowserHistory, true, false);

    printBrowserHistory(pBrowserHistory, false, true);

    deleteBrowserHistoryItem(pBrowserHistory, 3);

    fprintf(stdout, "AFTER DELETING BROWSER HISTORY ITEM 3\n");
    printBrowserHistory(pBrowserHistory, false, false);

    deleteBrowserHistoryItem(pBrowserHistory, 1);

    fprintf(stdout, "AFTER DELETING BROWSER HISTORY ITEM 1\n");
    printBrowserHistory(pBrowserHistory, false, false);

    destroyBrowserHistory(pBrowserHistory);

    return 0;
}