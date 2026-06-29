/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:00:10 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/12 14:02:21 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				signFlag;
		const int			signGrade;
		const int			executeGrade;

	public:
		AForm(void);
		AForm(const std::string name, const int signGrade, const int executeGrade);
		AForm(const AForm& origin);
		~AForm(void);
		AForm&				operator=(const AForm& origin);
		const std::string	getName(void) const;
		bool				getSignFlag(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrad(void) const;
		bool				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const& executor) = 0;
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
				RequiredGradeException(std::string bureaucratName, std::string formName, \
						std::string behavior);
				~RequiredGradeException(void) throw();
				const char* what(void) const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& origin);

#endif
