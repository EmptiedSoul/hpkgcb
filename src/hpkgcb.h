#ifndef LIBHPKGCB_H
#define LIBHPKGCB_H

#define HARDMAN "/usr/bin/hardman"
#define HPKG "/usr/bin/hpkg"

#define UPDATE_ROADMAP "update-roadmap"
#define INSTALL "install"
#define REMOVE "remove"
#define UPDATE "update"

#define DATABASE "/var/hpkg/packages/"
#define REPO "/var/hardman/repo/"

#ifdef __cplusplus
extern "C"{
#endif

extern bool isPackageInstalled(char* package, char* database);
extern void getPackageInfo(char* package, char* field, char* database, char* result);
extern void getPackagesFromRepo(int offset, char* repo, char* package);
extern int updateRoadmap();

#ifdef __cplusplus
}
#endif

/*extern int removePackage(char* package);
extern int installPackage(char* package);
extern int installPackageFromRepo(char* package);
*/
#endif
