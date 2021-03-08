#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Matrix
{
private:
	int** matr;
	int size;
public:
	Matrix(int a)
	{
		int i = 0;
		size = a;
		matr = (int**)malloc(sizeof(int*) * size);//�������� ���������� ������� size*size
		for (i = 0; i < size; i++)
			matr[i] = (int*)malloc(sizeof(int) * size);

		for (i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				matr[i][j] = 0;//��������� �������
		}


	}
	void setsize(int a)//������� ������� �������
	{

		for (int i = 0; i < size; i++)//������� ������
		{
			free(matr[i]);
		}
		free(matr);
		size = a;

		matr = (int**)malloc(sizeof(int) * size * size);//������� ����� � ����� ��������
		for (int i = 0; i < size; i++)
			matr[i] = (int*)malloc(sizeof(int) * size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				matr[i][j] = 0;
		}
	}
	int getsize()//������� ������� �������
	{
		return size;
	}
	void Print()//����� ������� �� �������
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (j != size - 1)
					cout << matr[i][j] << "\t";
				else
					cout << matr[i][j];
			}
			cout << endl;
		}

	}
	void setind(int i, int j, int a)//������� �������� �� ��� �������
	{
		matr[i][j] = a;
	}
	int getind(int i, int j)// ������� �������� �������� �� ��� �������
	{
		return matr[i][j];
	}
	bool diag()//�������� �� ������������ ������������
	{

		int i, s; int** a;
		a = (int**)malloc(size * sizeof(int*));//��������� ������ �� 2 ����� � size ��������
		// � ������� ������ ������� �������� ��������� �� ���������, � ������ ����� ��������� ������ ������ ������

		for (i = 0; i < size; i++)  
		{
			
			a[i] = (int*)malloc(2 * sizeof(int));
		}
		bool flag = 1;//���������� true ,���� �������� ���� ���� ������������ ������� ������ ����� ��������� � ������ flag ���������� 0
		for (i = 0; i < size; i++)
		{
			s = 0;
			a[i][0] = matr[i][i];
			for (int j = 0; j < size; j++)
			{
				if (j != i)
					s += matr[i][j];
			}
			a[i][1] = s;
		}
		for (int j = 0; j < size; j++)
			if (a[j][1] > a[j][0])
				flag = 0;
		for (int i = 0; i < size; i++)//������ ��������� ��������� ������
		{
			free(a[i]);
		}

		free(a);
		return flag;
	}

	Matrix operator+ (const Matrix& c)//�������� �������� ������ ������ �������
	{
		Matrix res(size);

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				res.matr[i][j] = matr[i][j] + c.matr[i][j];
			}

		;
		return res;
	}

	Matrix(const Matrix& m)//����������� �����������
	{

		size = m.size;
		matr = (int**)malloc(sizeof(int*) * size);//�������� �������
		for (int i = 0; i < size; i++)
		{
			matr[i] = (int*)malloc(sizeof(int) * size);
		}
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matr[i][j] = m.matr[i][j];
	}
	~Matrix()//����������
	{
		for (int i = 0; i < size; i++)
		{
			free(matr[i]);
		}
		free(matr);
	}

};


int menu()//����� ���� �� �������
{
	int a;
	cout << "�������� ���������� ��������" << endl;
	cout << "1.������ ������ �������" << endl << "2.������ ������ �������" << endl << "3.������ ������� ������� �� ��� ��������" << endl << "4.������ ������� ������� �� ��� ��������" << endl;
	cout << "5.���������, �������� �� ������� ������������ �������������" << endl << "6.��������� ����� ���� ������ ������ �������" << endl <<"7.������� ������� �� �������"<<endl<< "0.�����" << endl;
	cin >> a;
	return a;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int m, size = 0, i, j, a;
	bool flag;
	Matrix p(2);
	cout << "�� ��������� ������ ���������� ������� ����� 2" << endl;
p:
	size = p.getsize();//���������� ���� ������������ ������� case 3,case 4 �� setsize
	m = menu();
	switch (m)
	{
	case 1://������� �������
		cout << "������� ������ �������" << endl;
		cin >> size;
		p.setsize(size);
		break;
	case 2://������� �������
		size = p.getsize();
		cout << "���������� ������� " << size << " �������" << endl;
		break;
	case 3://������� �������� �� �������
		cout << "������� ������ ��������" << endl;
	l:
		cin >> i >> j;
		if ((i > size) || (i < 1) || (j > size) || (j < 1))
		{
			cout << "�������������� ������,������� �����" << endl;
			goto l;
		}
		cout << "������� ������������� ��������" << endl;
		cin >> a;
		p.setind(i - 1, j - 1, a);
		cout << "�������� ������� ������" << endl;
		break;
	case 4://������� �������� �� �������
		cout << "������� ������ ��������" << endl;
	k:
		cin >> i >> j;
		if ((i > size) || (i < 1) || (j > size) || (j < 1))
		{
			cout << "�������������� ������,������� �����" << endl;
			goto k;
		}
		a = p.getind(i - 1, j - 1);
		cout << "������� ������� " << a << endl;
		break;
	case 5://�������� �� ������������ ������������
		flag = p.diag();
		if (flag == 1)
			cout << "������� �������� ������������ �������������" << endl;
		else cout << "������� �� �������� ������������ �������������" << endl;
		break;
	case 6://������������ ������
	{
		size = p.getsize();
		Matrix c(size);

		for (i = 0; i < size; i++)//������������� ������� ����������-�������(������ �������� � ������� setind)
		{
			cout << "������� �������� ��������� " << i + 1 << " ������" << endl;
			for (j = 0; j < size; j++)
			{
				cin >> a;
				c.setind(i, j, a);
			}

		}

		
		Matrix rep(p + c);
		cout << "����� ������ �����:" << endl;
		rep.Print();
		break;
	}
	case 7://��� �������� ����� ������� �� �����(���� � ������� ����� �� �����������)
		p.Print();
		break;
	case 0://����� �� ���������
		return;
		break;
	}
	goto p;









}