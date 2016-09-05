#include "four_gearless_db.h"

four_gearless_db* four_gearless_db::m_instance = NULL;

four_gearless_db::four_gearless_db()
{
	ifstream infile("/home/thejas/mini_pj/mini_pj_makefile_23july11pm/resources/database.txt");
	string temp;
	getline(infile,temp);
	vector<string> allSpecsName;
        strtk::parse(temp,":",allSpecsName);
	for(string line;getline(infile,line);)
        {
                vector<string> allSpecs;
                strtk::parse(line,":",allSpecs);
		if((allSpecs[0] == "4") && (allSpecs[1] == "GL"))
		{
			autocar.insert(make_pair(allSpecs[2],specs()));
			for(int i=3;i<allSpecs.size();i++)
                	{
                		autocar[allSpecs[2]].insert(make_pair(allSpecsName[i],allSpecs[i]));
                	}
		}	
        }
//	for(auto it = autocar.begin();it != autocar.end();it++)
//        {
//              cout << it->first;
//              for(auto itin = (it->second).begin();itin != (it->second).end();itin++)
//              {
//                      cout << "\t" << itin->first << "\t" << itin->second << endl;
//              }
//        }
}
four_gearless_db* four_gearless_db::instance()
{
        if(!m_instance)
        {
                m_instance = new four_gearless_db;
        }
        return m_instance;
}
