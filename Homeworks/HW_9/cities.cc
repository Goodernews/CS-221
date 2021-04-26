#include "cities.hh"
#include <math.h>
#include <fstream>
#include <iostream>


Cities::Cities(char file_name){
	int size = 0;
	std::ifstream coord_file(file_name);
	while(coord_file >> x >> y){
		size++;
		coords_.push_back(coord_t(x, y));
	}
}


Cities::Cities(){
	int size = 0;
}


Cities Cities::reorder(const permutation_t& ordering) const {
	// I saw faster methods on stackoverflow, I will  stick with what works
	Cities reordered;
	
	for(int x=0; x<size; x++){
		reordered.size++;
		reordered.coords_.push_back(this->coords_[ordering[x]]);
	}

	return reordered;
}

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean 
  // distance on a plane between their coordinates.

double euclid_dist(Cities::coord_t city_one, Cities::coord_t city_two){
	int x_dist = city_one.first -city_two.first;
	int y_dist = city_one.second-city_two.second;

	return sqrt(pow(x_dist, 2)+pow(y_dist, 2));
}

double Cities::total_path_distance(const permutation_t& ordering) const{
	double traveled=0;
	for(int i=0; i<size; i++){
	traveled+=euclid_dist(coords_[ordering[i]], coords_[ordering[i+1]]);
	}
	traveled += euclid_dist(coords_[ordering[0]], coords_[ordering[size-1]]) //travel from first to last
	return traveled;
}


