#include "stdafx.h"
#include "fract.h"
int fract::divisor(int a, int b)
{
	if (!a || !b) return 1;
	if (abs(a) == abs(b)) return b;
	if (abs(a) > abs(b)) return divisor(a - abs(b), b);
	if (abs(a) < abs(b)) return divisor(a, b - abs(a));
}
fract & fract::operator=(const fract &ob)
{
	this->numer = ob.numer;
	this->denom = ob.denom;
	return *this;
}
fract fract::operator+(const fract &f)
{
	fract tmp;
	tmp.denom = f.denom * denom;
	tmp.numer = f.denom * numer + f.numer * denom;
	int div = divisor(tmp.numer, tmp.denom);
	tmp.denom /= div;
	tmp.numer /= div;
	return tmp;
}
fract fract::operator-(const fract &f)
{
	fract tmp;
	tmp.denom = f.denom * denom;
	tmp.numer = f.denom * numer - f.numer * denom;
	int div = divisor(tmp.numer, tmp.denom);
	tmp.denom /= div;
	tmp.numer /= div;
	return tmp;
}
fract fract::operator*(const fract &f)
{
	fract tmp;
	tmp.denom = f.denom * denom;
	tmp.numer = f.numer * numer;
	int div = divisor(tmp.numer, tmp.denom);
	tmp.denom /= div;
	tmp.numer /= div;
	return tmp;
}
fract fract::operator/(const fract &f)
{
	fract tmp;
	tmp.denom = f.denom * numer;
	tmp.numer = f.numer * denom;
	int div = divisor(tmp.numer, tmp.denom);
	tmp.denom /= div;
	tmp.numer /= div;
	return tmp;
}
std::istream & operator>>(std::istream &os, fract &ob)
{
	std::cout << "Введите дробь (a/b): ";
	scanf_s("%i/%i", &ob.numer, &ob.denom);
	return os;
}
std::ostream & operator<<(std::ostream &os, fract &ob)
{
	system("cls");
	if (!ob.numer) os << 0 << std::endl;
	else os << ob.numer << "/" << ob.denom << std::endl;
	system("pause");
	return os;
}