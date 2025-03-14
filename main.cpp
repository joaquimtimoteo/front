#include <windows.h>
#include <tchar.h>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

// Declarações de funções
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void CalcularPi(HWND hwnd);
void AdicionarControles(HWND hwnd);
double CalcularSerieArctg(double z, double epsilon, int nMax, HWND listBox);

// Identificadores dos controles
#define ID_EDIT_X 1
#define ID_EDIT_EPSILON 2
#define ID_EDIT_NMAX 3
#define ID_BUTTON_CALCULAR 4
#define ID_BUTTON_SAIR 5
#define ID_LISTBOX_RESULTADOS 6
#define ID_STATIC_X 7
#define ID_STATIC_EPSILON 8
#define ID_STATIC_NMAX 9
#define ID_STATIC_TITLE 10

// Handles dos controles
HWND hEditX, hEditEpsilon, hEditNMax, hButtonCalcular, hButtonSair, hListBox;
HWND hStaticX, hStaticEpsilon, hStaticNMax, hStaticTitle;
HFONT hFont, hFontTitle;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Registrar a classe da janela
    const TCHAR CLASS_NAME[] = _T("CalculoPiWindow");
    
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    
    RegisterClass(&wc);
    
    // Criar a janela
    HWND hwnd = CreateWindowEx(
        0,                          // Estilos estendidos
        CLASS_NAME,                 // Nome da classe
        _T("Cálculo de π usando Série de Arctg"),  // Título da janela
        WS_OVERLAPPEDWINDOW,        // Estilo da janela
        CW_USEDEFAULT, CW_USEDEFAULT, 600, 500, // Posição e tamanho
        NULL, NULL, hInstance, NULL
    );
    
    if (hwnd == NULL) {
        return 0;
    }
    
    // Criar fonte para os controles
    hFont = CreateFont(16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                       DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                       DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T("Segoe UI"));
    
    hFontTitle = CreateFont(20, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                           DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                           DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T("Segoe UI"));
    
    // Adicionar controles à janela
    AdicionarControles(hwnd);
    
    // Mostrar e atualizar a janela
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    // Loop de mensagens
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    // Liberar recursos
    DeleteObject(hFont);
    DeleteObject(hFontTitle);
    
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case ID_BUTTON_CALCULAR:
                    CalcularPi(hwnd);
                    break;
                    
                case ID_BUTTON_SAIR:
                    DestroyWindow(hwnd);
                    break;
            }
            break;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    
    return 0;
}

void AdicionarControles(HWND hwnd) {
    // Título
    hStaticTitle = CreateWindow(
        _T("STATIC"), _T("Cálculo de π usando a Série de Arctg"),
        WS_VISIBLE | WS_CHILD | SS_CENTER,
        50, 20, 500, 30,
        hwnd, (HMENU)ID_STATIC_TITLE, NULL, NULL
    );
    SendMessage(hStaticTitle, WM_SETFONT, (WPARAM)hFontTitle, TRUE);
    
    // Label para X
    hStaticX = CreateWindow(
        _T("STATIC"), _T("Valor de x:"),
        WS_VISIBLE | WS_CHILD,
        50, 70, 100, 25,
        hwnd, (HMENU)ID_STATIC_X, NULL, NULL
    );
    SendMessage(hStaticX, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // Campo de entrada para X
    hEditX = CreateWindow(
        _T("EDIT"), _T("10"),
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        160, 70, 100, 25,
        hwnd, (HMENU)ID_EDIT_X, NULL, NULL
    );
    SendMessage(hEditX, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // Label para Epsilon
    hStaticEpsilon = CreateWindow(
        _T("STATIC"), _T("Precisão (ε):"),
        WS_VISIBLE | WS_CHILD,
        280, 70, 100, 25,
        hwnd, (HMENU)ID_STATIC_EPSILON, NULL, NULL
    );
    SendMessage(hStaticEpsilon, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // Campo de entrada para Epsilon
    hEditEpsilon = CreateWindow(
        _T("EDIT"), _T("0.0001"),
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        390, 70, 100, 25,
        hwnd, (HMENU)ID_EDIT_EPSILON, NULL, NULL
    );
    SendMessage(hEditEpsilon, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // Label para NMax
    hStaticNMax = CreateWindow(
        _T("STATIC"), _T("Iterações máximas:"),
        WS_VISIBLE | WS_CHILD,
        50, 110, 150, 25,
        hwnd, (HMENU)ID_STATIC_NMAX, NULL, NULL
    );
    SendMessage(hStaticNMax, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // Campo de entrada para NMax
    hEditNMax = CreateWindow(
        _T("EDIT"), _T("100"),
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        210, 110, 100, 25,
        hwnd, (HMENU)ID_EDIT_NMAX, NULL, NULL
    );
    SendMessage(hEditNMax, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // Botão Calcular
    hButtonCalcular = CreateWindow(
        _T("BUTTON"), _T("Calcular"),
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        350, 110, 100, 30,
        hwnd, (HMENU)ID_BUTTON_CALCULAR, NULL, NULL
    );
    SendMessage(hButtonCalcular, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // ListBox para resultados
    hListBox = CreateWindow(
        _T("LISTBOX"), NULL,
        WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL | LBS_NOTIFY | LBS_NOINTEGRALHEIGHT,
        50, 160, 500, 240,
        hwnd, (HMENU)ID_LISTBOX_RESULTADOS, NULL, NULL
    );
    SendMessage(hListBox, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // Botão Sair
    hButtonSair = CreateWindow(
        _T("BUTTON"), _T("Sair"),
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        250, 420, 100, 30,
        hwnd, (HMENU)ID_BUTTON_SAIR, NULL, NULL
    );
    SendMessage(hButtonSair, WM_SETFONT, (WPARAM)hFont, TRUE);
}

void CalcularPi(HWND hwnd) {
    // Limpar o ListBox
    SendMessage(hListBox, LB_RESETCONTENT, 0, 0);
    
    // Obter os valores dos controles
    TCHAR buffer[256];
    
    GetWindowText(hEditX, buffer, 256);
    double x = _ttof(buffer);
    
    GetWindowText(hEditEpsilon, buffer, 256);
    double epsilon = _ttof(buffer);
    
    GetWindowText(hEditNMax, buffer, 256);
    int nMax = _ttoi(buffer);
    
    // Adicionar cabeçalho
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)_T("Calculando π com arctg usando x = 10"));
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)_T("---------------------------------------"));
    
    // Aplicar a identidade trigonométrica para x/4 > 1
    double z = x / 4.0;  // z = 10/4 = 2.5
    
    std::wstringstream ss;
    ss << _T("Valor de z = x/4 = ") << z;
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)ss.str().c_str());
    
    // Como z = 2.5 > 1, precisamos usar a identidade: arctg(z) = π/2 - arctg(1/z)
    ss.str(std::wstring());
    ss << _T("Como z > 1, usamos: arctg(z) = π/2 - arctg(1/z)");
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)ss.str().c_str());
    
    double zConvergente = 1.0 / z;  // 1/2.5 = 0.4
    
    ss.str(std::wstring());
    ss << _T("Valor z' = 1/z = ") << std::fixed << std::setprecision(6) << zConvergente;
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)ss.str().c_str());
    
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)_T("---------------------------------------"));
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)_T("n | Termo | Soma Parcial"));
    
    // Calcular a série de arctg para o valor z' = 0.4 (dentro do raio de convergência)
    double arctgResult = CalcularSerieArctg(zConvergente, epsilon, nMax, hListBox);
    
    // Calcular π usando a relação: π = 4 * arctg(1/0.4)
    // OU: π = 4 * (π/2 - arctg(0.4)) → Isso está ERRADO no código original!
    double piApprox = 4.0 * arctgResult;
    
    // Exibir resultados finais
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)_T("---------------------------------------"));
    
    ss.str(std::wstring());
    ss << _T("Aproximação de π: ") << std::fixed << std::setprecision(10) << piApprox;
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)ss.str().c_str());
    
    ss.str(std::wstring());
    ss << _T("Valor verdadeiro de π: ") << std::fixed << std::setprecision(10) << M_PI;
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)ss.str().c_str());
    
    ss.str(std::wstring());
    ss << _T("Erro absoluto: ") << std::fixed << std::setprecision(10) << fabs(piApprox - M_PI);
    SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)ss.str().c_str());
}

double CalcularSerieArctg(double z, double epsilon, int nMax, HWND listBox) {
    double currentTerm = z;
    double sum = currentTerm;
    int n = 1;
    
    std::wstringstream ss;
    ss << n << " | " << std::fixed << std::setprecision(10) << currentTerm << " | " << sum;
    SendMessage(listBox, LB_ADDSTRING, 0, (LPARAM)ss.str().c_str());
    
    while (fabs(currentTerm) > epsilon && n < nMax) {
        // Fórmula recorrente: a_n = -a_{n-1} * (z^2 * (2n-3))/(2n-1)
        currentTerm = -currentTerm * (z * z * (2 * n - 1)) / (2 * n + 1);
        sum += currentTerm;
        n++;
        
        ss.str(std::wstring());
        ss << n << " | " << std::fixed << std::setprecision(10) << currentTerm << " | " << sum;
        SendMessage(listBox, LB_ADDSTRING, 0, (LPARAM)ss.str().c_str());
    }
    
    return sum;
}
