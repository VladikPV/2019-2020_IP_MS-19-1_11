#include <iostream>
#include <Windows.h>
using namespace std;
void PUT(char var[])
{
    cout << " Введите вариант: ";
    cin.getline(var, 100);
    while ((var[0] != '1' && var[0] != '2' && var[0] != '3' && var[0] != '4') || (strlen(var) != 1))
    {
        cout << " Внимание! Введённое число должно быть единицей, двойкой, тройкой или четвёркой!" << endl;
        cout << " Введите вариант: ";
        cin.getline(var, 100);
    }
}
char* imitator_strrchr(char* str, int symbol)
{
    int last_symbol;
    for (last_symbol = 0; str[last_symbol] != '\0'; last_symbol++);
    while (last_symbol >= 0)
    {
        if ((int)str[last_symbol] == symbol)
            return &str[last_symbol];
        last_symbol--;
    }
    return nullptr; // нулевой указатель
}
int imitator_strncmp(const char* str1, const char* str2, int len_act)
{
    for (int i = 0; i < len_act; i++)
    {
        if(str1[i] == '\0' && str2[i] == '\0') return 0;
        if((unsigned int)str1[i] > (unsigned int)str2[i]) return 1;
        if((unsigned int)str1[i] < (unsigned int)str2[i]) return -1;
    }
    return 0;
}
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char var[100], string[500],additional_string[500], symbol; int universal;
    cout << " Лабораторная работа 9.2" << endl;
    cout << "  Вариант 11" << endl;
    do
    {
        cout << " Выберете одну из стандартных функций:" << endl;
        cout << "  1) функция strrchr()\n  2) функция strncmp()\n  3) очистить консоль\n  4) выход с программы\n";
        PUT(var);
        switch (var[0])
        {
        case '1':
            cout << " Функция strrchr()" << endl;
            cout << "  Введите строку: "; cin.getline(string, 500);
            cout << "  Введите символ для переобразования его в кодировку таблицы ASCII: ";
            cin >> symbol;
            while (cin.get() != '\n')
            {
                while (cin.get() != '\n');
                cout << "  Вы должны ввести один символ!" << endl;
                cout << "  Введите символ для переобразования его в кодировку таблицы ASCII: ";
                cin >> symbol;
            }
            universal = (unsigned int)symbol;
            cout << "  Код введённого символа: " << universal << endl << endl;
            cout << " Результат моей функции (значение - указатель на последний элемент, соотвецтвующий введённому): ";
            cout << imitator_strrchr(string, universal);
            cout << endl << " Результат стандартной функции (значение такое же): ";

            cout << strrchr(string, universal);
            
            cout << endl << endl;
            break;
        case '2':
            cout << " Функция strncmp()" << endl;
            cout << "  Введите строку 1: "; cin.getline(string, 500);
            cout << "  Введите строку 2: "; cin.getline(additional_string, 500);
            cout << "  Введите число n, которое обозначает первые n символов введённых массивов: ";
            cin >> universal;
            cout << endl;
            cout << " Результат моей функции: ";
            cout << imitator_strncmp(string, additional_string, universal);
            cout << endl << " Результат стандартной функции: ";

            cout << strncmp(string, additional_string, universal);

            cout << endl << endl;
            break;
        case '3': system("CLS");
            cout << " Лабораторная работа 9.2" << endl;
            cout << "  Вариант 11" << endl;
        }
    }
    while (var[0] != '4');
    return 0;
}