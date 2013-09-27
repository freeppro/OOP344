/**********************************************
 *
 *  Modifier     : Nak Gyu Choi (061-349-122)
 *  Lastest date : September 25th 2013
 *
 *  basic math
 *  bm.cpp
 *
 **********************************************
 */

#include <iostream>   // cout
#include <cstdarg>    // argc, argva
   using namespace std;

#include "op.h"
   using namespace oper;

int main(int argc, char* argv[]){

   double ldb_leftNo, ldb_rightNo;
   char ch_oper = argv[2][0];
   
   Oper oper(argc, argv);
   
   if (argc == 4 && oper.isValid()) {
   
	  oper.cal(ch_oper);

      cout << oper;
	  
   } else {
      cout << "Usage : bm [number] [+-x(X)/] [number]" << endl;
   }
   system("pause");
   return 0;

}

