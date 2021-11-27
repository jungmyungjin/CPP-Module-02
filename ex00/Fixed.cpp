/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 03:37:29 by mjung             #+#    #+#             */
/*   Updated: 2021/11/28 03:37:30 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// 생성자 : 고정 소수점 값을 0으로 초기화
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	fixedNum = 0;
}

// 소멸자
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

}

// 복사 생성자
Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedNum = fixed.fixedNum;
}

// 대입 연산자 overload
Fixed Fixed::operator=(Fixed &ref)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedNum = ref.fixedNum;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedNum);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "Default constructor called" << std::endl;
	fixedNum = raw;
}
