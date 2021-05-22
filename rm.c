#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{	
	//printf("%s\n","hiiii" );
	//char cwd[1000];
	//getcwd(cwd, sizeof(cwd));
	//strcat(cwd, "/");
	//strcat(cwd, argv[1]);
	if(strcmp(argv[1],"-v")==0){//print message for outputs
		struct stat st={0};
		char cwd[1000];
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/");
		strcat(cwd, argv[2]);
		int ret=remove(cwd);
		if(ret==0){
			printf("removed %s\n",argv[2] );
		}
		else{
			printf("rm: cannot remove '%s': Is a directory\n",argv[2] );
		}
	}
	else if(strcmp(argv[1],"-d")==0){
		struct stat st={0};
		if(stat(argv[2],&st)==-1){//checks if such dirtectory does not exist
			printf("%s\n","oops" );

		}
		else{
			int t=rmdir(argv[2]);
			if(t!=0){
				printf("%s\n","File does not exist" );
			}
		}
	}

	else{
		struct stat st={0};
		char cwd[1000];
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/");
		strcat(cwd, argv[1]);
		int ret=remove(cwd);
		if(ret==0){

		}
		else{
			printf("rm: cannot remove '%s': Is a directory\n",argv[1] );
		}
		
	}
	return 0;
}
/*if(stat(argv[1],&st)==-1){//checks if such dirtectory does not exist
			printf("%s\n","oops" );

		}
		else{
			rmdir(argv[1]);
		}
*/