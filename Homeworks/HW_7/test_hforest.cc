#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <cassert>

#include "hforest.hh"
#include "htree.hh"

HTree::tree_ptr_t create_test_tree_small(){
// Creates a tree with only a root node
  return make_shared<HTree>(3,5);
}

HTree::tree_ptr_t create_test_tree_medium(){
// Creates a tree with only two children
  return make_shared<HTree>(1,2,
		  make_shared<HTree>(3,4),
		  make_shared<HTree>(5,6));
}

HTree::tree_ptr_t create_test_tree_large()
// Creates a large sample tree
// creates a tree with depth 3 to 4
{
  return make_shared<HTree>(126, 999,
		 make_shared<HTree>(1,5, 
			  make_shared<HTree>(9,8), 
			  make_shared<HTree>(30,2)),
		  make_shared<HTree>(12,40,
			  make_shared<HTree>(9,8,
				  make_shared<HTree>(85, 2)),
			  make_shared<HTree>(13,12)));
}

auto create_test_forest(){ //TYPE NEEDS TO BE CHANGED
  return make_shared<HForest>(create_test_tree_medium()); //not sure of exact syntax
}



void test_size(HForest::forest_ptr_t forest){
  assert(HForest().size()==0); //test on empty forest
  assert(forest.size()==1) 
}

void test_add_tree(){
  auto small_tree = create_test_tree_small(); //creates a tree with only one node
  forest.add_tree(small_tree); //adds tree pointer to the forest
  assert(forest.size()==2); //check size of changed forest
}


void test_pop(){
 auto large_tree = create_test_tree_large(); //tree with a known large root
 forest.add_tree(large_tree);
 assert(forest.pop_tree()==large_tree);
}



int main(){
    	park = create_test_forest();
	test_size(park);
	test_add_tree(park);
	test_pop(park);
	return 0;
}
