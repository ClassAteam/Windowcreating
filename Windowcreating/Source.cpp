#include <Windows.h>
#include<windowsx.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // ������� �������
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	// ��������� ���������, ������� ���������� ��� �������� ����
	HWND hwnd; // ��������� ������ ����
	MSG msg; // ��������� MSG �������� ����������
	//� ���������� �� ������� ������ ���������.
	WNDCLASS w; // ���������, ������������ ����� ����
	memset(&w, 0, sizeof(WNDCLASS)); // ��������� ������ ��� ������ ����
	w.style = 0; // ����� ���� �� ���������
	w.lpfnWndProc = WndProc; // ������� ����
	w.hInstance = hInstance; // ���������� ����������
	w.hbrBackground = GetStockBrush(WHITE_BRUSH); // ���� ��� ���������� ����
	w.lpszClassName = "API Windows"; // ��� ������ ����
		RegisterClass(&w); // ������������ ����� ����
		// ������� ����
	hwnd = CreateWindow("API Windows", // ��� ������
		"API Windows", //�������� ����
		WS_OVERLAPPEDWINDOW, // ����� ����
		10, // x � ����������
		10, // y � ����������
		600, // ������
		480, // ������
		NULL, // ��� ������������� ����
		NULL, // ��� ����
		hInstance, // ���������� ����������
		NULL); // �� �������� ������
	ShowWindow(hwnd, nCmdShow); // ��������� ����
	UpdateWindow(hwnd); // �����������
	// ���� ��������� ���������
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); // ��������� ������������� ����������
		DispatchMessage(&msg); // ������� ���������� Windows
	}
	//������������ �������� ��� ������� WndProc()
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message,
	WPARAM wparam, LPARAM lparam)
{
	if (Message == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, Message, wparam, lparam);
}