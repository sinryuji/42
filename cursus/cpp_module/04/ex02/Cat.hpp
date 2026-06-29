/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:49:12 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/06 02:39:58 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;
		
	public:
		Cat(void);
		Cat(const Cat& origin);
		~Cat(void);
		Cat& operator=(const Cat& origin);
		void makeSound(void) const;
		Brain*	getBrain(void) const;
};

#endif
