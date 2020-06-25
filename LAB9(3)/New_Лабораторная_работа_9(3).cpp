#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include "Header.h"

using namespace std;

int main(int argc, char** argv)
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    printf("  Лабораторная_работа_9.3\n   Вариант_11\n");

    FILE* fin = NULL, * fout;

    char f_name1[101] = "\0",
         f_name2[101],
         str[2000],
         strd[3000];

    int i,
        iteration;

    bool request1,
         request2;

    if (argc == 2) {
        fin = fopen(argv[1], "r");
        for (i = 0; argv[1][i] != '\0'; i++)
            f_name1[i] = argv[1][i];
        f_name1[i] = '\0';
    }

    if (fin == NULL || r_checker(fin, f_name1))
        while (fprintf(stdout, " Задайте имя входящего файла: "), scanf("%s", f_name1),
            (fin = fopen(f_name1, "r")) == NULL || r_checker(fin, f_name1) )
            if (fin == NULL)printf(" Файл %s открыть не удалось! Попробуйте ещё раз!\n", f_name1);
            else printf(" Длина одной из строк в файле %s превышает 80 символов! По условиям лабороторной работы такого не должно быть!\n", f_name1);
    for (i = 0; f_name1[i] != '\0'; i++);
    while (f_name1[i] != '\\') i--;
    i = i + 3; //индекс последнего
    for (iteration = 0; iteration <= i; iteration++)
    {
        if (f_name1[iteration] == '.') break;
        f_name2[iteration] = f_name1[iteration];
    }

    f_name2[iteration] = '_'; f_name2[iteration + 1] = 'o'; f_name2[iteration + 2] = 'u'; f_name2[iteration + 3] = 't'; f_name2[iteration + 4] = '.'; f_name2[iteration + 5] = 'd'; f_name2[iteration + 6] = 'a'; f_name2[iteration + 7] = 't'; f_name2[iteration + 8] = '\0';

    fout = fopen(f_name2, "w");

    request1 = request("входного файла");
    request2 = request("выходного файла");

    if(request1) printf("\n\n Содержимое файла %s:\n\n", f_name1);
    while (fgets(str, 200, fin))
    {
        if(request1)printf("%s", str);
        fputs(str, fout);
    }
    fclose(fin); fin = fopen(f_name1, "r");

    if (request2) printf("\n\n Содержимое файла %s:\n\n", f_name2);

    if (request2)
    {
        while (fgets(str, 200, fin))
        {
            printf("%s", str);
        }
        fclose(fin); fin = fopen(f_name1, "r");
        fprintf(stdout, "\n\n---CONVERTED---\n\n");
    }
    fprintf(fout, "\n\n---CONVERTED---\n\n");

    i = 0; // переменная теперь будет хранить количество цифр
    while (fgets(str, 200, fin)) // NULL при неудаче
    {
        convert_our_numbers_and_count_amount_of_digits(str, strd, i);
        //fputs(strd, fout);
        fprintf(fout, "%s", strd);
        if (request2)fprintf(stdout, "%s", strd);
    }
    fprintf(fout, "\n\n  Количество цифр в файле %s равно %d\n", f_name1, i);
    if (request2) printf("\n\n  Количество цифр в файле %s составляет %d\n", f_name1, i);
    fclose(fin);
    fclose(fout);
    return 0;
}