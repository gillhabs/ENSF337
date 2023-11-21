//
//  main.cpp
//  Lab8_exeA
//
//  Created by Gillian Habermehl on 2022-11-24.
//
// OLList.h
// ENSF 337 Fall 2021 Lab 8 Exercises A and B


#ifndef OLLIST_H
#define OLLIST_H

typedef int ListItem;

struct Node {
  ListItem item;
  Node *next;
};

class OLList {
public:
  OLList(); // PROMISES: Creates empty list.
  OLList(const OLList& source);
  OLList& operator =(const OLList& rhs);
  ~OLList();

  void insert(const ListItem& itemA);
  // PROMISES:
  //    A node with a copy of itemA is added in
  //    a way that preserves the nondecreasing
  //    order of items in nodes.

  void remove(const ListItem& itemA);
  //  PROMISES:
  //    If no node has an item matching itemA,
  //    list is unchanged.
  //    Otherwise exactly one node with
  //    its item == itemA is removed.

  void print() const;
  // PROMISES:
  //   Prints items in list on a single line, with commas separating
  //   the items and square brackets marking the ends of the list.
  // NOTE:
  //   This is different from the print function presented in lectures.

private:
  Node *headM;
  void destroy();
  // Deallocate all nodes, set headM to zero.

  void copy(const OLList& source);
  // List becomes copy of source.
};
#endif







// OLList.cpp
// ENSF 337 Fall 2021 Lab 8 Exercise A and B

#include <iostream>
#include <stdlib.h>
using namespace std;
//#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    Node *maybe_doomed = 0;
    Node *before = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        before = headM;
        maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if(maybe_doomed -> next == 0)
            before -> next = 0;
        else{
            before -> next = maybe_doomed -> next;
            maybe_doomed -> next = 0;
        }
    }
}

void OLList::destroy()
{
    // if list is empty, do nothing
    if (headM == 0)
        return;
    
    Node *before = headM;
    Node *after = headM -> next;
    Node *node_to_delete = 0;
    
    while(after -> next != 0){
        node_to_delete = before;
        before = after;
        after = after -> next;
        node_to_delete -> next = 0;
    }
    
}

void OLList::copy(const OLList& source)
{
    if(source.headM == 0)
        return;
    
    Node *before = source.headM;
    Node *after = before -> next;
    Node *temp_node = new Node;
    
    temp_node -> item = before -> item;
    headM = temp_node;
    
    while(after != 0){
        temp_node -> next = new Node;
        temp_node = temp_node -> next;
        
        temp_node -> item = after -> item;
        
        after = after -> next;
    }
    temp_node -> next = 0;
}




// lab8ExB.cpp
//
// ENSF 337 Fall 2021, Lab 8 Exercise B
//

#include <iostream>
using namespace std;

//#include "OLList.h"

int main()
{
    OLList the_list;
    
    cout << "List just after creation. expected to be [ ]" << endl;
    the_list.print();
    the_list.insert(330);
    the_list.insert(440);
    the_list.insert(220);
    the_list.insert(110);
    the_list.insert(550);
    the_list.insert(99);
    the_list.insert(120);
    cout << "the_list after some insertions. Expected to be: [ 99, 110, 120, 220, 330, 440, 550 ]"<< endl;
    the_list.print();
    
#if 1     // change #if 0 to #if 1 to test copyiong list.
    cout << "testing for copying lists ..."<< endl;
    OLList other_list;
    other_list = the_list;
    cout << "other_list as a copy of the_list: expected to be [ 99, 110, 120, 220, 330, 440, 550 ]" << endl;
    other_list.print();
    OLList third_list = the_list;
    cout << "third_list as a copy of the_list: expected to be: [ 99, 110, 120, 220, 330, 440, 550 ]" << endl;
    third_list.print();
#endif
    
#if 1     //  change #if 0 to #if 1 to test removing and chaining.
    cout << "testing for removing and chaining assignment operator..."<< endl;
    the_list.remove(550);
    the_list.remove(330);
    cout << "the_ist after some removals: expected to be: [ 99, 110, 120, 220, 440 ]" << endl;
    the_list.print();
    cout << "printing other_list one more time: expected to be: [ 99, 110, 120, 220, 330, 440, 550 ]" << endl;
    other_list.print();
    cout << "printing third_list one more time: expected to be: [ 99, 110, 120, 220, 330, 440, 550 ]" << endl;
    third_list.print();
    cout << "chaining assignment operator ..."<< endl;
    third_list = other_list = the_list;
    cout << "the_list after chaining assignment operator: expected to be: [ 99, 110, 120, 220, 440 ]" << endl;
    the_list.print();
    cout << "other_list after chaining: expected to be: [ 99, 110, 120, 220, 440 ]" << endl;
    other_list.print();
    cout << "third_list after chaining: expected to be: [ 99, 110, 120, 220, 440 ]" << endl;
    third_list.print();
#endif
    return 0;
}






//
//
//// lab8ExA.cpp
////
//// ENSF 337 Lab 8 Exercise A
////
//
//#include <iostream>
//using namespace std;
////
////#include "OLList.h"
//
//int main()
//{
// OLList the_list;
//
// cout << "List just after creation: ";
// the_list.print();
// the_list.insert(330);
// the_list.insert(440);
// the_list.insert(220);
// the_list.insert(110);
// cout << "List after some insertions: ";
// the_list.print();
// the_list.remove(550);
// the_list.remove(330);
// cout << "List after some removals: ";
// the_list.print();
//
// return 0;
//}
//
//
