#include <Windows.h>

int main()
{
    int x = 1260;
    int y = 1420;
    int time = 5000;

    while (true) {
        SetCursorPos(x, y);

        mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

        Sleep(time);
    }
}
