#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <map>
	#ifndef A1_H
		#define A1_H
		class gasStation{
		public:
			gasStation();
			gasStation(int, int, double);
			
			int getXPos();
			int getYPos();
			double getPricePerGal();
			
			void setXPos(int);
			void setYPos(int);
			void setPricePerGal(double);
		
		private:
			int xPos;
			int yPos;
			double pricePerGal;
		};
		
		class car{
		public:
			car();
			car(int, int, double, int);
			
			int getXPos() const;
			int getYPos() const;
			double getFuelMPG() const;
			int getTankCapacity() const;
			double getCurrentFuel() const;
			
			void setXPos(int);
			void setYPos(int);
			void setCurrentFuel(double);
			
			bool moveTo(int, int, car);
			double distanceTo(int, int, int, int);
			car* allMoveTo(car*, int, int, int);
			car* allMoveToGas(car*, int, gasStation*, int, int, int);
		private:
			int xPos;
			int yPos;
			double fuelConsumedMPG;
			int	fuelTankCapacity;
			double currentFuel;
			
		protected:
			void setFuelMPG(double);
			void setTankCapacity(int);
		};
		class bus: public car{
		public:
			bus();
			bus(int,int,double,int,int,std::vector<int>,double);
			
			int getMaxPassengers() const;
			int getNumPass() const;
			std::vector<int> getStopNums() const;
			double getGasPenPerPass() const;
			
			void setMaxPassengers(int);
			void setNumPass(int);
			void setStopNums(std::vector<int>);
			void setGasPenPerPass(double);
			
			std::vector<int> generateRoute(int);//assumes is already sorted ascending
			bool moveTo(int,int, bus);
		private:
			int maxPassengers;
			int numPass;
			std::vector<int> stopNums;
			double gasPenPerPass;
		};
		class medicalCenter{
		public:
			medicalCenter();
			medicalCenter(std::map<int, std::string>, std::map<int, std::string>);
			
			std::map<int, std::string> getProviders() const;
			std::map<int, std::string> getPatients() const;
			
			void setProviders(std::map<int, std::string>);
			void setPatients(std::map<int, std::string>);
		private:
			std::map<int, std::string> providers;
			std::map<int, std::string> patients;
		};
		class ambulance: public medicalCenter, public car{
		public:
			ambulance();
			ambulance(int,int,double,int,int,int,double);
			
			int getMaxPatients() const;
			int getNumPatients() const;
			int getMaxPassengers() const;
			int getNumPassengers() const;
			double getGasPenPerPass() const;
			
			void setMaxPatients(int);
			void setNumPatients(int);
			void setMaxPassengers(int);
			void setNumPassengers(int);
			void setGasPenPerPass(double);
			
			bool moveTo(int,int, ambulance);
		private:
			int maxPatients;
			int numPatients;
			int maxPassengers;
			int numPassengers;
			double gasPenPerPass;
		};
		
		std::vector<car> allTypeMoveToGas(std::vector<car>, int, gasStation*, int, int, int);
		
	#endif
