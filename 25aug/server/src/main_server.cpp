#include "two_gear_db.h"
#include "two_gearless_db.h"
#include "four_gear_db.h"
#include "four_gearless_db.h"

#include "bikeHandler.h"
//#include "scootyHandler.h"
//#include "carHandler.h"
//#include "carglHandler.h"

#include "tw_gear.h"

void getDataBasePath(void);
void initialize_alldb();
string database_path;
pthread_t inotify_thread;
int main()
{
	logger("INFO","SERVER","Staring the server");
	logger("INFO","SERVER","Fetching data base path");
	getDataBasePath();
	logger("DEBUG","SERVER","Database path found");

	// user requests for Pulsar, This needs to be added in a queue, request message.
	// A thread need to handle this requests and show the details.
	// This thread needs to identify which object need to be provided to invoke showdetails.
	// How to handle if our server supports more than two clients requesting for 2gear.

	initialize_alldb();

	{
		// There has to be separate thread that needs to start up for updating the database during runtime //Inotify 
		// ..................
		// ..................
		logger("INFO","SERVER","initializing the inotify");
		init_inotify();
		//get information for type of vehicle
		cout << "enter vehicle type:\n 1. bike \n 2. scooty \n 3.car\n 4. cargl\n" << endl;
		int typeOfVehicle;
		cin >> typeOfVehicle;
		switch (typeOfVehicle){
		case 1:
			handleBike();
			break;
	/*	case 2:
			handleScooty();
			break;
		case 3:
			handleCar();
			break;
		case 4:
			handleCargl();
			break;*/
		default:
			logger("ERROR","SERVER","no matching vehicle received from client");
			break;
		}
		logger("INFO","SERVER","Server exiting.....");
		pthread_join(inotify_thread,NULL);
		return 0;
	}
}

void getDataBasePath(void)
{
	// Shall change the path to our own directory 
	string home=getenv("HOME");
	string path=home+"/"+getenv("ConfPath");

	/*if ( path == NULL  )
	  {
	  logger("ERROR","SERVER","Database getenv path not found");
	  exit (-1); // destrcutor needs to be called
	  }*/


	fstream ifile(path);

	if ( ! ifile) 
	{
		logger("ERROR","SERVER","Database path not found");
		exit (-1); // destrcutor needs to be called
	}

	string temp;
	while ( getline(ifile,temp) )
	{
		vector<string> path;
		strtk::parse(temp,"=",path);
		if ( path[0] == "databasePath" )
		{
			database_path = home+"/"+path[1];
			break;
		}
	}	
}

void initialize_alldb()
{
	// Updating the database during start up of server in constructor 
	// Same constructor cannot be used for updating during runtime changes of database.
	two_gear_db *pBike = two_gear_db::instance();
	two_gearless_db *pScooty = two_gearless_db::instance();
	four_gear_db *pCar = four_gear_db::instance();
	four_gearless_db *pAutoCar = four_gearless_db::instance();
}	
