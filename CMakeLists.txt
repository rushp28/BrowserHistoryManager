cmake_minimum_required(VERSION 3.27)
project(BrowserHistoryManager C)

set(CMAKE_C_STANDARD 17)

add_executable(BrowserHistoryManager main.c
        date.c
        date.h
        webPage.c
        webPage.h
        browserHistoryItem.c
        browserHistoryItem.h
        browserHistory.c
        browserHistory.h
)
