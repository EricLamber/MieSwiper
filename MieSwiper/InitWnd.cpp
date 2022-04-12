#include "Header.h"

BOOL InitMainWnd(HWND hwnd, HINSTANCE hInstance, int nCmdShow) {
	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WinProc0;
	wc.lpszClassName = L"MyAppClass";
	wc.lpszMenuName = nullptr;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&wc))
		return EXIT_FAILURE;

	if (hwnd = CreateWindow(wc.lpszClassName, L"MineSwiper", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 60 + (X_CORD * 20), 110 + (Y_CORD * 20), nullptr, nullptr, wc.hInstance, nullptr); hwnd == INVALID_HANDLE_VALUE)
		return EXIT_FAILURE;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	return true;
}

pair<bool, HWND> FrameWnd(const wstring&& winClass, const wstring&& title, HWND hParantWnd, const WNDPROC CallBack) {
	UnregisterClass(winClass.c_str(), GetModuleHandle(nullptr));
	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	HWND Frame{};
	wc.lpfnWndProc = CallBack;
	wc.lpszClassName = winClass.c_str();

	const auto create_window = [&Frame, &winClass, &title, &hParantWnd]() -> pair<bool, HWND> {
		if (Frame = CreateWindow(winClass.c_str(), title.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER, 20, 50, X_CORD * 20 + 2, Y_CORD * 20 + 2, hParantWnd, nullptr, nullptr, nullptr); !Frame)
			return { false, nullptr };

		ShowWindow(Frame, SW_SHOWDEFAULT);
		UpdateWindow(Frame);
		return {true, Frame};
	};

		if (!RegisterClassEx(&wc))
			return create_window();
	
	return create_window();
}
