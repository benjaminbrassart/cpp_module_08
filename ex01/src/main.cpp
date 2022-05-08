/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 06:20:11 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/09 01:08:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "tests.h"

#include <cstdarg>
#include <cstdlib>
#include <list>
#include <vector>

static void	_ctor_dfl(void);
static void	_ctor_cpy(void);
static void	_ctor_n(void);
static void	_op_assign(void);
static void	_span_short(void);
static void	_span_long(void);
static void	_add_number(void);
static void	_add_range(void);

static void	__manual_test(std::vector< std::string > const &args);

int	main(int argc, char const *argv[])
{
	std::vector< std::string >	args;

	if (argc > 1)
	{
		args = std::vector< std::string >(argc - 1);
		for (int i = 1; i < argc; ++i)
			args.push_back(std::string(argv[i]));
		__manual_test(args);
		return (0);
	}

	TEST_DECL() {
		TEST(_ctor_dfl)
		TEST(_ctor_cpy)
		TEST(_ctor_n)
		TEST(_op_assign)
		TEST(_span_short)
		TEST(_span_long)
		TEST(_add_number)
		TEST(_add_range)
	};
	TEST_RUN();
}

static void	_ctor_dfl(void)
{
	Span	span;

	std::cout << span << std::endl;
}

static void	_ctor_cpy(void)
{
	Span	span(5);

	span.addNumber(4);
	span.addNumber(1);
	span.addNumber(45);
	span.addNumber(0);

	Span	cpy(span);

	std::cout << span << std::endl;
	std::cout << cpy << std::endl;

	std::cout << std::endl;
	cpy.addNumber(69);

	std::cout << span << std::endl;
	std::cout << cpy << std::endl;
}

static void	_ctor_n(void)
{
	Span	span0(10);
	Span	span1(15);
	Span	span2(20);
	Span	span3(25);

	std::cout
		<< span0 << std::endl
		<< span1 << std::endl
		<< span2 << std::endl
		<< span3 << std::endl;
}

static void	_op_assign(void)
{
	Span	span;

	span = Span(45);
	std::cout << span << std::endl;
	span = Span(55);
	std::cout << span << std::endl;
}

static void	_span_short(void)
{
	Span				span(45);
	std::vector< int >	vec;

	for (int i = 0; i < 45; ++i)
		vec.push_back(i * 4);
	span.addRange(vec.rbegin(), vec.rend());
	std::cout << span << std::endl;
	std::cout << "shortestSpan = " << span.shortestSpan() << std::endl;
}

static void	_span_long(void)
{
	Span				span(45);
	std::vector< int >	vec;

	for (int i = 0; i < 45; ++i)
		vec.push_back(i * 4);
	span.addRange(vec.rbegin(), vec.rend());
	std::cout << span << std::endl;
	std::cout << "longestSpan = " << span.longestSpan() << std::endl;
}

static void	_add_number(void)
{
	{
		Span	span(10);

		std::cout << span << std::endl << "-----" << std::endl;
		for (int i = 0; i < 20; ++i)
		{
			try
			{
				span.addNumber(i);
				std::cout
					<< "added "
					<< i
					<< std::endl;
			}
			catch(std::exception& e)
			{
				std::cout
					<< "\033[31m"
					<< "cannot add "
					<< i
					<< ": "
					<< e.what()
					<< "\033[0m"
					<< std::endl;
			}
		}
		std::cout << std::endl << span << std::endl;
	}

	std::cout
		<< std::endl
		<< "======================================="
		<< std::endl << std::endl;

	{
		Span	span;

		std::cout << span << std::endl << "-----" << std::endl;
		try
		{
			span.addNumber(42);
			std::cout
				<< "added "
				<< 42
				<< std::endl;
		}
		catch(std::exception& e)
		{
			std::cout
				<< "\033[31m"
				<< "cannot add "
				<< 42
				<< ": "
				<< e.what()
				<< "\033[0m"
				<< std::endl;
		}
		std::cout << std::endl << span << std::endl;
	}
}

static void	_add_range(void)
{
	Span				span(45);
	std::vector< int >	vec;

	for (int i = 0; i < 45; ++i)
		vec.push_back(i * 4);
	span.addRange(vec.rbegin(), vec.rend());
	std::cout << span << std::endl;
}

static void	__manual_test(std::vector< std::string > const &args)
{
	Span				span;
	std::string			line;
	std::list< int >	*values;

	if (args[1] == "-")
	{
		values = new std::list< int >();
		while (std::getline(std::cin, line))
			values->push_back(std::atoi(line.c_str()));
		span = Span(values->size());
		span.addRange(values->begin(), values->end());
		delete values;
	}
	else
	{
		span = Span(args.size() - 1);
		std::cout << span << std::endl << std::endl;
		for (
			std::vector< std::string >::const_iterator it = args.begin();
			it != args.end();
			++it
		)
		{
			if (it == args.begin())
				continue ;
			span.addNumber(std::atoi(it->c_str()));
		}
	}
	std::cout
		<< span
		<< std::endl << std::endl
		<< "Shortest span: ";
	try
	{
		std::cout << span.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout
			<< "\033[31m"
			<< e.what()
			<< "\033[0m";
	}
	std::cout
		<< std::endl
		<< "Longest span:  ";
	try
	{
		std::cout << span.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cout
			<< "\033[31m"
			<< e.what()
			<< "\033[0m";
	}
	std::cout << std::endl;
}
