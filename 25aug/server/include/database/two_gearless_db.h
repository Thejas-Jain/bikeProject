#ifndef two_gearless_db_ 
#define two_gearless_db_

#include "masterheaders.h"
#include "strtk.hpp"
typedef map<string, string> specs;
typedef map<string, specs> vehicle;

class two_gearless_db
{
private:
	two_gearless_db();
	vehicle scooty;
	static two_gearless_db *m_instance;
public:
	static two_gearless_db* instance();
};	

#endif 
