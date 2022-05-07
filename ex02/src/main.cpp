/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:53:20 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/07 11:12:04 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int	main(void)
{
	MutantStack< int >	*stack = new MutantStack< int >();

	stack->push(1);
	stack->push(3);
	stack->push(6);
	stack->push(1);
	for (
		MutantStack< int >::const_iterator it = stack->begin();
		it != stack->end();
		++it
	)
		std::cout << *it << std::endl;
	delete stack;
}
