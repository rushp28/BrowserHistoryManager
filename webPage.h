#ifndef BROWSERHISTORYMANAGER_WEBPAGE_H
#define BROWSERHISTORYMANAGER_WEBPAGE_H

#include <stdbool.h>

// Constants

/*
 * @brief the maximum length of a page ID
 */
#define MAX_PAGE_ID_LENGTH (4 + 1)

/*
 * @brief the maximum length of a page name
 */
#define MAX_PAGE_NAME_LENGTH (50 + 1)

/*
 * @brief the maximum length of a site URL
 */
#define MAX_SITE_URL_LENGTH (200 + 1)

// WebPage struct

/*
 * @brief WebPage struct to represent a web page
 *
 * @var pageId       - the ID of the web page
 * @var pageName     - the name of the web page
 * @var siteUrl      - the URL of the web page
 * @var isBookmarked - whether the web page is bookmarked
 */
typedef struct WebPage
{
    char pageId[MAX_PAGE_ID_LENGTH];
    char pageName[MAX_PAGE_NAME_LENGTH];
    char siteUrl[MAX_SITE_URL_LENGTH];
    bool isBookmarked;
} WebPage;

// WebPage function prototypes

/*
 * @brief creates a WebPage object with the given page name, page ID, site URL and bookmarked status
 *
 * @param pageName     - the name of the web page
 * @param pageId       - the ID of the web page
 * @param siteUrl      - the URL of the web page
 * @param isBookmarked - whether the web page is bookmarked
 *
 * @returns a WebPage object pointer if the web page is valid, otherwise NULL
 */
WebPage* createWebPage(char pageName[], char pageId[], char siteUrl[], bool isBookmarked);

/*
 * @brief destroys the given WebPage object
 *
 * @param pWebPage - the pointer to the WebPage object to destroy
 */
void destroyWebPage(WebPage* pWebPage);

/*
 * @brief checks if the given web page is valid
 *
 * @param pageName     - the name of the web page
 * @param pageId       - the ID of the web page
 * @param siteUrl      - the URL of the web page
 * @param isBookmarked - whether the web page is bookmarked
 *
 * @returns true if the web page is valid, otherwise false
 */
bool areValidWebPageDetails(char pageName[], char pageId[], char siteUrl[], bool isBookmarked);

#endif //BROWSERHISTORYMANAGER_WEBPAGE_H
