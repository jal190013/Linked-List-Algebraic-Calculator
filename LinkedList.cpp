#include <iostream>
using namespace std;

#include "LinkedList.h"
#include "Node.h"


LinkedList::LinkedList()
{
    head = NULL;
    length = 0;
}
LinkedList::~LinkedList()
{ 
    head = NULL;
    length = 0;
}

LinkedList::LinkedList(Node* copyHead)
{
    head = copyHead;
}

void LinkedList::setHead(Node* newhead)
{
    head = newhead;
    length = 1;
}

void LinkedList::setLength(int l)
{
    length = l;
}

Node* LinkedList::getHead()
{
    return head;
}

int LinkedList::getLength()
{
    return length;
}

void LinkedList::add(int ex, double co)
{
    if(head == NULL)
    { 
        head = new Node(ex, co);
    }
    else
    {
        Node* temp = new Node(ex, co);
        temp->setNext(head);
        head = temp;
    }
    length += 1;
} 


Node* LinkedList::operator [] (int value) {
    Node *temp = head;
    if(value < 0 || value > length)
    {
        return NULL;
    }
    for(int i = 0; i < value && temp!=NULL; i++)
    {
        temp = temp->next;
    }
    return temp;
}
ostream& operator<<(std::ostream& os, LinkedList* current)
{
  string choose = "";
  for(int i = 0; i < current->getLength(); i++)
  {
      string operatorValue = "";
      Node *currentNode;
    if(i < (current->getLength() - 1))     // Not last node
    {
        currentNode = (*current)[i+1];
        if(currentNode->getCoef() > 0)
        {
            operatorValue = "+ ";
        }
        else if(currentNode->getCoef() < 0)
        {
            operatorValue = "- ";
        }
    }
    else
    {
        currentNode = (*current)[i];
        operatorValue = "";
    }
    currentNode->setCoef(abs(currentNode->getCoef()));
    os << (*current)[i] << choose << " " << operatorValue;
  }
  return os;
}
void LinkedList::operator += (Node* insertNode)
{
    Node* copy = insertNode;
    if(head == NULL)
    {
      head = copy;
    }
    else 
    {
      Node *temp = head;
      while(temp->next != NULL)
      {
          temp = temp->next;
      }
      temp->next = copy;
    }
    length += 1;
}
void LinkedList :: sortList()
{
  int tmp;
  double tmp2;
  for(Node *i = head; i->next != NULL;i = i->next)
  {
    for(Node* j = i;j->next != NULL;j= j->next)
    {
      if(i->expo < j->expo)
      {
        tmp = i->expo;
        tmp2 = i->coeff;
        i->expo = j->expo;
        i->coeff = j->coeff;
        j->expo = tmp;
        j->coeff = tmp2;
      }
    }
  }
}

void LinkedList::clearList()
{
    length = 0;
    head = NULL;
}