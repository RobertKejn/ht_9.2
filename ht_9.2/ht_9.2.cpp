#include <iostream>
#include<Windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	int find_nod(int a, int b) {
		while (a != 0 && b != 0) {
			if (a > b) a = a % b;
			else b = b % a;
		}
		return a + b;
	}

	void shortcut(Fraction& fr) {
		int nod = find_nod(fr.numerator_, fr.denominator_);
		if (nod != 1) {
			fr.numerator_ = fr.numerator_ / nod;
			fr.denominator_ = fr.denominator_ / nod;
		}
		if (fr.denominator_ < 0) {
			fr.numerator_ *= -1;
			fr.denominator_ *= -1;
		}
	}

public:
	Fraction(int numerator= 0, int denominator=1)
	{
		numerator_ = numerator;
		denominator_ = denominator;

	}

	void print() {
		std::cout << numerator_ << "/" << denominator_;
	}

	Fraction operator+(Fraction& fr) {
		int num = numerator_ * fr.denominator_ + fr.numerator_ * denominator_;
		int denom = denominator_ * fr.denominator_;
		Fraction f(num, denom);
		shortcut(f);
		return f;
	}

	Fraction operator-(Fraction& fr) {
		int num = numerator_ * fr.denominator_ - fr.numerator_ * denominator_;
		int denom = denominator_ * fr.denominator_;
		Fraction f(num, denom);
		shortcut(f);
		return f;
	}

	Fraction operator*(Fraction& fr) {
		int num = numerator_ * fr.numerator_;
		int denom = denominator_ * fr.denominator_;
		Fraction f(num, denom);
		shortcut(f);
		return f;
	}

	Fraction operator/(Fraction& fr) {
		int num = numerator_ * fr.denominator_;
		int denom = denominator_ * fr.numerator_;
		Fraction f(num, denom);
		shortcut(f);
		return f;
	}

	Fraction& operator++(void) {
		numerator_ += denominator_;
		return *this;
	}

	Fraction& operator--(void) {
		numerator_ -= denominator_;
		return *this;
	}

	Fraction operator++(int) {
		Fraction f = *this;
		++(*this);
		return *this;
	}

	Fraction operator--(int) {
		Fraction f = *this;
		--(*this);
		return *this;
	}

	bool operator==(Fraction& fr) {
		shortcut(*this);
		shortcut(fr);
		return this->numerator_ == fr.numerator_ && this->denominator_ == fr.denominator_;
	}

	bool operator!=(Fraction& fr) {
		return !(*this == fr);
	}

	bool operator<(Fraction& fr) {
		double a = numerator_ / static_cast<double>(denominator_);
		double b = fr.numerator_ / static_cast<double>(fr.denominator_);
		return a < b;
	}

	bool operator>(Fraction& fr) {
		double a = numerator_ / static_cast<double>(denominator_);
		double b = fr.numerator_ / static_cast<double>(fr.denominator_);
		return a > b;
	}

	bool operator>=(Fraction& fr) {
		double a = numerator_ / static_cast<double>(denominator_);
		double b = fr.numerator_ / static_cast<double>(fr.denominator_);
		return a >= b;
	}

	bool operator<=(Fraction& fr) {
		double a = numerator_ / static_cast<double>(denominator_);
		double b = fr.numerator_ / static_cast<double>(fr.denominator_);
		return a <= b;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Fraction f1(1, 2);
	Fraction f2(1, 2);
	Fraction f3(1, 2);
	Fraction f4(1, 2);

	(f1++ + f2).print();
	std::cout << std::endl;
	(++f3 + f4).print();
	std::cout << std::endl;
	
	int i1 = 10, i2 = 10, i3 = 10, i4 = 10;
	std::cout << ++i1 + i2 << std::endl;
	std::cout << i3++ + i4 << std::endl;

	/*int num = 0, denom = 1;
	Fraction f1, f2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> num;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denom;
	f1 = Fraction(num, denom);
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> num;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denom;
	f2 = Fraction(num, denom);
	std::cout << "\n\n";

	f1.print();
	std::cout << " + ";
	f2.print();
	std::cout << " = ";
	(f1 + f2).print();
	std::cout << "\n\n";

	f1.print();
	std::cout << " - ";
	f2.print();
	std::cout << " = ";
	(f1 - f2).print();
	std::cout << "\n\n";

	f1.print();
	std::cout << " * ";
	f2.print();
	std::cout << " = ";
	(f1 * f2).print();
	std::cout << "\n\n";

	f1.print();
	std::cout << " / ";
	f2.print();
	std::cout << " = ";
	(f1 / f2).print();
	std::cout << "\n\n";

	f1.print();
	std::cout << " + ";
	f2.print();
	std::cout << " = ";
	(f1 + f2).print();
	std::cout << "\n\n";

	std::cout << "++";
	f1.print();
	std::cout << " + ";
	f2.print();
	std::cout << " = ";
	(++f1 * f2).print();
	std::cout << "\nЗначение дроби 1: ";
	f1.print();
	std::cout << "\n\n";

	f1.print();
	std::cout << "-- + ";
	f2.print();
	std::cout << " = ";
	(f1-- * f2).print();
	std::cout << "\nЗначение дроби 1: ";
	f1.print();
	std::cout << "\n\n";*/
	
}
