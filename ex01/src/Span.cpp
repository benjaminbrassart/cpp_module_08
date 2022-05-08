/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:53:18 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/07 09:19:07 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) :
	values(std::multiset<int>()),
	n(0)
{
}

Span::Span(Span const &x) :
	values(x.values),
	n(x.n)
{
}

Span::Span(unsigned int n) :
	values(std::multiset<int>()),
	n(n)
{
}

Span::~Span()
{
}

Span &Span::operator=(Span const &x)
{
	if (&x == this)
		return (*this);
	this->values = x.values;
	*(unsigned int *)&this->n = x.n;
	return (*this);
}

void Span::addNumber(int number)
throw(SpanFullException)
{
	if (this->values.size() >= n)
		throw SpanFullException();
	this->values.insert(number);
}

unsigned int Span::shortestSpan(void) const
throw(NotEnoughValuesException)
{
	std::multiset<int>::const_iterator	it;
	std::multiset<int>::const_iterator	prev;
	unsigned int						span;
	unsigned int						tmp;

	if (this->values.size() < 2)
		throw NotEnoughValuesException();
	span = this->longestSpan();
	for (it = this->values.begin(); span > 0 && it != this->values.end();)
	{
		prev = it++;
		tmp = abs(*it - *prev);
		if (tmp < span)
			span = tmp;
	}
	return (span);
}

unsigned int Span::longestSpan(void) const
throw(NotEnoughValuesException)
{
	if (this->values.size() < 2)
		throw NotEnoughValuesException();
	return (abs(*this->values.begin() - *this->values.rbegin()));
}

std::multiset<int> const &Span::getValues(void) const
{
	return (this->values);
}

unsigned int	Span::getSize(void) const
{
	return (this->n);
}

unsigned int Span::abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

std::ostream &operator<<(std::ostream &os, Span const &span)
{
	std::multiset<int> const	&values = span.getValues();

	os << "Span (" << span.getSize() << ") [";
	for (
		std::multiset<int>::const_iterator it = values.begin();
		it != values.end();
		++it
	)
	{
		if (it != values.begin())
			os << ", ";
		os << *it;
	}
	return (os << "]");
}

Span::SpanFullException::~SpanFullException() throw() {}
Span::NotEnoughValuesException::~NotEnoughValuesException() throw() {}
char const	*Span::SpanFullException::what(void) const throw() { return ("the span is full"); }
char const	*Span::NotEnoughValuesException::what(void) const throw() { return ("not enough values in the span"); }
