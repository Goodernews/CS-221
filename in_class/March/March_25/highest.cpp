#include <iostream>
#include <typeinfo>

const int* highest(int val, const int* start, const int* finish){

if (val==*finish){
	return finish;
}

if (val<*start || val>*finish){
	return nullptr;
}

if (start==finish){
	return nullptr;
}

int half_elements = static_cast<int>((finish-start)/2); //the pointer in the middle

auto mid_pointer = start + half_elements;

std::cout << mid_pointer << std::endl;
std::cout << typeid(mid_pointer).name() << std::endl;	

/*
if (val >*mid_pointer){ //The value is greater that the mid point
	return highest(val, mid_pointer, finish); // set start to the mid point

}

else if (val<*mid_pointer){ // value less than the mid_pointer
	return highest(val, start, mid_pointer);
}
*/

return nullptr;
}


