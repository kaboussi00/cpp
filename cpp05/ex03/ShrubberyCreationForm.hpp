#pragma once

#include "AForm.hpp"
#include <fstream>

#define ARBRE "\
             *\n\
            ***\n\
           *****\n\
          *******\n\
      ***************\n\
         *********\n\
    *******************\n\
        ***********\n\
  ***********************\n\
       *************\n\
***************************\n\
     *****************\n\
   *********************\n\
 *************************\n\
           |||||\n\
           |||||\n\
           |||||\n\
           |||||\n\
           |||||\n\
           |||||\n\
           |||||\n"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &obj);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
        void execute(Bureaucrat const & executor) const;
        ~ShrubberyCreationForm();
};
