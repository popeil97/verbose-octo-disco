/* 
 * File:   BinaryTree.h
 * Author: fox2eagle1
 *
 * Created on July 10, 2016, 12:03 AM
 */

#ifndef BINARYTREE_H
#define	BINARYTREE_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cmath>

using namespace std;

struct Node {
    double data;
    Node *left = nullptr;
    Node *right = nullptr;
};

class BinaryTree {
    
private:
    Node *root = nullptr;
    
public:
    
    Node* createNode(double num) {
        Node *node = new Node;
        node->data = num;
        return node;
    }
    
    void insert(double num) {
        Node *ptr;
        ptr = root;
        
        if(root == nullptr) {
            root = createNode(num);
        }
        
        else {
            Node *parent;
            while (ptr != nullptr) {
                parent = ptr;
                if(num > ptr->data) {
                    ptr = ptr->right;
                }
                
                else {
                    ptr = ptr->left;
                }
            }
            
            if(num > parent->data) {
                parent->right = createNode(num);
            }
            
            else {
                parent->left = createNode(num);
            }
        }
    }
    
    void inOrderTrav() {
        inOrder(root);
    }
    
    void inOrder(Node *ptr) {
        
        if(ptr != nullptr) {
            inOrder(ptr->left);
            cout << ptr->data << " ";
            inOrder(ptr->right);
        }
    }
    
    void preOrderTrav() {
        preOrder(root);
    }
    
    void preOrder(Node *ptr) {
        if(ptr != nullptr) {
            cout << ptr->data << " ";
            preOrder(ptr->left);
            preOrder(ptr->right);
        }
    }
    
    void postOrderTrav() {
        postOrder(root);
    }
    
    void postOrder(Node *ptr) {
        if(ptr!=nullptr) {
            postOrder(ptr->left);
            postOrder(ptr->right);
            cout << ptr->data << " ";
        }
    }
    
    BinaryTree* split(double key) {
        Node *ptr = root;
        Node *parent = ptr;
        
        while(ptr != nullptr) {
            
            parent = ptr;
            
            if(ptr->data == key) {
                BinaryTree *newTree = new BinaryTree();
                newTree->root = ptr;
                if(parent->right == ptr) {
                    parent->right = nullptr;
                }
                
                else
                    parent->left = nullptr;
                
                return newTree;
            }
            
            else if(ptr->data < key) {
                ptr = ptr->right;
                
            }
            
            else {
                ptr = ptr->left;
            }
        }
    }
    
    
};


#endif	/* BINARYTREE_H */

