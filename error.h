#pragma once
#include <string>
using namespace std;

class Error
{
private:
    string receiptNumber;
    string name;
    string type;
    string inform;

public:
    Error(string receiptNumber,string name,string type,string inform) :
        receiptNumber(receiptNumber), name(name), type(type), inform(inform) {}
    Error() {}
    string getReceiptNumber() { return this->receiptNumber; }
    string getName() { return this->name; }
    string getType() { return this->type; }
    string getInform() { return this->inform; }
    string display()
    {
        string result=this->receiptNumber+"\n"+
                this->name+"\n"+
                this->type+"\n"+
                this->inform;
        return result;
    }
};
