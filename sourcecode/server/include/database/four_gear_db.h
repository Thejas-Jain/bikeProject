#ifndef four_gear_db_ 
#define four_gear_db_

#include "masterheaders.h"
#include "strtk.hpp"

typedef map<string, string> specs;
typedef map<string, specs> vehicle;

class four_gear_db
{
private:	
	four_gear_db();
	vehicle car;
	static four_gear_db *m_instance;
public:
	static four_gear_db* instance();
};	
#endif
