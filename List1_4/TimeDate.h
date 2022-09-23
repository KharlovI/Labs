#pragma once
#include<iostream>

namespace Date
{
	struct Time
	{
		int year;
		int month;
		int day;
		int hour;
		int minut;
		int second;
		Time(int year, int month, int day, int hour, int minut, int second);
		Time();
	};

	class DateTime
	{
	private:
		Time date;
	public:
		void SetData(int year, int month, int day, int hour, int minut, int second);

		int GetSec();
		int GetMin();
		int GetHour();
		int GetDay();
		int GetMonth();
		int GetYear();

		bool IsCorrectByGregorianCalendar();
		bool IsLeapYear();

		void PrintExactDate();
		void PrintDateByGregorianCalendar();

		void NormalizeTime();

		//void PrintDayOfWeek();

		DateTime operator + (DateTime& time2)
		{
			DateTime answer{};
			int year = this->date.year + time2.date.year;
			int month = this->date.month + time2.date.month;
			int day = this->date.day + time2.date.day;
			int hour = this->date.hour + time2.date.hour;
			int minut = this->date.minut + time2.date.minut;
			int second = this->date.second + time2.date.second;

			answer.SetData(year,month,day,hour,minut,second);
			answer.NormalizeTime();

			return answer;
		}
	};
}