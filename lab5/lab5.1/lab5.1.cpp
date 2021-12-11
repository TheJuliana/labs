// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);

	std::ifstream in("input.txt");

	char s[100][50];

	int n = 0;

	while (!in.eof()) {
		in >> s[n];
		for (int i = 0; i < n; i++) {
			if (s[n][i] >= 'A' && s[n][i] <= 'Z') {
				s[n][i] += 32;
			}
		}
		n++;
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			if (strcmp(s[i], s[j]) > 0)
				std::swap(s[i], s[j]);
		}

	for (int i = 0; i < n; i++) {
		std::cout << s[i] << std::endl;
	}

}
