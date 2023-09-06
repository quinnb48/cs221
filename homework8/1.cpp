#include <stdio.h>
#include <math.h>
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
	int car::getXPos(){
		return xPos;
	}
	int car::getYPos(){
		return yPos;
	}
	double car::getFuelMPG(){
		return fuelConsumedMPG;
	}
	int car::getTankCapacity(){
		return fuelTankCapacity;
	}
	double car::getCurrentFuel(){
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
