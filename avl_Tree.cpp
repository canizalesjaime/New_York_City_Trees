/******************************************************************************************************************************************
  Title          : avl_Tree.cpp
  Author         : Jaime Canizales
  Created on     : January 1st, 2018
  Description    : The implemetation to an AVL tree class
  Purpose        : Using the avl tree data structure the tree items will be stored and organized.
 
*******************************************************************************************************************************************/

#include <iostream>
#include "Tree.h"
#include "avl_Tree.h"
#include <list>
#include <unordered_map>

using namespace std;

AVL_Tree::AVL_Tree()
{   
  root = NULL;
  size = 0;
}

//constructor
//****************************************************************************************************************************************

void AVL_Tree::insert( const Tree& x, avlNode*& t)
{

    if( t == NULL )
         t = new avlNode(x);
         

    else if( x < t->element )
        insert( x, t->left );

    else if( t->element < x )
         insert( x, t->right );

    balance( t );
  
}
// insert
//****************************************************************************************************************************************
static const int ALLOWED_IMBALANCE = 1;
// Assume t is balanced or within one of being balanced
void AVL_Tree::balance( avlNode*&t)
{
    if( t == NULL )
      return;

    if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
       if( height( t->left->left ) >= height( t->left->right ) )
          rotateWithLeftChild( t );   

       else doubleWithLeftChild( t );

    else
          if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
             if( height( t->right->right ) >= height( t->right->left ) )
                 rotateWithRightChild( t );

             else doubleWithRightChild( t );
    
   t->height = max( height( t->left ), height( t->right))+1;     
}

//balance
//*****************************************************************************************************************************************
int AVL_Tree:: height( avlNode *t ) 
{
     return t == NULL ? -1 : t->height;
}

//height 
//******************************************************************************************************************************************

void AVL_Tree::print(avlNode*& t)
{
      if ( t != NULL )
      {
        cout<<t->element;
        print( t->right);
        print( t->left);
      }
}
//print
//*****************************************************************************************************************************************

const Tree& AVL_Tree::find(const Tree& x, avlNode*& t)
{
    if( t == NULL )
       cout<<"not found"<<endl;

    else if( x < t->element )
        find( x, t->left );

    else if( t->element < x )
         find( x, t->right );

    else return t->element;
}

//find
//*****************************************************************************************************************************************

avlNode::avlNode(Tree item)
{
     element = item;
     left = NULL;
     right = NULL;
     height = 0;
}

//constructor for struct 
//****************************************************************************************************************************************

void AVL_Tree::rotateWithLeftChild( avlNode * & k2 )
{
    avlNode *k1 = k2->left;

    k2->left = k1->right;

    k1->right = k2;

    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;

    k1->height = max( height( k1->left ), k2->height ) + 1;

    k2 = k1;
}

//ll rotation
//*****************************************************************************************************************************************
void AVL_Tree::doubleWithLeftChild( avlNode * & k3 )
{

   rotateWithRightChild( k3->left );

   rotateWithLeftChild( k3 );
}

//lr rotation
//*****************************************************************************************************************************************

 void AVL_Tree::doubleWithRightChild( avlNode * & k3 )
{
   rotateWithLeftChild( k3->right );
   rotateWithRightChild( k3 );
}
   
//rl rotation
//*****************************************************************************************************************************************

void AVL_Tree::rotateWithRightChild( avlNode * & k2 )
{
    avlNode *k1 = k2->right;

    k2->right = k1->left;

    k1->left = k2;

    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;

    k1->height = max( height( k1->left ), k2->height ) + 1;

    k2 = k1;
}

//rr rotation (fix up maybe)
//*****************************************************************************************************************************************

list<Tree> AVL_Tree::findallmatches ( const Tree & x, avlNode *& t, list<Tree> &found,
                                      unordered_map<string,int> &count_of_species_in_each_boro ) const 
{
   if( t != NULL)
   {	   
    if( islessname(x, t->element))
       findallmatches( x, t->left, found, count_of_species_in_each_boro );

    else if( islessname(t->element , x))
       findallmatches( x, t->right, found, count_of_species_in_each_boro );
   
     else if( samename(x,t->element) )
     {               
       found.push_back(t->element);

       if(t->element.borough_name() == "Manhattan")
          count_of_species_in_each_boro["Manhattan"]++;
       else if(t->element.borough_name() == "Bronx")
          count_of_species_in_each_boro["Bronx"]++;
       else if(t->element.borough_name() == "Brooklyn")
          count_of_species_in_each_boro["Brooklyn"]++;
       else if(t->element.borough_name() == "Queens")
          count_of_species_in_each_boro["Queens"]++;
       else if(t->element.borough_name() == "Staten Island")
          count_of_species_in_each_boro["Staten Island"]++;

       findallmatches( x, t->left, found, count_of_species_in_each_boro );
       findallmatches( x, t->right, found, count_of_species_in_each_boro);
      }
    }
    return found;

} 

