#include "Header.h"

int n_Buttons = 0;
HWND hButton[X_CORD * Y_CORD];

LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CREATE: 
		Field(hWnd);
		return 0;
	

	case WM_COMMAND: {
		switch (LOWORD(wParam)) {

		case 88: {
			EnumChildWindows(hWnd, DestoryChildCallback, NULL);
			Field(hWnd);
			break;
		}

		case BN_CLICKED: {
				for (int k = 0; k < n_Buttons; k++) {
					if ((HWND)lParam == hButton[k])
						ShowWindow(hButton[k], SW_HIDE);
				}
			}

		case BN_DOUBLECLICKED: {
				for (int k = 0; k < n_Buttons; k++) {
					if ((HWND)lParam == hButton[k])
						SetWindowTextA(hButton[k], "F");
				}
			}
		}
	return 0;
	}

	case WM_DESTROY: {
		PostQuitMessage(EXIT_SUCCESS);
	}
	return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

BOOL CALLBACK DestoryChildCallback(HWND hwnd, LPARAM lParam) {
	if (hwnd != NULL)
		DestroyWindow(hwnd);
	return TRUE;
}
