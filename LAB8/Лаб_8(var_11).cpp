
/*Завдання: Складіть програму, яка здійснює обробку вхідних даних за допомогою двовимірних масивів.

При виконанні лабораторної роботи слід врахувати наступне:

1. Дати користувачеві можливість вибору: вводити вхідні дані з консолі, чи вводити їх з файлу; у випадку вводу з консолі продемонструвати можливість пере напрямлення потоку вводу/виводу на файл.

2. При програмуванні однотипних підзадач (сортування, ввід/вивід масивів, знаходження суми стовпця матриці тощо) слід оформлювати їх у вигляді функцій.

Варіант 11. Задайте матриці А і В розмірністю (n x m), де n і m ≥ 6 (n¹m). Виконайте такі завдання:

1. знайдіть кількість від’ємних елементів в обох матрицях;

2. визначте матрицю С як результат транспонування матриці А,якщо кількість від’ємних елементів матриці А більша кількості від’ємних елементів матриці В (в іншому випадку – як результат транспонування матриці В);

3. упорядкуйте за спаданням значення елементів заданого стовпця.*/

#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;
const int c = 100;
int A[c][c], B[c][c], C[c][c];
int str(char lett, char called[])
{
    int a;
    cout << " Количество " << called << ' ' << lett << " (где " << lett << " >= 6): ";
    cin >> a;
    while (a < 6)
    {
        cout << " Внимание! Вы должны ввести число большое либо равное числу 6!" << endl;
        cout << " Количество " << called << ' ' << lett << " (где " << lett << " >= 6): ";
        cin.clear();
        while (cin.get() != '\n');
        cin >> a;
    }
    return a;
}
void PUT(char var[])
{
    cin.getline(var, 100);
    while ((var[0] != '1' && var[0] != '2') || (strlen(var) != 1))
    {
        cout << " Внимание! Введённое число должно быть единицей или двойкой!" << endl;
        cin.getline(var, 100);
    }
}

bool add_to_file(int M[][c], char var[], char file[], int n, int m)
{
    ofstream put;
    cout << " Выберете вариант для дозаписи объявленной матрицы в файл:\n";
    cout << "  1) ввести расположение файла вручную\n";
    cout << "  2) указать файл D:\\My_environment.txt\n";
    cout << " Введите выбранный Вами вариант: "; PUT(var);
    if (var[0] == '1')
    {
        cout << " Введите расположение файла вручную: ";
        cin.getline(file, 200); put.open(file, ios::app);
    }
    else
        put.open("D:\\My_environment.txt", ios::app);
    if (put.is_open())
    {
        put << endl << n << ' ' << m << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                put << M[i][j] << '\t';
            put << endl;
        }
        put.close();
        cout << " Дозапись в файл успешно завершена!\n";
        return false;
    }
    else
    {
        cout << " Файл не доступен! Но Вы можете попробовать выбрать другой\n";
        cout << " Хотите ли Вы дозаписать введённую матрицу в другой файл? (1 - да, 2 - нет)\n"; PUT(var);
        if (var[0] == '1') return true;
        else return false;
    }
}
void add_Matrix(int Mat[][c], char nam_Mat, int& n, int& m)
{
    char var[100], file[200], cal[] = "строк"; bool mist = false;
    cout << " Выберете вариант ввода матрицы " << nam_Mat << ":\n  1) вручную (с клавиатуры);\n  2) с файла.\n" << " Введите выбранный Вами вариант: "; PUT(var);
    if (var[0] == '1')
    {
        cout << "  Ввод матрицы с помощью клавиатуры:\n";
        cout << " Введите количество строк и столбцов матрицы " << nam_Mat << ":\n";
        n = str('n', cal);
        char cal[] = "столбцов";
        m = str('m', cal);
        cout << "  Задайте матрицу " << nam_Mat << ", где i - индекс строки, j - столбца, а " << nam_Mat << "[i][j] - элемент в матрице:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cout << ' ' << i * m + j + 1 << ") " << nam_Mat << '[' << i << "][" << j << "] = "; cin >> Mat[i][j];
            }
        cin.ignore();
        cout << " Хотите ли Вы дозаписать введённую матрицу в файл? (1 - да, 2 - нет)\n";
        PUT(var);
        if (var[0] == '1')
            while(add_to_file(Mat, var, file, n, m));
    }
    else
    {
        ifstream save;
        cout << "  Ввод матрицы " << nam_Mat << " с помощью файла:\n";
        cout << " Выберете вариант:\n";
        cout << "  1) ввести расположение файла вручную\n";
        cout << "  2) указать файл D:\\My_environment.txt\n";
        cout << " Введите выбранный Вами вариант: "; PUT(var);
        if (var[0] == '1')
        {
            cout << " Введите расположение файла вручную: ";
            cin.getline(file, 200); save.open(file);
        }
        else
            save.open("D:\\My_environment.txt");
        if (save.is_open())
        {
            save >> file; n = atoi(file);
            if (atoi(file) == 0 && file[0] != '0') mist = true;
            save >> file; m = atoi(file);
            if (atoi(file) == 0 && file[0] != '0') mist = true;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    save >> file; Mat[i][j] = atoi(file);
                    if (atoi(file) == 0 && file[0] != '0') mist = true;
                }
            save.close();
            cout << " Извлечённые данные из файла:" << endl;
            cout << "  n = " << n << endl;
            cout << "  m = " << m << endl;
            cout << " Матрица " << nam_Mat << " размером " << n << '*' << m << ':' << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << Mat[i][j] << '\t';
                }
                cout << endl;
            }
            if (n < 6 || m < 6 || mist) {
                cout << " Внимание! Извлечённые параметры не соотвецтвуют условиям ввода матрицы! Повторите попытку!\n";
                add_Matrix(Mat, nam_Mat, n, m);
            }
        }
        else {
            cout << " Файл не доступен! Но Вы можете попробовать задать матрицу " << nam_Mat << " ещё раз!";
            add_Matrix(Mat, nam_Mat, n, m);
        }
    }
}
int calcul_of_neg(int Mat[][c], char nam_Mat, int n, int m)
{
    int value = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (Mat[i][j] < 0) value++;
    cout << "  Количество отрицательных элементов в матрице " << nam_Mat << ':' << value << '\n';
    return value;
}
void Transpon_Mat_into_new(int Mat[][c], int n, int m)
{
    char var[100], file[200];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[j][i] = Mat[i][j];
    // вывод матрицы
    cout << " Вывод транспонированной матрицы с большим числом отрицательных элементов:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << '\t';
        cout << '\n';
    }
    cout << " Хотите ли Вы дозаписать транспонированную матрицу в файл? (1 - да, 2 - нет)\n";
    PUT(var);
    if (var[0] == '1') while (add_to_file(C, var, file, m, n));
}
bool comp(int x, int y)
{
    return x < y;
}
void SWAP(int& x, int& y)
{
    int t;
    t = x; x = y; y = t;
}
void sort_column(int Mat[][c], char nam_Mat, int n, int m)
{
    char var[100], file[200];
    int J;
    cout << " Введите столбик матрицы " << nam_Mat << ", который будет сортирован по убыванию значений элементов в нём: ";
    cin >> J;
    while (1 > J || J > m)
    {
        cout << " Номер столбика должен находиться в диапазоне от 1 до " << m << " включительно!\n"
            << " Повторите попытку. Введите столбик матрицы " << nam_Mat << ", который будет сортирован по убыванию значений элементов в нём: ";
        cin.clear();
        while (cin.get() != '\n');
        cin >> J;
    }
    for (int L = 0; L < n; L++)
        for (int R = L + 1; R < n; R++)
            if (comp(Mat[L][J - 1], Mat[R][J - 1]))
                for (int I = 0; I < m; I++)
                    SWAP(Mat[L][I], Mat[R][I]);
    cout << " Вид сортированной матрицы " << nam_Mat << " по убыванию значений элементов в столбике " << J << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << Mat[i][j] << '\t';
        cout << '\n';
    }
    cout << " Хотите ли Вы дозаписать сортированную матрицу " << nam_Mat << " в файл? (1 - да, 2 - нет)\n";
    cin.ignore();
    PUT(var);
    if (var[0] == '1') while (add_to_file(Mat, var, file, n, m));
}
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int A_n, A_m, B_n, B_m, neg_A, neg_B;
    cout << "  Задание 1, вариант 11\n";
    add_Matrix(A, 'A', A_n, A_m); //ввод матрицы
    add_Matrix(B, 'B', B_n, B_m); //ввод матрицы
    // определение количества отрицательных значений
    cout << " Результаты вычисений:\n";
    neg_A = calcul_of_neg(A, 'A', A_n, A_m); // определение количества отрицательных элементов в матрице A
    neg_B = calcul_of_neg(B, 'B', B_n, B_m); // определение количества отрицательных элементов в матрице B
    (neg_A < neg_B) ? Transpon_Mat_into_new(B, B_n, B_m) : Transpon_Mat_into_new(A, A_n, A_m);
    sort_column(A, 'A', A_n, A_m); // сортировка по убыванию значений элементов заданого столбика
    sort_column(B, 'B', B_n, B_m); // сортировка по убыванию значений элементов заданого столбика
    return 0;
}
