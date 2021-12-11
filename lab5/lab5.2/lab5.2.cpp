// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <cctype>

using std::cout;
using std::endl;
using std::cin;



int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	
	std::string s;
	char a, b;
	int N;
	in >> N;
	in >> a >> b;

	std::string mas[5000];
	int size = 0;

	//int mx = INT_MIN;

	bool ch = false;
	bool word = false;

	while (in >> s) {

		s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end());
		
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] += 32;
			}
		}

		// слово содержит букву а
		bool consistA = false;
		for(int i=0;i<s.length();i++)
			if (s[i] == a)
			{
				consistA = true;
				break;
			}

		// слово содержит букву b
		bool consistB = false;
		for (int i = 0; i < s.length(); i++)
			if (s[i] == b)
			{
				consistB = true;
				break;
			}

		if (consistA && !consistB)
		{
			bool consistWord = false;
			for(int i=0; i<size;i++)
				if (s == mas[i])
				{
					consistWord = true;
					break;
				}

			if (!consistWord)
			{
				mas[size] = s;
				size++;
			}
		}
	}

	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {
			if (mas[i].length() < mas[j].length()) {
				std::swap(mas[i], mas[j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		out << mas[i] << endl;
	}


	// Сортировка слов

	// Вывод n первых слов

}
