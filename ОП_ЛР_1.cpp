#include <iostream> //Подключение директивы ввод-вывод
#include<string> //Подключение директивы строк, является элементом iostream, но на старых версиях С++ требует подключения
#include <regex> //Подключение директивы регулярных выражений

using namespace std; //Работа в пространстве имён стандартной библиотеки

int timeFormCheck(string x)
{
	regex regular("([0-1][0-9]|[2][0-3])""(:)""([0-5][0-9])""(:)""([0-5][0-9])"); //Регулярное выражение
	while (!regex_match(x.c_str(), regular)) //Цикл пока не будут получены корректные данные, проверка на соответствие регулярному выражению
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
	for (int i = 0; i <= 7; i++) //Перебор строки введённого времени
	{
		if (time_in[i] != ':') // Условие пропуска двоеточий, перевод времени в абстрактную форму прошедших секунд с начала суток
		{
			replace = time_in[i];
			replace_int = stoi(replace); // Перевод типа данных char в т.д. int
			switch (i)
			{
			case 0:time_out += replace_int * 36000; break; //Перевод. Десятки часов в секунды
			case 1:time_out += replace_int * 3600; break; //Перевод. Единицы часов в секунды
			//Case 2 это двоеточие, пропущенное условием
			case 3:time_out += replace_int * 600; break; //Перевод. Десятки минут в секунды
			case 4:time_out += replace_int * 60; break; //Перевод. Единицы минут в секунды
			//Case 5 это двоеточие, пропущенное условием
			case 6:time_out += replace_int * 10; break; //Перевод. Десятки секунд в секунды
			case 7:time_out += replace_int; break; //Прибавление оставшихся единиц секунд
			}
		}
	}
return time_out; //Возвращает функции вычисленное значение
}

int main()  {
	char user_continue;
	do //Повтор программы 
	{

		string begining_time, end_time;
		int result;
		
		cout << "Enter begining time: [HH:MM:SS] "; //Ввод времени начала операции
		std::cin >> begining_time;

		timeFormCheck(begining_time);

		cout << "Enter end time: [HH:MM:SS] "; //Ввод времини конца операции
		cin >> end_time;

		timeFormCheck(end_time);

		result = translator(end_time) - translator(begining_time); //Вычисления через функцию translator
		while (result < 0) //Проверка на отсутсвие отрицательного результата и повторный ввод
		{
			cout << "Error. Beginning time cannot be later than end time...\n";
			cout << "Try again:\n";
			cout << "Enter begining time: [HH:MM:SS] "; //Ввод времени начала операции
			std::cin >> begining_time;

			timeFormCheck(begining_time);

			cout << "Enter end time: [HH:MM:SS] "; //Ввод времини конца операции
			cin >> end_time;

			timeFormCheck(end_time);
		}
		cout << result <<"(seconds) or "; //Вывод результата в секундах
		cout << result/60 << "(minutes)"; //Вывод результата в минутах (приблизительно)

		cout << "\nPrefer to continue working?[Y/N]"; //Запрос повтора программы
		cin >> user_continue;
	} while (user_continue == 'Y'); //Условие повтора программы
return 0;
}