#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc, char const *argv[])
{	
	//printf("%s\n","hendn" );
	DIR *dir;
	struct dirent **file;
	char cwd[1000];
	getcwd(cwd,sizeof cwd);
	dir=opendir(cwd);
	if(dir!=NULL){
		//printf("%s\n","hiii" );
		int size=scandir(cwd,&file,0,alphasort);
		int i=0;
		while(i<size){
			char *line=file[i]->d_name;
			char a=line[0];
			char b=line[1];
			if(a!='.' & b!='.'){//ignores file starting with . and ..
				printf("%s  ",line );
				free(file[i]);
			}
			i++;
		}
		printf("%s\n","" );
		free(file);
	}
	else{
		//printf("%s\n","ooops" );
		if(errno==ENOENT){
			printf("%s\n","The directory specified in path does not exist." );
		}
		else if(errno==EACCES){
			printf("%s\n","Search permission is denied for one of the components of path." );
		}
		else{
			printf("%s\n","ERR" );
		}
	}
	return 0;
}