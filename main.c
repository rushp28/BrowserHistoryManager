#include <stdio.h>

#include "date.h"
#include "webPage.h"
#include "browserHistoryItem.h"
#include "browserHistory.h"

int main() {
    // Create a BrowserHistory object
    BrowserHistory* pBrowserHistory = createBrowserHistory();
    if (pBrowserHistory == NULL)
    {
        return 1;
    }

    // Create BrowserHistoryItem objects
    BrowserHistoryItem* pItem1 = createBrowserHistoryItem(createWebPage("Stackoverflow", "003D", "https://stackoverflow.com/", false), createDate(5, 8, 2023));
    BrowserHistoryItem* pItem2 = createBrowserHistoryItem(createWebPage("Tutorialspoint", "012C", "https://www.tutorialspoint.com/index.htm", true), createDate(6, 8, 2023));
    BrowserHistoryItem* pItem3 = createBrowserHistoryItem(createWebPage("GeeksforGeeks", "011B", "https://www.geeksforgeeks.org/", true), createDate(9, 8, 2023));
    BrowserHistoryItem* pItem4 = createBrowserHistoryItem(createWebPage("YouTube", "001A", "https://www.youtube.com/", false), createDate(10, 8, 2023));
    if(pItem1 == NULL || pItem2 == NULL || pItem3 == NULL || pItem4 == NULL)
    {
        return 1;
    }

    // Push BrowserHistoryItem objects to BrowserHistory object
    pushBrowserHistoryItem(pBrowserHistory, pItem1);
    pushBrowserHistoryItem(pBrowserHistory, pItem2);
    pushBrowserHistoryItem(pBrowserHistory, pItem3);
    pushBrowserHistoryItem(pBrowserHistory, pItem4);

    // Print BrowserHistory object
    printBrowserHistory(pBrowserHistory, false, false);

    // Print BrowserHistory object in reverse order
    printBrowserHistory(pBrowserHistory, true, false);

    // Print BrowserHistory object with only bookmarked items
    printBrowserHistory(pBrowserHistory, false, true);

    // Delete BrowserHistoryItem objects and print BrowserHistory object
    deleteBrowserHistoryItem(pBrowserHistory, 3);
    fprintf(stdout, "AFTER DELETING BROWSER HISTORY ITEM 3\n");
    fflush(stdout);
    printBrowserHistory(pBrowserHistory, false, false);

    deleteBrowserHistoryItem(pBrowserHistory, 1);
    fprintf(stdout, "AFTER DELETING BROWSER HISTORY ITEM 1\n");
    fflush(stdout);
    printBrowserHistory(pBrowserHistory, false, false);

    // Destroy BrowserHistory object
    destroyBrowserHistory(pBrowserHistory);

    // Pause the Console
    printf("\nPress Enter to Continue...");
    getchar();

    // Return 0 to indicate successful completion
    return 0;
}