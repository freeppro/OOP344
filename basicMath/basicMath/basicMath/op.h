/**********************************************
 *
 *  Modifier     : Nak Gyu Choi (061-349-122)
 *  Lastest date : September 25th 2013
 *
 *  basic math
 *  bm.h
 *
 **********************************************
 */

#ifndef __OPER_H__
#define __OPER_H__

#include <iostream>
	using namespace std;

namespace oper{

	class Oper{

		int    in_argc;
		char*  ch_argv[4];
	  
		double db_leftNo, db_rightNo, db_result;
		char   ch_oper;
      
		bool   isValidOper(char* chk_valid);
		bool   isValidNo(char*);

	public :
		Oper();
		Oper(int, char**);
		~Oper();

		bool   isValid();
		void   cal(char);
		friend ostream& operator<<(ostream&, const Oper&);

	};

}
#endif