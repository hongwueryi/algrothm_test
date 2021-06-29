// Win32Project2.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Win32Project2.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;                                // ��ǰʵ��
WCHAR szTitle[MAX_LOADSTRING];                  // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING];            // ����������

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
HWND g_childWnd = nullptr;
HWND G_hWnd = NULL;
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lPram)
{
	if (hwnd)
	{
		char classname[MAX_PATH] = { 0 };
		GetClassNameA(hwnd, classname, MAX_PATH);
		if (strcmp(classname, "SHELLDLL_DefView") == 0)
		{
			int num = 0;
		}

		char wndname[MAX_PATH] = { 0 };
		GetWindowTextA(hwnd, wndname, MAX_PATH);
		if (strcmp(wndname, "SHELLDLL_DefView") == 0)
		{
			int num = 0;
		}
#if 1
		HWND parentWnd = FindWindowExA(hwnd, NULL, "SHELLDLL_DefView", NULL);
		if (parentWnd)
		{
			g_childWnd = FindWindowExA(0, hwnd, "WorkerW", 0);
			if (g_childWnd)
			{
				//DestroyWindow(g_childWnd);
				int num = 0;
				HWND hw = NULL; // FindWindowExA(0, hwnd, "Wintext111", 0);
				if (hw)
				{
					int num = 3;
					CloseWindow(hw);
				}
			}
		}
#endif
		
	}

	return TRUE;
}


LRESULT CALLBACK hookProc(int code, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT  ptr = (PKBDLLHOOKSTRUCT)lParam;
	int vKey = LOBYTE(ptr->vkCode);
	if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
	{
		switch (vKey)
		{
		case 'd':
		case 'D':
		{
			MessageBox(NULL, 0, 0, MB_OK);
			//DestroyWindow(G_hWnd);
			//PostQuitMessage(0);
		}
			
			break;
		}
	}

	return CallNextHookEx(NULL, code, wParam, lParam);
}

void CallHook()
{
	HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, hookProc, hInst, 0);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//CallHook();
	// TODO: �ڴ˷��ô��롣
	HWND hWnd = ::FindWindow(L"Progman", NULL);
	if (NULL != hWnd)
	{
		//SendMessage(hWnd, 0x052C, 0, 0);
		//EnumWindows(EnumWindowsProc, 0);
	}



    // ��ʼ��ȫ���ַ���
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32PROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT2));

    MSG msg;

    // ����Ϣѭ��: 
	//Sleep(10000);
	//PostQuitMessage(0);
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECT2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   G_hWnd = hWnd;
   HWND hwndTest = ::FindWindowA("Wintext222", "Wintext222");
   if (hwndTest)
   {
	   SetParent(hWnd, hwndTest);
   }
   //SetParent(hWnd, g_childWnd);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_PAINT    - ����������
//  WM_DESTROY  - �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �����˵�ѡ��: 
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: �ڴ˴����ʹ�� hdc ���κλ�ͼ����...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND hwndTest = ::FindWindowA("Wintext222", "Wintext222");
	if (hwndTest)
	{
		CloseWindow(hwndTest);
	}

	return FALSE;
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
