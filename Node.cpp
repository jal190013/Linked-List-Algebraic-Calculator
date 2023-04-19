#include <iostream>
using namespace std;

#include "Node.h"

Node::Node()
{
    coeff = 0;
    expo = 0;
}

Node::Node(double x, int y)
{
    coeff = x;
    expo = y;
}

void Node::setCoef(double temp)
{
    coeff = temp;
}

void Node::setExp(int temp)
{
    expo = temp;
}

void Node::setNext(Node* n)
{
    next = n;
}

double Node::getCoef() const
{
    return coeff;
}

int Node::getExp() const
{
    return expo;
}

Node* Node::getNext()
{
    return next;
}

ostream& operator<<(std::ostream& os, Node* current)
{
    if(abs(current->coeff) <= 1.0 && current->expo != 0)
    {
        if(current->expo == 1)
            os << "x";
        else
            os << "x^" << current->expo;
    }
    else if(current->expo == 0)
    {
        os << current->coeff;
    }
    else
    {
        os << current->coeff << "x^" << current->expo;
    }
  return os;
}

