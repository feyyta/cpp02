/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:55:34 by mcastrat          #+#    #+#             */
/*   Updated: 2025/11/12 14:11:24 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int	 _value;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif

