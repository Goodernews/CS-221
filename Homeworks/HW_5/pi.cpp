#include <cmath>
#include <iostream>
using namespace std;


double gridpi(double npoints){
	if(npoints==1){
	return 1;
	/* If it is a one by one return one
	 *This is to prevent a division by zero.
	 * .*/
	}

	int points = npoints+1; 
	/*Assuming that y max is 1 and y=0 npoints,
	 * thus no need to caluslate the first or last row*/
	
	double y; 
	/*The number used in for loops */

	double jump_dist=1/(npoints-1);
	/*Used for calculate the number of points in a given row*/
	
	double x;
	/*Used to calulate the intra x-distance*/

	for (y=1; y<npoints; y++){
		x = sqrt(1-pow(y*jump_dist, 2));
		/* This takes a given y value and gives the x value
		 * */
		points+=floor(x/jump_dist)+1;
		/*The points are appended on
		 * The floor function is used for rounding error
		 * The x/jump dist represents the number of gridpoints unrounded
		 * The +1 is used to account for the zeroth digit.
		 * This is used instead of ciel for syntactical purposes.*/
	}
	return points;

}


int main(){
	int points;
	cout << "Num points in row: ";
	cin >> points;

	double points_in_circ =  gridpi(points);
	
	double total_points = pow(points, 2);

	cout << "Total points: " << total_points << endl;
	
	cout << "Points in circle: " << points_in_circ <<endl;
	double aprox_pi = 4*points_in_circ/total_points;
	cout << "Approximation of Pi: " << aprox_pi;
	cin >> points;
}
