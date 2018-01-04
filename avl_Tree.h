/******************************************************************************************************************************************
  Title          : avl_Tree.h
  Author         : Jaime Canizales
  Created on     : January 1st, 2018
  Description    : The interface to an AVL tree class
  Purpose        : 
 
*******************************************************************************************************************************************/

#ifndef __AVL_H__
#define __AVL_H__

#include "Tree.h"

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
    const Tree& find(const Tree & x, avlNode*& t);    
    //const Tree& findMin () const;
   // const Tree& findMax () const;
    //list<Tree> findallmatches ( const Tree & x ) const;
    
    // Displaying the tree contents:
    void print( avlNode*& t) ; 
   
    // Tree modifiers:
   // void   clear();                       // empty the tree
    void insert( const Tree& x, avlNode*& t);  // insert element x
   // void   remove( const Tree& x);  // remove element x

    void balance( avlNode*&t);
    int height(avlNode* t);
    void rotateWithLeftChild( avlNode * & k2 );
    void rotateWithRightChild( avlNode * & k2 );
    void doubleWithRightChild( avlNode * & k3 );
    void doubleWithLeftChild( avlNode * & k3 );
    friend class TreeCollection;
    


private :
    
    avlNode* root;
    int size;
};

#endif /* __AVL_H__ */

