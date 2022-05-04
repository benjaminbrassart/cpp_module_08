/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:27:29 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/04 22:47:57 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "tests.h"
#include <list>
#include <queue>
#include <set>
#include <vector>
#include <ostream>

template < class Container >
static void	_easyfind(Container const &container, int value)
{
	std::cout << value << " -> ";
	if (easyfind(container, value))
		std::cout << "\033[32mfound";
	else
		std::cout << "\033[31mnot found";
	std::cout << "\033[0m" << std::endl;
}

template < class Container >
static void	_print(Container const &container)
{
	std::cout << "[ ";
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (it != container.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout
		<< " ] ("
		<< container.size()
		<< ")"
		<< std::endl;
}

static void	_vector(void);
static void	_set(void);
static void	_deque(void);
static void	_list(void);

int	main(void)
{
	TEST_DECL() {
		TEST(_vector)
		TEST(_set)
		TEST(_deque)
		TEST(_list)
	};
	TEST_RUN();
}

static void	_vector(void)
{
	std::vector<int>	vec;

	vec.push_back(5);
	vec.push_back(10);
	vec.push_back(111);
	vec.push_back(-111);
	vec.push_back(0);
	_print(vec);
	std::cout << std::endl;
	for (int i = 0; i < 30; ++i)
		_easyfind(vec, i);
}

static void	_set(void)
{
	std::set<int>	set;

	set.insert(5);
	set.insert(10);
	set.insert(111);
	set.insert(-111);
	set.insert(0);
	_print(set);
	std::cout << std::endl;
	for (int i = 0; i < 30; ++i)
		_easyfind(set, i);
}

static void	_deque(void)
{
	std::deque<int>	dq;

	dq.push_back(5);
	dq.push_back(10);
	dq.push_back(111);
	dq.push_back(-111);
	dq.push_back(0);
	_print(dq);
	std::cout << std::endl;
	for (int i = 0; i < 30; ++i)
		_easyfind(dq, i);
}

static void	_list(void)
{
	std::list<int>	list;

	list.push_back(5);
	list.push_back(10);
	list.push_back(111);
	list.push_back(-111);
	list.push_back(0);
	_print(list);
	std::cout << std::endl;
	for (int i = 0; i < 30; ++i)
		_easyfind(list, i);
}
