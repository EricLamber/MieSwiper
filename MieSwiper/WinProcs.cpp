#include "Header.h"

int n_Buttons = 0;
HWND hButton[X_CORD * Y_CORD];

LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CREATE: {
		Field(hWnd);
		Buttons(hWnd);
		return 0;
	}

	case WM_COMMAND: {
	case WM_LBUTTONUP: {
		for (int k = 0; k < n_Buttons; k++) {
			if ((HWND)lParam == hButton[k])
				SetWindowPos(hButton[k], nullptr, NULL, NULL, 20, 20, SWP_HIDEWINDOW);
		}
		return 0;
	}

	case WM_RBUTTONUP: {
		for (int k = 0; k < n_Buttons; k++) {
			if ((HWND)lParam == hButton[k])
				SetWindowTextA(hButton[k], "F");
		}
		return 0;
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
