/****************************************************************************************************************************************
  Title          : tree_collection.h
  Author         : Jaime Canizales
  Created on     : March 26, 2017
  Description    : The header file for the TreeCollection class
  Purpose        : Encapsulates the containers that represent the set of trees
                   and the collections properties
 
*****************************************************************************************************************************************/


#ifndef __Tree_Collection_H__
#define __Tree_Collection_H__

#include <string>
#include <iostream>
#include <list>
#include <set>
#include "Tree.h"
#include "avl_Tree.h"

struct boroContainer
{
   string b;
   int treesInBorough;
};

using namespace std;

class TreeCollection
{
public:
    TreeCollection ( );
    //~TreeCollection ( );
    //int total_tree_count(); 
    //int count_of_tree_species ( const string & species_name ); 
    //int count_of_trees_in_boro( const string & boro_name ); 
    list<string> get_matching_species(const string & species_name); 
    void insert( const Tree& x);
    void find(const Tree& x);
    friend class AVL_Tree;
    
private:   
    boroContainer b_t[5];
    set<string> tree_species;
    AVL_Tree collection;
    

};


#endif 

