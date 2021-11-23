#include "Fixed.hpp"

// 생성자 : 고정 소수점 값을 0으로 초기화
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	value = num << bitCount;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(num * (1 << Fixed::bitCount));
}

// 복사 생성자
Fixed::Fixed(Fixed const &ref)
{
	std::cout << "Copy constructor called" << std::endl;
//	value = ref.value;
	*this = ref;
}

// 소멸자
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// 대입 연산자 overload
Fixed &Fixed::operator=(const Fixed &ref)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = ref.value;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "Default constructor called" << std::endl;
	value = raw;
}

// 고정 소수점 값을 부동 소수점 값으로
float Fixed::toFloat(void) const
{
	return ((float)(this->value / (float)(1 << bitCount)));
}

int Fixed::toInt(void) const
{
	return (this->value >> bitCount);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}

