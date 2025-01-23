#include "include.h"

class Integer 
{
public:
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

	 Integer findNOD(const Integer& b)
	{
		unsigned x = getUnist();
		unsigned y = b.getUnist();

		while (x != 0 && y != 0)
		{
			if (x > y)
			{
				x %= y;
			}
			else
			{
				y %= x;
			}
		}
		return Integer(x + y);
	}

	 Integer findNOK( const Integer& b) 
	{
		Integer nok =findNOD( b);
		unsigned nokUnits = (getUnist() / nok.getUnist()) * b.getUnist();

		return Integer(nokUnits);
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

	Integer& operator++()
	{
		if (sign_)
		{
			if (units_ > 0)
			{
				units_ -= 1;
				if (units_ == 0) sign_ = false;
			}
		}
		else {
			units_ += 1;
		}
		return *this;
	}

	Integer operator++(int)
	{
		Integer temp(*this);
		++(*this);
		return temp;
	}


	Integer& operator--()
	{
		if (sign_)
		{
			units_ += 1;
		}
		else
		{
			if (units_ > 0)
			{
				units_ -= 1;
				if (units_ == 0) sign_ = true;
			}
		}
		return *this;
	}

	Integer operator--(int)
	{
		Integer temp(*this);
		--(*this);
		return temp;
	}


	friend std::ostream& operator<<(std::ostream& os, const Integer obj)
	{
		os << obj.getValue();
		return os;
	}



private:
	bool sign_;
	unsigned units_;

};

class Rational
{
public:
	Rational() : numerator_(0), denominator_(1){ }
	Rational(const Integer& numerator, const Integer& denominator) : numerator_(numerator), denominator_(denominator){ }
	
	void reduce()
	{
		auto NOD = numerator_.findNOD(denominator_);
		numerator_ = Integer(numerator_.getUnist()) / NOD;
		denominator_ = Integer(denominator_.getUnist()) / NOD;
	}

	friend std::ostream& operator<<(std::ostream os, const Rational& obj)
	{
		os << obj.numerator_.getUnist() << "/" << obj.denominator_.getUnist();
		return os;
	}

private:
	Integer numerator_;
	Integer denominator_;

	
};

Rational::Rational()
{
}

Rational::~Rational()
{
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Integer a(15);
	Integer b(20);

	std::cout << "исходные числа:\n";
	std::cout << "a: " << a << ", b: " << b << "\n\n";

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


	Integer nod = a.findNOD(b);
	Integer nok = a.findNOK(b);

	std::cout << "Ќќƒ a и b - " << nod << "\n";
	std::cout << "Ќќ  a и b - " << nok << "\n\n";

	std::cout << "инкремент и декремент:\n";
	std::cout << "++a: " << ++a << "\n";
	std::cout << "a++: " << a++ << ", a стало = " << a << "\n";
	std::cout << "--a: " << --a << "\n";
	std::cout << "a--: " << a-- << ", a стало = " << a << "\n\n";
	std::cout << "++b: " << ++b << "\n";
	std::cout << "b++: " << b++ << ", b стало = " << b << "\n";
	std::cout << "--b: " << --b << "\n";
	std::cout << "b--: " << b-- << ", b стало = " << b << "\n\n";

	Rational r(a,b);
	std::cout << "ƒробь: " << r << "\n";

	return 0;
}