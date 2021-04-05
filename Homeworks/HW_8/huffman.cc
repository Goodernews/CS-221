#include <stdio.h>
#include <iostream>

#include "hforest.hh"
#include "htree.hh"


Huffman::Huffman(){ //because this will start out the same every time, it can be made in advance
	HTree::key_t holder_key = -1; //key value for in between nodes, non leaf nodes

	auto forest = HForest(); //create forest
	
	for(i=0; i=<ALPHABET_SIZE+1; i++){
	forest->add_tree(std::make_shared<HTree>(i, 0, nullptr, nullptr));
	} //makes a blank huffman forest

	auto encoder_ = build_tree(forest); //turns forest into an encoding tree

}



HForest::forest_ptr_t break_tree(HTree::tree_ptr_t){
       	// splits tree into forest
	HForest::forest_ptr_t forest = HForest();
	while(HForest->size()<ALPHABET_SIZE){
		//find a leaf node
		//add to forest
		//remove pointer from parent
	}
	return forest;
}


HTree::tree_ptr_t build_tree(HForest::forest_ptr_t forest){
       	//makes forest into huffman tree
	while(forest->size>1){ //Pop two trees
		auto smallest_tree = forest->pop_tree();
		auto small_tree = forest->pop_tree(); //gets smallest trees
		HTree::value_t num_nodes = smallest_tree->get_value() + small_tree->get_value(); //Num children
		auto merged_tree = make_shared<HTree>(holder_key, //to signify it is not a leaf node
				num_nodes, //root value temporarily holds number of leaves in tree
				small_tree, //adds nodes to merging node
				smallest_tree);
		forest->add_tree(merged_tree); //adds merged tree back to the forest
	}

	return forest->pop_tree();//clear forest add base tree to encoder_
}




bits_t Huffman::encode(int symbol){
	auto update_path = encoder_->path_to(symbol); //find pointer to node with a key
	auto node_pointer = ...; //pointer to value of node
		
	//add one to value of target node frequency

	auto broken_tree_ = break_tree(forest); //break apart tree into forest

	//add current value to parent nodes
	//
}



int Huffman::decode(bool bits){
	auto node = encoder_;
	/*for(i, i<bits_len;i++){
	// iterate through the boolean
	  }
	  */
	return node->get_key();

}


