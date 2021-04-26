#include "cities.hh"
#include "cities.cc"


int main(int argc, char *argv[]){
	if (argc!=1){
		std::cout << "Please pass only one argument" << std::endl;
		return -1;
	}
	Cities route(const argv[0]); // Reads in file
	
	Cities::permutation_t ordered(route.size); //empty vector of same size as trip 

	std::iota(ordered.begin(), ordered.end(), 1); // makes vector (0 to size)

	double best_dist = route.total_path_distance(ordered); // Curent trip

	for(int j=0; j<100; j++){
	//permute
		std::random_shuffle(ordered.begin(), ordered.end());
		if (route.total_path_distance(ordered) < best_dist){
			best_dist = route.total_path_distance(ordered);
			route.reorder(ordered);
			std::cout << "Better distance: " << best_dist << std::endl;
			std::cout << "Prremutation: " << j << std::endl;
		}
	}

	//Write output here
		

	return 1;
}

