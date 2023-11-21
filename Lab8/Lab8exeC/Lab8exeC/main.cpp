//
//  zip file of list.h, list.cpp, hydro.h and hydro.cpp
//  Lab8exeC
//  Created by Gillian Habermehl
//


//list.h

#ifndef LIST_H
#define LIST_H

struct ListItem {
    int year;
    double flow;
};

struct Node {
    ListItem item;
    Node *next;
};

class FlowList {
public:
    FlowList(); // PROMISES: Creates empty list.
    FlowList(const FlowList& source);
    FlowList& operator =(const FlowList& rhs);
    ~FlowList();

    void print() const;
    // PROMISES:
    //   Prints items in list on a single line, with commas separating
    //   the items and square brackets marking the ends of the list.
    // NOTE:
    //   This is different from the print function presented in lectures.

    
    void insert(int year, double flow);
    
    double getflow(FlowList& source, int n);
    
    double getyear(FlowList& source, int n);
    
  private:
    Node *headM;
    void destroy();
    // Deallocate all nodes, set headM to zero.

    void copy(const FlowList& source);
    // List becomes copy of source.
  };
  #endif

    



//list.cpp

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

FlowList::FlowList()
: headM(0)
{
}

FlowList::FlowList(const FlowList& source)
{
    copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

FlowList::~FlowList()
{
    destroy();
}

void FlowList::print() const
{
    if (headM != 0) {
        cout << ' ' << headM->item.year;
        cout << ' ' << headM->item.flow;
        for (const Node *p = headM->next; p != 0; p = p->next){
            cout << ", " << p->item.year;
            cout << ", " << p->item.flow;
        }
    }
}

void FlowList::insert(int year, double flow){
    Node *new_node = new Node;
    new_node->item.year = year;
    new_node->item.flow = flow;
    
    if (headM == 0 || year <= headM->item.year) {
        new_node->next = headM;
        headM = new_node;
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && year > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}


void FlowList::destroy()
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

void FlowList::copy(const FlowList& source)
{
    if(source.headM == 0)
        return;

    Node *before = source.headM;
    Node *after = before -> next;
    Node *temp_node = new Node;

    temp_node -> item.year = before -> item.year;
    temp_node -> item.flow = before -> item.flow;

    headM = temp_node;

    while(after != 0){
        temp_node -> next = new Node;
        temp_node = temp_node -> next;

        temp_node -> item.year = after -> item.year;
        temp_node -> item.flow = after -> item.flow;

        after = after -> next;
    }
    temp_node -> next = 0;
}

double FlowList::getflow(FlowList& source, int n){
    
    double a;
    Node *temp_node = source.headM;
    
    int k = 0;
    while(k != n){
        temp_node = temp_node -> next;
        k++;
    }
    
    if(k == n){
        a = temp_node -> item.flow;
        return a;
    }
    else
        return 1;
}


double FlowList::getyear(FlowList& source, int n){
    
    double a;
    Node *temp_node = source.headM;
    
    int k = 0;
    while(k != n){
        temp_node = temp_node -> next;
        k++;
    }
    
    if(k == n){
        a = temp_node -> item.year;
        return a;
    }
    else
        return 1;
}








//hydro.h

#ifndef HYDRO_H
#define HYDRO_H

int readData(FlowList& source);
//PROMISES: Will open "flow.txt" for reading and will read
//all the contents of the text file into a linked list ordered
//by year.

void addData(int year, double flow, FlowList& source);
//PROMISES:
//A node with the new year and flow is added in
//a way that preserves the nondecreasing
//order of items in nodes.

void removeData(int year, FlowList& source);
//PROMISES:
//If no node has an year matching year,
//list is unchanged.
//Otherwise exactly one node with
//its year == year is removed.

void saveData(FlowList& source);
//PROMISES:
//Will open "flow.txt" for writing and will
//write into the text file all the data from the linked list.

void display(FlowList& source);

double average(FlowList& source);
//PROMISES:
//Will return the average of all the flow amounts
//included in the linked list.

int menu();

void displayHeader();

void pressEnter();
//PROMISES:
//Waits for user to hit the enter button, once done the code will proceed.

#endif





//hydro.cpp

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "hydro.h"
using namespace std;



int readData(FlowList& source) {
    int a;
    double b;
    int count = 0;
    
    ifstream inObj;
    inObj.open ("flow.txt");
    
    if(inObj.fail()){
        cout << "Error opening file ... quitting\n";
        exit(1);
    }
    
    
    while(inObj.eof() == 0){
        inObj >> a >> b;
        source.insert(a, b);
        count += 1;
    }
    inObj.close();
    
    return count;
}


void addData(int year, double flow, FlowList& source){
    source.insert(year, flow);
}


void removeData(int year, FlowList& source){
    //still to be completed
    
}

void saveData(FlowList& source){
    
    ofstream outObj;
    outObj.open ("flow.txt");
    
    if(outObj.fail()){
        cout << "Error opening file ... quitting\n";
        exit(1);
    }
    
    int i = 0;
    
    while(i != 1)
        outObj >> source.getyear(source, i) >> source.getflow(source, i);
    
    outObj.close();
}

void display(FlowList& source) {
    cout << "Year" << "         " << "Flow (int billions of cubic meters)";
    source.print();
    double x = average(source);
    cout << "The annual average of the flow is: " << x << "billions of cubic meters.";
}

double average(FlowList& source){
    
    int count = 0;
    int sum = 0;
    
    int i = 0;
    
    while(i != 1){
        sum += source.getflow(source, i);
        count++;
    }
    double avg = sum / count;
    
    return avg;
}


int menu() {
    int n;
    cout << "Please select one of the following operations\n" << "1. Display flow list, and the average\n" << "2. Add data\n" << "3. Save data into the file\n" << "4. Remove data\n" << "5. Quit\n" << "Enter your choice (1, 2, 3, 4, or 5): " << endl;
    cin >> n;
    return n;
}


void displayHeader() {
    cout << "Program: Flow Studies - Fall 2022\n" << "Version 1.0\n" << "Lab Section: B02\n" << "Produced by: Gillian Habermehl\n" << endl;
}


void pressEnter() {
    cout << "\n<<< Press Enter to Continue >>>\n";
    cin.get();
}


int main() {
    
    FlowList x;
    int numRecords;
    displayHeader();
    numRecords = readData(x);
    int quit = 0;
    
    while(1){
        switch(menu()){
            case 1 :
                display(x);
                pressEnter();
                break;
            
            case 2 :
                int a;
                double b;
                cout << "Please enter a year: " << endl;
                cin >> a;
                cout << "Please enter the flow: " << endl;
                cin >> b;
                addData(a, b, x);
                pressEnter();
                break;
                
            case 3 :
                saveData(x);
                pressEnter();
                break;
                
            case 4 :
                int y;
                cout << "Please enter thr year that you want to remove: ";
                cin >> y;
                removeData(y, x);
                pressEnter();
                break;
                
            case 5 :
                cout << "\nProgram terminated successfully.\n\n";
                quit = 1;
                break;
            default:
                cout << "\nNot a valid input.\n";
                pressEnter();
            
        }
        if(quit == 1) break;
    }
    return 0;
}
