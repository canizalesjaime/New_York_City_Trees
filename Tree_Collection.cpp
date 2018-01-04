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

list<string> TreeCollection::get_matching_species(const string & species_name)
{
      set<string>::const_iterator it; 

      list<string> matches ;

     for ( it = tree_species.begin(); it != tree_species.end(); ++it)
     {
       string build = *it;
       string check = "";
              
       if( species_name == build)
       {
         matches.push_back(build);
         return matches;
       }
       
       else 
       {
          for ( int i = 0; i < build.length(); i++)
          {
           check = check + build[i];
           if ( build[i] == ' ' )
           {
              cout<<"did you make it"<<endl;
              if ( check == species_name)
              {
                 matches.push_back(build);
                 break;
              }
            }
           }
        }
      }
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

//int TreeCollection::count_of_tree_species ( const string & species_name )
//{
  //  if(samename(



























                 
