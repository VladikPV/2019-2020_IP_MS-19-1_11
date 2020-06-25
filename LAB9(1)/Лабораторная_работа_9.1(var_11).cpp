/*Завдання: Виконати задані дії із введенним текстом.

Індивідуальне завдання за варіантами:

11. Вивести всі слова, які повторюються та число їх повторень.*/

#include <iostream>
#include <Windows.h>
using namespace std;

const int maxLenPut = 300;
const int maxWords = 150;

char Put[maxLenPut]; // массив, содержащий ввод
char NextW[maxLenPut]; // массив, содержащий на каждой итерации определённого цыкла соотвецтвующее слово из массива Put

char qWords[maxWords][maxLenPut]; // двумерный массив, содержащий уникальный (не повторяющейся) набор слов из массива Put
int  cWords[maxWords]; // массив, индексы которого в соотвецтвии с индексами массива qWords, показывают количество повторений слов

int wordCount = 0; // переменная хранит количество добавленных слов в массив qWords

bool similar(char *A1, char *A2)
{
    if (strlen(A1) == strlen(A2))
    {
        for (int i = 0; A1[i] != '\0'; i++)
            if (A1[i] != A2[i]) return false;  // tolower() - функция, котрая приводит буквы в маленькие (английские) // toupper() приводит в большие (английские)
    }
    else return false;
    return true;
}
void str_copy(char *A1, char *A2)
{
    int i;
    for (i = 0; A2[i] != '\0'; i++)
        A1[i] = A2[i];
    A1[i] = '\0';
}
bool is_let(char a)
{
    if (a == ' ' || a == '.' || a == '!' || a == '/' || a == '?' || a == '\0'|| a == ',' || a == ';'|| a=='(' || a == ')')
        return false;
    return true;
}
int add_new_word(char NewWord[maxLenPut]) //передаем адрес первого элемента массива NextW(массив, содержащий на каждой итерации определённого цыкла соотвецтвующее слово из массива Put)
{
    int i = 0;
    while (i < wordCount) // int wordCount = 0;
    {
        if (similar(qWords[i], NewWord)) // проверка на соотвецтвие // if (strcmp(qWords[i], NewWord) == 0)
        {
            // слово нашли в нашем массиве уникальных слов qWords 
            cWords[i] = cWords[i] + 1;
            return 0;
        }
        i++;
    }
    // Если слово в NewWord не нашлось в массиве qWords
    // Добавляем слово в наш масив уникальных слов qWords
    str_copy(qWords[wordCount], NewWord);                                                                                      //strcpy_s(qWords[wordCount], NewWord);
    cWords[wordCount] = 1; //слово NewWord повторилось 1 раз
    wordCount++; //готовимся записывать новое слово в следующую строку двумерного массива qWords

    return 0;
}

int main()
{
    int i = 0;
    int symcnt = 0;

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << " Лабораторная работа №9.1\n";
    cout << "  Введите текст:\n ";
    cin.getline(Put, maxLenPut);

    NextW[0] = '\0';

    while (i <= strlen(Put)) // цикл просматривает все введённые буквы
    {
        if (is_let(Put[i])) // если россматриваемый символ - буква слова
        {
            NextW[symcnt] = Put[i]; // добавляем в массив NextW
            symcnt++;
        }
        else // иначе
        {
            if (symcnt > 0)
            {
                NextW[symcnt] = '\0'; // добавляем признак конца
                add_new_word(NextW); // полученный массив добавляем в двумерный, если такой же массив не был добавлен раньше
                NextW[0] = '\0';
                symcnt = 0; // в последующей итерации вводим следующее слово массива Put в начало NextW
            }
        }
        i++;
    }

    // -------------------------------
    i = 0;
    while (i < wordCount)
    {
        if (cWords[i] > 1) cout << " Слово [" << qWords[i] << "] встретилось " << cWords[i] << " раз" << '\n';
        i++;
    }
    return 0;
}