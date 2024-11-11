#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Рекурсивна функція підрахунку кількості символів B, A, S, I, C у рядку
void countBASICCharsRecursive(const char* str, int& countB, int& countA, int& countS, int& countI, int& countC)
{
    if (*str == '\0') return; // умова завершення

    // Перевіряємо поточний символ і збільшуємо відповідний лічильник
    switch (*str)
    {
    case 'B': countB++; break;
    case 'A': countA++; break;
    case 'S': countS++; break;
    case 'I': countI++; break;
    case 'C': countC++; break;
    }

    // Рекурсивний виклик для наступного символу
    countBASICCharsRecursive(str + 1, countB, countA, countS, countI, countC);
}

// Рекурсивна функція заміни всіх входжень "BASIC" на "Delphi"
char* replaceBASICWithDelphiRecursive(char* str, const char* search, const char* replace)
{
    // Якщо рядок коротший за "BASIC", повертаємо його без змін
    if (strlen(str) < strlen(search)) return str;

    // Перевіряємо, чи збігається початок рядка з "BASIC"
    if (strncmp(str, search, strlen(search)) == 0)
    {
        // Зміщуємо рядок і додаємо "Delphi"
        char* tmp = new char[strlen(str) + strlen(replace) - strlen(search) + 1];
        strcpy(tmp, replace);
        strcat(tmp, replaceBASICWithDelphiRecursive(str + strlen(search), search, replace));
        
        strcpy(str, tmp); // Копіюємо результат назад в оригінальний рядок
        delete[] tmp; // Звільняємо тимчасову пам'ять

        return str;
    }
    else
    {
        // Переміщуємо поточний символ до результату і викликаємо функцію рекурсивно
        char next[2] = {str[0], '\0'};
        strcat(next, replaceBASICWithDelphiRecursive(str + 1, search, replace));
        
        strcpy(str, next); // Копіюємо результат назад в оригінальний рядок

        return str;
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Лічильники символів B, A, S, I, C
    int countB = 0, countA = 0, countS = 0, countI = 0, countC = 0;
    countBASICCharsRecursive(str, countB, countA, countS, countI, countC);

    // Виведення результату підрахунку символів
    cout << "Count of B: " << countB << endl;
    cout << "Count of A: " << countA << endl;
    cout << "Count of S: " << countS << endl;
    cout << "Count of I: " << countI << endl;
    cout << "Count of C: " << countC << endl;

    // Замінюємо "BASIC" на "Delphi" рекурсивно
    replaceBASICWithDelphiRecursive(str, "BASIC", "Delphi");
    cout << "Modified string: " << str << endl;

    return 0;
}
