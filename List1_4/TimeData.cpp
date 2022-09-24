#include "TimeDate.h"
Time::Time(int year, int month, int day, int hour, int minut, int second)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minut = minut;
	this->second = second;
}
Time::Time()
{
	this->year = NULL;
	this->month = NULL;
	this->day = NULL;
	this->hour = NULL;
	this->minut = NULL;
	this->second = NULL;
}

void DateTime::SetData(int year, int month, int day, int hour, int minut, int second)
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

int DateTime::GetSec()
{
	return this->date.second;
}
int DateTime::GetMin()
{
	return this->date.minut;
}
int DateTime::GetHour()
{
	return this->date.hour;
}
int DateTime::GetDay()
{
	return this->date.day;
}
int DateTime::GetMonth()
{
	return this->date.month;
}

int DateTime::GetYear()
{
	return this->date.year;
}

bool DateTime::IsBigerOrEqual(DateTime& date2)
{
	if (this->date.year != date2.date.year)
		return this->date.year > date2.date.year;
	else if (this->date.month != date2.date.month)
		return this->date.year > date2.date.month;
	else if (this->date.day != date2.date.day)
		return this->date.day > date2.date.day;
	else if (this->date.hour != date2.date.hour)
		return this->date.hour > date2.date.hour;
	else if (this->date.minut != date2.date.minut)
		return this->date.minut > date2.date.minut;
	else if (this->date.second != date2.date.second)
		return this->date.second > date2.date.second;

	return 1;
}

bool DateTime::IsCorrectByGregorianCalendar()
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
bool DateTime::IsLeapYear()
{
	if (this->date.year % 400 == 0)
		return 1;
	if (this->date.year % 100 == 0)
		return 0;
	if (this->date.year % 4 == 0)
		return 1;

	return 0;
}

void DateTime::PrintExactDate()
{
	std::cout << "Year:  \t" << this->date.year << std::endl;
	std::cout << "Month: \t" << this->date.month << std::endl;
	std::cout << "Day:   \t"  <<this->date.day << std::endl;
	std::cout << "Hour:  \t" << this->date.hour << std::endl;
	std::cout << "Minut: \t" << this->date.minut << std::endl;
	std::cout << "Second:\t" << this->date.second << std::endl;
	std::cout << std::endl;
}
void DateTime::PrintDateByGregorianCalendar()
{
	std::cout <<this->date.day << ".";
	if (this->date.month > 10)
		std::cout << this->date.month << "." << this->date.year << std::endl;
	else
		std::cout << "0" << this->date.month << "." << this->date.year << std::endl;
	std::cout << std::endl;
}


void DateTime::PrintDayOfWeek()
{
	int lastTwoDigits = this->date.year % 100;
	int firstDigits = this->date.year % 10000;

	const int koef = 6 - 2 * (((firstDigits - lastTwoDigits) / 100) % 4);
	const int codeOfYear = (koef + lastTwoDigits + lastTwoDigits / 4) % 7;

	int codeOfMonth;	
	if (this->date.month == 1 || this->date.month == 2)
	{
		codeOfMonth = 1;
	}
	else if (this->date.month == 5)
	{
		codeOfMonth = 2;
	}
	else if (this->date.month == 8)
	{
		codeOfMonth = 3;
	}
	else if (this->date.month == 6)
	{
		codeOfMonth = 5;
	}
	else if (this->date.month == 12 || this->date.month == 9)
	{
		codeOfMonth = 6;
	}
	else if (this->date.month == 4 || this->date.month == 7)
	{
		codeOfMonth = 0;
	}
	else
	{
		codeOfMonth = 4;
	}

	int dayOfWeek = (this->date.day + codeOfMonth + codeOfYear) % 7;
	switch (dayOfWeek)
	{
	case 0:
		std::cout << "Saturday" << std::endl;
		break;
	case 1:
		std::cout << "Sunday" << std::endl;
		break;
	case 2:
		std::cout << "Monday" << std::endl;
		break;
	case 3:
		std::cout << "Tuesday" << std::endl;
		break;
	case 4:
		std::cout << "Wednesday" << std::endl;
		break;
	case 5:
		std::cout << "Thursday" << std::endl;
		break;
	case 6:
		std::cout << "Friday" << std::endl;
		break;
	}
}
void DateTime::NormalizeTime()
{
	while (this->date.second > 59)
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
	if (this->date.month == 2 && this->date.day >= 28)
	{
		if (IsLeapYear())
		{
			if (this->date.day > 28)
			{
				this->date.month++;
				this->date.day -= 28;
				while (true)
				{
					if (this->date.month % 2 == 0 && this->date.month < 8)
					{
						this->date.month++;
						this->date.day -= 30;
					}
					else if (this->date.month % 2 == 0 && this->date.month > 8)
					{
						this->date.month++;
						this->date.day -= 31;
					}
					else if (this->date.month % 2 == 1 && this->date.month < 8)
					{
						this->date.month++;
						this->date.day -= 31;
					}
					else if (this->date.month % 2 == 1 && this->date.month > 8)
					{
						this->date.month++;
						this->date.day -= 30;
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			if (this->date.day > 27)
			{
				this->date.month++;
				this->date.day -= 27;
				while (true)
				{
					if (this->date.month % 2 == 0 && this->date.month < 8)
					{
						this->date.month++;
						this->date.day -= 30;
					}
					else if (this->date.month % 2 == 0 && this->date.month > 8)
					{
						this->date.month++;
						this->date.day -= 31;
					}
					else if (this->date.month % 2 == 1 && this->date.month < 8)
					{
						this->date.month++;
						this->date.day -= 31;
					}
					else if (this->date.month % 2 == 1 && this->date.month > 8)
					{
						this->date.month++;
						this->date.day -= 30;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	while (this->date.month > 12)
	{
		this->date.minut++;
		this->date.second -= 12;
	}
}