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
	ofstream fout("201 ready.txt", ios::app);
	ifstream fin("201 RAW.txt");
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

	system("notepad 201 ready.txt");
}