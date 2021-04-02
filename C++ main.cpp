#include <iostream>
#include <windows.h>

#define __MAX_ACCOUNT_ 101

using namespace std;

typedef struct user
{
	unsigned int Account_ID;
	char user_name[10];
	unsigned int Amount;
	char Activation = 0;
}user;

user _A_User[__MAX_ACCOUNT_];

void Opening_Account()
{
	int i;

	for (i = 1; i < __MAX_ACCOUNT_; i++)
	{
		if (_A_User[i].Activation == 0)
		{
			break;
		}
	}

	_A_User[i].Activation = 1;
	_A_User[i].Account_ID = i;
	_A_User[i].Amount = 0;
	cout << "���� : ";
	cin >> _A_User[i].user_name;
	cout << endl;

	cout << "�ű� ������ "<< _A_User[i].user_name << "���� ���¹�ȣ�� " << _A_User[i].Account_ID << "�Դϴ�." << endl;
	cout << endl;

	return;
}

int Account_Find()
{
	unsigned int Account_ID;

	int i, checker = 0;

	while (checker == 0)
	{
		cout << "���¹�ȣ : ";
		cin >> Account_ID;

		if (Account_ID == 0)
		{
			return -1;
		}

		for (i = 1; i < __MAX_ACCOUNT_; i++)
		{
			if (_A_User[i].Account_ID == Account_ID)
			{
				checker = 1;
				break;
			}
		}

		if (checker == 0)
		{
			cout << "\n�߸��� ���¹�ȣ.\n" << endl;
		}
	}

	return i;
}

void Deposit()
{
	unsigned int Deposit;

	int i = Account_Find();

	if (i == -1)
	{
		cout << "\n����Ǿ����ϴ�.\n" << endl;
		return;
	}

	cout << "�Աݾ� : ";
	cin >> Deposit;
	cout << endl;

	_A_User[i].Amount += Deposit;

	cout << _A_User[i].user_name << "�� ���·� " << Deposit << "�� �ԱݿϷ�." << endl;
	cout << endl << "�ܾ� : " << _A_User[i].Amount << "��" << endl;
}

void Withdrawal()
{
	unsigned int withdrawal;

	int i = Account_Find();

	if (i == -1)
	{
		cout << "\n����Ǿ����ϴ�.\n" << endl;
		return;
	}

	while (1)
	{
		cout << "��ݾ� : ";
		cin >> withdrawal;
		cout << endl;

		if (withdrawal > _A_User[i].Amount)
		{
			cout << "�ܾ��� �����մϴ�." << endl;
			cout << endl << "�ܾ� : " << _A_User[i].Amount << "��" << endl;
			cout << endl << endl;
		}

		else
		{
			break;
		}
	}

	_A_User[i].Amount -= withdrawal;

	cout << _A_User[i].user_name << "�� ���¿��� " << withdrawal << "�� ��ݿϷ�." << endl;
	cout << endl << "�ܾ� : " << _A_User[i].Amount << "��" << endl;
}

void All_Account_Show()
{
	int i;
	int choose;

	for (i = 1; i < __MAX_ACCOUNT_; i++)
	{
		if (_A_User[i].Activation == 1)
		{
			cout << "���¹�ȣ : " << _A_User[i].Account_ID << endl;
			cout << "���� : " << _A_User[i].user_name << endl;
			cout << "�ܾ� : " << _A_User[i].Amount << endl;
			cout << endl << endl;
		}
	}
	
	while (1)
	{
		cout << "1. �ݱ�\n" << endl;
		cout << "���� : ";
		cin >> choose;

		if (choose == 1)
		{
			return;
		}

		else
		{
			cout << endl << "�߸��� �Է�." << endl << endl << endl;
		}
	}
}

int main()
{
	int choose = 0;

	while (1)
	{
		cout << "��������������������������������������������������" << endl;
		cout << "1. ���� ����" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl << endl << "���� : ";
		cin >> choose;
		cout << "��������������������������������������������������" << endl;
		cout << endl;

		switch (choose)
		{
		case 1:
			Opening_Account();
			Sleep(3000);
			system("cls");
			break;

		case 2:
			Deposit();
			Sleep(3000);
			system("cls");
			break;

		case 3:
			Withdrawal();
			Sleep(3000);
			system("cls");
			break;

		case 4:
			All_Account_Show();
			Sleep(3000);
			system("cls");
			break;

		case 5:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;

		default:
			cout << endl << "�߸��� �Է�.";
			Sleep(3000);
			system("cls");
			break;
		}
	}
	
	return 0;
}