#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int value) {
	_value = value << _fractional;
}

Fixed::Fixed(const float value) {
	_value = roundf(value * (1 << _fractional));
}

Fixed::Fixed(const Fixed &other) {
	_value = other._value;
}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other)
	{
		this->_value = other._value;
	}
	return *this;
}

Fixed::~Fixed(){
}

float Fixed::toFloat(void) const {
	return (float)_value / (1 << _fractional);
}

int Fixed::toInt(void) const {
	return _value >> _fractional;
}

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

/****operator: > < >= <= == != *****/
bool Fixed::operator>(const Fixed& other) const {
	return _value > other._value;
}


bool Fixed::operator<(const Fixed& other) const {
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _value >= other._value;
}


bool Fixed::operator<=(const Fixed& other) const {
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _value != other._value;
}

/****operator: + - * / *****/
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed((this->_value + other._value) >> _fractional);
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed((this->_value - other._value) >> _fractional);
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other._value == 0) {
		std::cout << "Error: Divisio by zero!" << std::endl;
		return Fixed(0);
	}
	float result = (float)this->_value / other._value;
	return Fixed(result);
}

/****operator: pre-increment, pre-decrement,
	 *post-increment, post-decrement, *******/

Fixed& Fixed::operator++() {
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_value += 1;
	return temp;
}

Fixed& Fixed::operator--() {
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_value -= 1;
	return temp;
}

/*******max() and min() *****/
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}