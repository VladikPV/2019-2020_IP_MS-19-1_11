#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
bool request(const char *std)
{
    char get[50];
    while (printf(" �������� �� ����� %s �� ����� �������?(1 - ��, 2 - ���)\n  ������� �����: ", std),
        scanf("%s", get), (get[0] != '1' && get[0] != '2') || get[1] != '\0')
        printf(" �� ����� ������������ �����! ��������� �������!\n");
    if (get[0] == '1') return true;
    return false;
}
bool r_checker(FILE* point, char* named)
{
    char str[1000];
        while (fgets(str, 1000, point))
            if (strlen(str) > 80)
            {
                fclose(point); point = fopen(named, "r");
                return true;
            }
        fclose(point); point = fopen(named, "r");
    return false;
}
void str_copy(char* A1, char* A2) // �������� ����� A2 � ������ A1 
{
    int i;
    for (i = 0; A2[i] != '\0'; i++)
        A1[i] = A2[i];
    A1[i] = '\0';
}
void My_strcat(char* A, const char* B) // ���������� � ������� A ������ B
{
    int Ai, Bi;
    for (Ai = 0; A[Ai] != '\0'; Ai++); // ������ \0-��
    for (Bi = 0; B[Bi] != '\0'; Bi++)
        A[Ai + Bi] = B[Bi];
    A[Ai + Bi] = '\0';
}
bool is_let_or_num_and_amount_of_digits(char a, int &i)
{
    if (a == ' ' || a == '.' || a == '!' || a == '/' || a == '?' || a == '\0' || a == ',' || a == ';' || a == '(' || a == ')' || a == '\n')
        return false;
    if ('0' <= a && a <= '9') i++;
    return true;
}

bool is_num(char* fData)
{
    int i = 0;
    if (fData[0] == '\0') return false;
    while (i < strlen(fData))
    {
        if /*((fData[i] < '0' || fData[i] > '9') && fData[0] != '-')*/ ((fData[i] < '0' || fData[i] > '9') && !(i == 0 && fData[i] == '-'))
        {
            return false;
        }
        i++;
    }
    return true;
}

void convert_simple_number(char* inData)
{
    char keeping[2000];
    int i = 0;
    int rl;

    keeping[0] = '"';
    keeping[1] = '\0';

    while (inData[i] != '\0')
    {
        if (i > 0)
        {
            My_strcat(keeping, " ");
        }

        switch (inData[i])
        {
        case '1':My_strcat(keeping, "����"); break;
        case '2':My_strcat(keeping, "���"); break;
        case '3':My_strcat(keeping, "���"); break;
        case '4':My_strcat(keeping, "������"); break;
        case '5':My_strcat(keeping, "����"); break;
        case '6':My_strcat(keeping, "�����"); break;
        case '7':My_strcat(keeping, "����"); break;
        case '8':My_strcat(keeping, "������"); break;
        case '9':My_strcat(keeping, "������"); break;
        case '0':My_strcat(keeping, "����"); break;
        case '-':My_strcat(keeping, "�����");
        }
        i++;
    }
    rl = strlen(keeping);
    keeping[rl] = '"';
    keeping[rl + 1] = '\0';
    str_copy(inData, keeping);
}

void convert_our_numbers_and_count_amount_of_digits(char* inData, char* outData, int & amount_of_digits)
{
    int i = 0;
    int symcnt = 0;
    char NextW[1000];

    outData[0] = '\0';
    NextW[0] = '\0';

    while (i <= strlen(inData)) // ��������� ��������. ������� ������� inData - '\0'
    {
        if (is_let_or_num_and_amount_of_digits(inData[i], amount_of_digits)) // ���� ��������������� ������ - ����� ����� ��� �����
        {
            NextW[symcnt] = inData[i]; // ��������� � ������ NextW
            symcnt++;
        }
        else // �����
        {
            NextW[symcnt] = '\0';

            if (is_num(NextW)) 
            {
                //������������� ����� � ������
                convert_simple_number(NextW);
                symcnt = strlen(NextW);
            }

            NextW[symcnt] = inData[i];
            NextW[symcnt + 1] = '\0';
            My_strcat(outData, NextW);

            NextW[0] = '\0';
            symcnt = 0; // � ����������� �������� ������ ��������� ����� ������� � ������ NextW
        }
        i++;
    }
}