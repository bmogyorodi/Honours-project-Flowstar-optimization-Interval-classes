/*---
  Flow*: A Verification Tool for Cyber-Physical Systems.
  Authors: Xin Chen, Sriram Sankaranarayanan, and Erika Abraham.
  Email: Xin Chen <chenxin415@gmail.com> if you have questions or comments.
  
  The code is released as is under the GNU General Public License (GPL).
---*/

#include "modelParser.h"
#include <ctime>

extern int yyparse();

int main(int argc, const char *argv[])
{
  
  
	yyparse();
  std::cout<<flowstar::NumofSwitches()<<std::endl;
	return 0;
}



