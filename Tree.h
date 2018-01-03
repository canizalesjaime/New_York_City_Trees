/******************************************************************************************************************************************
Title  : Tree.h
Author : Jaime Canizales 
Created on : January 1st, 2018
Purpose : The tree class creates an object that encapsulates all the data for a specific tree. The tree objects are to be stored in the
          treecollection class.

******************************************************************************************************************************************/
#ifndef TREE_H
#define TREE_H  

#include <string>

using namespace std;

class Tree 
{
public:
Tree();          
Tree( int id, int diam, string stat,
      string heal, string spc, int zip,
      string boro, double x, double y    );
/** Constructor : 
 *  Creates a tree object with a specific tree id, diameter, status, health, species common name(spc), zip code, borough and spatial 
 *  coordinates x and y.
 * @pre     None
 * @post    The tree object with the data mentioned above encapsulated.(status, health, and species common name may be empty).
 * 
 */
          
string common_name()const;
/** common_name : 
 * @returns   This returns the spc_common name of tree.
 */
       
string borough_name() const;
/** borough_name : 
 * @returns   This returns the name of the borough in which the tree is located.
 */

int diameter ();
/** diameter : 
 * @returns   This returns the value of the tree_dbh member.
 */

friend bool operator== ( const Tree &t1, const Tree &t2 ); 
/** Overloaded operator== :
 * Given two tree objects it checks for equivalency within the spc_common, and tree_id members.
 * @returns Returns true if the parameters have the same species common name and tree id, otherwise returns fasle.
 */

friend bool operator< ( const Tree &t1, const Tree &t2 ); 
/** Overloaded operator< :
 * This compares two trees using spc_common as primary key, and tree id as the secondary key.
 * @returns Returns true if t1 is less than t2 and false otherwise.
 */    
                
friend bool samename ( const Tree &t1, const Tree &t2 );
/** samename  :
 * Given two tree objects checks for equivalnecy between the spc_common members.
 * @returns Returns true if t1 and t2 have identical spc_common, otherwise return false.
 */

friend bool islessname ( const Tree &t1, const Tree &t2 );
/** islessname :
 * This compares two trees using spc_common.
 * @returns Returns true if t1 is less than t2 and false otherwise.
 */

friend ostream& operator<< (ostream &os, const Tree &t);
/** Overloaded operator<< :
 * This prints a tree object onto the given ostream. 
 */


    private :
             int tree_id;
             int tree_dbh;
             string status;
             string health;
             string spc_common;
             int zipcode;
             string boroname;
             double x_sp;
             double y_sp;
             
};


#endif
