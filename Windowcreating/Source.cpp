#include <Windows.h>
#include<windowsx.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // главна€ функци€
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	// описываем параметры, которые необходимы дл€ создани€ окна
	HWND hwnd; // указатель класса окна
	MSG msg; // —труктура MSG содержит информацию
	//о сообщени€х из очереди потока сообщений.
	WNDCLASS w; // структура, определ€юща€ класс окна
	memset(&w, 0, sizeof(WNDCLASS)); // выделение пам€ти дл€ класса окна
	w.style = 0; // стиль окна по умолчанию
	w.lpfnWndProc = WndProc; // функци€ окна
	w.hInstance = hInstance; // дескриптор приложени€
	w.hbrBackground = GetStockBrush(WHITE_BRUSH); // цвет дл€ заполнени€ окна
	w.lpszClassName = "API Windows"; // им€ класса окна
		RegisterClass(&w); // –егистрируем класс окна
		// —оздаем окно
	hwnd = CreateWindow("API Windows", // им€ класса
		"API Windows", //название окна
		WS_OVERLAPPEDWINDOW, // стиль окна
		10, // x Ч координата
		10, // y Ч координата
		600, // ширина
		480, // высота
		NULL, // нет родительского окна
		NULL, // нет меню
		hInstance, // дескриптор приложени€
		NULL); // не передаем данных
	ShowWindow(hwnd, nCmdShow); // активаци€ окна
	UpdateWindow(hwnd); // перерисовка
	// ÷икл обработки сообщений
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); // разрешить использование клавиатуры
		DispatchMessage(&msg); // вернуть управление Windows
	}
	//возвращаемое значение дл€ функции WndProc()
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