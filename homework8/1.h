#include <stdio.h>
#include <math.h>
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
			
			int getXPos();
			int getYPos();
			double getFuelMPG();
			int getTankCapacity();
			double getCurrentFuel();
			
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
		
		
	#endif
