//-------------- file includes ------------------//

#include "two_gear_db.h"
#include "two_gearless_db.h"                     // reads database to singleton class
#include "four_gear_db.h"
#include "four_gearless_db.h"

#include "bikeHandler.h"
//#include "scootyHandler.h"			// handle the client request in different functions for different type of vehicles
//#include "carHandler.h"
//#include "carglHandler.h"

#include "tw_gear.h"				// derived class of vehicles (create an instance of the specific vehicle as required)

//-----------------------------------------------//

//-------------global variables-----------------//

string database_path;
pthread_t inotify_thread;			// handles notification when database is changed
const int MAX_THREADS = 10;
map<int,string> threadsAvailable;
pthread_mutex_t mutex_threadsAvailable = PTHREAD_MUTEX_INITIALIZER;
//----------------------------------------------//

//------------function prototyping--------------//

void getDataBasePath(void);
void initialize_alldb();			// update database when server starts or when iNotify is called

//----------------------------------------------//
int main()
{
	logger("INFO","SERVER","Staring the server"); 		//common logger function for debugging
	logger("INFO","SERVER","Fetching data base path");
	getDataBasePath();
	logger("DEBUG","SERVER","Database path found");

	// user requests for Pulsar, This needs to be added in a queue, request message.
	// A thread need to handle this requests and show the details.
	// This thread needs to identify which object need to be provided to invoke showdetails.
	// How to handle if our server supports more than two clients requesting for 2gear.

	initialize_alldb();


	// There has to be separate thread that needs to start up for updating the database during runtime //Inotify 
	// ..................
	// ..................
	logger("INFO","SERVER","initializing the inotify");
	init_inotify();
	while(1){
		//get information for type of vehicle from client /// as of now get it from cout
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
	while(1);
	}
	logger("INFO","SERVER","Server exiting.....");
	pthread_join(inotify_thread,NULL);
	return 0;

}

void getDataBasePath(void)
{
	// Shall change the path to our own directory (Vinod: /home/osboxes , Thejas: /home/thejas, vatsa: ??)
	string home=getenv("HOME");
	if ( getenv("ConfPath") == NULL  )
	{
		cerr << "Environmental variable ConfPath is not set, set it to PRO2016/Conf/Config.conf \n Ex: export ConfPath=PRO2016/Conf/Config.conf in .bashrc and run again!! " << endl ;
		logger("ERROR","SERVER","Environmental variable ConfPath is not set");
		exit (-1); 
	}

	string path=home+"/"+getenv("ConfPath");

	fstream ifile(path);

	if ( ! ifile) 
	{
		logger("ERROR","SERVER","Database file not found");
		exit (-1); 
	}

	string temp;
	char corruptFlag=1;
	while ( getline(ifile,temp) )
	{
		vector<string> path;
		strtk::parse(temp,"=",path);
		if ( path[0] == "databasePath" )		//read the database path from the Config file
		{
			database_path = home+"/"+path[1];
			corruptFlag = 0;
			break;
		}
	}
	if(corruptFlag)
	{
		logger("ERROR","SERVER","Database file corrupted, correct it!");
	}
}

void initialize_alldb()
{
	// Updating the database during start up of server in constructor 
	// Same constructor cannot be used for updating during runtime changes of database. (why?)
	two_gear_db *pBike = two_gear_db::instance();			//creating singleton class of all databases for reference
	two_gearless_db *pScooty = two_gearless_db::instance();
	four_gear_db *pCar = four_gear_db::instance();
	four_gearless_db *pAutoCar = four_gearless_db::instance();
	for(int i=0;i<MAX_THREADS;i++){
		threadsAvailable[i] = "unlocked";
	}
	//for (std::map<int,string>::iterator it=threadsAvailable.begin(); it!=threadsAvailable.end(); ++it)
//    std::cout << it->first << " => " << it->second << '\n';
}	
