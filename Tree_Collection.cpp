/****************************************************************************************************************************************
  Title          : Tree_Collection.cpp
  Author         : Jaime Canizales
  Created on     : january 1st, 2018
  Description    : The implementation file for the TreeCollection class
  Purpose        : Encapsulates the containers that represent the set of trees
                   and the collections properties
 
*****************************************************************************************************************************************/

#include <string>
#include <list>
#include "Tree.h"
#include "avl_Tree.h"
#include "Tree_Collection.h"
#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

TreeCollection::TreeCollection()
{ 
}

//constructor
//*****************************************************************************************************************************************

void TreeCollection::insert(const Tree& x)
{
    collection.insert( x, collection.root);  
    tree_species.insert(x.common_name());
    numberOfTreesinEachBorough[x.borough_name()]++;
}

//insert 
//******************************************************************************************************************************************

list<string> TreeCollection::get_matching_species(string & species_name)
{
      set<string>::const_iterator it; 
      string save = species_name;
      list<string> matches ;

     for ( it = tree_species.begin(); it != tree_species.end(); ++it)
     {
       string build = *it;
       for(int i = 0; i < build.length(); i++)
          build[i] = tolower(build[i]);
  
       for(int i = 0; i < species_name.length(); i++)
          species_name[i] = tolower(species_name[i]);
              
       if( species_name == build)
         matches.push_back(*it);
       
       else 
       {
          string build2 = " " + build;
          build2 = build2 + " ";
          string build3 = "-" + build;
          build3 = build3 + "-";
          string check = " " + species_name ;
          check = check + " ";
          string check2 = "-" + species_name;
          check2 = check2 + "-";
          size_t pos = build2.find(check);
          size_t pos2 = build3.find(check2);
          if(pos != std::string::npos || pos2 != std::string::npos)
             matches.push_back(*it);
       }
      }
     species_name = save;
     return matches;
}

//all the matching species from the query
//*************************************************************************************************************************************

int TreeCollection::total_tree_count()
{
    return collection.size;
}

//total amount of trees
//*************************************************************************************************************************************

int TreeCollection::count_of_trees_in_boro( const string & boro_name )
{
   return numberOfTreesinEachBorough[boro_name];
}

//total number of trees in a given borough
//************************************************************************************************************************************

int TreeCollection::count_of_tree_species ( const string & species_name, unordered_map<string,int> &count_of_species_in_each_boro )
{
    Tree lookup(species_name);
    list<Tree> matching_Objects; 
    matching_Objects = collection.findallmatches(lookup,collection.root ,matching_Objects, count_of_species_in_each_boro);
    return matching_Objects.size();    
}

