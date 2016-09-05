#ifndef four_gearless_DB
#define four_gearless_DB 

#include "masterheaders.h"
#include "strtk.hpp"

typedef map<string, string> specs;
typedef map<string, specs> vehicle;

class four_gearless_db
{
private:	
	four_gearless_db();
	vehicle autocar;
	static four_gearless_db *m_instance;
public:
	static four_gearless_db* instance();
};	

#endif 
