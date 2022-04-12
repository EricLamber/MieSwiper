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
extern int n_EmptyButtons;
extern HWND hEmptyButton[];
extern int n_Buttons;
extern HWND hButton[];
extern HWND hRepeatable[];

//Prototypes
LRESULT CALLBACK WinProc0(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WinProc1(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL InitMainWnd(HWND hWnd, HINSTANCE hInstance, int nCmdShow);
BOOL CALLBACK DestoryChildCallback(HWND hwnd, LPARAM lParam);
pair<bool, HWND> FrameWnd(const wstring&& winClass, const wstring&& title, HWND hParantWnd, const WNDPROC CallBack);
void Field(HWND hWnd);
void Coording();
void HideAllEmpty(HWND hWnd, int l);
int randX();
int randY();
int NumBox(int a, int b);
bool Mines_coords(int a, int b);
bool IsEmpty(HWND hWnd);
bool IsRepeat(HWND hWnd);
