/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:00:10 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/11 21:26:21 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				signFlag;
		const int			signGrade;
		const int			executeGrade;

	public:
		Form(void);
		Form(const std::string name, const int signGrade, const int executeGrade);
		Form(const Form& origin);
		~Form(void);
		Form&				operator=(const Form& origin);
		const std::string	getName(void) const;
		bool				getSignFlag(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrad(void) const;
		bool				beSigned(const Bureaucrat& bureaucrat);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class RequiredGradeException : public std::exception
		{
			private:
				std::string message;

			public:
				RequiredGradeException(std::string bureaucratName, std::string formName);
				~RequiredGradeException(void) throw();
				const char* what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Form& origin);

#endif
