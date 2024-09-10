#include "framework.h"
#include "Window_Editor.h"
#include "..\MEGA_ENGINE_SOURCE\MEGA_APP.h"
#include "..\MEGA_ENGINE\MEGA_LoadScenes.h"
#include "..\MEGA_ENGINE\MEGA_LoadResources.h"

//#pragma commet(lib, "..\x64\Debug\MEGA_ENGINE.lib")

#define MAX_LOADSTRING 256

// 전역 변수:
HINSTANCE hInst;                              
WCHAR szTitle[MAX_LOADSTRING];                  
WCHAR szWindowClass[MAX_LOADSTRING]; 

// MEGA ENGINE
MEGA::APP application;

ULONG_PTR gdiPlusToken;
Gdiplus::GdiplusStartupInput gdiPlusStartupInput;

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWEDITOR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 윈도우 생성
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWEDITOR));

    MSG msg;

    while (true)
    {
        // 메시지 처리
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                break;
            }

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        // 게임 로직 처리
        else
        {
            application.Run();
        }
    }
    Gdiplus::GdiplusShutdown(gdiPlusToken);
    return static_cast<int>(msg.wParam);
}



// 윈도우 등록
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWEDITOR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWEDITOR);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

// 윈도우 생성
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;

   constexpr UINT width = 1080;
   constexpr UINT height = 480;

   HWND hWnd = CreateWindowW
   (
       szWindowClass, 
       szTitle, 
       WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, 
       width, height, 
       nullptr, 
       nullptr, 
       hInstance,
       nullptr
   );

   if (!hWnd)
   {
      return FALSE;
   }

   application.Initialize(hWnd, width, height);
   //ShowWindow(hWnd, nCmdShow);
   
   UpdateWindow(hWnd);

   Gdiplus::GdiplusStartup(&gdiPlusToken, &gdiPlusStartupInput, NULL);

   //loadScene
   MEGA::LoadResources();
   MEGA::LoadScenes();

   return TRUE;
}

// 메시지 처리
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
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

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 대화 상자 메시지 처리
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
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
