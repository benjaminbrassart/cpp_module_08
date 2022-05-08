/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:53:20 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/09 00:58:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int	main(void)
{
	MutantStack< int >	*stack = new MutantStack< int >();

	std::cout << *stack << std::endl;
	stack->push(1);
	stack->push(3);
	stack->push(6);
	stack->push(11);
	std::cout << *stack << std::endl;
	stack->pop();
	std::cout << *stack << std::endl;
	stack->top() += 42;
	std::cout << *stack << std::endl;
	delete stack;
}
