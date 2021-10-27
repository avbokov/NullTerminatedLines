#include<iostream>
#include<fstream> // File straem (�������� ������)
using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//cout << "Hello World" << endl;
	ofstream fout("file.txt", ios::app);		// ������ � ��������� �����
	fout << "Hello World" << endl;
	fout.close();					// ������ ����������� ����� ���������
	//system("notepad file.txt"); // ��������� ����
	system("more file.txt"); // ��������� ���������� ����� � �������  
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	ifstream fin;	// ������ �����
	fin.open("file.txt");
	
	const unsigned int SIZE = 10240;
	char sz_buffer[SIZE]{};	// � ��� ������ ����� ������ �� �����
	// sz - String Zero (������, ��������������� ����)
	if (fin.is_open())		// ���������, ������ �� ����
	{
		//TODO: ���� ������, ����� ������
		while (!fin.eof())	// ���� �� ����� �����, 
		{
			// ����� ������������� ������
			// eof() - End Of File.
			//fin >> sz_buffer;				// ��� ������ ��� ��������
			fin.ignore();
			fin.getline(sz_buffer, SIZE);	// ��� ������ � ���������
			cout << sz_buffer << endl;
		}
	}
	else
	{
		cerr << "Error: file not found" << endl; // cerr - ����� ������ (������ ������� ���������� � ���� �����)
	}
	fin.close();

#endif // READ_FROM_FILE

	// � ����� 201 RAW.txt �������� ������� �������� � ���-������� � IP-�������
	// �������� ���� ������ �������� ����������, ��������� ������ ������� ����� ��������� ����
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