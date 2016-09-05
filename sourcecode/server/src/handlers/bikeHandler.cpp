#include "bikeHandler.h"

void handleBike()
{
	cout << "enter bike name:\n 1. Pulsar \n 2. Karisma " << endl;
                int typeOfVehicle;
                cin >> typeOfVehicle;
	string tp;
	if(typeOfVehicle == 1) tp="Pulsar"; else tp="Karisma";
	//create a new thread which will process information of bikes received by clients
	int num = 23;		//dummy data

	logger("INFO","SERVER","Client[ ] request for details " +tp+" "+to_string(num));
	// always try to get instance of db. 
	two_gear_db *tmp = two_gear_db::instance();
	logger("DEBUG","SERVER","Getting the instance of database");
	tw_gear *temp = new tw_gear(tmp->get_data(tp));
	cout << tp<< endl;
	temp->show_details();
	logger("INFO","SERVER","Pulsar details sent over socket");
	// delete temp in destructor of tw_gear class 
	delete temp;
}
