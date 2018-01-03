/****************************************************************************************************************************************
  Title          : Tree_Collection.cpp
  Author         : Jaime Canizales
  Created on     : january 1st, 2018
  Description    : The implementation file for the TreeCollection class
  Purpose        : Encapsulates the containers that represent the set of trees
                   and the collections properties
 
*****************************************************************************************************************************************/

#include <string>
#include <iostream>
#include <list>
#include "Tree.h"
#include "avl_Tree.h"
#include "Tree_Collection.h"

using namespace std;

TreeCollection::TreeCollection()
{
   b_t[0].b = "manhattan";
   b_t[0].treesInBorough = 0;
   b_t[1].b = "brooklyn";
   b_t[1].treesInBorough = 0;
   b_t[2].b = "bronx";
   b_t[2].treesInBorough = 0;
   b_t[3].b = "staten island";
   b_t[3].treesInBorough = 0;
   b_t[4].b = "queens";
   b_t[4].treesInBorough = 0;
}

//constructor
//*****************************************************************************************************************************************

void TreeCollection::insert(const Tree& x)
{
   collection.insert(x);
    if( x.borough_name() == "Manhattan" )
         b_t[0].treesInBorough ++;

    else if( x.borough_name() == "Brooklyn" )
         b_t[1].treesInBorough ++;

    else if( x.borough_name() == "Bronx" )
         b_t[2].treesInBorough ++;

    else if( x.borough_name() == "Staten Island" )
         b_t[3].treesInBorough ++;

    else if( x.borough_name() == "Queens" )
         b_t[4].treesInBorough ++;

    tree_species.insert(x.common_name());

}

//insert 
//******************************************************************************************************************************************

void TreeCollection:: find(const Tree& x)
{
    collection.find(x);
}

//find 
//*****************************************************************************************************************************************
list<string> TreeCollection::get_matching_species(const string & species_name)
{
      set<string>::const_iterator it; 

      list<string> matches ;

     for ( it = tree_species.begin(); it != tree_species.end(); ++it)
     {
       string build = *it;
       string check;
              
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
              if ( check == species_name)
              {
                 matches.push_back(check);
                 break;
              }
           
           }
        }
      }
     return matches;
}



/*int treeidNum, dbhNum, zipcoNum;
      double x_num, y_num;
      string stat, heal, spccommon, bor;
      cout<<"find node:(treeidNum, dbhNum, stat, heal, spccommon, zipcoNum, bor, x_num, y_num)";
      cin>>treeidNum>>dbhNum>>stat>>heal>>spccommon>>zipcoNum>>bor>>x_num>>y_num;

      Tree temp ( treeidNum, dbhNum, stat, heal, spccommon, zipcoNum, bor, x_num, y_num);
      collection.find(temp);
      */
          
                                          
