#pragma once
#include <string>
using namespace std;

class date
{
private:
	static bool is31(int month)
	{
		return month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12;
	}
	static bool isRun(int year)
	{
		if (year % 4 == 0 && year % 100 != 0)
			return true;
		else if (year % 400 == 0)
			return true;
		else
			return false;
	}

	static int getDayNum(int year, int month)
	{
		if (date::is31(month))
			return 31;
		else
		{
			if (month == 2)
			{
				if (isRun(year))
					return 29;
				else
					return 28;
			}
			else
				return 30;
		}
	}

	int _getDay()
	{
		int dd = knowday->dvalue(*this);
		if (dd % 7 == 5 && dd % 7 == 6)
		{
			this->weekday = 2 + dd % 7 - 7;
		}
		else
			this->weekday = 2 + dd % 7;
		//weekday = (day + 1 + 2 * month + 3 * (month + 1) / 5 + year + (year >> 2) - year / 100 + year / 400) % 7;
		return this->weekday;
	}

	int _getWeek()
	{
		int a = (knowday->dvalue(*this) / 7);
		this->week = (a + 1) % 52;
		return this->week;
	}

public:
	int year;
	int month;
	int day;
	int week;
	int weekday;
	int hour;
	int min;
	date()
	{
		year = 2019;
		month = 1;
		day = 1;
		week = 1;
		weekday = 2;
		hour = 0;
		min = 0;
	}

	date(int year,int month,int day,int hour,int min):year(year),month(month),day(day),hour(hour),min(min)
	{
		this->_getDay();
		this->_getWeek();
		this->hour = hour;
		this->min = min;
	}

	string getDetailedTime()
	{
		return to_string(hour) + to_string(min);
	}

	date(const date &d) : year(d.year), month(d.month), day(d.day){}

	void reSet(int year, int month, int day, int hour, int min)
	{
		this->year = year;
		this->month = month;
		this->day = day;
		this->_getDay();
		this->_getWeek();
		this->hour = hour;
		this->min = min;
	}

	string toString()
	{
		return to_string(year) + "年" + to_string(month) + "月" + to_string(day) + "日" + to_string(hour) + "时" + to_string(min) + "分"
			+ "第" + to_string(week) + "周" +"星期"+ to_string(weekday);
	}

	void nextMonth()
	{
		this->month += 1;
		if (this->month == 13)
		{
			this->year += 1;
			this->month = 1;
		}
	}
	void nextDay()
	{
		this->day += 1;
		int monDay = date::getDayNum(this->year, this->month);
		if (day == monDay + 1)
		{
			this->day = 1;
			this->nextMonth();
		}
	}
	bool isBigger(date &d) //本体比d大返回true
	{
		if (this->year > d.year)
			return true;
		else if (this->year < d.year)
			return false;
		else
		{
			if (this->month > d.month)
				return true;
			else if (this->month < d.month)
				return false;
			else
			{
				return this->day > d.day;
			}
		}
	}
	int dvalue(date &d) //参数是大的
	{
		int result = 0;
		date ct = *this;

		if (ct.month != d.month) //需要追
		{
			result += date::getDayNum(ct.year, ct.month) - ct.day + 1;
			ct.day = 1;
			ct.nextMonth();
		}

		for (; !(ct.year == d.year && ct.month == d.month); ct.nextMonth()) //让ct追d
			result += date::getDayNum(ct.year, ct.month);

		result += d.day - ct.day; //同月补全
		return result;
	}

	int getDay() { return this->weekday; }
	int getWeek() { return this->week; }
	
	static date *knowday;
};

