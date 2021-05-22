#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{	
	if(strcmp(argv[1],"-n")==0){//to print the line number
		struct stat st={0};
		if(stat(argv[2],&st)==-1){//checks if such dirtectory does not exist
			printf("%s\n","File does not exist" );

		}
		else{
		FILE *f = fopen(argv[2],"r");
		char line[1000];
		int count=1;
		while(fgets(line,sizeof line,f)!=NULL){
			fprintf(stdout, "%d  %s",count,line);
			count++;
		}
		perror(argv[2]);
		fclose(f);
		}
	}
	else if(strcmp(argv[1],"-E")==0){//to print $ at the begining of each line
		struct stat st={0};
		if(stat(argv[2],&st)==-1){//checks if such dirtectory does not exist
			printf("%s\n","File does not exist" );

		}
		else{
		FILE *f = fopen(argv[2],"r");
		char line[1000];
		while(fgets(line,sizeof line,f)!=NULL){
			fprintf(stdout, "$%s",line);
		}
		perror(argv[2]);
		fclose(f);
		}
	}
	else{//default
		struct stat st={0};
		if(stat(argv[1],&st)==-1){//checks if such dirtectory does not exist
			printf("%s\n","File does not exist" );

		}
		else{
		FILE *f = fopen(argv[1],"r");
		char line[1000];
		while(fgets(line,sizeof line,f)!=NULL){
			fprintf(stdout, "%s",line);
		}
		perror(argv[1]);
		fclose(f);
		}
	}
	return 0;
}
/*DIR *dir;
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
				printf("%s  ",line );//print all files including . and ..
				free(file[i]);
				i++;
			}
			free(file);
		}
		else{
			printf("%s\n","ooops" );
			}*/