#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void moveActiveWindow(int xOffset) {
    HWND hwnd = GetForegroundWindow();
    if (hwnd == NULL) 
    {
        printf("error_0\n");
        return;
    }

    RECT rect;
    if (GetWindowRect(hwnd, &rect)) 
    {
        int newX = rect.left + xOffset;
        int newY = rect.top;

        SetWindowPos(hwnd, NULL, newX, newY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    } 
    else 
    {
        printf("error_1\n");
    }
}

void print_help() 
{
    printf("Usage: program [OPTION]...\n");
    printf("Options:\n");
    printf("  0 or 1        Set ONLY_LEFT to 1 to enable it, 0 otherwise (default is 0)\n");
    printf("  <way_value>   Set the WAY integer value, defaults to 100\n");
    printf("  -1            Display this help message and exit\n");
}

int main(int argc, char* argv[]) 
{
    int ONLY_LEFT = 0;
    int WAY = 100;


    if (argc > 1) 
    {
        if (atoi(argv[1]) == -1) 
        {
            print_help();
            return 0;
        }
        if (atoi(argv[1]) == 1) 
        {
            ONLY_LEFT = 1;
        }
    }

    if (argc > 2)
    {
        WAY = atoi(argv[2]);
    }
    

    while (1)
    {
        moveActiveWindow(-WAY);
        

        if (ONLY_LEFT == 0) moveActiveWindow(WAY);
    }
    

    return 0;
}
