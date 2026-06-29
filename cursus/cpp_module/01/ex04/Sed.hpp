/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:56:28 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/28 15:49:32 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>

class Sed
{
	private:
		std::string		filename;
		std::string		s1;
		std::string		s2;
		std::ifstream	ifs;
		std::ofstream	ofs;
		void			putError(std::string msg);
		void			validateArguments(void);

	public:
		Sed(std::string filename, std::string s1, std::string s2);
		void	replace(void);
};

#endif
