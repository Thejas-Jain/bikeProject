#include "two_gearless_db.h"

two_gearless_db* two_gearless_db::m_instance = NULL;
two_gearless_db::two_gearless_db()
{
	ifstream infile("../resources/database.txt");
	string temp;
	getline(infile,temp);
	vector<string> allSpecsName;
        strtk::parse(temp,":",allSpecsName);
	for(string line;getline(infile,line);)
        {
                vector<string> allSpecs;
                strtk::parse(line,":",allSpecs);
		if((allSpecs[0] == "2") && (allSpecs[1] == "GL"))
		{
			scooty.insert(make_pair(allSpecs[2],specs()));
			for(int i=3;i<allSpecs.size();i++)
                	{
                		scooty[allSpecs[2]].insert(make_pair(allSpecsName[i],allSpecs[i]));
                	}
		}	
        }
//	for(auto it = scooty.begin();it != scooty.end();it++)
//        {
//              cout << it->first;
//              for(auto itin = (it->second).begin();itin != (it->second).end();itin++)
//              {
//                      cout << "\t" << itin->first << "\t" << itin->second << endl;
//              }
//        }
}
two_gearless_db* two_gearless_db::instance()
{
        if(!m_instance)
        {
                m_instance = new two_gearless_db;
        }
        return m_instance;
}
