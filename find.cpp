#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "请输入查找的题目:";
    string s, com;
    cin >> s;
    cout << "请输入指令:";
    cin >> com;
    if (com != "--all" && com != "--copy" && com != "--print") {
        cerr << "ERROR!" << endl;
        return 1;
    }
    ifstream in((s + "/" + s + ".cpp").c_str());
    string line;
    string copyLine = "";
    while (getline(in, line)) {
        if (com != "--copy")
            cout << line << endl;
        copyLine += line;
        copyLine += '\n';
    }
    if (com != "--print") {
        HWND hWnd = NULL;
        OpenClipboard(hWnd);
        EmptyClipboard();
        HANDLE hHandle = GlobalAlloc(GMEM_FIXED, 1000);
        char* pData = (char*) (GlobalLock(hHandle));
        strcpy(pData, copyLine.c_str());
        SetClipboardData(CF_TEXT, hHandle);
        GlobalUnlock(hHandle);
        CloseClipboard();
        cout << "已复制到剪切板" << endl;
    }
    return 0;
}