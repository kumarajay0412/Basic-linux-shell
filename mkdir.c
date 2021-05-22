#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{	
	//printf("%s\n","hiii" );
	if(strcmp(argv[1],"-v")==0){//to display messages
		struct stat st={0};
		if(stat(argv[2],&st)==-1){//checks if such dirtectory does not exists
			mkdir(argv[2],0700);
			printf("mkdir: created directory '%s'\n",argv[2] );
		}
		else{
			printf("mkdir: cannot create directory ‘%s’: File exists\n",argv[2]);
		}
	}
	else if(strcmp(argv[1],"-p")==0){
		printf("%s\n","hellooo" );
		char path[1000];
		snprintf(path,sizeof path,"%s",argv[2]);
		size_t length=strlen(path);
		char *f;
		/*if(path[length-1] == '/'){
			path[length-1] = 0;
		}*/
		for(f=path+1;*f;f++){
			if(*f=='/'){
				*f='\0';
				mkdir(path,S_IRWXU);
				*f='/';
			}
		}
		mkdir(path,S_IRWXU);
		printf("mkdir: created directory '%s'\n",argv[2] );
	}
	else{
		struct stat st={0};
		if(stat(argv[1],&st)==-1){//checks if such dirtectory does not exists
			mkdir(argv[1],0700);
		}
		else{
			printf("mkdir: cannot create directory ‘%s’: File exists\n",argv[1]);
		}
	}
	return 0;
}