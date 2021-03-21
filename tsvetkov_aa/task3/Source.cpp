#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
using namespace std;

class Redaktor
{
private:
	char *str;
	int x, y;
	int buffer;
	int lenght;
public:
	Redaktor()//�����������
	{
		str = new char[5];
		x = 0; y = 0;
		lenght = 4;
		buffer = 5;
		str[lenght] = '\0';
	}
	void lengh(int l)//��������� ����� ���� �����
	{
		delete[] str;
		buffer = l + 1;
		lenght = l;
		str = new char[buffer];
		str[lenght] = '\0';
	}
	int lengh()//������� ����� ���� �����
	{
		return lenght;
	}
	void poz(int _x, int _y)//������� ������� ���� � �������
	{
		x = _x;
		y = _y;
	}
	int retX()//������� ���������� X
	{
		return x;
	}
	int  retY()//������� ���������� Y
	{
		return y;
	}
	void read()//��������� ��������
	{
		char s;
		int i = 0;
		while (i != buffer)
		{
			s = _getch();
			switch (s) {
			case '\r':
				str[i] = '\0';
				return;
			case '\b':
				i--;
				if (i < 0)
					i++;
				else cout << "\b \b";
				break;
			default:
				if (i != lenght)
				{
					str[i] = s;
					cout << str[i];
					i++;
				}
			}
		}
	}
	char* strok()//������� ������
	{
		return str;
	}
	~Redaktor()//����������
	{
		delete [] str;
	}
};

void position(int x, int y)//����������� ������� � �������
{
	COORD position;										
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	position.X = x;									// ��������� ���������� X
	position.Y = y;									// ��������� ���������� Y
	SetConsoleCursorPosition(hConsole, position);
}

int menu()
{
	int a;
	cout << "�������� ���������� ��������" << endl;
	cout << "1.������ ����� ���� �����" << endl << "2.������ ����� ���� �����" << endl << "3.������ ������� ���� ����� � ���� �������" << endl << "4.������ ������� ���� ����� � ���� �������" << endl <<
		"5.������ ������ � ��������� ���������" << endl << "6.������ ��������� ������������� ������." << endl <<"0.�����" << endl;
	cin >> a;
	return a;
}

void main()
{
	SetConsoleCP(1251);//������� ���� ��� ����� � �������
	SetConsoleOutputCP(1251);
	cout << "�� ��������� ����� ���� ����� ����� 4" << endl;
	Redaktor ak;
	char* str;
	int m, size=4, x=0, y=0;
p:
	m = menu();
	switch (m)
	{
	case 1://������� ����� ���� �����
		cout << "������� ����� ���� �����" << endl;
	s:
		cin >> size;
		if (size < 0)
		{
			cout << "������������ �����, ������� �����" << endl;
			goto s;
		}
		ak.lengh(size);
		cout << "�������� ������� ������" << endl;
		break;
	case 2://������� ����� ���� �����
		size = ak.lengh();
		cout << "����� ���� ����� �����: " << size << endl;
		break;
	case 3://������� ��������� ���� �����
		cout << "������� ���������� X � Y " << endl;
	l:
		cin >> x >> y;
		if ((x < 0) || (y < 0))
		{
			cout << "������������ ����������, ������� �����" << endl;
			goto l;
		}
		ak.poz(x, y);
		cout << "�������� ������� ������" << endl;
		break;
	case 4://������� ��������� ���� �����
		cout << "���������� �� X: " << ak.retX() << endl;
		cout << "���������� �� Y: " << ak.retY() << endl;
		break;
	case 5://���������� ���������� ��������� � ���� ������
		system("cls");
		position(x, y);
		ak.read();
		system("cls");
		break;
	case 6://����� �� ������� ��������� ������������� ������
		str = ak.strok();
		cout << str <<endl;
		break;
	case 0://����� �� ���������
		return;
		break;
	}
	goto p;	
}