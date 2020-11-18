#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <list>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <direct.h>
#include <vector>

using namespace std;
/*
*
* ���α׷� ȭ�� ���� �޼ҵ� �Լ�
*
*/



void mainmenu(string user);		// ������ ���� �α��� ��, ���� �޴�
string signin();			// ������ ���� �α��� 
void signup();			// ������ ���� ȸ������
void viewaccounts(string user);	// ����� ����,��й�ȣ ����
void addaccount(string user);		// ����,��й�ȣ �߰�
void changeaccount(string user);	// ����,��й�ȣ ����
void recommendpwd();	// ��й�ȣ ��õ ��� ����
void toClipboard(HWND hwnd, const string& s);



string signin() {
	string id;
	string pwd;
	string text;
	string stringBuffer;

	ifstream file("./MasterAccounts.dat");
	
	if (!file) {
		cout << "������ �������� �ʽ��ϴ�." << endl;
	}
	else {

		cout << "ID: ";
		cin >> id;
		cout << "PASSWORD: ";
		cin >> pwd;

		while (getline(file, text)) {

			istringstream ss(text);

			getline(ss, stringBuffer, ' ');	// stringBuffer�� id ����
			if (stringBuffer == id) {
				getline(ss, stringBuffer, ' ');
				if (stringBuffer == pwd) {
					system("cls");
					return id;
				}
				else {
					system("cls");
					cout << "Password error!" << endl;
					return signin();
					
				}
			}
		}
		if (file.eof()) {
			system("cls");
			cout << "do not exist ID" << endl;
			return signin();
			
		}
	}

}

void signup() {
	string id;
	string pwd;
	string filepath = "./MasterAccounts.dat";


	cout << "input ID: ";
	cin >> id;
	cout << "input Password: ";
	cin >> pwd;

	ofstream file(filepath, std::ios::app);

	file << id << " " << pwd << endl;
	
	string dir = "./" + id;

	if (_mkdir(dir.c_str()) == -1) {
		cout << "���丮 ������ �����Ͽ����ϴ�." << endl;
	}
}

void mainmenu(string user) {
	while (1)
	{
		system("cls");

		int check;

		cout << "-------------------------------------------------" << endl << endl;
		cout << "|		1. ����/��й�ȣ ����		|" << endl << endl;
		cout << "|		2. ����/��й�ȣ �߰�		|" << endl << endl;
		cout << "|		3. ����/��й�ȣ ����		|" << endl << endl;
		cout << "|		4. ��й�ȣ ��õ		|" << endl << endl;
		cout << "-------------------------------------------------" << endl;
		cin >> check;
		switch (check)
		{
		case 1:
			system("cls");
			viewaccounts(user);
			break;
		case 2:
			system("cls");
			addaccount(user);
			break;
		case 3:
			system("cls");
			changeaccount(user);
			break;
		case 4:
			system("cls");
			recommendpwd();
			break;
		default:
			break;
		}
	}
}

void viewaccounts(string user) {

	string filepath = "./" + user + "/Accounts.txt";
	ifstream file(filepath);
	string text;
	vector<string> vec;
	vector<string>::iterator iter;

	while (getline(file, text)) {
		vec.push_back(text);

		for (int j = 0; j < vec.size()-1; j++) {
			for (int i = (vec.size() - 1); i > j; i--) {
				if (vec[i] < vec[i - 1]) {
					string temp = vec[i];
					vec[i] = vec[i - 1];
					vec[i - 1] = temp;
				}
			}
		}
	}

	for (iter = vec.begin(); iter != vec.end(); iter++) {
		cout << (*iter) << endl;
	}

	char ch;
	cout << "mainmenu�� ���ư����� ���ڸ� �Է��ϰ� enter�� ��������." << endl;
	cin >> ch;
}

void addaccount(string user) {

	string info;
	string filepath = "./" + user + "/Accounts.txt";

	cout << "���� ������ �Է��ϼ���." << endl;
	cout << "(����Ʈ��) (������) (��й�ȣ) (�Է� ��¥) (�޸�)" << endl;

	getline(cin, info);
	getline(cin, info);

	ofstream file(filepath, std::ios::app);

	file << info << endl;

}

void changeaccount(string user) {
	cout << "���� ����";
}

//character set
static const char alphnum[] = "0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
int strLen = sizeof(alphnum) - 1;

char RandomGen()
{
	return alphnum[rand() % strLen];
}

void recommendpwd() {
	
		int plength, c = 0, s = 0;
		srand((unsigned int)time(0));
		cout << "enter password length = ";
		cin >> plength;
		cout << "generating a random password with " << plength << " characters" << endl;
		cout << "generated password: ";

	loopGen:
		char C;
		string passw;
		for (int z = 0; z < plength; z++)
		{
			C = RandomGen();
			passw += C;
			if (isdigit(C))
			{
				c++;
			}
			//special character
			if (C == '!' || C == '@' || C == '$' || C == '%' || C == '^' || C == '&' || C == '*' || C == '#')
			{
				s++;
			}
		}
		if (plength > 2 && (s == 0 || c == 0))
		{
			goto loopGen;
		}

		cout << passw<<endl;
	

	char ch;
	cout << "mainmenu�� ���ư����� ���ڸ� �Է��ϰ� enter�� ��������." << endl;
	cin >> ch;

	system("cls");
}




int main(void) {
	
	string user;
	int check;

	cout << "-----------------------------------------" << endl << endl;
	cout << "|		1. Sign in		|" << endl << endl;
	cout << "|		2. Sign up		|" << endl << endl;
	cout << "-----------------------------------------" << endl;
	cin >> check;
	switch (check)
	{
	case 1:
		system("cls");
		user = signin();
		mainmenu(user);
		break;
	case 2:
		system("cls");
		signup();
		break;
	default:
		break;
	}
	return 0;

}

