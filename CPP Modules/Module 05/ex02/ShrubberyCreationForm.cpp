#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm", 145, 137) 
{
    this->Target = "none";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target):Form("ShrubberyCreationForm", 145, 137) 
{
    this->Target = Target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):Form("ShrubberyCreationForm", 145, 137) 
{
    this->Target = src.Target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & obj) 
{
    this->Target = obj.Target;
    return *this;
}

void ShrubberyCreationForm::action() const 
{
    std::ofstream outFile(this->Target + "_shrubbery");
    if (!outFile) 
	{
        std::cerr << "can't open/create" << this->Target + "_shrubbery" << std::endl;
        return ;
    }
    outFile << 
    "            # #### ####\n"
    "        ### \\/#|### |/####\n"
    "        ##\\/#/ \\||/##/_/##/_#\n"
    "       ###  \\/###|/ \\/ # ###\n"
    "    ##_\\_#\\_\\## | #/###_/_####\n"
    "    ## #### # \\ #| /  #### ##/##\n"
    "    __#_--###`  |{,###---###-~\n"
    "                \\ }{\n"
    "                }}{\n"
    "                }}{\n"
    "        akarafi {{}\n"
    "        , -=-~{ .-^- _\n"
    "                `}\n"
    "                 {"
    << std::endl;
}