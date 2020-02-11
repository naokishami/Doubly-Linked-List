#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    Node (const string &p_name, unsigned &p_weight) {
        name = p_name;
        weight = p_weight;
        nextName = NULL;
        nextWeight = NULL;
    }
    string name;
    unsigned weight;
    Node *nextName;
    Node *nextWeight;
};


class DLL {
private:
    Node *headName;
    Node *headWeight;
public:
    /* constructor */
    DLL () {
        headName = NULL;
        headWeight = NULL;
    }
    /* destructor */
    ~DLL () {}
    
    /* create nodes */
    void addNode (const string &name, unsigned weight) {
        Node **temp1 = &headWeight;
        Node **temp2 = &headName;
        Node *node = new Node(name, weight);
        node->name = name;
        node->weight = weight;
        node->nextName = 0;
        node->nextWeight = 0;
        sortbyName(temp2, node);
        sortbyWeight(temp1, node);
    }
    
    /* sort nodes by alphabetical order */
    void sortbyName (Node **headName, Node *node) {
        Node *curr;
        if (*headName == NULL || (*headName)->name >= node->name) {
            node->nextName = *headName;
            *headName = node;
        }
        else {
            curr = *headName;
            while (curr->nextName != NULL && curr->nextName->name < node->name) {
                curr = curr->nextName;
            }
            node->nextName = curr->nextName;
            curr->nextName = node;
        }
    }
    
    /* sort nodes by weight ascending order */
    void sortbyWeight (Node **headWeight, Node *node) {
        Node *curr;
        if (*headWeight == NULL || (*headWeight)->weight >= node->weight) {
            node->nextWeight = *headWeight;
            *headWeight = node;
        }
        else {
            curr = *headWeight;
            while (curr->nextWeight != NULL && curr->nextWeight->weight < node->weight) {
                curr = curr->nextWeight;
            }
            node->nextWeight = curr->nextWeight;
            curr->nextWeight = node;
        }
    }
    
    /* Print nodes by name */
    void printbyName () {
        for (Node *temp = headName; temp != 0; temp = temp->nextName) {
            cout << temp->name << " - " << temp->weight << ", ";
        }
        cout << endl;
    }
    /* Print nodes by weight */
    void printbyWeight () {
        for (Node *temp = headWeight; temp != 0; temp = temp->nextWeight) {
            cout << temp->name << " - " << temp->weight << ", ";
        }
        cout << endl;
    }
};


int main () {
    string name;
    int weight;
    DLL *theList = new DLL ();
    
    cout << "Type a name followed by the weight on a new line: " << endl;
    
    for (int i = 0; i < 15; i++) {
        cin >> name;
        cin >> weight;
        theList->addNode(name, weight);
    }
    
    theList->printbyName();
    theList->printbyWeight();
    
    return 0;
}
