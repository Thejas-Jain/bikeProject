#ifndef two_gear_db_
#define two_gear_db_

#include "masterheaders.h"
#include "strtk.hpp"

typedef map<string, string> specs;
typedef map<string, specs> vehicle;

class two_gear_db
{
private:
	two_gear_db();	
	vehicle bike;
	static two_gear_db *m_instance;
public:
	static two_gear_db* instance();
	specs get_data(string);
	void update_two_gear_db();
	void db_fill();
};	

#endif 
