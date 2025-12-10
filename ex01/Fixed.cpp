/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:48:57 by mcastrat          #+#    #+#             */
/*   Updated: 2025/12/10 16:11:04 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
}
/*42 (sans décalage):
  00000000 00000000 00000000 00101010
                             └──┬──┘
                               42

  42 << 8 (avec décalage):
  00000000 00000000 00101010 00000000
                    └──┬──┘  └──┬──┘
                      42     frac=0
*/
Fixed::Fixed(const int n) : _value(n << _fractionalBits){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits))){
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		this->_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	return this->_value;
}

void Fixed::setRawBits(int const raw){
	this->_value = raw;
}

float Fixed::toFloat(void) const{
	return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const{
	return this->_value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
	/*if else int ou float pas neccesaire*/
	out << fixed.toFloat();
	return out;
}
