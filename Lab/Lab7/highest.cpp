#include <iostream>
#include <typeinfo>

const int* highest(int val, const int* start, const int* finish){

	if (start==finish || finish<start ||finish==start++){
		return nullptr;
	}
	
	//std::cout << finish << std::endl;
	//std::cout << start << std::endl;

	auto mid_pointer = (finish-start)/2+start; //the pointer in the middle


	if (*start == val){
		return start;
	}
	//std::cout << mid_pointer << std::endl;

	if (mid_pointer == nullptr){
		return nullptr;
	}

	if (val == *mid_pointer){
		return mid_pointer;
	}

	if (val >*mid_pointer){ //The value is greater that the mid point
		return highest(val, mid_pointer, finish); // set start to the mid point
	}

	else if (val<*mid_pointer){ // value less than the mid_pointer
		return highest(val, start, mid_pointer);
	}
	return nullptr;
}


