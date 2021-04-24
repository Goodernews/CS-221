#include <"cities.hh">




Cities::Cities(char file_name){
	int size = 0;

}

Cities Cities::reorder(const permutation_t& ordering) const {


}

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean 
  // distance on a plane between their coordinates.

double euclid_dist(){
	return;
}

double Cities::total_path_distance(const permutation_t& ordering) const{
	double traveled=0;
	for(int i=0; i<size; i++){
	traveled+=euclid_dist([i], [i+1]);
	}
	return traveled;
}

int main(int argc, char* argv[]){
	if (argc!=1){
		std::cout << "Please pass only one argument" << std::endl;
		return -1;
	}
	Cities route = Cities(argv[0]);
	double best_dist = route.total_path_distance();
	int best_iter = 0;
	for(int j=0; j<100; j++){
	//permute
	if ()
	}

	return 1;
}

