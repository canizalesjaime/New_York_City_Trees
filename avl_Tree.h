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
#include <list>
#include <unordered_map>

using namespace std;

class avlNode
{
    public:
    Tree element;
    avlNode* left;
    avlNode* right;
    int height;
    avlNode( Tree item);
    avlNode(Tree item, avlNode* l, avlNode* r, int ht);
};
    


class AVL_Tree
{
public:
    AVL_Tree  ( );                       // default
    AVL_Tree  ( const AVL_Tree & tree);  // copy constructor
    avlNode* clone( avlNode*t ) const;
    ~AVL_Tree ( );                       // destructor
      
    // Search methods:
    const Tree& find(const Tree & x, avlNode*& t);    
    avlNode * findMin( avlNode *t ) const;
    avlNode * findMax( avlNode *t ) const;
    list<Tree> findallmatches ( const Tree & x, avlNode*& t, list<Tree> &found,
                                unordered_map<string,int> &count_of_species_in_each_boro ) const;
    
    // Displaying the tree contents:
    void print( avlNode*& t) ; 
   
    // Tree modifiers:
    void   clear(avlNode * & t );                       // empty the tree
    void insert( const Tree& x, avlNode*& t);  // insert element x
    void   remove( const Tree& x, avlNode*& t);  // remove element x

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

