#include <stdio.h>
#include <iostream>

#include "hforest.hh"
#include "htree.hh"


Huffman::Huffman(){ //because this will start out the same every time, it can be made in advance
	HTree::key_t holder_key = -1; //key value for in between nodes, non leaf nodes

	auto forest = HForest(); //create forest
	
	for(i=0; i<257; i++){
	forest->add_tree(std::make_shared<HTree>(i, 0, nullptr, nullptr));
	} //makes a blank huffman forest

	auto encoder_ = build_tree(forest); //turns forest into an encoding tree

}



HForest Huffman::break_tree(){
       	// splits tree into forest
	auto forest = HForest();
	for(int i=0; i<257; i++){ //assumes there is a value for each node
		auto curr_val = encoder_->search_key(i)->get_value();//find a leaf node val
		forest->add_tree(i, curr_val, nullptr, nullptr) //add to forest
	}
	
	return forest;
}


HTree::tree_ptr_t Huffman::build_tree(HForest::forest_ptr_t forest){
       	//makes forest into huffman tree
	for(int i=0; i<257; i++){ //Pop two trees
		auto smallest_tree = forest->pop_tree();
		auto small_tree = forest->pop_tree(); //gets smallest trees
		HTree::value_t num_nodes = smallest_tree->get_value() + small_tree->get_value(); //Num children
		auto merged_tree = make_shared<HTree>(Huffman::dummy_key_, //to signify it is not a leaf node
				num_nodes, //root value temporarily holds number of leaves in tree
				small_tree, //adds nodes to merging node
				smallest_tree);
		forest->add_tree(merged_tree); //adds merged tree back to the forest
	}

	return forest->pop_tree();//clear forest add base tree to encoder_
}




Huffman::bits_t Huffman::encode(int symbol){
	auto node_pointer = encoder_->search_key(symbol); //find pointer to node with a key
	node_pointer->add_one_val(); ///add one to value of target node frequency
	auto broken_tree_ = break_tree(forest); //break apart tree into forest
	encoder_ = build_tree(broken_tree);


	auto enum_path = encoder_->path_to(symbol); //gets path to in form of enum left and rights
	Huffman::bits_t encode_path = new(bits_t());
	for(auto i: enum_path){
		if (i*==Direction::LEFT){
			encode_path.push_back(true);
		}
		else(){
			encode_path.push_back(false);
		}
	}
}



int Huffman::decode(bool bits){
	auto node = encoder_; //intial node
	/*
	while(bits!=nullptr){
		auto current_dir = //first bit 
		if (current_dir==TRUE){
			auto node = node->get_child(HTree::Direction::LEFT);
			}
		else(){
			auto node = node->get_child(HTree::Direction::RIGHT);
		}
		bits = bits++ //next bit
	}
	*/  
	auto node = root_node->path_to(converted_path);
	return node->get_key();

}


