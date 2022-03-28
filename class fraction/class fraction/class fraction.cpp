
#include <iostream>
using namespace std;

int UCLN(int number1, int number2)
{
	while (number1 != number2)
	{
		if (number1 > number2)
		{
			number1 -= number2;
		}
		else
		{
			number2 -= number1;
		}
	}
	return number1;
}
int BCNN(int number1, int number2)
{
	return (number1 * number2) / UCLN(number1, number2);
}

class fraction
{
private:
	int numerator;
	int denominator;
public:
	fraction()
	{
		numerator = 0;
		denominator = 1;
	}
	fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
	~fraction()
	{

	}
	void rutgon()
	{
		int ucln = UCLN(numerator, denominator);
		numerator /= ucln;
		denominator /= ucln;
	}
	void nhap()
	{
		cout << "enter numerator:";
		cin >> numerator;
		do {
			cout << "enter denominator:";
			cin >> denominator;
			if (denominator == 0) {
				system("cls");
				cout << "re-enter the denominator\n";
			}
		} while (denominator == 0);
		system("cls");
		cout << "successfully entered" << endl;
	}
	void xuat()
	{
		cout << "fraction:";
		rutgon();
		cout << numerator << "/" << denominator;
		if (denominator == 1) {
			cout << " or " << numerator;
		}
		cout << "\n";
	}

	fraction sum(fraction frac2)
	{
		fraction frac3;
		frac3.numerator = this->numerator * frac2.denominator + this->denominator * frac2.numerator;
		frac3.denominator = frac2.denominator * this->denominator;
		frac3.rutgon();
		return frac3;

	}
	fraction subtraction (fraction frac2)
	{
		fraction frac3;
		frac3.numerator = this->numerator * frac2.denominator - this->denominator * frac2.numerator;
		frac3.denominator = frac2.denominator * this->denominator;
		frac3.rutgon();
		return frac3;

	}
	fraction Multiplication(fraction frac2)
	{
		fraction frac3;
		frac3.numerator = this->numerator * frac2.numerator;
		frac3.denominator = frac2.denominator * this->denominator;
		frac3.rutgon();
		return frac3;

	}
	fraction Division(fraction frac2)
	{
		fraction frac3;
		frac3.numerator = this->numerator * frac2.denominator;
		frac3.denominator = frac2.numerator * this->denominator;
		frac3.rutgon();
		return frac3;

	}
	
};

int main()
{
	fraction a;
	fraction b;
	cout << "nhap so thu nhat\n";
	a.nhap();
	cout << "nhap so thu 2\n";
	b.nhap();
	cout << "ketqua\n";
	a.Division(b).xuat();
	system("pause");
	return 0;
}