#include<iostream>
#include<string.h>
using namespace std;


//#define COPY_AND_LENGHT
//#define COPY_MEMORY
//#define CONCATENATION
//#define COMPARISON


// string.h - библиотека содержит функции, написанные на языке С
// cstring


void main()
{
	setlocale(LC_ALL, "");

#ifdef COPY_AND_LENGHT
	const unsigned int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	cin.getline(str, SIZE);
	cout << str << endl;
	cout << "Длина введенной строки: " << strlen(str) << endl;

	// Копирование строк:
	char dst[SIZE] = {};
	strcpy(dst, str); //string copy
	// strcpy(dst, src);
	// dst (destinanion) - строка-получатель, в которую скопируется другая строка
	// src (source) - строка-источник, содержимое которой будем копировать
	cout << "Копия строки: " << dst << endl; // No SDL checks в свойствах, чтобы не беспокоил по безопасности  
#endif // COPY_AND_LENGHT

#ifdef COPY_MEMORY
	const int SIZE = 5;
	int arr[SIZE] = { 3,5,8,13,21 };
	int brr[SIZE] = {};
	memcpy(brr, arr, SIZE * sizeof(int)); // SIZE это количество в байтах, поэтому умножаем
	for (int i = 0; i < SIZE; i++)
	{
		cout << brr[i] << "\t";
	}
	cout << endl;
#endif // COPY_MEMORY

#ifdef CONCATENATION
	// Конкатенация (объединение/слияние) строк:

	const size_t SIZE = 256;
	char str1[SIZE] = {};
	char str2[SIZE] = {};
	cout << "Введите первую строку: "; cin >> str1;
	cout << "Введите вторую строку: "; cin >> str2;
	//strcat(str1, str2); // += лепитв кучу и записывает в первую строку
	strncat(str1, str2, 2); // число символов второй строки, которые нужно скопировать
	cout << str1 << endl;
	cout << str2 << endl;
#endif // CONCATENATION

#ifdef COMPARISON
	/*char str1[] = "hello ";
char str2[] = "Hello";
cout << strcmp(str1, str2) << endl;*/
	const char* movie[] =
	{
		"Hello",
		"World",
		"Avatar",
		"Terminator",
		"Captain America",
		"Tor",
		"Loki"
	};

	for (int i = 0; i < sizeof(movie) / sizeof(const char*); i++)
	{
		cout << movie[i] << endl;
	}

	for (int i = 0; i < sizeof(movie) / sizeof(const char*); i++)
	{
		for (int j = i + 1; j < sizeof(movie) / sizeof(const char*); j++)
		{
			if (strcmp(movie[i], movie[j]) > 0)
			{
				const char* buffer = movie[i];
				movie[i] = movie[j];
				movie[j] = buffer;
			}
		}
	}

	cout << "--------------------------------------" << endl;

	for (int i = 0; i < sizeof(movie) / sizeof(const char*); i++)
	{
		cout << movie[i] << endl;
	}
#endif // COMPARISON

	const size_t n = 5;
	int arr[n];
	memset(arr, 0x000000FF, n*sizeof(int));
	for (int i = 0; i <n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

}