#include "bikeHandler.h"
extern map<int,string> threadsAvailable;
extern pthread_mutex_t mutex_threadsAvailable;
void handleBike(){
	pthread_t bike; // thread ID
	pthread_attr_t attr; //	thread attribute

	// set thread detach state attribute to DETACHED 
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_mutex_lock( &mutex_threadsAvailable );
	for (std::map<int,string>::iterator it=threadsAvailable.begin(); it!=threadsAvailable.end(); ++it){
		if(it->second == "unlocked"){
			it->second = "locked";
			pthread_create(&bike, &attr, create_bikeThread,(void*)(intptr_t)(it->first));
			break;
		}
	}
	pthread_mutex_unlock( &mutex_threadsAvailable );
}
void *create_bikeThread(void* threadNo)
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
	tw_gear *temp = new tw_gear((two_gear_db::instance())->get_data(tp));
	//	cout << tp<< endl;
	temp->show_details();
	cout << "child doing\n" << endl;
	logger("INFO","SERVER","Pulsar details sent over socket");
	// delete temp in destructor of tw_gear class 
	delete temp;

	pthread_mutex_lock( &mutex_threadsAvailable );
	for (std::map<int,string>::iterator it=threadsAvailable.begin(); it!=threadsAvailable.end(); ++it){
		if(it->first ==(intptr_t)threadNo){
			it->second = "unlocked";
		}
	}
	pthread_mutex_unlock( &mutex_threadsAvailable );
}
