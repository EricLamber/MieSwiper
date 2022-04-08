#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

// Libraris
#include <Windows.h>
#include <random>

//defines
#define N_MINES 10
#define X_CORD 9
#define Y_CORD 9

using namespace std;

//Variables
extern int n_Buttons;
extern HWND hButton[];

//Prototypes
LRESULT CALLBACK WinProc0(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WinProc1(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL InitMainWnd(HWND hWnd, HINSTANCE hInstance, int nCmdShow);
pair<bool, HWND> FrameWnd(const wstring&& winClass, const wstring&& title, HWND hParantWnd, const WNDPROC CallBack);
void Field(HWND hWnd);
int randX();
int randY();
void Coording();
bool Mines_coords(int a, int b);
int NumBox(int a, int b);
BOOL CALLBACK DestoryChildCallback(HWND hwnd, LPARAM lParam);
