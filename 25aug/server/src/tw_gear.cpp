#include "tw_gear.h"

tw_gear::tw_gear(specs vahan)
{
	logger("INFO","SERVER","Fiiling up base class vahan");
	this->gaadi = vahan;
}

void tw_gear::show_details(void)
{
	cout << " Bike details are " << endl;
	for(auto it = gaadi.begin();it != gaadi.end();it++)
	{
	 // cout << " Show details are " << endl;
		cout << "\t" << it->first << "\t" << it->second << endl;
	}
}
