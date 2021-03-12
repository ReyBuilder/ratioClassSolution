#include "Ratio.h"
#include "gcd.cpp"

void Ratio::beautify()
{
	// Определение НОД с помощью алгоритма Евклида
	int tmp = gcd(num, den);
	// Сокращение соотношения
	num /= tmp;
	den /= tmp;

	// Вынос отрицания из num и den в negative
	if (num < 0) {
		num *= -1;
		negative = !negative;
	}
	if (den < 0) {
		den *= -1;
		negative = !negative;
	}
}

Ratio::Ratio()
{
	num = 1;
	den = 1;
}

Ratio::Ratio(int n, int d)
{
	set(n, d);
}

void Ratio::set(int n, int d)
{
	num = n;
	den = d;
	beautify();
}

Ratio Ratio::operator*(const Ratio ratio) const
{
	return Ratio(
		num * ratio.num * (negative ? -1 : 1),
		den * ratio.den * (ratio.negative ? -1 : 1)
	);
}

Ratio Ratio::operator+(const Ratio ratio) const
{
	return Ratio(
		(negative ? -1 : 1) * num * ratio.den + (ratio.negative ? -1 : 1) * ratio.num * den,
		ratio.den * den
	);
}

Ratio Ratio::operator*(const int value) const
{
	return Ratio(
		(negative ? -1 : 1) * num * value,
		den
	);
}

std::ostream& operator<<(std::ostream& os, const Ratio& ratio)
{
	// Отделение пространства для знака минус перед соотношением
	os << (ratio.negative ? " " : "");
	os << ratio.num << std::endl;

	// Минус перед соотношением
	if (ratio.negative) {
		os << "-";
	}
	// Разделитель num и den, размер по большему из чисел
	for (int i = 1; i < ratio.num || i < ratio.den; i *= 10)
		os << "#";
	os << std::endl;
	
	// Отделение пространства для знака минус перед соотношением
	os << (ratio.negative ? " " : "");
	os << ratio.den << std::endl;

	return os;
}
