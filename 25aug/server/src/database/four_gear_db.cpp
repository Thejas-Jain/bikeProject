#include "four_gear_db.h"

four_gear_db* four_gear_db::m_instance = NULL;

four_gear_db::four_gear_db()
{
	ifstream infile("/home/osboxes/bikeproject/mini_pj/resources/database.txt");
	string temp;
	getline(infile,temp);
	vector<string> allSpecsName;
        strtk::parse(temp,":",allSpecsName);
	for(string line;getline(infile,line);)
        {
                vector<string> allSpecs;
                strtk::parse(line,":",allSpecs);
		if((allSpecs[0] == "4") && (allSpecs[1] == "G"))
		{
			car.insert(make_pair(allSpecs[2],specs()));
			for(int i=3;i<allSpecs.size();i++)
                	{
                		car[allSpecs[2]].insert(make_pair(allSpecsName[i],allSpecs[i]));
                	}
		}	
        }
	/*for(auto it = car.begin();it != car.end();it++)
        {
              cout << it->first;
              for(auto itin = (it->second).begin();itin != (it->second).end();itin++)
              {
                      cout << "\t" << itin->first << "\t" << itin->second << endl;
              }
        }*/
}

four_gear_db* four_gear_db::instance()
{
        if(!m_instance)
        {
                m_instance = new four_gear_db;
        }
        return m_instance;
}
