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
	cout << "성명 : ";
	cin >> _A_User[i].user_name;
	cout << endl;

	cout << "신규 개설된 "<< _A_User[i].user_name << "님의 계좌번호는 " << _A_User[i].Account_ID << "입니다." << endl;
	cout << endl;

	return;
}

int Account_Find()
{
	unsigned int Account_ID;

	int i, checker = 0;

	while (checker == 0)
	{
		cout << "계좌번호 : ";
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
			cout << "\n잘못된 계좌번호.\n" << endl;
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
		cout << "\n종료되었습니다.\n" << endl;
		return;
	}

	cout << "입금액 : ";
	cin >> Deposit;
	cout << endl;

	_A_User[i].Amount += Deposit;

	cout << _A_User[i].user_name << "님 계좌로 " << Deposit << "원 입금완료." << endl;
	cout << endl << "잔액 : " << _A_User[i].Amount << "원" << endl;
}

void Withdrawal()
{
	unsigned int withdrawal;

	int i = Account_Find();

	if (i == -1)
	{
		cout << "\n종료되었습니다.\n" << endl;
		return;
	}

	while (1)
	{
		cout << "출금액 : ";
		cin >> withdrawal;
		cout << endl;

		if (withdrawal > _A_User[i].Amount)
		{
			cout << "잔액이 부족합니다." << endl;
			cout << endl << "잔액 : " << _A_User[i].Amount << "원" << endl;
			cout << endl << endl;
		}

		else
		{
			break;
		}
	}

	_A_User[i].Amount -= withdrawal;

	cout << _A_User[i].user_name << "님 계좌에서 " << withdrawal << "원 출금완료." << endl;
	cout << endl << "잔액 : " << _A_User[i].Amount << "원" << endl;
}

void All_Account_Show()
{
	int i;
	int choose;

	for (i = 1; i < __MAX_ACCOUNT_; i++)
	{
		if (_A_User[i].Activation == 1)
		{
			cout << "계좌번호 : " << _A_User[i].Account_ID << endl;
			cout << "성명 : " << _A_User[i].user_name << endl;
			cout << "잔액 : " << _A_User[i].Amount << endl;
			cout << endl << endl;
		}
	}
	
	while (1)
	{
		cout << "1. 닫기\n" << endl;
		cout << "선택 : ";
		cin >> choose;

		if (choose == 1)
		{
			return;
		}

		else
		{
			cout << endl << "잘못된 입력." << endl << endl << endl;
		}
	}
}

int main()
{
	int choose = 0;

	while (1)
	{
		cout << "─────────────────────────" << endl;
		cout << "1. 계좌 개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl << endl << "선택 : ";
		cin >> choose;
		cout << "─────────────────────────" << endl;
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
			cout << "프로그램을 종료합니다." << endl;
			return 0;

		default:
			cout << endl << "잘못된 입력.";
			Sleep(3000);
			system("cls");
			break;
		}
	}
	
	return 0;
}