/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 03:37:35 by mjung             #+#    #+#             */
/*   Updated: 2021/11/28 03:37:44 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed{
public:
	// 생성자 : 고정 소수점 값을 0으로 초기화
	Fixed();
	// 소멸자
	~Fixed();
	// 복사 생성자
	Fixed(const Fixed& fixed);

	// 대입 연산자 overload
	Fixed operator=(Fixed &ref);

	// 고정 소수점 값의 원시 값을 반환
	int getRawBits(void) const;

	// 고정 소수점 값의 원시 값을 설정
	void setRawBits(int const raw);
	
private:
	// 고정 소수점 값을 저장할 정수
	int fixedNum;

	// 소수 비트 수를 저장하기 위한 정적 상수, 이 상수의 자리수는 9이다.
	 const static int bitNum = 8;
};

#endif
