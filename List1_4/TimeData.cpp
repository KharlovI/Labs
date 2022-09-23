#include "TimeDate.h"
Date::Time::Time(int year, int month, int day, int hour, int minut, int second)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minut = minut;
	this->second = second;
}
Date::Time::Time()
{
	this->year = NULL;
	this->month = NULL;
	this->day = NULL;
	this->hour = NULL;
	this->minut = NULL;
	this->second = NULL;
}

void Date::DateTime::SetData(int year, int month, int day, int hour, int minut, int second)
{
	if (year < 0 || month < 0 || day < 0 || hour < 0 || minut < 0 || second < 0)
	{
		std::cout << "incorrect value" << std::endl;
		return;
	}

	this->date.year = year;
	this->date.month = month;
	this->date.day = day;
	this->date.hour = hour;
	this->date.minut = minut;
	this->date.second = second;
}

int Date::DateTime::GetSec()
{
	return this->date.second;
}
int Date::DateTime::GetMin()
{
	return this->date.minut;
}
int Date::DateTime::GetHour()
{
	return this->date.hour;
}
int Date::DateTime::GetDay()
{
	return this->date.day;
}
int Date::DateTime::GetMonth()
{
	return this->date.month;
}

int Date::DateTime::GetYear()
{
	return this->date.year;
}


bool Date::DateTime::IsCorrectByGregorianCalendar()
{
	if (this->date.month > 12)
		return 0;
	if (IsLeapYear())
	{
		if (this->date.month == 2)
		{
			if (this->date.day > 28)
				return 0;
		}
	}
	else
	{
		if (this->date.month == 2)
		{
			if (this->date.day > 27)
				return 0;
		}
	}

	if (this->date.month > 7 && this->date.month % 2 == 0)
	{
		if (this->date.day > 31)
			return 0;
	}
	if (this->date.month > 7 && this->date.month % 2 == 1)
	{
		if (this->date.day > 30)
			return 0;
	}
	if (this->date.month < 7 && this->date.month % 2 == 0)
	{
		if (this->date.day > 30)
			return 0;
	}
	if (this->date.month < 7 && this->date.month % 2 == 1)
	{
		if (this->date.day > 31)
			return 0;
	}

	if (this->date.hour > 23)
		return 0;
	if (this->date.minut > 59)
		return 0;
	if (this->date.second > 59)
		return 0;
	return 1;
}
bool Date::DateTime::IsLeapYear()
{
	if (this->date.year % 400 == 0)
		return 1;
	if (this->date.year % 100 == 0)
		return 0;
	if (this->date.year % 4 == 0)
		return 1;

	return 0;
}

void Date::DateTime::PrintExactDate()
{
	std::cout << "Year:  \t" << this->date.year << std::endl;
	std::cout << "Month: \t" << this->date.month << std::endl;
	std::cout << "Day:   \t"  <<this->date.day << std::endl;
	std::cout << "Hour:  \t" << this->date.hour << std::endl;
	std::cout << "Minut: \t" << this->date.minut << std::endl;
	std::cout << "Second:\t" << this->date.second << std::endl;
	std::cout << std::endl;
}
void Date::DateTime::PrintDateByGregorianCalendar()
{
	std::cout <<this->date.day << ".";
	if (this->date.month > 10)
		std::cout << this->date.month << "." << this->date.year << std::endl;
	else
		std::cout << "0" << this->date.month << "." << this->date.year << std::endl;
	std::cout << std::endl;
}

void Date::DateTime::NormalizeTime()
{
	while(this->date.second > 59)
	{
		this->date.minut++;
		this->date.second -= 60;
	}
	while (this->date.minut > 59)
	{
		this->date.hour++;
		this->date.minut -= 60;
	}
	while (this->date.hour > 23)
	{
		this->date.day++;
		this->date.hour -= 24;
	}
	if (this->date.month == 2)
	{
		if (IsLeapYear())
		{
			while (this->date.day > 28)
			{
				this->date.month++;
				this->date.day -= 28;
			}
		}
		else
		{
			while(this->date.day > 27)
			{
				this->date.month++;
				this->date.day -= 27;
			}
		}
	}
	else if (this->date.month % 2 == 0 && this->date.month < 8)
	{
		while (this->date.day > 30)
		{
			this->date.month++;
			this->date.day -= 30;
		}
	}
	else if(this->date.month % 2 == 1 && this->date.month > 8)
	{
		while (this->date.day > 30)
		{
			this->date.month++;
			this->date.day -= 30;
		}
	}
	else if(this->date.month % 2 == 0 && this->date.month > 8)
	{
		while (this->date.day > 31)
		{
			this->date.month++;
			this->date.day -= 31;
		}
	}
	else if (this->date.month % 2 == 1 && this->date.month < 8)
	{
		while (this->date.day > 31)
		{
			this->date.month++;
			this->date.day -= 31;
		}
	}
	while (this->date.month > 12)
	{
		this->date.year++;
		this->date.month -= 12;
	}
}

//void Date::DateTime::PrintDayOfWeek()
//{
//	const int koef = 
//	int codeOfYear = (6 + 5*(this->date.year % 100))
//}