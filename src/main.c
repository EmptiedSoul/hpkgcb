#include "cstd.h"
#include "hpkgcb.h"

#define MAX_CHAR 1024

bool isPackageInstalled(char* package, char* database)
{
	char package_l[MAX_CHAR] = "";
	char database_l[MAX_CHAR] = "";
	
	strcpy(package_l, package);
	strcpy(database_l, database);

	strcat(package_l,".info");
	strcat(database_l,package_l);

	FILE* packageInfo = fopen(database_l, "r");

	if(packageInfo){
		fclose(packageInfo);
	       	return true;
	}else{

	 	return false;
	}	
}

void getPackageInfo(char* package, char* field, char* database, char* result)
{
	char package_l[MAX_CHAR] = "";
	char database_l[MAX_CHAR] = "";
	char infoString[MAX_CHAR] = "";

	strcpy(package_l, package);
	strcpy(database_l, database);

	strcat(package_l,".info");
	strcat(database_l,package_l);

	FILE* packageInfo = fopen(database_l, "r");

	if(!packageInfo) return;

	while(fgets(infoString, MAX_CHAR, packageInfo) != NULL){
		if(*infoString == *field) break;
	}

	fclose(packageInfo);

	char* rawformatted = strtok(infoString, " ");
	rawformatted = strtok(NULL, " ");
  
    char formatted[MAX_CHAR] = "";
    
    if(rawformatted == NULL) return;

	while(rawformatted != NULL){

		strcpy(formatted, rawformatted);
		strcat(formatted, " ");
		
		if(*result == *""){

			strcpy(result, formatted);
			rawformatted = strtok(NULL, " ");
			continue;

		}

		strcat(result, formatted);
		rawformatted = strtok(NULL, " ");

	}
		result[strlen(result)-2] = *"\0";

	return;
}

void getPackagesFromRepo(int offset, char* repo, char* package){
	
	char repo_l[MAX_CHAR] = "";
	strcpy(repo_l, repo);
	strcat(repo_l, "ROADMAP");
	FILE* ROADMAP = fopen(repo_l, "r");

	if(!ROADMAP) return;

	fseek(ROADMAP, 0, SEEK_END);
	long fsize = ftell(ROADMAP);
	rewind(ROADMAP); 
	char *string = malloc(fsize + 1);
	fread(string, 1, fsize, ROADMAP);
	fclose(ROADMAP);

	string[fsize] = 0;

	char* formatted = strtok(string, "\n");
	char result[MAX_CHAR] = "";
	for(int i = 0; i<offset; i++){
		if (formatted == NULL) {
			result[0] = *"\0";
			package[0] = *"\0";
			break;
		}
		strcpy(result, formatted);
		formatted = strtok(NULL, "\n");
	}
	strcpy(package, result);
	free(string);
}
int updateRoadmap(){
	pid_t PID = fork();
	int status;
	int exitcode = -1;
	if (PID>0){
		waitpid(PID, &status, 0);	
		exitcode = WEXITSTATUS(status);
	}else{
		printf("Calling: %s with arg0 %s and arg1 %s", HARDMAN, HARDMAN, UPDATE_ROADMAP);
		execl(HARDMAN, HARDMAN, UPDATE_ROADMAP, NULL);
	}
	return exitcode;
}












