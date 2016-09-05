#include<stdio.h>

int main()
{
FILE *fd;

fd = fopen("/home/osboxes/bikeproject/july30/6thaug/server/resources/database.txt","a");
fprintf(fd,"%d",10);
fclose(fd);

}

