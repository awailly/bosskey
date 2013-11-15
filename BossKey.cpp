// BossKey.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <tchar.h>
#include <windows.h>

int Hide(_TCHAR* name)
{
	HWND hwnd;

	hwnd = FindWindow(NULL, name);
	printf("Found: %X\n", hwnd);
	ShowWindow(hwnd, SW_HIDE);

	return 0;
}

int Show(_TCHAR* name)
{
	HWND hwnd;

	hwnd = FindWindow(NULL, name);
	printf("Found: %X\n", hwnd);
	ShowWindow(hwnd, SW_SHOW);

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MSG msg = {0};
	bool peek = 0;

	if (RegisterHotKey(
        NULL,
        1,
        NULL,
        222))  //0x42 is 'b'
    {
        _tprintf(_T("Hotkey 'ALT+b' registered, using MOD_NOREPEAT flag\n"));
    }

	printf("Lala\n");

    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {
            _tprintf(_T("WM_HOTKEY received\n"));

			if (peek)
			{
				Show(_T("Age of Empires II: HD Edition"));
				Show(_T("Steam"));
			}
			else
			{
				Hide(_T("Age of Empires II: HD Edition"));
				Hide(_T("Steam"));
			}

			peek = !peek;
        }
    } 

	return 0;
}