#pragma once
#include "express.h"
#include <tuple>
#include <vector>
using namespace std;

class dataOperation
{
public:
    static list<package> allPackage;
    static list<express> allExpress;

    static package* queryPackage(string pickupCode)
    {
        for(package &p : allPackage)
        {
            if(p.getPickupCode()==pickupCode)
                return &p;
        }
        return nullptr;
    }

    static express* queryExpress(string courierNumber)
    {
        for(express &p : allExpress)
        {
            if(p.getCourierNumber()==courierNumber)
                return &p;
        }
        return nullptr;
    }

    static tuple<int,int> packageStockTaking()
    {
        int outStockNum=0;
        for(package &p : allPackage)
        {
            if(p.getIsOutStock())
                outStockNum++;
        }
        return make_tuple(outStockNum,allPackage.size()-outStockNum);
    }

    static vector<express*> getAllUnpaidExpress()
    {
        vector<express*> result;
        for(express &p : allExpress)
        {
            if(!p.getIsPaid())
                result.push_back(&p);
        }
        return result;
    }

	static void init()
	{
		date::knowday = new date;
	}
};
