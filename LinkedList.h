/* 
 * File:   LinkedList.h
 * Author: fox2eagle1
 *
 * Created on July 9, 2016, 2:52 PM
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

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
    Node* next;
};

class LinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int numOfNodes = 0;
    
public:
    
    Node* createNode(double num) {
        Node *node = new Node;
        node->data = num;
        node->next = nullptr;
        numOfNodes++;
        return node;
    }
    
    void insert(double num) {
        if(head == nullptr) {
            head = createNode(num);
            tail = head;
        }
        
        else {
            tail->next = createNode(num);
            tail = tail->next;
        }
    }
    
    void printList() {
        Node *iterator = head;
        
        while(iterator != nullptr) {
            cout << iterator->data << " ";
            iterator = iterator->next;
        }
        
        cout << endl;
    }
    
    void deleteNode(int position) {
        Node *iterator = head;
        Node *begin;
        Node *end;
        Node *pos;
        int num = 1;
        
        if(position == 1) {
            pos = head;
            head = head->next;
            
            delete pos;
        }
        
        else if(position == numOfNodes) {
            Node *temp = tail;
            pos = head;
            while(num != numOfNodes-1) {
                pos = pos->next;
                num++;
            }
            
            tail = pos;
            tail->next = nullptr;
           
            delete temp;
        }
        
        else {
            pos = head;
            
            while(true) {
                
                if(num == position - 1) {
                    begin = iterator;
                    iterator = iterator->next;
                    num++;
                }
                
                else if(num == position) {
                    pos = iterator;
                    iterator = iterator->next;
                    num++;
                }
                
                else if(num == position+1) {
                    end = iterator;
                    iterator = iterator->next;
                    num++;
                    break;
                }
                
                else {
                    iterator = iterator->next;
                    num++;
                }
            }
            
            begin->next = end;
            delete pos;
        }
        
        
    }
};

#endif	/* LINKEDLIST_H */

