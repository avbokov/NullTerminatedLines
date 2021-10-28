#include<iostream>
#include<fstream> // File straem (файловые потоки)
using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//cout << "Hello World" << endl;
	ofstream fout("file.txt", ios::app);		// создаём и открываем поток
	fout << "Hello World" << endl;
	fout.close();					// потоки обязательно нужно закрывать
	//system("notepad file.txt"); // открывать файл
	system("more file.txt"); // открывать содержимое файла в консоли  
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	ifstream fin;	// создаём поток
	fin.open("file.txt");
	
	const unsigned int SIZE = 10240;
	char sz_buffer[SIZE]{};	// в эту строку будем читать из файла
	// sz - String Zero (строка, заканчивающаяся нулём)
	if (fin.is_open())		// проверяем, открыт ли файл
	{
		//TODO: если открыт, будем читать
		while (!fin.eof())	// пока НЕ конец файла, 
		{
			// будет производиться чтение
			// eof() - End Of File.
			//fin >> sz_buffer;				// для строки без пробелов
			fin.ignore();
			fin.getline(sz_buffer, SIZE);	// для строки с пробелами
			cout << sz_buffer << endl;
		}
	}
	else
	{
		cerr << "Error: file not found" << endl; // cerr - канал ошибок (ошибки принято отправлять в этот канал)
	}
	fin.close();

#endif // READ_FROM_FILE

	// В файле 201 RAW.txt поменять местами столбики с МАС-адресом и IP-адресом
	// Исходный файл должен остаться неизменным, программа должна создать новый изменённый файл
	// 201 ready.txt
	/*ofstream fout("201 ready.txt");
	fout << "Hello";
	fout.close();
	system("more 201 ready.txt");
	system("notepad 201 ready.txt");*/

	const unsigned int SIZE = 256; // выделяем размер буфера в байтах
	char sz_source_filename[SIZE] = {};
	char sz_destination_filename[SIZE] = {};
	cout << "Введите имя исходного файла: "; cin.getline(sz_source_filename, SIZE);
	// 1) Находим последнюю точку в строке
	char* extension = strrchr(sz_source_filename, '.');
	// char* strchr(char* str, char symbol); синтаксис функции
	// char* strrchr(char* str, char symbol); синтаксис функции
	nullptr; // указатель на 0, указатель в никуда.
	// 2) Теперь нужно проверить, являются ли символы после последней точке правильным расширением файла
	if (extension == nullptr || strcmp(extension, ".txt") != 0)
	{
		strcat(sz_source_filename, ".txt");
	}

	//cout << (extension ? extension : "У файла нет расширения") << endl;
	cout << "Введите имя конечного файла: "; cin.getline(sz_destination_filename, SIZE);
	extension = strrchr(sz_destination_filename, '.');
	if (extension == nullptr || strcmp(extension, ".txt") != 0)
	{
		strcat(sz_destination_filename, ".txt");
	}
	//cout << (extension ? extension : "У файла нет расширения") << endl;

	ifstream fin(sz_source_filename);
	ofstream fout(sz_destination_filename);
	const unsigned int IP_SIZE = 16;
	const unsigned int MAC_SIZE = 18;
	char sz_ip_buffer[IP_SIZE] = {};
	char sz_mac_buffer[MAC_SIZE] = {};
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			
			fout << sz_mac_buffer << "\t";
			fout << sz_ip_buffer << "\n";
			
		}
	}
	else
	{
		cerr << "Error: file not found!" << endl;
	}
	fin.close();
	fout.close();

	char sz_cmd[SIZE] = "notepad ";
	strcat(sz_cmd, sz_destination_filename);
	// strcat(sz_dst, sz_src); //strcat выполняет конкатенацию (слияние) строк,
	// например, "Hello" + "World" = "HelloWorld";
	// sz_dst - строка получатель, в которую будет сохранен результат конкатенации
	// sz_src - строка источник, которая будет добавлена к получателю

	system(sz_cmd);
}