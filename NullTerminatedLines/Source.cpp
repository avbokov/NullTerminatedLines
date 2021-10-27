//NULL Terminated Lines
// '\0'
#include<iostream>
#include<Windows.h>

using namespace std;

int StringLenght(char str[]); // Принимает строку и возвращает размер строки
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);

bool is_int_number(char str[]);
bool is_bin_number(char str[]);
bool is_hex_number(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251); // Выставляет кодировку на ввод
	SetConsoleOutputCP(1251); // Выставляет кодировку на вывод

	//char str[] = {'H', 'e', 'l', 'l', 'o','\0'}; // 1 способ
	/*char str[] = "Hello";						   // 2 способ
	cout << str << endl;
	cout << sizeof(str) << endl;
	cout << str[1] << endl;*/

	const int n = 30;								// 3 способ
	char str[n] = {};
	cout << "Введите строку: "; // выводит символы в кодировке 866
	//cin >> str; // не знает размер строки (после пробела для cin - другая переменная)

	cin.getline(str, n); // знает размер строки

	//cout << str << endl;
	cout << StringLenght(str) << endl;
	//to_upper(str);
	//to_lower(str);
	//shrink(str);
	//cout << str << endl;

	cout << "Является ли введённая строка двоичным числом? " << is_bin_number(str) << endl;
	cout << "Является ли введённая строка десятичным числом? " << is_int_number(str) << endl;
	cout << "Является ли введённая строка шестнадцатеричным числом? " << is_hex_number(str) << endl;

	
}

int StringLenght(char str[])
{
	/*cout << typeid(str).name() << endl;
	return sizeof(str);*/
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
		}
		if ((str[i] >= -32) && (str[i] <= -1))
		{
			str[i] = str[i] - 32;
		}
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			str[i] = str[i] + 32;
		}
		if ((str[i] >= -64) && (str[i] <= -33))
		{
			str[i] = str[i] + 32;
		}
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] == ' ') && (str[i + 1] == ' '))
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}

bool is_int_number(char str[])
{
	if (StringLenght(str) > 1 && str[0] == '0') return false; // предполагаем, что десятичное число не может начинаться с нуля
	int N = 0; // счётчик символов от 0 до 9
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 48) && (str[i] <= 57))
		{
			N++;
		}
	}
	if (N == StringLenght(str))
	{
		return true;
	}
	else return false;
}

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] != 48) && (str[i] != 49))
		{
			return false;
		}
	}
	return true;
}

bool is_hex_number(char str[])
{
	int N = 0; // счётчик символов от 0 до 9 и от a(A) до f(F)
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 48) && (str[i] <= 57))
		{
			N++;
		}
		if ((str[i] >= 65) && (str[i] <= 70))
		{
			N++;
		}
		if ((str[i] >= 97) && (str[i] <= 102))
		{
			N++;
		}
	}
	if (N == StringLenght(str))
	{
		return true;
	}
	else return false;
}