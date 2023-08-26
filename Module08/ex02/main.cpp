/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:22:46 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/26 23:22:16 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <iomanip>
#include <list>

void	test_deque(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737); 
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	// more test
	MutantStack<int> copy(mstack);
	std::cout << "# origin" << std::endl;
	mstack.show(); mstack.rshow();
	std::cout << "# fill acsending" << std::endl;
	mstack.fill();
	mstack.show(); mstack.rshow();
	std::cout << "# fill desending" << std::endl;
	mstack.rfill();
	mstack.show(); mstack.rshow();
	std::cout << "# copy show" << std::endl;
	copy.show(); copy.rshow();
	std::cout << "stack pop: ";
	for (; s.empty() == false; s.pop())
		std::cout << s.top() << " ";
	std::cout << std::endl;
}

void	test_list(void)
{
	MutantStack<int, std::list<int> > mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737); 
	//[...]
	mstack.push(0);

	MutantStack<int, std::list<int> >::iterator it = mstack.begin();
	MutantStack<int, std::list<int> >::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int, std::list<int> > s(mstack);
	// more test
	MutantStack<int, std::list<int> > copy(mstack);
	std::cout << "# origin" << std::endl;
	mstack.show(); mstack.rshow();
	std::cout << "# fill acsending" << std::endl;
	mstack.fill();
	mstack.show(); mstack.rshow();
	std::cout << "# fill desending" << std::endl;
	mstack.rfill();
	mstack.show(); mstack.rshow();
	std::cout << "# copy show" << std::endl;
	copy.show(); copy.rshow();
	std::cout << "stack pop: ";
	for (; s.empty() == false; s.pop())
		std::cout << s.top() << " ";
	std::cout << std::endl;
}

int main()
{
	std::cout << std::setw(80) << std::setfill('=') << "=" << std::endl;
	test_deque();
	std::cout << std::setw(80) << std::setfill('=') << "=" << std::endl;
	test_list();
	std::cout << std::setw(80) << std::setfill('=') << "=" << std::endl;
	return 0;
}
