/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:51:03 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/07 06:39:45 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <ostream>
# include <set>

class Span
{
	public:
	class SpanFullException : public std::exception
	{
		public:
		virtual ~SpanFullException() throw();
		virtual char const	*what(void) const throw();
	}; // class SpanFullException

	class NotEnoughValuesException : public std::exception
	{
		public:
		virtual ~NotEnoughValuesException() throw();
		virtual char const	*what(void) const throw();
	}; // class NotEnoughValuesException

	private:
	std::multiset<int>	values;
	unsigned int const	n;

	public:
	Span(void);
	Span(Span const &x);
	Span(unsigned int n);
	virtual ~Span();

	Span						&operator=(Span const &x);

	public:
	void						addNumber(int number) throw(SpanFullException);
	unsigned int				shortestSpan(void) const throw(NotEnoughValuesException);
	unsigned int				longestSpan(void) const throw(NotEnoughValuesException);
	std::multiset<int> const	&getValues(void) const;
	unsigned int				getSize(void) const;

	private:
	static unsigned int	abs(int n);

	public:
	template < class Iterator >
	void						addRange(Iterator first, Iterator last)
	throw(SpanFullException)
	{
		for (Iterator it = first; it != last; ++it)
			addNumber(*it);
	}
}; // class Span

std::ostream	&operator<<(std::ostream &os, Span const &span);

#endif
