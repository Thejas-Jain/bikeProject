#ifndef  MasterHeader
#define MasterHeader

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>
#include <ctime>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/inotify.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <cstring>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )
#define FILENAME	  "/home/osboxes/bikeproject/july30/6thaug/server/resources/"

using namespace std;

void printlog(string date,int seconds,string severity,string tag, string message);
void logger(string severity, string tag, string message);
void* inotify(void * f1);
void init_inotify();

void getDataBasePath(void);
void initialize_alldb();		
#endif 
