#pragma once

class Date {
public:
	Date(int year, int month, int day) :
		year(year), month(month), day(day)
	{

	}

	friend class AccessDate;

private:
	int year;
	int month;
	int day;
};
