#include <stdio.h>
#include <time.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	time_t rawtime;
	struct tm * timeinfo;
  	time ( &rawtime );
  	timeinfo = localtime ( &rawtime );
  	//printf ( "%s", asctime (timeinfo) );
  	char buf[270]={0};
  	memset(buf,0,270);
  	strftime(buf,270,"%a, %d %b %Y %T +0530 ",timeinfo);
  	puts(buf);
  	return 0;
	 }