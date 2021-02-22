
#include <iostream>
#include <cmath>
using namespace std;
class Time 
{
private:
	int m_hours;
	int m_minutes;
	int m_seconds;
public:
	Time(int a, int b, int c)//�����������
	{
		m_hours = a;
		m_minutes = b;
		m_seconds = c;
	}
	void Setime(int hours, int minutes, int seconds)//������� ��������� �������
	{
		m_hours = hours;
		m_minutes = minutes;
		m_seconds = seconds;
	}

	void Print()//������� ������ �������������� ������� � �������
	{
		cout << "����" <<'\t'<< "������" << '\t'<<"�������" << endl;
		cout << m_hours <<'\t'<< m_minutes << '\t'<<m_seconds <<endl;
	}

	int difference(int a, int b, int c)//������� ���������� ������� �������������� � ��������� �������
	{
		int priv, zadan, diff;
		priv = (m_hours * 3600) + (m_minutes * 60) + m_seconds;
		zadan= (a * 3600) + (b* 60) + c;
		diff = abs(priv - zadan);
		return diff;
	}
	void offset(int a, int b, int c, int m)//������� ������ ������� �� �������� ��������
	{
		int priv, zadan, diff;
		priv = (m_hours * 3600) + (m_minutes * 60) + m_seconds;
		zadan = (a * 3600) + (b * 60) + c;
		if (m == 1)
		{
			diff = priv + zadan;
			while (diff > 86400)
				diff = diff - 86400;
		
		}
		if (m == 2)
		{
			diff = priv - zadan;
			while (diff < 0)
				diff = 86400 + diff;
		}
		m_hours = diff / 3600;
		diff = diff - m_hours * 3600;
		m_minutes = diff / 60;
		diff = diff - m_minutes * 60;
		m_seconds = diff;
	}




};
int menu()//����� ���� �� �������
{
	int a;
	cout << "�������� ���������� ��������"<<endl;
	cout << "1.���������� �����" << endl << "2.������ �����" << endl << "3.��������� ������� ����� �������� �������� � �������������" << endl << "4.�������� �����"<<endl <<"0.�����"<< endl;

	cin >> a;
	return a;
}


void main()
{
	setlocale(LC_ALL, "Russian");
	Time k(0,0,0);
d:
	int a, b, c;
	int m,diff;
	m = menu();
	switch (m)
	{
	case 1://��������� �������
	l:
		cout << "���������� ����� (������: ����, ������, �������)" << endl;
		cin >> a >> b >> c;
		if ((a >= 24) || (a < 0) || (b >= 60) || (c >= 60) || (b < 0) || (c < 0))
		{
			cout << "�������� ������, ���������� �����" << endl;
			goto l;
		}
		else
		{
			k.Setime(a, b, c);
			cout << "����� ������� �����������" << endl;
		}
		break;

	case 2://����� ������� �� �������
		k.Print();
		break;
	case 3:// ���������� ������� �������������� � ��������� �������
	k:
		cout << "������� ����� ��� ���������� ������� (������: ����, ������, �������)" << endl;
		cin >> a >> b >> c;
		if ((a >= 24) || (a < 0) || (b >= 60) || (c >= 60) || (b < 0) || (c < 0))
		{
			cout << "�������� ������, ���������� �����" << endl;
			goto k;
		}
		diff = k.difference(a, b, c);
		a = diff / 3600;
		diff = diff - a * 3600;
		b = diff / 60;
		diff = diff - b * 60;
		c = diff;
		cout << "������� ����������:" << endl;
		cout << "����" << '\t' << "������" << '\t' << "�������" << endl;
		cout << a << '\t' << b << '\t' << c << endl;
		break;

	case 4://�������� �������
	p:
		cout << "������� �������� (������: ����, ������, �������)" << endl;
		cin >> a >> b >> c;
		if ( (a < 0) || (b >= 60) || (c >= 60) || (b < 0) || (c < 0))
		{
			cout << "�������� ������, ���������� �����" << endl;
			goto p;
		}
		cout << "� ����� ������� �������:" << endl << "1.� �������\n2.� �������" << endl;
		cin >> m;
		k.offset(a, b, c,m);
		cout << "�������� ��������� �������" << endl;
		break;
	case 0://����� �� ���������
		return;
		break;


	
	}
	goto d;




	
	
	
	


}