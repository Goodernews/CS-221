/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>



// Representation of an ordering of cities
class Cities {
private:


public:
  // A pair of integral coordinates for each city
  using coord_t = std::pair<int, int>;

  // An ordering of cities. Each value represents a unique index
  // into the current city ordering in some container.
  using permutation_t = std::vector<unsigned int>;
  
  permutation_t coords_;
  
  Cities(char file_name);
  Cities();
  // Given a permutation, return a new Cities object where the order of the
  // cities reflects the original order of this class after reordering with
  // the given ordering. So for example, the ordering { 1, 0 } simply swaps
  // the first two elements (coordinates) in the new Cities object.
  Cities reorder(const permutation_t& ordering) const;

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean 
  // distance on a plane between their coordinates.
  double total_path_distance(const permutation_t& ordering) const;


  int size = 0; 

};

//euclid dist between two city coords
double euclid_dist(Cities::coord_t city_one, Cities::coord_t city_two);
