#pragma once
class fract
{
	int numer = 0;
	int denom = 1;
	int divisor(int, int);
public:
	fract() = default;
	fract(int n, int d) : numer(n), denom(d) {}
	fract & fract::operator=(const fract &);
	fract fract::operator+(const fract &);
	fract fract::operator-(const fract &);
	fract fract::operator*(const fract &);
	fract fract::operator/(const fract &);
	friend std::istream & operator>>(std::istream &, fract &);
	friend std::ostream & operator<<(std::ostream &, fract &);
};