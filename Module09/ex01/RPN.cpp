#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(char* expr) : _expr(expr) {}

RPN::RPN(const RPN &ref) {
	*this = ref;
}

RPN& RPN::operator=(const RPN &ref) {
	_expr = ref._expr;
	_stack = ref._stack;
	return *this;
}

RPN::~RPN() {}

int RPN::calc(int A, int B, char op) {
	switch (op) {
		case '+':
			return A + B;
		case '-':
			return B - A;
		case '*':
			return A * B;
		case '/': {
			if (A == 0) 
				throw std::invalid_argument(ZeroDivision_ERR);
			return B / A;
		}
	}
	return 0;
}

void RPN::execute()
{
	std::string operators = "+-*/";

	for (size_t i = 0; i < _expr.length(); i++) {
		if (isspace(_expr[i]))
			continue;
		if (isdigit(_expr[i]))
			_stack.push(_expr[i] - '0');
		else if (operators.find(_expr[i]) == std::string::npos)
			throw std::invalid_argument(INVALIDINPUT_ERR);
		else {
			if (_stack.size() < 2)
				throw std::invalid_argument(INVALIDINPUT_ERR);
			int A = _stack.top();
			_stack.pop();
			_stack.top() = calc(A, _stack.top(), _expr[i]);
		}
	}

	if (_stack.size() != 1)
		throw std::invalid_argument(INVALIDINPUT_ERR);

	std::cout << _stack.top() << std::endl;
}