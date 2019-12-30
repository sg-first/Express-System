#pragma once
#include <list>
#include "date.h"
#include "error.h"
#include <string>
using namespace std;

class expressBase
{
protected:
    string courierNumber;
    string consignor;
    string consignee;
    string name;
    float weight;
    float volume;
    float value;

public:
    expressBase() {}
    expressBase(string consignor, string consignee, string name, float weight, float volume, float value) :
        consignor(consignor), consignee(consignee), name(name), weight(weight), volume(volume), value(value) {}
    expressBase(string courierNumber,string consignor, string consignee, string name, float weight, float volume, float value) :
        courierNumber(courierNumber), consignor(consignor), consignee(consignee), name(name), weight(weight), volume(volume), value(value) {}
    string getCourierNumber() { return this->courierNumber; }

    string getExpressBill()
    {
        return this->courierNumber+"\n"+
                this->consignor+"\n"+
                this->consignee+"\n"+
                this->name+"\n"+
                to_string(this->weight)+"\n"+
                to_string(this->volume)+"\n"+
                to_string(this->value)+"\n";
    }
};

class express : public expressBase
{
private:
    bool isPaid=false;
    string getCourierNumberFromNet(date sendingTime) //fix:
    {
        return "";
    }

public:
    express() {}
    express(string _consignor, string _consignee, string _name, float _weight, float _volume, float _value, date sendingTime) :
        expressBase(_consignor,_consignee,_name,_weight,_volume,_value)
    {
        this->courierNumber=this->getCourierNumberFromNet(sendingTime);
    }

    void pay() { this->isPaid=true; }

    string getExpressBill()
    {
        string result=expressBase::getExpressBill();
        if(this->isPaid)
            result+="已支付";
        else
            result+="未支付";
        return result;
    }

    bool getIsPaid() { return this->isPaid; }

    string getLogisticsInformation() //fix:
    {

    }
};

class package : public expressBase
{
private:
    date warehousingTime;
    date outgoingTime;
    string pickupCode;
    bool isOutStock=false;

public:
    package() {}
    package(string _courierNumber, string _consignor, string _consignee, string _name, float _weight, float _volume, float _value, date warehousingTime) :
        expressBase(_courierNumber, _consignor,_consignee,_name,_weight,_volume,_value), warehousingTime(warehousingTime)
    {
        int week= this->warehousingTime.getWeek();
        int day=warehousingTime.getDay();
        string detailedTime=warehousingTime.getDetailedTime();
        this->pickupCode=to_string(week)+"-"+to_string(day)+"-"+detailedTime;
    }

    string getPickupCode() { return this->pickupCode; }

    void outStock(date outgoingTime)
    {
        this->isOutStock=true;
        this->outgoingTime=outgoingTime;
    }

    string display()
    {
        string result=expressBase::getExpressBill();
        result+=this->pickupCode+"\n"+
                this->warehousingTime.toString()+"\n"+
                this->outgoingTime.toString()+"\n";
        if(this->isOutStock)
            result+="已取件";
        else
            result+="未取件";
        if(this->isError())
            result+="差错信息:\n"+error.display();
        return result;
    }

    bool getIsOutStock() { return this->isOutStock; }

    Error error;
    bool isError() { return this->error.getReceiptNumber()!=""; }
};

