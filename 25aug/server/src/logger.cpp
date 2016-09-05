#include "masterheaders.h" 
#include "strtk.hpp"

void printlog(string datestring,int seconds,string severity,string tag, string message)
{
	string home = getenv("HOME");
	string path = home+"/"+getenv("ConfPath");
	fstream ifile(path);
	string temp;
	while ( getline(ifile,temp) )
	{
		vector<string> path;
		strtk::parse(temp,"=",path);
		if ( path[0] == "logFilePath" )
		{
			string logFilePath = home+"/"+path[1];
			FILE  *fp = fopen(logFilePath.c_str(),"a");
			fprintf(fp,"%s:%d %s:	%s:%s \n",datestring.c_str(),seconds,severity.c_str(),tag.c_str(),message.c_str());
			fclose(fp);
			break;
		}
	}
}

void logger(string severity,string tag, string message)
{
	timeval rawtime; // To extract micro seconds
	time_t timer;
	gettimeofday(&rawtime, NULL);
	int microseconds = rawtime.tv_usec;
	struct tm * timeinfo;
	char buffer[80];
	int verbosity = 6; // By default // Get the data from the admin before starting the server

	time(&timer);
	timeinfo = localtime(&timer);
	strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
	std::string str(buffer);

	// Check for the verbosity

	if ( verbosity >= 5 && severity == "DEBUG" )
	{
		// Print debug logs
		printlog(str,microseconds,severity,tag,message);
	}
	if ( verbosity > 1 && severity != "DEBUG" )
	{
		// Print info logs and error logs. 
		printlog(str,microseconds,severity,tag,message);
	}	
}

