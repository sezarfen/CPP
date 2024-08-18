#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
: AForm() // calling default constructor for AForm also
{
	// nothing to do I think
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ){
	// nothing to do I think
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
: AForm(other)
{
	int executeGrade = other.getGradeNeededToExecute();
	int signGrade = other.getGradeNeededToSign();

	// AForm already checks 1 right?
	if (executeGrade > 137)
		throw AForm::GradeTooLowException();
	else if (signGrade > 145)
		throw AForm::GradeTooHighException();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& rhs ){
	if (this == &rhs){
		return (*this);
	}
	// what can be done here?
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ){
	this->_target = target;

  	  std::string tree = 
"                                   .         ; \n"
"      .              .              ;%     ;; \n"
"        ,           ,                :;%  %; \n"
"         :         ;                   :;%;'     ., \n"
",.        %;     %;            ;        %;'    ,; \n"
"  ;       ;%;  %%;        ,     %;    ;%;    ,%' \n"
"   %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"    ;%;      %;        ;%;        % ;%;  ,%;' \n"
"     `%;.     ;%;     %;'         `;%%;.%;' \n"
"      `:;%.    ;%%. %@;        %; ;@%;%' \n"
"         `:%;.  :;bd%;          %;@%;' \n"
"           `@%:.  :;%.         ;@@%;' \n"
"             `@%.  `;@%.      ;@@%; \n"
"               `@%%. `@%%    ;@@%; \n"
"                 ;@%. :@%%  %@@%; \n"
"                   %@bd%%%bd%%:; \n"
"                     #@%%%%%:;; \n"
"                     %@@%%%::; \n"
"                     %@@@%(o);  . ' \n"
"                     %@@@o%;:(.,' \n"
"                 `.. %@@@o%::; \n"
"                    `)@@@o%::; \n"
"                     %@@(o)::; \n"
"                    .%@@@@%::; \n"
"                    ;%@@@@%::;. \n"
"                   ;%@@@@%%:;;;. \n"
"               ...;%@@@@@%%:;;;;,..    \n"
;

  std::ofstream newFile(target);
  if (!newFile.is_open()){
    throw std::exception();
  }
  newFile << tree;
  newFile.close();  
}

