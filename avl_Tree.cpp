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
#include "Tree_Collection.h"
using namespace std;

AVL_Tree::AVL_Tree()
{   
  root = NULL;
  size = 0;
}

//constructor
//****************************************************************************************************************************************

void AVL_Tree::insert( const Tree& x)
{
     insert( x, root);    
}
//wrapper insert 
//***************************************************************************************************************************************
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

void AVL_Tree::print( ) 
{
    print( root);
}

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

const Tree& AVL_Tree::find(const Tree& x) 
{ 
    find(x, root);
    
}

//find 
//****************************************************************************************************************************************

const Tree& AVL_Tree::find(const Tree& x, avlNode*& t)
{
    if( t == NULL )
       cout<<"not found"<<endl;

    else if( x < t->element )
        find( x, t->left );

    else if( t->element < x )
         find( x, t->right );

    else cout<<"found!!"<<endl<<x;
}

//find continued
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


  

