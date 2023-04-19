#ifndef LinkedList_H
#define LinkedList_H

#include "Node.h"

class LinkedList
{
    private:
        Node* head;
        int length;
    public:
        Node *sorted;
        LinkedList();
        ~LinkedList();
        LinkedList(Node*);
        //Mutators
        void setHead(Node*);
        void setLength(int);
        void add(int, double);
        void sortList();
        void sortedInsert(Node*);
        //Accesors
        Node* getHead();
        int getLength();
        //Destructor
        void clearList();

        Node* operator[](int);
        friend std::ostream& operator<<(std::ostream&, LinkedList*);
        void operator +=(Node*);
        
};

#endif