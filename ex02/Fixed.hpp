#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <cmath>

class Fixed{
public:
	// 생성자 : 고정 소수점 값을 0으로 초기화
	Fixed();

	// 생성자 : integer를 매개변수로 사용하고, 이를 fixed(8) 포인트 값으로 변환하는 생성자.
	//			소수점 자리수의 비트 값은 ex00와 같이 초기화 된다.
	Fixed(const int num);

	// 생성자 : floating 부동 소수점을 매개변수로 사용하고 fixed(8) 소수점 값으로 변환하는 생성자.
	//			소수 비트 값은 ex00와 같이 초기화 된다.
	Fixed(const float num);

	// 소멸자
	~Fixed();
	// 복사 생성자
	Fixed(Fixed const &fixed);

	// 고정 소수점 값의 원시 값을 반환
	int getRawBits(void) const;

	// 고정 소수점 값의 원시 값을 설정
	void setRawBits(const int raw);

	// 고정 소수점 값을 부동 소수점 값으로
	float toFloat(void) const;

	// 고정 소수점 값을 정수값으로
	// 또한 헤더 및 소스 파일에 함수 오버로드를 추가한다.
	int toInt(void) const;

	// 대입 연산자 overload
	Fixed &operator=(const Fixed &ref);

	// 6가지 비교 연산자: >, <, >=, <=, == 및 !=.
	bool operator>(const Fixed &ref);
	bool operator<(const Fixed &ref);
	bool operator>=(const Fixed &ref);
	bool operator<=(const Fixed &ref);
	bool operator==(const Fixed &ref);
	bool operator!=(const Fixed &ref);

	// 4개의 산술 연산자: +, -, * 및 /.
	Fixed operator+(const Fixed &ref);
	Fixed operator-(const Fixed &ref);
	Fixed operator*(const Fixed &ref);
	Fixed operator/(const Fixed &ref);

	// 사전 증가, 사후 증가, 사전 감소 및 사후 감소 연산자
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	// 멤버함수
	static Fixed min(const Fixed &ref1, const Fixed &ref2);
	static Fixed max(const Fixed &ref1, const Fixed &ref2);

private:
	// 고정 소수점 값을 저장할 정수
	int value;

	// 소수 비트 수를 저장하기 위한 정적 상수, 이 상수의 자리수는 8이다.
	 const static int bitCount = 8;
};

std::ostream& operator<<(std::ostream &outputStream, const Fixed &ref);


#endif
