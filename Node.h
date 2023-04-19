#ifndef NODE_H
#define NODE_H

class Node
{
    friend class LinkedList;
    public:
        double coeff;
        int expo;
        Node* next;
    public:
        Node();
        Node(double, int);
        //Mutators
        void setCoef(double);
        void setExp(int);
        void setNext(Node*);
        //Accessors
        double getCoef() const;
        int getExp() const;
        Node* getNext();
        friend std::ostream& operator<<(std::ostream&, Node*);
};

#endif