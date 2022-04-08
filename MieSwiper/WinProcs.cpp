#include "Header.h"

int n_Buttons = 0;
HWND hButton[X_CORD * Y_CORD];
int MouseButton = 0;
HWND hChildWnd{}, Reset{};

LRESULT CALLBACK WinProc0(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CREATE: {
		Reset = CreateWindowEx(0, L"Button", L"R", WS_CHILD | WS_BORDER | WS_VISIBLE | BS_CENTER, (60 + (X_CORD * 20)) / 2 - 20, 10, 25, 25, hWnd, reinterpret_cast<HMENU>(88), nullptr, nullptr);
		if (hChildWnd) DestroyWindow(hChildWnd);
		const auto [flag, hChild] = FrameWnd(L"MyFrameClass", L"", hWnd, WinProc1);
		return 0;
	}

	case WM_COMMAND: {
		switch (LOWORD(wParam)) {

		case 88: {
			EnumChildWindows(hWnd, DestoryChildCallback, NULL);
			if (hChildWnd) DestroyWindow(hChildWnd);
			const auto [flag, hChild] = FrameWnd(L"MyFrameClass", L"YO!", hWnd, WinProc1);
			break;
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

LRESULT CALLBACK WinProc1(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_CREATE: {
			Field(hWnd);
		return 0;
		}

		case WM_COMMAND: {
			for (int p = 0; p < n_Buttons; p++) {
				if ((HWND)lParam == hButton[p]) {
					ShowWindow(hButton[p], SW_HIDE);
					break;
				}
			}
			return 0;
		}
	return 0;
	}
return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

BOOL CALLBACK DestoryChildCallback(HWND hwnd, LPARAM lParam) {
	if (hwnd != NULL && hwnd != Reset)
		DestroyWindow(hwnd);
	return TRUE;
}
