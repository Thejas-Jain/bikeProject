#include "masterheaders.h"
#include "two_gear_db.h"
#include "tw_gear.h"
extern pthread_t inotify_thread;
void* inotify(void * f1)
{
	int length, i = 0;
	int fd;
	int wd;
	char buffer[BUF_LEN];

	fd = inotify_init();
	if ( fd < 0 ) {
		perror( "inotify_init" );
		printf( "ERROR" );
	}

	logger("INFO","SERVER","Adding a watch for file");	
	string path=getenv("HOME");
	string respath=path+"/PRO2016/resource/";

	wd = inotify_add_watch( fd, respath.c_str() ,IN_MODIFY ); // Blocking call

	while ( 1 )
	{
		i=0;

		length = read( fd, buffer, 1024 );

		if ( length < 0 ) {
			printf("READ ERROR");
			perror( "read" );
		}

		while ( i < length )
		{
			struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];

			string str1=string(event->name);

			if ( event->mask & IN_MODIFY ) // Check the file name as validation   
			{
				logger("INFO","SERVER","Database is modified "+str1);
				two_gear_db *updateptr;
				updateptr = two_gear_db::instance();
				updateptr->update_two_gear_db();
				logger("INFO","SERVER","Database is Updated "+str1);
				tw_gear *temp = new tw_gear(updateptr->get_data("Pulsar"));
				temp->show_details();
				//temp=NULL;
				//delete temp;
			}


			i += EVENT_SIZE + event->len;

		}

		sleep(5);
	}

	( void ) inotify_rm_watch( fd, wd );
	( void ) close( fd );
	return NULL;
}

void init_inotify()
{
	logger("INFO","SERVER","Staring the thread for inotify");	
//	pthread_t inotify_thread;
	pthread_create(&inotify_thread , NULL , inotify , &inotify_thread);
//	pthread_join(inotify_thread,NULL);
}
