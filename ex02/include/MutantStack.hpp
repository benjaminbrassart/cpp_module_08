/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:36:31 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/07 11:06:42 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template< class T >
class MutantStack : public std::stack< T >
{
	public:
	typedef typename std::stack< T >::container_type::iterator					iterator;
	typedef typename std::stack< T >::container_type::const_iterator			const_iterator;
	typedef typename std::stack< T >::container_type::reverse_iterator			reverse_iterator;
	typedef typename std::stack< T >::container_type::const_reverse_iterator	const_reverse_iterator;

	public:
	MutantStack(void) : std::stack< T >()
	{
	}

	MutantStack(MutantStack const &x) : std::stack< T >(x)
	{
	}

	virtual ~MutantStack()
	{
	}

	MutantStack	&operator=(MutantStack const &x)
	{
		std::stack<T>::operator=(x);
		return (*this);
	}

	public:
	iterator				begin(void)
	{
		return (this->c.begin());
	}

	const_iterator			begin(void) const
	{
		return (this->c.begin());
	}

	reverse_iterator		rbegin(void)
	{
		return (this->c.rbegin());
	}

	const_reverse_iterator	rbegin(void) const
	{
		return (this->c.rbegin());
	}

	iterator				end(void)
	{
		return (this->c.end());
	}

	const_iterator			end(void) const
	{
		return (this->c.end());
	}

	reverse_iterator		rend(void)
	{
		return (this->c.rend());
	}

	const_reverse_iterator	rend(void) const
	{
		return (this->c.rend());
	}

}; // class MutantStack

#endif
