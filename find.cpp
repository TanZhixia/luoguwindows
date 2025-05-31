#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int main() {
    cout << "请输入查找的题目:";
    string s;
    cin >> s;
    ifstream in(s + "/" + s + ".cpp");
    string line;
    string copyLine = "";
    while (getline(in, line)) {
        cout << line << endl;
        copyLine += line;
        copyLine += '\n';
    }
    HWND hWnd = NULL;
    OpenClipboard(hWnd);
    EmptyClipboard();
    HANDLE hHandle = GlobalAlloc(GMEM_FIXED, 1000);
    char* pData = (char*) (GlobalLock(hHandle));
    strcpy(pData, copyLine.c_str());
    SetClipboardData(CF_TEXT, hHandle);
    GlobalUnlock(hHandle);
    CloseClipboard();
    return 0;
}