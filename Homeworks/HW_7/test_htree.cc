/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <cassert>

using namespace std;

// Create an elaborate example test tree:
HTree::tree_ptr_t create_test_tree()
{
  return make_shared<HTree>(126, 1,
		 make_shared<HTree>(1,5, 
			  make_shared<HTree>(9,8), 
			  make_shared<HTree>(30,2)),
		  make_shared<HTree>(12,40,
			  make_shared<HTree>(9,8,
				  make_shared<HTree>(85, 2)),
			  make_shared<HTree>(13,12)));
}

void test_get_child(const HTree::tree_ptr_t root){
  assert(root->get_child(HTree::Direction::LEFT)==root->left_);
}

void test_path_to(const HTree::tree_ptr_t root)
{
  assert(*(root->path_to(126)) == HTree::path_t({ })); //testing path to root
  assert(root->path_to(1000)==nullptr); //Testing path to a non existent item
}

void test_get_key(const HTree::tree_ptr_t root){
  assert(root->get_key()==126); //testing get key on root
  assert(root->get_child(HTree::Direction::LEFT)->get_key()==1); // testing get key on a left child 
  
}

void test_get_val(const HTree::tree_ptr_t root){
  assert(root->get_value()==1); //testing get key on root
  assert(root->get_child(HTree::Direction::RIGHT)->get_value()==40); // testing get key on a left child 
  
}

int main()
{
  auto root = create_test_tree();
  test_get_child(root);
  test_path_to(root);
  test_get_key(root);
  test_get_val(root);
  return 0;
}

