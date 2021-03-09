#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;


constexpr double gridpi(double npoints){
	if(npoints==1){
	return 1;
	/* If it is a one by one return one
	 *This is to prevent a division by zero.
	 * .*/
	}

	int points = npoints+1; 
	/*Assuming that y max is 1 and y=0 npoints,
	 * thus no need to caluslate the first or last row*/
	
	double y=1; 
	/*The number used in for loops */

	double jump_dist=1/(npoints-1);
	/*Used for calculate the number of points in a given row*/
	
	/*double x;
	Used to calulate the intra x-distance*/

	for (y=1; y<npoints; y++){
		double x = sqrt(1-pow(y*jump_dist, 2));
		/* This takes a given y value and gives the x value
		 * */
		points+=floor(x/jump_dist)+1;
		/*The points are appended on
		 * The floor function is used for rounding error
		 * The x/jump dist represents the number of gridpoints unrounded
		 * The +1 is used to account for the zeroth digit.
		 * This is used instead of ciel for syntactical purposes.
		 * Namely, a zeroth case. Ciel(0)=0 while floor(0)+1=1*/
	}
	return points;

}


int main(){
	int points;
	cout << "Num points in row: ";
	cin >> points;
	/*Self explanatory, gets the dimensions from user*/

	clock_t time_start = clock();
	/*Starts timing the function*/

	double points_in_circ =  gridpi(points);
	/*Calls the gridpi function and returns to the var points_in_circ*/
	
	double elapsed_time = clock()-time_start;
	elapsed_time = elapsed_time/double(CLOCKS_PER_SEC);
	cout << "Function runtime: " << elapsed_time *1000 << "ms"<< endl;
	/*Declares a new variable that gets the current time, subtracts it from the
	 * previous time to calculate time elapsed to a double.*/


	double total_points = pow(points, 2);
	cout << "Total points: " << total_points << endl;
	/*The decleration is used to give the numerator for the pi approximation*/

	
	cout << "Points in circle: " << points_in_circ <<endl;
	/* Outputs the points within the grid and total points for 
	 * Debugging purposes*/


	double aprox_pi = 4*points_in_circ/total_points;
	cout << "Approximation of Pi: " << aprox_pi <<endl;
	/*Because we calculated only one quadrant of the circle, the answer is multiplied by 4
	 * `points_in_circ`/`total_points` gives the percent of grid */
}
