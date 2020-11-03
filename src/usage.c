#include "cstd.h"
#include "hpkgcb.h"

int main(int argc, char **argv){
	
	char package[1024];
	char database[1024] = "/var/hpkg/packages/";
	char query[1024];
	int c;
  opterr = 0;


  while ((c = getopt (argc, argv, "abp:q:")) != -1)
    switch (c)
      {
      case 'a':
        
        break;
      case 'b':
       
        break;
      case 'p':
        strcpy(package, optarg);
        break;
      case 'q':
      	strcpy(query, optarg);
      	break;
      case '?':
        if (optopt == 'p')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if(optopt == 'q')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

      printf("Package: %s Query: %s \n", package, query);
	//printf("Package: ");
	//fgets(package, 1024, stdin);
	
	//strtok(package, "\n");
	//printf("Database: %s\n", database);
	
	if(!isPackageInstalled(package, database)){
	
	//	printf("%s is not installed\n", package);
		exit(1);
	
	}
	
	//printf("%s is installed\n\n", package);
	
	char info[1024] = "";
	char repo[1024] = "/var/hardman/repo/";

	//printf("Package: %s\n", package);
	//printf("Database: %s\n", database);

	//fgets(query, 1024, stdin);

	getPackageInfo(package, query, database, info);
	printf("Info: %s Error: %i %s\n\n", info, errno, strerror(errno));
	for (int i = 1; i < 10; i++)
	{
		getPackagesFromRepo(i, repo, package);
		if(package[0] == *"\0") break;
		printf("%i package: %s\n", i, package);
	}
	printf("\nUpdating ROADMAP...\n");
	printf("ROADMAP updated with code: %i", updateRoadmap());
	


}
