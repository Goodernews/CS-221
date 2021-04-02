#include <stdio.h>
#include <iostream>

#include "hforest.hh"
#include "htree.hh"


constexpr Huffman::Huffman(){ //because this will start out the same every time, it can be made in advance
	HTree::key_t holder_key = -1; //key value for in between nodes, non leaf nodes

	auto forest = std::make_shared<HForest>(); //create forest
	/*
	for(i=0; i<ALPHABET_SIZE; i++){
	forest->add_tree(std::make_shared<HTree>(i, 1, nullptr, nullptr));
	}

	*/
	//add nodes to forest
	//RECURSIVE STEP
	//
	while(forest->size>1){ //Pop two trees
		auto smallest_tree = forest->pop_tree();
		auto small_tree = forest->pop_tree(); //gets smallest trees
		HTree::value_t num_nodes = smallest_tree->get_value() + small_tree->get_vale(); //Num children
		auto merged_tree = make_shared<HTree>(holder_key, //to signify it is not a leaf node
				num_nodes, //root value temporarily holds number of leaves in tree
				small_tree, //adds nodes to merging node
				smallest_tree);
		forest->add_tree(merged_tree); //adds merged tree back to the forest
	}

	auto encoder_ = forest->pop_tree();//clear forest add base tree to encoder_
	~forest; //releases memory
	// Sets all node values to zero
}


bits_t Huffman::encode(int symbol){
	auto update_path = encoder_->path_to(symbol); //find pointer to node with a key
	//pointer to value of node
	
	//subtract current freq value from all parent nodes
	
	//add one to value of node frequency
	
	//find node to swap with
	//swap
	
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


