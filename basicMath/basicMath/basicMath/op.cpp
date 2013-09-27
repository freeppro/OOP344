/**********************************************
 *
 *  Modifier     : Nak Gyu Choi (061-349-122)
 *  Lastest date : September 25th 2013
 *
 *  basic math
 *  op.cpp
 *
 **********************************************
 */

#include <iostream>   // ostream
#include <cstring>    // strlen, strcpy
#include <cstdlib>    // atof
#include <cctype>     // toupper
	using namespace std;
   
#include "op.h"

namespace oper{

// constructor
Oper::Oper(){

	in_argc    = 0;
   
	db_leftNo  = 0;
	db_rightNo = 0;
	ch_oper    = '\0';

}


// constructor
Oper::Oper(int p_argc, char* p_argv[]){

	in_argc = p_argc;

	for(int i = 0; i < p_argc; i++){
		ch_argv[i] = new char[strlen(p_argv[i])+1];
		strcpy(ch_argv[i], p_argv[i]);
	}
   
}


// destructor
Oper::~Oper(){
	delete [] *ch_argv;
}


// Check wheather two numbers and operator are valid
bool Oper::isValid(){

	bool result = false;

	if(isValidNo(ch_argv[1]) == true && isValidNo(ch_argv[3]) == true && isValidOper(ch_argv[2]) == true){

		db_leftNo  = atof(ch_argv[1]);
		ch_oper    = ch_argv[2][0];
		db_rightNo = atof(ch_argv[3]);
		
		result = true;
	}
	
	return result;

}


// Check operator
bool Oper::isValidOper(char* chk_valid){

	bool bl_valid = false; //return value; return 1 if not valid;
   
	if(strlen(chk_valid) == 1){
		if(chk_valid[0] == '+' || chk_valid[0] == '-' || tolower(chk_valid[0]) == 'x' || chk_valid[0] == '/')
			bl_valid = true;
	}

	return bl_valid;

}


// Check digit : this function is copied from Wei-Hao Lo's Code
bool Oper::isValidNo(char* chk_valid){
    
	int  deci_counter = 0;
	bool valid        = true; //return value; return 1 if not valid;
    
    int  neg_counter  = 0;

    for (int i = 0; chk_valid[i] != '\0'; i++) {
        
        if ( chk_valid[i] == 45 && neg_counter == 0) {
            neg_counter += 1;   //increase counter, go to next position.
        } else {
            if ( chk_valid[i] == 46 && deci_counter == 0 ) {
                deci_counter+=1;
            } else if( chk_valid[i] == 46 && deci_counter == 1 ) {   //more than 2 decimal points
                valid = false;
                break;
            } else if ( chk_valid[i] < 48 || 57 < chk_valid[i] ) {
                valid = false;
                break;
            }
        }

	}

    return valid;

}


// calcurate with two numbers
void Oper::cal(char p_oper){

	switch(ch_oper){
		case '+' : db_result = db_leftNo + db_rightNo; break;
		case '-' : db_result = db_leftNo - db_rightNo; break;
		case 'x' :
		case 'X' : db_result = db_leftNo * db_rightNo; break;
		case '/' : db_result = db_leftNo / db_rightNo; break;
	}

}


// display the result
ostream& operator<<(ostream& os, const Oper& o){

	cout << o.db_leftNo << " " << o.ch_oper << " " << o.db_rightNo << " = " << o.db_result << endl;
   
	return os;

}

}