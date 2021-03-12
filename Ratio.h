#pragma once
#include <iostream>
class Ratio
{
private:
	int num, den;
	// Знак пропорции (true = отрицательный)
	bool negative = false;

	// Преобразование к сокращённому виду и вынесение отрицаний из num и den в negative
	void beautify();
public:
	// num = 1, den = 1
	Ratio();
	Ratio(int num, int den);

	// Установка num = n и den = d
	void set(int n, int d);

	Ratio operator*(const Ratio) const;
	Ratio operator+(const Ratio) const;
	Ratio operator*(const int) const;

	// Потоковый вывод в виде
	//  1234
	// -#####
	//  12345
	friend std::ostream& operator<<(std::ostream&, const Ratio&);
};

