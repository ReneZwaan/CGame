#include <Windows.h>


//typedef struct tagWNDCLASS {
//	UINT      style;
//	WNDPROC   lpfnWndProc;
//	int       cbClsExtra;
//	int       cbWndExtra;
//	HINSTANCE hInstance;
//	HICON     hIcon;
//	HCURSOR   hCursor;
//	HBRUSH    hbrBackground;
//	LPCTSTR   lpszMenuName;
//	LPCTSTR   lpszClassName;
//} WNDCLASS, *PWNDCLASS;


// Deals with the mssg it gets from windows
LRESULT CALLBACK HandleMessagesFromWindows(HWND   Window, UINT   Message, WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = 0;
	switch (Message)
	{
		case WM_CLOSE: // When the window is closed
		{
		
		}break;

		case WM_DESTROY: //When the window is getting destroyed
		{

		}break;

		case WM_SIZE: // when the window is resized
		{
			
		}break;

		case WM_ACTIVATEAPP: // when the window is resized
		{

		}break;

		case WM_PAINT:
		{
			PAINTSTRUCT Paint;
			HDC deviceContext = BeginPaint(Window,&Paint);
			int x = Paint.rcPaint.left;
			int y = Paint.rcPaint.top;
			int Height = Paint.rcPaint.bottom - Paint.rcPaint.top;
			int Width = Paint.rcPaint.right - Paint.rcPaint.left;
			PatBlt(deviceContext, x, y, Width, Height, WHITENESS);
			EndPaint(Window, &Paint);
		}break;

		default:
			Result = DefWindowProc(Window, Message, wParam, lParam);
			break;
	}

	return Result;
}

int CALLBACK WinMain(HINSTANCE Instance, HINSTANCE PrevInstance, LPSTR     comandLine, int       ShowCode)
{
	unsigned int Test;
	
	WNDCLASSA windowClass = {};
	windowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW ;
	windowClass.lpfnWndProc = HandleMessagesFromWindows;
	windowClass.hInstance = Instance;
	//windowClass.lpszMenuName = "Test";
	windowClass.lpszClassName = "CGame";

	if (RegisterClassA(&windowClass))
	{
		HWND WindowHandle = CreateWindowExA(0, windowClass.lpszClassName, "Name??", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, Instance, 0);

		if (WindowHandle)
		{
			MSG Message;
			

			for (;;)
			{
				BOOL  messagerResult = GetMessageA(&Message, 0, 0, 0);
				if (messagerResult > 0)
				{
					TranslateMessage(&Message);
					DispatchMessageA(&Message);
				}
				else
				{
					break;
				}
			}

		}

	}
	
}