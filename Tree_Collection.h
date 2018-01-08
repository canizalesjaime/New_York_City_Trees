/****************************************************************************************************************************************
  Title          : tree_collection.h
  Author         : Jaime Canizales
  Created on     : January 1st, 2018
  Description    : The header file for the TreeCollection class
  Purpose        : Encapsulates the containers that represent the set of trees
                   and the collections properties
 
*****************************************************************************************************************************************/


#ifndef __Tree_Collection_H__
#define __Tree_Collection_H__

#include <string>
#include <list>
#include <set>
#include "Tree.h"
#include "avl_Tree.h"
#include <unordered_map>


class TreeCollection
{
public:
    TreeCollection ( );
    //~TreeCollection ( );
    int total_tree_count(); 
    int count_of_tree_species ( const string & species_name, unordered_map<string,int> &count_of_species_in_each_boro );
    int count_of_trees_in_boro( const string & boro_name ); 
    list<string> get_matching_species(string & species_name); 
    void insert( const Tree& x);
    
private:   
    unordered_map<string,int> numberOfTreesinEachBorough = {{"Manhattan",0},{"Brooklyn",0},{"Queens",0},{"Bronx",0},{"Staten Island",0}};
    set<string> tree_species;
    AVL_Tree collection;
    
};


#endif 

