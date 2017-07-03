#include <Windows.h>

HINSTANCE HINST;
int counter_wind= 0;

LRESULT CALLBACK WndProcChild(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		counter_wind--;
		break;
	case WM_KEYDOWN:
		DestroyWindow(hWnd); break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

HWND CreateChildWindow()
{
	if (counter_wind == 5) return NULL;
	WNDCLASS ChildClass;

	ChildClass.style = CS_DBLCLKS;
	ChildClass.lpfnWndProc = (WNDPROC)WndProcChild;
	ChildClass.cbClsExtra = 0;
	ChildClass.cbWndExtra = 0;
	ChildClass.hInstance = HINST;
	ChildClass.hIcon = LoadIcon(HINST, (LPCTSTR)IDI_APPLICATION);
	ChildClass.hCursor = LoadCursor(NULL, NULL);
	ChildClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	ChildClass.lpszMenuName = 0;
	ChildClass.lpszClassName = TEXT("Class_child");

	RegisterClass(&ChildClass);

	HWND hWndC;

	WCHAR* title = new WCHAR[1];
	char *buf = new char[1];
	_itoa_s(counter_wind + 1, buf, 2,10);
	title[0]=buf[0];
	title[1]='\0';


	hWndC = CreateWindow(TEXT("Class_child"), title,
	WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, NULL, NULL, HINST, NULL);
	ShowWindow(hWndC, SW_SHOW);
	UpdateWindow(hWndC);
	counter_wind++;
	return hWndC;
}

LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	switch (Message) {
	case WM_KEYDOWN:
	{
		switch (wparam)
		{
		case VK_F1:
		{
			int x = 10;
			int y = 10;
			int width = 700;
			int height = 500;
			MoveWindow(hwnd, x, y, width, height, TRUE);
		}
		break;
		case VK_F2:
		{
			int x = 100;
			int y = 100;
			int width = 700;
			int height = 500;
			MoveWindow(hwnd, x, y, width, height, TRUE);
		}
		break;
		case VK_F3:
		{
			int x = 100;
			int y = 100;
			int width = 700;
			int height = 500;
			MoveWindow(hwnd, x, y, width, height, TRUE);
		}
		break;
		case VK_F4:
		{
			int x = 150;
			int y = 150;
			int width = 700;
			int height = 500;
			MoveWindow(hwnd, x, y, width, height, TRUE);
		}
		break;
		case VK_F5:
		{
			int x = 700;
			int y = 200;
			int width = 700;
			int height = 500;
			MoveWindow(hwnd, x, y, width, height, TRUE);
		}
		break;
		}
	}
	break;

	case WM_CLOSE:
	{
		if (IDOK == MessageBox(hwnd, L"Выйти из Программы?", L"Выход", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2))

			SendMessage(hwnd, WM_DESTROY, NULL, NULL);
		break;
	}	

	case WM_LBUTTONUP:
	{
		CreateChildWindow();
		break;
	}

	case WM_CREATE:
		break;
	case WM_RBUTTONUP:{
			SetWindowText(hwnd, L"New title");		  
					  }break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, Message, wparam, lparam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	HWND hwnd;
	MSG msg;
	WNDCLASS windmain;

	memset(&windmain, 0, sizeof(WNDCLASS));
	windmain.style = CS_HREDRAW | CS_VREDRAW;
	windmain.lpfnWndProc = WndProc;
	windmain.hInstance = hInstance;
	windmain.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windmain.lpszClassName = L"My_Class";
	

	RegisterClass(&windmain);
	hwnd = CreateWindow(L"My_Class", L"LAB_11 WINAPI", WS_TILEDWINDOW,
		700, 200, 700, 500, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;

}