#include <stdio.h>
#include "homework1_6.h"
	int rosterEntry (int id, int role, int grade, int rosterGrade[], int rosterRole[]){
		rosterGrade[id] = grade;
		rosterRole[id] = role;
		
	return 0;
	}
	
	/*int rosterEntry2 (int id, int role, char grade, int rosterGrade[], int rosterRole[]){
		rosterGrade[id] = grade;
		if (role == 1) {
			rosterRole[id] = "student";
		}
		else if (role == 2) {
			rosterRole[id] = "instructor";
		}
		else if(role == 3) {
			rosterRole[id] = "teaching assistant";
		}
		else if (role == 4) {
			rosterRole[id] = "observer";
		}
		else{
			rosterRole[id] = role;
		}
		
	return 0;
	}
	
	int rosterEntry3 (int id, char role, int grade, int rosterGrade[], int rosterRole[]){
		rosterGrade[id] = grade;
		if (role == "student") {
			rosterRole[id] = 1;
		}
		else if (role == "instructor") {
			rosterRole[id] = 2;
		}
		else if(role == "teaching assistant") {
			rosterRole[id] = 3;
		}
		else if (role == "observer") {
			rosterRole[id] = 4;
		}
		else{
			rosterRole[id] = role;
		}
		
	return 0;
	}
	
	int rosterEntry4 (int id, char role, char grade, int rosterGrade[], int rosterRole[]){
		rosterGrade[id] = grade;
		if (role == "student") {
			rosterRole[id] = 1;
		}
		else if (role == "instructor") {
			rosterRole[id] = 2;
		}
		else if(role == "teaching assistant") {
			rosterRole[id] = 3;
		}
		else if (role == "observer") {
			rosterRole[id] = 4;
		}
		else{
			rosterRole[id] = role;
		}
		
	return 0;
	}*/