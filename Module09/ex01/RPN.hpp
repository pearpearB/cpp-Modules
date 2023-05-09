#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>


class RPN
{
	private:
		std::stack<int> _stack;
		std::string _expr;

	public:
		RPN();
		RPN(char* expr);
		RPN(const RPN &ref);
		RPN& operator=(const RPN &ref);
		~RPN();

		void execute();
		int calc(int A, int B, char op);
};

#endif