#include <stdio.h>
#include <string.h>
#include "homework1_6.c"
	int main (int argc, char *argv[]){
	#define ARRSIZE 300000
	int rosterGrade[ARRSIZE];
	int rosterRole [ARRSIZE];
	int id;
	int role;
	int grade;
	printf("Enter id number: ");
	scanf("%d", &id);
	
	printf("\nEnter role number: ");
	scanf("%d", &role);
	rosterRole[id]=role;
	while (role!=1 && role!=2 && role!=3 && role!=4 /*&& role!="student" && role!="instructor" && role!="teaching assistant" && role!="observer"*/){
		printf("\nInvalid role number. Enter role: ");
		scanf("%d", &role);
	}
	
	printf("\nEnter grade: ");
	scanf("%d", &grade);
	rosterGrade[id]=grade;
	
	/*rosterEntry(id,role,grade,rosterGrade,rosterGrade);*/
	
	printf("\nRoster entry: ");
	printf("\nId: %d", id);
	printf("\nRole: %d", rosterRole[id]);
	printf("\nGrade: %d", rosterGrade[id]);
	return 0;
	}