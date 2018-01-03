/******************************************************************************************************************************************
  Title          : avl_Tree.h
  Author         : Jaime Canizales
  Created on     : January 1st, 2018
  Description    : The interface to an AVL tree class
  Purpose        : 
 
*******************************************************************************************************************************************/

#ifndef __AVL_H__
#define __AVL_H__

#include <string>
#include <iostream>
#include <list>
#include "Tree.h"

using namespace std;


class avlNode
{
    public:
    Tree element;
    avlNode* left;
    avlNode* right;
    int height;
    avlNode( Tree item);
};
    


class AVL_Tree
{
public:
    AVL_Tree  ( );                       // default
    //AVL_Tree  ( const AVL_Tree & tree);  // copy constructor
   // ~AVL_Tree ( );                       // destructor
      
    // Search methods:
    const Tree& find    ( const Tree & x ) ;    
    //const Tree& findMin () const;
   // const Tree& findMax () const;
    //list<Tree> findallmatches ( const Tree & x ) const;
    
    // Displaying the tree contents:
    void   print   (  ) ;
    void print( avlNode*& t) ; 
   
    // Tree modifiers:
   // void   clear();                       // empty the tree
    void   insert( const Tree& x);  // insert element x
   // void   remove( const Tree& x);  // remove element x

    void insert(const Tree& x, avlNode*& y);
    void balance( avlNode*&t);
    int height(avlNode* t);
    const Tree& find( const Tree& x, avlNode*& t);
    void rotateWithLeftChild( avlNode * & k2 );
    void rotateWithRightChild( avlNode * & k2 );
    void doubleWithRightChild( avlNode * & k3 );
    void doubleWithLeftChild( avlNode * & k3 );
    


private :
    
    avlNode* root;
    int size;
};

#endif /* __AVL_H__ */

