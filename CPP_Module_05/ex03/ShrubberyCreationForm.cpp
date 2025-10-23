// ****************************************************************************************** //
//                               file: ShrubberyCreationForm.cpp                              //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/23 19:12 by mait-all                        //
//                               Updated: 2025/10/23 19:12 by mait-all                        //
// ****************************************************************************************** //

#include "ShrubberyCreationForm.hpp"

// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm ("ShruberyCreationForm", "unknown", 145, 137)
{}

// Parametrised constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
    : AForm("ShrubberyCreationForm", target, 145, 137) 
{}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other)
{}

// copy assignment operator
ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    AForm::operator=(other);
    return (*this);
}

// Destructor 
ShrubberyCreationForm::~ShrubberyCreationForm() {}


// -------------------------------
// Member functions
// -------------------------------

void    ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    std::ofstream   file((this->getTarget() + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("failed to open file");
    file << "                                               .\n"
            "                                              .         ;  \n"
            "                 .              .              ;%     ;;   \n"
            "                   ,           ,                :;%  %;   \n"
            "                    :         ;                   :;%;'     .,   \n"
            "           ,.        %;     %;            ;        %;'    ,;\n"
            "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
            "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
            "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
            "                `%;.     ;%;     %;'         `;%%;.%;'\n"
            "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
            "                    `:%;.  :;bd%;          %;@%;'\n"
            "                      `@%:.  :;%.         ;@@%;'   \n"
            "                        `@%.  `;@%.      ;@@%;         \n"
            "                          `@%%. `@%%    ;@@%;        \n"
            "                            ;@%. :@%%  %@@%;       \n"
            "                              %@bd%%%bd%%:;     \n"
            "                                #@%%%%%:;;\n"
            "                                %@@%%%::;\n"
            "                                %@@@%(o);  . '         \n"
            "                                %@@@o%;:(.,'         \n"
            "                            `.. %@@@o%::;         \n"
            "                               `)@@@o%::;         \n"
            "                                %@@(o)::;        \n"
            "                               .%@@@@%::;         \n"
            "                               ;%@@@@%::;.          \n"
            "                              ;%@@@@%%:;;;. \n"
            "                          ...;%@@@@@%%:;;;;,..\n";

    file.close();    
}