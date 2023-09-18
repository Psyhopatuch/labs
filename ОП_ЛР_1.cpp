#include <iostream> //����������� ��������� ����-�����
#include<string> //����������� ��������� �����, �������� ��������� iostream, �� �� ������ ������� �++ ������� �����������
#include <regex> //����������� ��������� ���������� ���������

using namespace std; //������ � ������������ ��� ����������� ����������

int timeFormCheck(string x)
{
	regex regular("([0-1][0-9]|[2][0-3])""(:)""([0-5][0-9])""(:)""([0-5][0-9])"); //���������� ���������
	while (!regex_match(x.c_str(), regular)) //���� ���� �� ����� �������� ���������� ������, �������� �� ������������ ����������� ���������
	{
		cout << "Error. Incorrect format, try enter again:\n";
		cout << "Enter time: [HH:MM:SS] ";
		cin >> x;
	}
return 0;
}

int translator(string time_in)
{
	string replace;
	int replace_int, time_out;
	time_out = 0;
	for (int i = 0; i <= 7; i++) //������� ������ ��������� �������
	{
		if (time_in[i] != ':') // ������� �������� ���������, ������� ������� � ����������� ����� ��������� ������ � ������ �����
		{
			replace = time_in[i];
			replace_int = stoi(replace); // ������� ���� ������ char � �.�. int
			switch (i)
			{
			case 0:time_out += replace_int * 36000; break; //�������. ������� ����� � �������
			case 1:time_out += replace_int * 3600; break; //�������. ������� ����� � �������
			//Case 2 ��� ���������, ����������� ��������
			case 3:time_out += replace_int * 600; break; //�������. ������� ����� � �������
			case 4:time_out += replace_int * 60; break; //�������. ������� ����� � �������
			//Case 5 ��� ���������, ����������� ��������
			case 6:time_out += replace_int * 10; break; //�������. ������� ������ � �������
			case 7:time_out += replace_int; break; //����������� ���������� ������ ������
			}
		}
	}
return time_out; //���������� ������� ����������� ��������
}

int main()  {
	char user_continue;
	do //������ ��������� 
	{

		string begining_time, end_time;
		int result;
		
		cout << "Enter begining time: [HH:MM:SS] "; //���� ������� ������ ��������
		std::cin >> begining_time;

		timeFormCheck(begining_time);

		cout << "Enter end time: [HH:MM:SS] "; //���� ������� ����� ��������
		cin >> end_time;

		timeFormCheck(end_time);

		result = translator(end_time) - translator(begining_time); //���������� ����� ������� translator
		while (result < 0) //�������� �� ��������� �������������� ���������� � ��������� ����
		{
			cout << "Error. Beginning time cannot be later than end time...\n";
			cout << "Try again:\n";
			cout << "Enter begining time: [HH:MM:SS] "; //���� ������� ������ ��������
			std::cin >> begining_time;

			timeFormCheck(begining_time);

			cout << "Enter end time: [HH:MM:SS] "; //���� ������� ����� ��������
			cin >> end_time;

			timeFormCheck(end_time);
		}
		cout << result <<"(seconds) or "; //����� ���������� � ��������
		cout << result/60 << "(minutes)"; //����� ���������� � ������� (��������������)

		cout << "\nPrefer to continue working?[Y/N]"; //������ ������� ���������
		cin >> user_continue;
	} while (user_continue == 'Y'); //������� ������� ���������
return 0;
}