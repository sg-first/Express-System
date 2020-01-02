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
    expressBase(string courierNumber, string consignor, string consignee, string name, float weight, float volume, float value) :
        courierNumber(courierNumber), consignor(consignor), consignee(consignee), name(name), weight(weight), volume(volume), value(value) {}
    string getCourierNumber() { return this->courierNumber; }

    string getExpressBill()
    {
        return "货运单号:"+this->courierNumber + "\n" +
            "发件人:"+this->consignor + "\n" +
            "收件人:"+this->consignee + "\n" +
            "货物类型:"+this->name + "\n" +
            "重量"+to_string(this->weight) + "\n" +
            "体积:"+to_string(this->volume) + "\n" +
            "价值:"+to_string(this->value) + "\n";
    }
};

class express : public expressBase
{
private:
    bool isPaid = false;
    string getCourierNumberFromNet(date sendingTime) //fix:
    {
        return "未连接到服务器";
    }

public:
    express() {}
    express(string consignor, string consignee, string name, float weight, float volume, float value, date sendingTime) :
        expressBase(consignor, consignee, name, weight, volume, value)
    {
        this->courierNumber = this->getCourierNumberFromNet(sendingTime);
    }

    void pay() { this->isPaid = true; }

    string getExpressBill()
    {
        string result = expressBase::getExpressBill();
        if (this->isPaid)
            result += "已支付";
        else
            result += "未支付";
        return result;
    }

    bool getIsPaid() { return this->isPaid; }

    string getLogisticsInformation() //fix:
    {
        return "未连接到服务器";
    }
};

class package : public expressBase
{
private:
    date warehousingTime;
    date outgoingTime;
    string pickupCode;
    bool isOutStock = false;

public:
    package() {}
    package(string courierNumber, string consignor, string consignee, string name, float weight, float volume, float value, date warehousingTime, int size) :
        expressBase(courierNumber, consignor, consignee, name, weight, volume, value), warehousingTime(warehousingTime)
    {
        int week = warehousingTime.getWeek();
        int day = warehousingTime.getDay();
        string detailedTime = warehousingTime.getDetailedTime();
        this->pickupCode = to_string(week) + to_string(day) + "-" + detailedTime + "-" + to_string(size);
    }

    string getPickupCode() { return this->pickupCode; }

    void outStock(date outgoingTime)
    {
        this->isOutStock = true;
        this->outgoingTime = outgoingTime;
    }

    string display()
    {
        string result = expressBase::getExpressBill();
        result += "取件码:"+this->pickupCode + "\n" +
            "入库时间:"+this->warehousingTime.toString() + "\n";
        if (this->isOutStock)
            result += "取件时间:"+this->outgoingTime.toString() + "\n";
        else
            result += "未取件";
        if (this->isError())
            result += "差错信息:\n" + error.display();
        return result;
    }

    bool getIsOutStock() { return this->isOutStock; }

    Error error;
    bool isError() { return this->error.getReceiptNumber() != ""; }
};

