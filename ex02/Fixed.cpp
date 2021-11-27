/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 03:59:06 by mjung             #+#    #+#             */
/*   Updated: 2021/11/28 04:06:08 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}

// 생성자 : 고정 소수점 값을 0으로 초기화
Fixed::Fixed(void)
{
	value = 0;
}

Fixed::Fixed(int num)
{
	value = num << bitCount;
}

Fixed::Fixed(const float num)
{
	value = roundf(num * (1 << Fixed::bitCount));
}

// 복사 생성자
Fixed::Fixed(Fixed const &ref)
{
	*this = ref;
}

// 소멸자
Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
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

// 대입 연산자 overload
Fixed &Fixed::operator=(const Fixed &ref)
{
	this->value = ref.value;
	return (*this);
}

bool Fixed::operator>(const Fixed &ref)
{
	return ((value > ref.value) ? true : false);
}

bool Fixed::operator<(const Fixed &ref)
{
	return ((value < ref.value) ? true : false);
}

bool Fixed::operator>=(const Fixed &ref)
{
	return ((value >= ref.value) ? true : false);
}


bool Fixed::operator<=(const Fixed &ref)
{
	return ((value <= ref.value) ? true : false);
}

bool Fixed::operator==(const Fixed &ref)
{
	return ((value == ref.value) ? true : false);
}

bool Fixed::operator!=(const Fixed &ref)
{
	return ((value != ref.value) ? true : false);
}

Fixed Fixed::operator+(const Fixed &ref)
{
	Fixed tmp(value + ref.value);
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &ref)
{
	Fixed tmp(value - ref.value);
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &ref)
{
	Fixed tmp(this->toFloat() * ref.toFloat());
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &ref)
{
	Fixed tmp(value / ref.value);
	return (tmp);
}

Fixed Fixed::operator++()
{
	value++;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	value++;
	return (tmp);
}

Fixed Fixed::operator--()
{
	value--;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;
	value--;
	return (tmp);
}

Fixed Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.getRawBits() < ref2.getRawBits())
		return (ref1);
	else if (ref1.getRawBits() == ref2.getRawBits())
		return (ref1);
	else
		return (ref2);
}

Fixed Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.getRawBits() > ref2.getRawBits())
		return (ref1);
	else if (ref1.getRawBits() == ref2.getRawBits())
		return (ref1);
	else
		return (ref2);
}




