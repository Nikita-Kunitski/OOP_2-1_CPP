#include <windows.h>
#include <stdlib.h>
#include <tchar.h>
#include <stdlib.h>
#include "dll.h"


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndSecondProc(HWND, UINT, WPARAM, LPARAM);


HINSTANCE hInstanceSecond;

int WINAPI WinMain(HINSTANCE hInstance, // ���������� ���������� ���������� - ����� ������ ���� ���������
	HINSTANCE hPrevInstance, // ���������� ��������. ����������
	LPSTR    lpCmdLine, // ��������� �� ������ ��������� ������
	int       nCmdShow) // ��������� ��� ����
{
	HWND hWnd;
	MSG message;

	WNDCLASS wndClass; //����� ����
	memset(&wndClass, 0, sizeof(wndClass));

	wndClass.lpszClassName = L"MyWindowClass";
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
	wndClass.lpfnWndProc = WndProc; // ��� ����������� �������
	wndClass.hInstance = hInstance; //����������� ����������
	wndClass.style = CS_HREDRAW | CS_VREDRAW; //1 - ����������� ���������� ������� ��� ��� ������ � ������ ����

	RegisterClass(&wndClass);


	hWnd = CreateWindow(L"MyWindowClass", L"MyWindow", WS_OVERLAPPEDWINDOW, 500, 300, 600, 450, NULL, NULL, hInstance, NULL);
	//L - ������� ����������� ��������������� ����� ��� ������
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&message, NULL, 0, 0)) // ���� ��������� ��������� || NULL - �� ���� ���� ��������� ��������� || 0 0 - ��������� ��� ���������(��� ����������� ������)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}




LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}	break;



	case WM_LBUTTONDOWN:
	{
		WNDCLASS wndSecondClass; //����� ����
		memset(&wndSecondClass, 0, sizeof(wndSecondClass));

		wndSecondClass.lpszClassName = L"MySecondClass";
		wndSecondClass.hbrBackground = (HBRUSH)(COLOR_WINDOW);
		wndSecondClass.lpfnWndProc = WndSecondProc; // ��� ����������� �������
		wndSecondClass.hInstance = hInstanceSecond; //����������� ����������
		wndSecondClass.style = CS_HREDRAW | CS_VREDRAW; //1 - ����������� ���������� ������� ��� ��� ������ � ������ ����

		RegisterClass(&wndSecondClass);

		unsigned int freeBytes = MyFunction();
		TCHAR str[256];
		_itow(freeBytes, str, 10);
		MessageBox(NULL, str, L"Function from DLL", MB_OK);
	}	break;

	case WM_RBUTTONDOWN:
	{
		WNDCLASS wndSecondClass; //����� ����
		memset(&wndSecondClass, 0, sizeof(wndSecondClass));

		wndSecondClass.lpszClassName = L"MySecondClass";
		wndSecondClass.hbrBackground = (HBRUSH)(COLOR_WINDOW);
		wndSecondClass.lpfnWndProc = WndSecondProc; // ��� ����������� �������
		wndSecondClass.hInstance = hInstanceSecond; //����������� ����������
		wndSecondClass.style = CS_HREDRAW | CS_VREDRAW; //1 - ����������� ���������� ������� ��� ��� ������ � ������ ����

		RegisterClass(&wndSecondClass);

		unsigned int freeBytes = myDll::classFunction();
		TCHAR str[256];

		_itow(freeBytes, str, 10);
		MessageBox(NULL, str, L"Function from classDLL", MB_OK);
	}	break;

	case WM_CLOSE:
	{
		DestroyWindow(hWnd);
	}	break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


LRESULT CALLBACK WndSecondProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CHAR: {
		DestroyWindow(hWnd);
	} break;

	default: {
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	}
	return 0;
}