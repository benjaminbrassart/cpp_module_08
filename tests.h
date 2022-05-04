/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:29:53 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/04 14:21:26 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <exception>
# include <iostream>

namespace __test
{
	struct test
	{
		char const	*name;
		void		(*fn)(void);
	};

	class Todo : public std::exception
	{
		public:
		virtual ~Todo() throw() {}
		char const	*what(void) const throw() { return ("TODO"); }
	};
};

# define TEST_DECL()	static struct __test::test const __tests[] =
# define TEST(x)		{#x, x},
# define TEST_RUN()		{								\
	for (												\
		unsigned int i = 0;								\
		i < (sizeof (__tests) / sizeof (*__tests));		\
		++i)											\
		{												\
			if (i != 0)									\
				std::cout << std::endl;					\
			std::cout									\
				<< "\033[32m"							\
				<< "================="					\
				<< std::endl							\
				<< __tests[i].name						\
				<< std::endl							\
				<< "================="					\
				<< "\033[0m"							\
				<< std::endl;							\
			try											\
			{											\
				__tests[i].fn();						\
			}											\
			catch (std::exception &e)					\
			{											\
				std::cout								\
					<< "\033[31mException caught: "		\
					<< e.what()							\
					<< std::endl;						\
			}											\
			std::cout << "\033[0m";						\
		}												\
	}
# define TODO()		{ throw __test::Todo(); }
#endif // TESTS_H
