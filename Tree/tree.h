//============================================================================
// Name        : tree.h
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Template for all code releted to tree.
//============================================================================

/**
* This class repersent tree.
* @member data: an integer - data of the node
* @left   pointer: a Node - repersent left link of tree
* @right   pointer: a Node - repersent left link of tree
* @Node() constructor: initialize tree with given values.
*/

class Tree {
    public:
        int data;
        Tree *left;
        Tree *right;
        
        Tree(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};








