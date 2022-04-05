#include "Header.h"

// Coordinates of mines
int coordsX[N_MINES];
int coordsY[N_MINES];

void Field(HWND hWnd) {
	Coording();
	for (int i = 0; i < X_CORD; i++) {
		for (int j = 0; j < Y_CORD; j++) {
			if (Mines_coords(i, j)) {
				CreateWindow(L"STATIC", L"*", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			}
			else if (NumBox(i, j) == 1) {
				CreateWindow(L"STATIC", L"1", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			}
			else if (NumBox(i, j) == 2) {
				CreateWindow(L"STATIC", L"2", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			}
			else if (NumBox(i, j) == 3) {
				CreateWindow(L"STATIC", L"3", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			}
			else if (NumBox(i, j) == 4) {
				CreateWindow(L"STATIC", L"4", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			}
			else if (NumBox(i, j) == 5) {
				CreateWindow(L"STATIC", L"5", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			}
			else if (NumBox(i, j) == 6) {
				CreateWindow(L"STATIC", L"6", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			}
			else if (NumBox(i, j) == 7) {
				CreateWindow(L"STATIC", L"7", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			}
			else if (NumBox(i, j) == 8) {
				CreateWindow(L"STATIC", L"8", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			}
			else {
				CreateWindow(L"STATIC", nullptr, WS_CHILD | WS_VISIBLE | SS_SUNKEN, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			}
		}
	}
}

void  Buttons(HWND hWnd) {
	for (int i = 0; i < X_CORD; i++) {
		for (int j = 0; j < Y_CORD; j++) {
			hButton[n_Buttons] = CreateWindow(L"BUTTON", L"", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, i * 20, j * 20, 20, 20, hWnd, nullptr, nullptr, nullptr);
			n_Buttons++;
		}
	}
}

int randX() {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist(0, X_CORD - 1);
	return dist(rng) * 20;
}

int randY() {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist(0, Y_CORD - 1);
	return dist(rng) * 20;
}

void Coording() {
	for (int p = 0; p < N_MINES; p++) {
		coordsX[p] = randX();
		coordsY[p] = randY();
	}
	int n = 0;
	while (n < 3) {
		for (int p = 1; p < N_MINES; p++) {
			for (int k = p - 1; k >= 0; k--) {
				if (coordsX[p] == coordsX[k] && coordsY[p] == coordsY[k]) {
					coordsX[p] = randX();
					coordsY[p] = randY();
				}
			}
		}
		n++;
	}
}

bool Mines_coords(int a, int b) {
	bool flag = 0;

	for (int t = 0; t < N_MINES; t++) {
		if (coordsX[t] == a * 20 && coordsY[t] == b * 20)
			flag = 1;
	}

	return flag;
}

int NumBox(int a, int b) {
	a *= 20;
	b *= 20;
	int f = 0;
	if (a == 0 && b == 0) {
		for (int m = 0; m < N_MINES; m++) {
			if (a == coordsX[m] && b + 20 == coordsY[m] ||
				a + 20 == coordsX[m] && b == coordsY[m] ||
				a + 20 == coordsX[m] && b + 20 == coordsY[m])
				f++;
		}
	}
	else if (a == 0 && b != 0) {
		for (int m = 0; m < N_MINES; m++) {
			if (a == coordsX[m] && b - 20 == coordsY[m] ||
				a == coordsX[m] && b + 20 == coordsY[m] ||
				a + 20 == coordsX[m] && b - 20 == coordsY[m] ||
				a + 20 == coordsX[m] && b == coordsY[m] ||
				a + 20 == coordsX[m] && b + 20 == coordsY[m])
				f++;
		}
	}
	else if (a != 0 && b == 0) {
		for (int m = 0; m < N_MINES; m++) {
			if (a - 20 == coordsX[m] && b == coordsY[m] ||
				a - 20 == coordsX[m] && b + 20 == coordsY[m] ||
				a == coordsX[m] && b + 20 == coordsY[m] ||
				a + 20 == coordsX[m] && b == coordsY[m] ||
				a + 20 == coordsX[m] && b + 20 == coordsY[m])
				f++;
		}
	}
	else if (a == X_CORD * 20 && b != Y_CORD * 20) {
		for (int m = 0; m < N_MINES; m++) {
			if (a - 20 == coordsX[m] && b - 20 == coordsY[m] ||
				a - 20 == coordsX[m] && b == coordsY[m] ||
				a - 20 == coordsX[m] && b + 20 == coordsY[m] ||
				a == coordsX[m] && b - 20 == coordsY[m] ||
				a == coordsX[m] && b + 20 == coordsY[m])
				f++;
		}
	}
	else if (a != X_CORD * 20 && b == Y_CORD * 20) {
		for (int m = 0; m < N_MINES; m++) {
			if (a - 20 == coordsX[m] && b - 20 == coordsY[m] ||
				a - 20 == coordsX[m] && b == coordsY[m] ||
				a == coordsX[m] && b - 20 == coordsY[m] ||
				a + 20 == coordsX[m] && b - 20 == coordsY[m] ||
				a + 20 == coordsX[m] && b == coordsY[m])
				f++;
		}
	}
	else if (a == X_CORD * 20 && b == Y_CORD * 20) {
		for (int m = 0; m < N_MINES; m++) {
			if (a - 20 == coordsX[m] && b - 20 == coordsY[m] ||
				a - 20 == coordsX[m] && b == coordsY[m] ||
				a == coordsX[m] && b - 20 == coordsY[m])
				f++;
		}
	}
	else {
		for (int m = 0; m < N_MINES; m++) {
			if (a - 20 == coordsX[m] && b - 20 == coordsY[m] ||
				a - 20 == coordsX[m] && b == coordsY[m] ||
				a - 20 == coordsX[m] && b + 20 == coordsY[m] ||
				a == coordsX[m] && b - 20 == coordsY[m] ||
				a == coordsX[m] && b + 20 == coordsY[m] ||
				a + 20 == coordsX[m] && b - 20 == coordsY[m] ||
				a + 20 == coordsX[m] && b == coordsY[m] ||
				a + 20 == coordsX[m] && b + 20 == coordsY[m])
				f++;
		}
	}
	return f;
}
