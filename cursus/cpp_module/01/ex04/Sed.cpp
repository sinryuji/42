/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:01:30 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/28 17:08:06 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2) : filename(filename), s1(s1), s2(s2)
{
	validateArguments();
}

void	Sed::putError(std::string msg)
{
	std::cerr << msg << std::endl;
	std::exit(1);
}

void	Sed::validateArguments(void)
{
	if (this->s1.empty() == true)
		putError("s1 is empty");
	if (this->s2.empty() == true)
		putError("s2 is empty");
	ifs.open(this->filename, std::ifstream::in);
	if (ifs.fail() == true)
		putError("failed to open file to read");
	this->filename.append(".replace");
	ofs.open(this->filename, std::ofstream::out);
	if (ofs.fail() == true)
		putError("failed to open file to write");
}

void	Sed::replace(void)
{
	std::string	line;

	while (true)
	{
		std::getline(this->ifs, line);
		if (ifs.eof() == true)
			break;
		while (true)
		{
			size_t found = line.find(this->s1);
			if (found == std::string::npos)
				break;
			line.erase(found, this->s1.length());
			line.insert(found, this->s2);
		}
		ofs << line << "\n";
	}
	ofs << std::flush;
	ifs.close();
	ofs.close();
}
