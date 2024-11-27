#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int CountWhileInFile(char* fname) {
    ifstream fin(fname);
    if (!fin) {
        cout << "Помилка відкриття файлу!" << endl;
        return 0;
    }

    int count = 0;
    string line;
    while (getline(fin, line)) {
        size_t pos = 0;
        while ((pos = line.find("while", pos)) != string::npos) {
            count++;
            pos += 5;  // пропускаємо знайдену групу "while"
        }
    }

    return count;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char fname[100];
    cout << "Введіть ім'я файлу: ";
    cin >> fname;

    int result = CountWhileInFile(fname);

    cout << "К-сть повторювань 'while': " << result << endl;

    return 0;
}
