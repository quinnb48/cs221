#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "1.h"
       
	int main () {
        car car1;
        car car2(2, 2, 15, 20);
        gasStation station1;
		return 0;
    }
    
    //default
    car::car(){
    	setXPos(0);
    	setYPos(0);
    	setFuelMPG(1);
    	setTankCapacity(0);
    	setCurrentFuel(0);
    }
    //creator
    car::car(int x, int y, double mpg, int capacity){
    	setXPos(x);
    	setYPos(y);
    	setFuelMPG(mpg);
    	setTankCapacity(capacity);
    	setCurrentFuel(capacity);
    }

	//getters
	int car::getXPos() const{
		return xPos;
	}
	int car::getYPos() const{
		return yPos;
	}
	double car::getFuelMPG() const{
		return fuelConsumedMPG;
	}
	int car::getTankCapacity() const{
		return fuelTankCapacity;
	}
	double car::getCurrentFuel() const{
		return currentFuel;
	}
	
	//setters
	void car::setXPos(int x){
		xPos = x;
	}
	void car::setYPos(int y){
		yPos = y;
	}
	void car::setFuelMPG(double mpg){
		fuelConsumedMPG = mpg;
	}
	void car::setTankCapacity(int capacity){
		fuelTankCapacity = capacity;
	}
	void car::setCurrentFuel(double fuel){
		currentFuel = fuel;
	}
	
	//other functions
	bool car::moveTo(int x, int y, car c){
		double travel = c.distanceTo(x, y, c.getXPos(), c.getYPos()) * c.getFuelMPG();
		if(travel > c.getCurrentFuel()){
			return false;
		}
		else{
			c.setXPos(x);
			c.setYPos(y);
			c.setCurrentFuel(c.getCurrentFuel() - travel);
			return true;
		}
	}
	
	double car::distanceTo(int x, int y, int fromX, int fromY){
		double xDistance = 0;
		double yDistance = 0;
		if(x >= fromX){
			xDistance = x - fromX;
		}
		else{
			xDistance = fromX - x;
		}
		if(y >= fromY){
			yDistance = y - fromY;
		}
		else{
			yDistance = fromY - y;
		}
		xDistance = xDistance * xDistance;
		yDistance = yDistance * yDistance;
		double travel = xDistance + yDistance;
		travel = sqrt(travel);
		return travel;
	}
	
	car* car::allMoveTo(car* cars, int lengthOfCars, int xGoTo, int yGoTo){
		car* returny = NULL;
		int length = 0;
		for(int i = 0; i < lengthOfCars; i++){
			if(cars[i].moveTo(xGoTo, yGoTo, cars[i])){
				returny[i] = cars[i];
				length += 1;
			}
		}
		return returny;
	}
	
	car* car::allMoveToGas(car* cars, int lengthOfCars, gasStation* stations, int lengthOfStations, int xGoTo, int yGoTo){
		car* returny = NULL; 
		int length = 0;		
		double* returnyCosts = NULL;
		for(int i = 0; i < lengthOfCars; i++){ 
			if(cars[i].moveTo(xGoTo, yGoTo, cars[i])){//check if can move directly there
				returny[length] = cars[i];
				returnyCosts[length] = 0;
				length += 1;
			}
			else{//check if detouring to gas station will help
				for(int k = 0; k < lengthOfStations; k++){
					int ogX = cars[i].xPos;
					int ogY = cars[i].yPos;
					double ogGas = cars[i].getCurrentFuel();
					if(cars[i].moveTo(stations[k].getXPos(), stations[k].getYPos(), cars[i])){
						//fill up the gas
						double cost = (cars[i].getTankCapacity() - cars[i].getCurrentFuel()) * stations[k].getPricePerGal();
						cars[i].setCurrentFuel(cars[i].getTankCapacity());
						if(cars[i].moveTo(xGoTo, yGoTo, cars[i])){ //check if they can now move
							returny[length]= cars[i];
							length+=0;
							returnyCosts[length] = cost;
						}
						else{	//reset back to og position & gas if they can't make it to destination
							cars[i].setXPos(ogX);
							cars[i].setYPos(ogY);
							cars[i].setCurrentFuel(ogGas);
						}
					}
				}
			}
		}
		return returny;
	}
	
	//gas station stuff
	
	//default
    gasStation::gasStation(){
    	setXPos(0);
    	setYPos(0);
    	setPricePerGal(1);
    }
    //creator
    gasStation::gasStation(int x, int y, double price){
    	setXPos(x);
    	setYPos(y);
    	setPricePerGal(price);
    }

	//getters
	int gasStation::getXPos(){
		return xPos;
	}
	int gasStation::getYPos(){
		return yPos;
	}
	double gasStation::getPricePerGal(){
		return pricePerGal;
	}
	
	//setters
	void gasStation::setXPos(int x){
		xPos = x;
	}
	void gasStation::setYPos(int y){
		yPos = y;
	}
	void gasStation::setPricePerGal(double price){
		pricePerGal = price;
	}
	
	//bus stuff
	
	//default
	bus::bus(){
		car();
		setMaxPassengers(0);
		setNumPass(0);
		std::vector<int> empty;
		setStopNums(empty);
		setGasPenPerPass(0);
	}
	//creator
	bus::bus(int x, int y, double mpg, int capacity, int maxPass, std::vector<int> stops, double gasPen){
		car(x,y,mpg,capacity);
		setMaxPassengers(maxPass);
		setNumPass(0);
		setStopNums(stops);
		setGasPenPerPass(gasPen);
	}
	//getters
	int bus::getMaxPassengers() const{
		return maxPassengers;
	}
	int bus::getNumPass() const{
		return numPass;
	}
	std::vector<int> bus::getStopNums() const{
		return stopNums;
	}
	double bus::getGasPenPerPass() const{
		return gasPenPerPass;
	}
	//setters
	void bus::setMaxPassengers(int max){
		maxPassengers = max;
	}
	void bus::setNumPass(int num){
		numPass = num;
	}
	void bus::setStopNums(std::vector<int> stops){
		stopNums = stops;
	}
	void bus::setGasPenPerPass(double penalty){
		gasPenPerPass = penalty;
	}
	//others
	std::vector<int> bus::generateRoute(int startingStop){
		std::vector<int> returny;
		std::vector<int>::iterator it = stopNums.begin();
		while(returny.size() != stopNums.size()){
			if(*it != startingStop){
				if(*it != stopNums.back()){
					it = std::next(it);
				}
				else{
					it=stopNums.begin();
				}
			}
			else{
				if(*it != returny.back()){
					returny.push_back(*it);
				}
				if(*it != stopNums.back()){
					it = std::next(it);
				}
				else{
					it=stopNums.begin();
				}
			}
		}
		return returny;
	}
	
	bool bus::moveTo(int x, int y, bus b){
		double travel = b.distanceTo(x, y, b.getXPos(), b.getYPos()) * (b.getFuelMPG() + (b.getNumPass() * b.getGasPenPerPass()));
		if(travel > b.getCurrentFuel()){
			return false;
		}
		else{
			b.setXPos(x);
			b.setYPos(y);
			b.setCurrentFuel(b.getCurrentFuel() - travel);
			return true;
		}
	}
	
	//medical center stuff
	//default
	medicalCenter::medicalCenter(){
		std::map<int, std::string> empty;
		setProviders(empty);
		setPatients(empty);
	}
	//creator
	medicalCenter::medicalCenter(std::map<int, std::string>prov ,std::map<int, std::string> pat){
		setProviders(prov);
		setPatients(pat);
	}
	//getters
	std::map<int, std::string> medicalCenter::getProviders() const{
		return providers;
	}
	std::map<int, std::string> medicalCenter::getPatients() const{
		return patients;
	}
	//setters		
	void medicalCenter::setProviders(std::map<int, std::string> prov){
		providers = prov;
	}
	void medicalCenter::setPatients(std::map<int, std::string> pat){
		patients = pat;
	}
	
	//ambulance stuff
	//default
	ambulance::ambulance(){
		car();
		setMaxPatients(0);
		setNumPatients(0);
		setMaxPassengers(0);
		setNumPassengers(0);
		setGasPenPerPass(0);
	}
	//creator
	ambulance::ambulance(int x,int y,double mpg,int gasCap,int patientCap,int passCap,double gasPen){
		car(x,y,mpg,gasCap);
		setMaxPatients(patientCap);
		setNumPatients(0);
		setMaxPassengers(passCap);
		setNumPassengers(0);
		setGasPenPerPass(gasPen);
	}
	//getters		
	int ambulance::getMaxPatients() const{
		return maxPatients;
	}
	int ambulance::getNumPatients() const{
		return numPatients;
	}
	int ambulance::getMaxPassengers() const{
		return maxPassengers;
	}
	int ambulance::getNumPassengers() const{
		return numPassengers;
	}
	double ambulance::getGasPenPerPass() const{
		return gasPenPerPass;
	}
	//setters		
	void ambulance::setMaxPatients(int max){
		maxPatients = max;
	}
	void ambulance::setNumPatients(int num){
		numPatients = num;
	}
	void ambulance::setMaxPassengers(int max){
		maxPassengers = max;
	}
	void ambulance::setNumPassengers(int num){
		numPassengers = num;
	}
	void ambulance::setGasPenPerPass(double pen){
		gasPenPerPass = pen;
	}
			
	bool ambulance::moveTo(int x,int y, ambulance a){
		double travel = a.distanceTo(x, y, a.getXPos(), a.getYPos()) * (a.getFuelMPG() + (a.getNumPassengers() * a.getGasPenPerPass()));
		if(travel > a.getCurrentFuel()){
			return false;
		}
		else{
			a.setXPos(x);
			a.setYPos(y);
			a.setCurrentFuel(a.getCurrentFuel() - travel);
			return true;
		}
	}
	
	
	
	
	std::vector<car> allTypeMoveToGas(std::vector<car> vehicles, int lengthOfCars, gasStation* stations, int lengthOfStations, int xGoTo, int yGoTo){
		std::vector<car> returny; 
		int length = 0;		
		double* returnyCosts = NULL;
		for(int i = 0; i < lengthOfCars; i++){ 
			if(vehicles[i].moveTo(xGoTo, yGoTo, vehicles[i])){//check if can move directly there
				returny[length] = vehicles[i];
				returnyCosts[length] = 0;
				length += 1;
			}
			else{//check if detouring to gas station will help
				for(int k = 0; k < lengthOfStations; k++){
					int ogX = vehicles[i].getXPos();
					int ogY = vehicles[i].getYPos();
					double ogGas = vehicles[i].getCurrentFuel();
					if(vehicles[i].moveTo(stations[k].getXPos(), stations[k].getYPos(), vehicles[i])){
						//fill up the gas
						double cost = (vehicles[i].getTankCapacity() - vehicles[i].getCurrentFuel()) * stations[k].getPricePerGal();
						vehicles[i].setCurrentFuel(vehicles[i].getTankCapacity());
						if(vehicles[i].moveTo(xGoTo, yGoTo, vehicles[i])){ //check if they can now move
							returny[length]= vehicles[i];
							length+=0;
							returnyCosts[length] = cost;
						}
						else{	//reset back to og position & gas if they can't make it to destination
							vehicles[i].setXPos(ogX);
							vehicles[i].setYPos(ogY);
							vehicles[i].setCurrentFuel(ogGas);
						}
					}
				}
			}
		}
		return returny;
	}
