#include "Header.h"

HWND hEmptyButton[X_CORD * Y_CORD];
HWND hButton[X_CORD * Y_CORD];
HWND hRepeatable[(X_CORD * Y_CORD)/2];
HWND hMineButtons[N_MINES];
HWND Reset{};
int n_EmptyButtons = 0;
int n_Buttons = 0;
int n_Repeat = 0;
int n_MineButtons = 0;

LRESULT CALLBACK WinProc0(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {

	case WM_CREATE: {
		Reset = CreateWindowEx(0, L"Button", L"R", WS_CHILD | WS_BORDER | WS_VISIBLE | BS_CENTER, (60 + (X_CORD * 20)) / 2 - 20, 10, 25, 25, hWnd, reinterpret_cast<HMENU>(88), nullptr, nullptr);
		FrameWnd(L"MyFrameClass", L"", hWnd, WinProc1);
		return 0;
	}

	case WM_COMMAND: {
		switch (LOWORD(wParam)) {

		case 88: {
			n_MineButtons = 0;
			n_Repeat = 0;
			n_EmptyButtons = 0;
			n_Buttons = 0;
			EnumChildWindows(hWnd, DestoryChildCallback, NULL);
			FrameWnd(L"MyFrameClass", L"", hWnd, WinProc1);
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
					if (IsMine(hButton[p])) {
						ShowWindow(hButton[p], SW_HIDE);
						DisplayMessageBox(hWnd);
						break;
					}
					else {
						HideAllEmpty(hButton[p], p);
						break;
					}
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

void HideAllEmpty(HWND hWnd, int l) {
	if (IsEmpty(hWnd) && !IsRepeat(hWnd)) {
		hRepeatable[n_Repeat] = hWnd;
		n_Repeat++;
		if (l == 0) {
			HideAllEmpty(hButton[l + (Y_CORD + 1)], l + (Y_CORD + 1));
			HideAllEmpty(hButton[l + Y_CORD], l + Y_CORD);
			HideAllEmpty(hButton[l + 1], l + 1);
		}
		else if (l == Y_CORD - 1) {
			HideAllEmpty(hButton[l + Y_CORD], l + Y_CORD);
			HideAllEmpty(hButton[l + (Y_CORD - 1)], l + (Y_CORD - 1));
			HideAllEmpty(hButton[l - 1], l - 1);
		}
		else if (l == Y_CORD * (X_CORD - 1)) {
			HideAllEmpty(hButton[l - Y_CORD], l - Y_CORD);
			HideAllEmpty(hButton[l - (Y_CORD - 1)], l - (Y_CORD - 1));
			HideAllEmpty(hButton[l + 1], l + 1);
		}
		else if (l == X_CORD * Y_CORD - 1) {
			HideAllEmpty(hButton[l - (Y_CORD + 1)], l - (Y_CORD + 1));
			HideAllEmpty(hButton[l - Y_CORD], l - Y_CORD);
			HideAllEmpty(hButton[l - 1], l - 1);
		}
		else if (l > 0 && l < Y_CORD - 1) {
			HideAllEmpty(hButton[l + (Y_CORD + 1)], l + (Y_CORD + 1));
			HideAllEmpty(hButton[l + Y_CORD], l + Y_CORD);
			HideAllEmpty(hButton[l + (Y_CORD - 1)], l + (Y_CORD - 1));
			HideAllEmpty(hButton[l - 1], l - 1);
			HideAllEmpty(hButton[l + 1], l + 1);
		}
		else if (l > Y_CORD * (X_CORD - 1) && l < X_CORD * Y_CORD - 1) {
			HideAllEmpty(hButton[l - (Y_CORD + 1)], l - (Y_CORD + 1));
			HideAllEmpty(hButton[l - Y_CORD], l - Y_CORD);
			HideAllEmpty(hButton[l - (Y_CORD - 1)], l - (Y_CORD - 1));
			HideAllEmpty(hButton[l - 1], l - 1);
			HideAllEmpty(hButton[l + 1], l + 1);
		}
		else if (l % Y_CORD == 0 && l != 0 && l != Y_CORD * (X_CORD - 1)) {
			HideAllEmpty(hButton[l - Y_CORD], l - Y_CORD);
			HideAllEmpty(hButton[l - (Y_CORD - 1)], l - (Y_CORD - 1));
			HideAllEmpty(hButton[l + (Y_CORD + 1)], l + (Y_CORD + 1));
			HideAllEmpty(hButton[l + Y_CORD], l + Y_CORD);
			HideAllEmpty(hButton[l + 1], l + 1);
		}
		else if ((l - (Y_CORD - 1)) % Y_CORD == 0 && l != (Y_CORD - 1) && l != ((X_CORD * Y_CORD) - 1)) {
			HideAllEmpty(hButton[l - (Y_CORD + 1)], l - (Y_CORD + 1));
			HideAllEmpty(hButton[l - Y_CORD], l - Y_CORD);
			HideAllEmpty(hButton[l + Y_CORD], l + Y_CORD);
			HideAllEmpty(hButton[l + (Y_CORD - 1)], l + (Y_CORD - 1));
			HideAllEmpty(hButton[l - 1], l - 1);
		}
		else {
			HideAllEmpty(hButton[l - (Y_CORD + 1)], l - (Y_CORD + 1));
			HideAllEmpty(hButton[l - Y_CORD], l - Y_CORD);
			HideAllEmpty(hButton[l - (Y_CORD - 1)], l - (Y_CORD - 1));
			HideAllEmpty(hButton[l + (Y_CORD + 1)], l + (Y_CORD + 1));
			HideAllEmpty(hButton[l + Y_CORD], l + Y_CORD);
			HideAllEmpty(hButton[l + (Y_CORD - 1)], l + (Y_CORD - 1));
			HideAllEmpty(hButton[l - 1], l - 1);
			HideAllEmpty(hButton[l + 1], l + 1);
		}
		ShowWindow(hWnd, SW_HIDE);
	}
	else {
		ShowWindow(hWnd, SW_HIDE);
	}
}

bool IsEmpty(HWND hWnd) {
	bool flag = 0;

	for (int l = 0; l < n_EmptyButtons; l++) {
		if (hWnd == hEmptyButton[l]) {
			flag = 1;
		}
	}
	return flag;
}

bool IsRepeat(HWND hWnd) {
	bool flag = 0;

	for (int l = 0; l < n_Repeat; l++) {
		if (hWnd == hRepeatable[l]) {
			flag = 1;
		}
	}
	return flag;
}

bool IsMine(HWND hWnd) {
	bool flag = 0;

	for (int l = 0; l < n_MineButtons; l++) {
		if (hWnd == hMineButtons[l]) {
			flag = 1;
		}
	}
	return flag;
}

int DisplayMessageBox(HWND hWnd) {
	int msgboxID = MessageBox(
		hWnd,
		L"Opps!",
		L"You Faild!",
		MB_RETRYCANCEL
	);

	switch (msgboxID)
	{
	case IDCANCEL:
		PostQuitMessage(0);
		break;
	case IDRETRY:
		n_MineButtons = 0;
		n_Repeat = 0;
		n_EmptyButtons = 0;
		n_Buttons = 0;
		EnumChildWindows(hWnd, DestoryChildCallback, NULL);
		Field(hWnd);
		break;
	}

	return msgboxID;
}
