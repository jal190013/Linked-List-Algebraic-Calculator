#include <iostream>
using namespace std;

#include "Node.h"
#include "LinkedList.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

bool nextIsNegative = false;
int countTerms(string inputString)
{
    int spaces = 0;
    int expressions = 0;
    
    for (int i = 0; i < inputString.size(); i++)
    {
        if ((inputString[i] == '+' || inputString[i] == '-') && inputString[i+1] == ' ')
        {
            spaces++;
        }
    }
            
    if(spaces == 0)
    {
        expressions = 1;
    }
    else
    {
        expressions = spaces + 1;
    }
    
    return expressions;
}
void parseTerm(string currentTerm, LinkedList *curList)
{
    double curCoeff = 0.0;
    int curExp = 0;
    int pos = currentTerm.find("x");
    if(pos == string::npos) // term without x variable condition
    {
        curCoeff = stod(currentTerm);
        if(nextIsNegative)
        {
            curCoeff *= -1.0; 
        }
    }
    else // term has x variable
    {
        if(currentTerm.length() == 1)
        {
            curExp = 1;
            curCoeff = 1.0;
            nextIsNegative = false;
            Node* node1 = new Node();
            node1->setExp(curExp);
            node1->setCoef(curCoeff);
            *(curList) += node1;
            return;
        }
        string checkNegativeExp = currentTerm.substr(pos+1,pos+1);
        if(checkNegativeExp == "^-")
        {
            string tempexp = currentTerm.substr(pos + 3, currentTerm.length());
            if(tempexp != "")
                curExp = stoi(currentTerm.substr(pos + 3, currentTerm.length())) * -1;
            else
                curExp = 1;
        }
        else
        {
            string tempexp = currentTerm.substr(pos + 2, currentTerm.length());
            if(tempexp != "")
                curExp = stoi(currentTerm.substr(pos + 2, currentTerm.length()));
            else
                curExp = 1;
        }
        string tempcoeff = currentTerm.substr(0,pos);
        if(tempcoeff != "")
            curCoeff = stod(currentTerm.substr(0,pos));
        else
            curCoeff = 1;
        if(nextIsNegative)
        {
            curCoeff *= -1.0; 
        }
    }
    Node* node1 = new Node();
    node1->setExp(curExp);
    node1->setCoef(curCoeff);
    *(curList) += node1;
    nextIsNegative = false;
}
double calculateExpression(LinkedList* curList, double fx)
{
    double sum = 0;
    for(int i = 0; i < curList->getLength(); i++)
    {
         Node* tempCalcNode = (*curList)[i];
         int tempExp = tempCalcNode->getExp();
         double tempCoeff = tempCalcNode->getCoef();
         sum = sum + pow(fx,tempExp) * tempCoeff;
    }
    return sum;
}
int main()
{
    string temp;
    string tempInput;
    double x;
    int tempCo;
    int tempEx;
    size_t spaces;
    int expressions;

    
    cout << "Enter input file name: " << endl;
    cin >> temp;
    
    fstream input;
    input.open(temp);
    
    if(input.is_open())
    {
        while(!input.eof())
        {
            getline(input, tempInput);
            //cout << tempInput << endl;
            int rightIndex = tempInput.find(")");
            x = stod(tempInput.substr(2, rightIndex));
            tempInput = tempInput.substr(rightIndex + 4, tempInput.length());
            
            int lengthNum = tempInput.length();
            LinkedList* list1 = new LinkedList();
            for(int i = 0; i < lengthNum; i++)
            {
                if((tempInput[i] == '+' || tempInput[i] == '-') && tempInput[i+1] == ' ')
                {
                    parseTerm(tempInput.substr(0,i-1), list1);
                    if(tempInput[i] == '-')
                    {
                        nextIsNegative = true;
                    }
                    tempInput.erase(0, i+2);
                    while(countTerms(tempInput) > 1)
                    {
                        int pos1 = tempInput.find("+");
                        int pos2 = 0;
                        if(pos1 == string::npos)
                        {
                            pos2 = tempInput.find("-");
                            if(tempInput[pos2+1] != ' ')
                                pos2 = tempInput.find("-", pos2+1);
                            if(tempInput[pos2+1] == ' ')
                            {
                                parseTerm(tempInput.substr(0,pos2-1), list1);
                                nextIsNegative = true;
                                tempInput.erase(0, pos2+2);
                            }
                        }
                        else
                        {
                            parseTerm(tempInput.substr(0,pos1-1), list1);
                            tempInput.erase(0, pos1+2);
                        }
                    }
                    parseTerm(tempInput, list1);
                    list1->sortList();
                    double tempCalculationExp = calculateExpression(list1,x);
                    cout << list1 << " = ";
                    cout << fixed;
                    cout << setprecision(3) << tempCalculationExp << endl;
                    // clearing
                    Node* tempListHead = list1->getHead();
                    list1->clearList();
                    cout.unsetf(std::ios_base::floatfield);
                    
                    break;
                }
                
            }
            
        }
    }
    
    
    return 0;
}