#include <stdio.h>
#include <stdlib.h>

#include "mmshellhook.h"

int main(int argc, char *argv[])
{
    MSG			msg;

    if (argc != 2)
        return -1;


    HWND hWnd = (HWND)atol(argv[1]);

    printf("Adding hook for %d\n", (long)hWnd);

    SetMMShellHook(hWnd);

    bool done = false; //initialize loop condition variable
    /*	main message loop*/
    while(!done)
    {
        PeekMessage(&msg,NULL,NULL,NULL,PM_REMOVE);
        if (msg.message == WM_CLOSE) //check for a quit message
        {
            done = true; //if found, quit app
        }
        ::Sleep(100);
    }
    return msg.wParam;
}

