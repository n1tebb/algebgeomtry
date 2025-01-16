#include "include.h"


class Integer 
{
private:
	int value_;

public:
	Integer(int value) : value_(value) {}

	int getValue() const { return value_; }

	bool isEven() const { return value_ % 2 == 0; } //�������� �� �������� 
	bool isOdd() const { return value_ % 2 != 0; } //�������� �� ����������
	bool isPozitive() const { return value_ > 0; } //�������� �� ���������������
	bool isNegative() const { return value_ < 0;  } //�������� �� ���������������

	//����������� �� ������� �����
	bool isProstota() const {
		if (value_ <= 1) return false;
		for (int i = 2; i <= sqrt(value_); i++)
		{
			if (value_ % i == 0) return false;
		}
		return true;
	}
	
	//����������� �� �������������� ���� ����� integer
	bool isVzaimProstota(const Integer& other) const {
		int a = value_;
		int b = other.value_;

		while (b != 0)
		{
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a == 1;
	}
	
	//���
	int nod(int a, int b) const
	{
		while (b != 0)
		{
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
	
	//���
	int nok(const Integer& other) const
	{
		int a = value_;
		int b = other.value_;

		int temp_a = a,  temp_b = b;
		while (temp_b != 0)
		{
			int temp = temp_b;
			temp_b = temp_a % temp_b;
			temp_a = temp; //���
		}
		return a / temp_b * b; //���
	}

	Integer operator+(const Integer& other) const {
		return Integer(value_ + other.value_);
	}

	Integer operator-(const Integer& other) const {
		return Integer(value_ - other.value_);
	}
	
	Integer operator*(const Integer& other) const {
		return Integer(value_ * other.value_);
	}

	Integer operator/(const Integer& other) const {
		return Integer(value_ / other.value_);
	}

	Integer operator%(const Integer& other) const {
		return Integer(value_ % other.value_);
	}

	Integer operator+=(const Integer& other) {
		value_ += other.value_;
		return *this;
	}
	
	Integer operator-=(const Integer& other) {
		value_ -= other.value_;
		return *this;
	}

	Integer operator*=(const Integer& other) {
		value_ *= other.value_;
		return *this;
	}

	Integer operator/=(const Integer& other) {
		value_ /= other.value_;
		return *this;
	}

	void print() const {
		std::cout << value_ << "\n";
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Integer a(15);
	Integer b(6);

	std::cout << "1 - true\n" << "0 - false\n\n\n";


	std::cout << "a = ";
	a.print();
	std::cout << "b = ";
	b.print();
	std::cout << "\n";

	std::cout << "a - ������ = " << a.isEven() << "\n";
	std::cout << "b - ������ = " << b.isEven() << "\n\n";

	std::cout << "a - �������� = " << a.isOdd() << "\n";
	std::cout << "b - �������� = " << b.isOdd() << "\n\n";

	std::cout << "a - ������������� = " << a.isPozitive() << "\n";
	std::cout << "b - ������������� = " << b.isPozitive() << "\n";

	std::cout << "a - ������������� = " << a.isNegative() << "\n";
	std::cout << "b - ������������� = " << b.isNegative() << "\n\n";

	std::cout << "a - ������� = " << a.isProstota() << "\n";
	std::cout << "b - ������� = " << b.isProstota() << "\n\n";

	std::cout << "a � b - ������������� = " << a.isVzaimProstota(b) << "\n\n";

	std::cout << "��� a � b = " << a.nod(a.getValue(), b.getValue()) << "\n\n";
	std::cout << "��� a � b " << a.nok({ a.getValue(), b.getValue() }) << "\n";

	Integer sum = a + b;
	std::cout << "��������� ��������: ";
	sum.print();

	Integer mnoj = a * b;
	std::cout << "��������� ���������: ";
	mnoj.print();

	Integer dele = a / b;
	std::cout << "��������� �������: ";
	dele.print(); 

	return 0;
}