#include "cities.hh"
#include <math.h>
#include <fstream>
#include <iostream>


Cities::Cities(char file_name){
	int size = 0;
	std::ifstream coord_file(file_name);
	while(coord_file >> x >> y){
		size++;
		city_coords.push_back(coord_t<x, y>);
	}
}

Cities Cities::reorder(const permutation_t& ordering) const {
	// I saw faster methods on stackoverflow, I will  stick with what works
	ordering;
	return this;
}

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean 
  // distance on a plane between their coordinates.

double euclid_dist(coord_t city_one, coord_t city_two){
	int x_dist = city_one[0]-city_two[0];
	int y_dist = city_one[1]-city_two[1];

	return sqrt(pow(x_dist, 2)+pow(y_dist, 2));
}

double Cities::total_path_distance(const permutation_t& ordering) const{
	double traveled=0;
	for(int i=0; i<size; i++){
	traveled+=euclid_dist([ordering][i], [ordering][i+1]);
	}
	return traveled;
}

int main(int argc, char* argv[]){
	if (argc!=1){
		std::cout << "Please pass only one argument" << std::endl;
		return -1;
	}
	Cities route = Cities(&argv[0]);
	

	permutation_t ordered(route.size); //empty vector of same size as trip 

	std::iota (std::begin(ordered), std::end(ordered), 0); // makes vector (0 to size)

	double best_dist = route.total_path_distance(ordered); // Curent trip

	for(int j=0; j<100; j++){
	//permute
		std::random_shuffle(ordered.begin(), ordered.end());
		if (route.total_path_distance(ordered)<best_dist){
			best_dist = route.total_path_distance(ordered);
			route.reorder(ordered);
			std::cout << "Better distance: " << best_dist << std::endl;
			std::cout << "Prremutation: " << j << std::endl;
		}
	}

	//Write output here
		

	return 1;
}

