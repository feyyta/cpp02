/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:48:53 by mcastrat          #+#    #+#             */
/*   Updated: 2025/11/12 16:56:03 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
/*Le but des fixed-point est d'avoir la vitesse des entiers avec la
  précision des décimaux
  
 Analogie :
  C'est comme stocker des centimes dans un int :
  - Tu as 42€50
  - Tu stockes 4250 (en centimes)
  - C'est un INT, mais tu l'INTERPRÈTES comme des euros avec 2 décimales
 */
class Fixed {

	private:
		int _value;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
