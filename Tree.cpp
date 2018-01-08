/******************************************************************************************************************************************
Title  : Tree.cpp
Author : Jaime Canizales 
Created on : January 1st, 2018
Purpose : The tree class creates an object that encapsulates all the data for a specific tree. The tree objects are to be stored in the
          treecollection class.

******************************************************************************************************************************************/

#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

Tree::Tree ( int id, int diam, string stat, string heal, string spc, int zip, string boro, double x, double y )
{
       tree_id = id;
       tree_dbh = diam;
       status = stat;
       health = heal;
       spc_common = spc;
       zipcode = zip;
       boroname = boro;
       x_sp = x;
       y_sp = y;
}

//Constructor
//****************************************************************************************************************************************/

string Tree::common_name( ) const
{
     return spc_common;
}

//common_name
//****************************************************************************************************************************************/

 string Tree::borough_name( ) const
{
     return boroname;
}

//borough_name
//****************************************************************************************************************************************/

int Tree::diameter( )
{
     return tree_dbh;
}

//diameter
//****************************************************************************************************************************************/

ostream& operator<< ( ostream &os, const Tree &t )
{
      os<<t.spc_common<<", "
        <<t.tree_id<<", "
        <<t.tree_dbh<<", "
        <<t.status<<", "
        <<t.health<<", "
        <<t.zipcode<<", "
        <<t.boroname<<", "
        <<t.x_sp<<", "<<t.y_sp<<endl;
}

//operator<<
//Friend functions and functions outside the tree class defined below
//****************************************************************************************************************************************/

bool operator== ( const Tree &t1, const Tree &t2 )
{
    if ( t1.spc_common == t2.spc_common )
       if( t1.tree_id == t2.tree_id )
          return true;

    else return false;
}

//operator==
//***************************************************************************************************************************************/

bool operator< ( const Tree &t1, const Tree &t2 )
{
    if ( t1.spc_common < t2.spc_common )
         return true;
       if ( t1.spc_common == t2.spc_common )
         if( t1.tree_id < t2.tree_id )
          return true;
  
    else return false;
}

//operator<
//***************************************************************************************************************************************/

bool samename ( const Tree &t1, const Tree &t2 )
{
    if ( t1.spc_common == t2.spc_common )
          return true;
 
    else return false;
}

//samename
//****************************************************************************************************************************************/

bool islessname ( const Tree &t1, const Tree &t2 )
{
    if ( t1.spc_common < t2.spc_common )
          return true;
 
    else return false;
}

//islessname
//****************************************************************************************************************************************/
Tree::Tree(string species_name)
{
   spc_common = species_name;
}

Tree::Tree()
{

}





