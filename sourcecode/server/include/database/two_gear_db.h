#ifndef two_gear_db_
#define two_gear_db_

#include "masterheaders.h"
#include "strtk.hpp"

#include "two_gear_db.h"
#include "two_gearless_db.h"                     // reads database to singleton class
#include "four_gear_db.h"
#include "four_gearless_db.h"


// vehicle information is stored in multi-dimentional map of strings (key -> value) key=string , value is a map of string->string
typedef map<string, string> specs;		// key value pair of specifications ex: mileage->45kmpl
typedef map<string, specs> vehicle;		// key value pair of different bikes ex: Pulsar->(all specifications)

class two_gear_db
{
private:
	two_gear_db();				// private constructor
	vehicle bike;					
	static two_gear_db *m_instance;
public:
	static two_gear_db* instance();		// creating singleton class
	specs get_data(string);			// return the specifications of the requested vehicle
	void update_two_gear_db();		
	void db_fill();
};	

#endif 
