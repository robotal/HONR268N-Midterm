#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Takes a range of values and returns a double between them
 */
double randomDouble(int floor, int ceiling){
	double r = (double) rand() / (double) RAND_MAX; //get a number from 0 to 1 --> rand() returns a value from 0 to RAND_MAX as defined by the compiler

	//if r = 0 then return floor
	//if r = 1 then return floor + ceiling - floor = ceiling
	//will return a double between floor and ceiling otherwise
	return floor + r * (ceiling - floor); 

}

void simulateCollision(int n, int maxAngle, int maxVelocity){


	//Define v1 and ang1 and v2 and ang2 as velocity and angle of two particles
	double v1, v2;
	double ang1, ang2;

	
	//set angles and velocities to random values between a given range using randomDouble (min, max).

	for(int i = 0; i < n; i++){
		
		//set random values for parctile 1
		ang1 = randomDouble(0, maxAngle);
		v1 = randomDouble(0, maxVelocity);
		
		// same for particle 2
		ang2 = randomDouble(0, maxAngle);
		v2 = randomDouble(0, maxVelocity);

		cout << "Collision number : " << i + 1 << endl << endl;

		//print i, angles and velocities of partciles before collison
		cout << "Before collision values:\n";
		cout << "v1: " << v1 << " m/s\n";
		cout << "ang1: " << ang1 << " degrees\n";
		cout << "v2: " << v2 << " m/s\n";
		cout << "ang2: " << ang2 << " degrees\n\n";
		
		//Collide the particles
		// two colliding particles swap angle and velocity
		double tempV = v1;
		double tempA = ang1;
		v1 = v2;
		ang1 = ang2;
		v2 = tempV;
		ang2 = tempA;
		

		//print i, angles and velocities of partciles after collison
		cout << "After collision values:\n";
		cout << "v1: " << v1 << " m/s\n";
		cout << "ang1: " << ang1 << " degrees\n";   	
		cout << "v2: " << v2 << " m/s\n";           
		cout << "ang2: " << ang2 << " degrees\n\n";
	}
}
//Call the simulateCollision function in the Main method for values of n=20, maxAngle=360 and maxVelocity=1000.

int main(){

	srand ( time (0)); //seed random number generator based on time

	//simulate 20 collisions with angles up to 360 degrees and velocities up to 1000 m/s
	simulateCollision(20,360,1000);


	return 0;
}
