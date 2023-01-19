#include "ShrubberyCreationForm.hpp"

/* orthodox canonical form */
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default") { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src), _target(src._target) { }
// AForm(src)하면 145, 137로 만들어질까?

ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

/* getter */
const std::string	&ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

/* member function */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	
	std::ofstream ofs(this->_target + "_shrubbery");
	if (!ofs.is_open())
		std::cout << this->_target << " cannot open file" << std::endl;
	else { 
		ofs << "               _{\\ _{\\{\\/}/}/}__                    " << std::endl;
		ofs << "              {/{/\\}{/{/\\}(\\}{/\\} _                " << std::endl;
		ofs << "             {/{/\\}{/{/\\}(_)\\}{/{/\\}  _            " << std::endl;
		ofs << "          {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}           " << std::endl;
		ofs << "         {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}            " << std::endl;
		ofs << "        _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}            " << std::endl;
		ofs << "       {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}           " << std::endl;
		ofs << "       _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}           " << std::endl;
		ofs << "      {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}          " << std::endl;
		ofs << "       {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}         " << std::endl;
		ofs << "        {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)          " << std::endl;
		ofs << "       {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}          " << std::endl;
		ofs << "        {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}          " << std::endl;
		ofs << "          {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}          " << std::endl;
		ofs << "           (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)           " << std::endl;
		ofs << "             {/{/{\\{\\/}{/{\\{\\{\\(_)/}               " << std::endl;
		ofs << "              {/{\\{\\{\\/}/}{\\{\\}}/}                 " << std::endl;
		ofs << "               {){/ {\\/}{\\/} \\}\\}                  " << std::endl;
		ofs << "               (_)  \\.-'.-/                        " << std::endl;
		ofs << "           __...--- |'-.-'| --...__                " << std::endl;
		ofs << "    _...--.   .-'   |'-.-'|  ' -.  ...--..__       " << std::endl;
		ofs << "  -.    ' .  . '    |.'-._| '  . .  '              " << std::endl;
		ofs << "  .  '-  '    .--'  | '-.'|    .  '  . '           " << std::endl;
		ofs << "           ' ..     |'-_.-|                        " << std::endl;
		ofs << "   .  '  .       _.-|-._ -|-._  .  '  .            " << std::endl;
		ofs << "               .'   |'- .-|   '.                   " << std::endl;
		ofs << "   ..-'   ' .  '.   `-._.-�   .'  '  - .           " << std::endl;
		ofs << "    .-' '        '-._______.-'     '  .            " << std::endl;
		ofs << "         .      ~,                                 " << std::endl;
		ofs << "     .       .   |\\   .    ' '-.                   " << std::endl;
		ofs << "     ___________/  \\____________                   " << std::endl;
		ofs << "    /                           \\                  " << std::endl;
		ofs << "   |     create shrubberry !!    |                 " << std::endl;
		ofs << "    \\___________________________/                  " << std::endl;
		ofs << "                                                   " << std::endl;
		ofs.close();
		std::cout << this->_target << "create shrubberry file" << std::endl;
	}
}