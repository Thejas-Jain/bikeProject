#include "two_gear_db.h"

two_gear_db* two_gear_db::m_instance = NULL;
extern string database_path;			// global variable used by all classes so extern

void two_gear_db::db_fill()
{
	cout << database_path << endl;
	fstream infile(database_path);
	string temp;
	getline(infile,temp);

	bike.clear();

	vector<string> allSpecsName;
	strtk::parse(temp,":",allSpecsName);
	for(string line;getline(infile,line);)
	{
		vector<string> allSpecs;
		strtk::parse(line,":",allSpecs);
		if((allSpecs[0] == "2") && (allSpecs[1] == "G"))
		{
			bike.insert(make_pair(allSpecs[2],specs()));
			for(int i=3;i<allSpecs.size();i++)
			{
				bike[allSpecs[2]].insert(make_pair(allSpecsName[i],allSpecs[i]));
			}
		}	
	}
}


two_gear_db::two_gear_db()
{
	db_fill();
}

two_gear_db* two_gear_db::instance()
{
	if(!m_instance)
	{
		m_instance = new two_gear_db;
	}
	return m_instance;
}

specs two_gear_db::get_data(string nameOfBike)
{
	specs gaadi;
	logger("INFO","SERVER","Get the data for the required vehicle");
	for(auto it = bike.begin();it != bike.end();it++)
	{
		if(nameOfBike.compare(it->first) != 0)
			continue;
		else
		{
			for(auto itin = (it->second).begin();itin != (it->second).end();itin++)
			{
				gaadi[itin->first] = itin->second;
			}
			return gaadi;
		}
	}
}			

// This can be kept in common place inorder to update for 2w and 4w.
void two_gear_db::update_two_gear_db()
{
	// Add lock here 
	db_fill();
}
