#include <iostream>
#include <typeinfo>

const int* highest(int val, const int* start, const int* finish){



if (start==finish){
	return nullptr;
}

if (val==*(finish-1)){
	return finish;
}

if (val==*start){
	return start;
}


if (val<*start || val>*finish){
	return nullptr;
}

const int *mid_pointer = (finish-start)/2+start; //the pointer in the middle


if (val >*mid_pointer){ //The value is greater that the mid point
	return highest(val, mid_pointer, finish); // set start to the mid point

}

else if (val<*mid_pointer){ // value less than the mid_pointer
	return highest(val, start, mid_pointer);
}


return nullptr;
}


