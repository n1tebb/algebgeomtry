#include <iostream>
#include <cmath>
#include <Windows.h>

class Integer 
{
private:
	bool sign_;
	unsigned units_;

public:
	//Integer() :Integer(false, 0u) { } 
	Integer():sign_(false), units_(0) { }
	Integer(int value) 
	{
		sign_ = value < 0;
		units_ = abs(value);
	}

	void setSign(bool sign)
	{
		this->sign_ = sign;
	}

	void setUnits(unsigned units)
	{
		this->units_ = units;
	}

	bool getSign() const 
	{
		return sign_;
	}

	unsigned getUnist() const
	{
		return units_;
	}

	//проверка четности 
	bool isOdd() const
	{
		return units_ % 2 != 0;
	}

	//проверка положительности
	bool isPositive() const
	{
		return !sign_ && units_ != 0;
	}

	//проверка отрицательности
	bool isNegative() const
	{
		return sign_ && units_ != 0;
	}

	//проверка простое ли число
	bool isProstoe() const
	{
		if (units_ <= 1) return false;
		for (unsigned i = 2; i <= sqrt(units_) ; i++)
		{
			if (units_ % i == 0) return false;
		}
		return true;
	}

	//взаимопростые числа
	bool isVzaimProstoe(const Integer& other) const
	{
		unsigned a = units_;
		unsigned b = other.units_;

		while (a != 0 && b != 0)
		{
			if (a > b)
			{
				a %= b;
			}
			else
			{
				b %= a;
			}
		}
		return (a + b) == 1;
	}

	unsigned NOD(unsigned a, unsigned b)
	{
		while (a != 0 && b != 0)
		{
			if (a > b)
			{
				a %= b;
			} else
			{
				b %= a;
			}
		}
		return a + b;
	}

	unsigned NOK(unsigned a, unsigned b)
	{
		unsigned nod = NOD(a, b);
		return (a / nod) * b;
	}

	int getValue() const
	{
		return sign_ ? -(int)units_ : (int)units_;
	}

	Integer operator+(const Integer& other) const
	{
		return Integer(this->getValue() + other.getValue());
	}

	Integer operator-(const Integer& other) const
	{
		return Integer(this->getValue() - other.getValue());
	}

	Integer operator*(const Integer& other) const
	{
		return Integer(this->getValue() * other.getValue());
	}

	Integer operator/(const Integer& other) const
	{
		return Integer(this->getValue() / other.getValue());
	}

	Integer operator%(const Integer& other) const
	{
		return Integer(this->getValue() % other.getValue());
	}

	Integer operator+=(const Integer& other)
	{
		*this = *this + other;
		return *this;
	}

	Integer operator-=(const Integer& other)
	{
		*this = *this - other;
		return *this;
	}

	Integer operator*=(const Integer& other)
	{
		*this = *this * other;
		return *this;
	}

	Integer operator/=(const Integer& other)
	{
		*this = *this / other;
		return *this;
	}

	Integer operator%=(const Integer& other)
	{
		*this = *this % other;
		return *this;
	}

	
};

int main() 
{
	Integer a(15);
	Integer b(20);

	std::cout << "a - четное: " << !a.isOdd() << "\n";
	std::cout << "b - четное: " << !b.isOdd() << "\n\n";

	std::cout << "a - нечетное: " << a.isOdd() << "\n";
	std::cout << "b - нечетное: " << b.isOdd() << "\n\n";

	std::cout << "a - положительное: " << a.isPositive() << "\n";
	std::cout << "b - положительное: " << b.isPositive() << "\n\n";

	std::cout << "a - отрицательное: " << a.isNegative() << "\n";
	std::cout << "b - отрицательное: " << b.isNegative() << "\n\n";

	std::cout << "a - простое: " << a.isProstoe() << "\n";
	std::cout << "b - простое: " << b.isProstoe() << "\n\n";

	std::cout << "a и b - взаимопростые: " << a.isVzaimProstoe(b) << "\n\n";

	unsigned nod = a.NOD(a.getUnist(), b.getUnist());

}