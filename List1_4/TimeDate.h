#pragma once
#include<iostream>
#include <ctime>

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
		bool IsBigerOrEqual(DateTime& time2);

		void PrintExactDate();
		void PrintDateByGregorianCalendar();

		void NormalizeTime();
		void PrintDayOfWeek();

		DateTime operator + (DateTime& time2)
		{
			time2.NormalizeTime();

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
		DateTime operator - (DateTime& time2)
		{
			this->NormalizeTime();
			time2.NormalizeTime();
			
			DateTime answer{};
			int year;
			int month;
			int day;
			int hour;
			int minut;
			int second;
			
			if (this->IsBigerOrEqual(time2))
			{
				if (this->date.second >= time2.date.second)
				{
					second = this->date.second - time2.date.second;
				}
				else
				{
					this->date.minut--;
					this->date.second += 60;
					second = this->date.second - time2.date.second;
				}

				if (this->date.minut >= time2.date.minut)
				{
					minut = this->date.minut - time2.date.minut;
				}
				else
				{
					this->date.hour--;
					this->date.minut += 60;
					minut = this->date.minut - time2.date.minut;
				}

				if (this->date.hour >= time2.date.hour)
				{
					hour = this->date.hour - time2.date.hour;
				}
				else
				{
					this->date.day--;
					this->date.hour += 24;
					hour = this->date.hour - time2.date.hour;
				}

				if (this->date.day >= time2.date.day)
				{
					day = this->date.day - time2.date.day;
				}
				else
				{
					if (this->date.month == 2)
					{
						if (this->IsLeapYear())
						{
							this->date.month--;
							this->date.day += 28;
						}
						else
						{
							this->date.month--;
							this->date.day += 27;
						}
						day = this->date.day - time2.date.day;
					}
					else if (this->date.month % 2 == 0 && this->date.month < 8)
					{
						this->date.month--;
						this->date.day += 30;
						day = this->date.day - time2.date.day;
					}
					else if (this->date.month % 2 == 0 && this->date.month >= 8)
					{
						this->date.month--;
						this->date.day += 31;
						day = this->date.day - time2.date.day;
					}
					else if (this->date.month % 2 == 1 && this->date.month < 8)
					{
						this->date.month--;
						this->date.day += 31;
						day = this->date.day - time2.date.day;
					}
					else
					{
						this->date.month--;
						this->date.day += 30;
						day = this->date.day - time2.date.day;
					}
				}

				if (this->date.month >= time2.date.month)
				{
					month = this->date.month - time2.date.month;
				}
				else
				{
					this->date.year--;
					this->date.month += 12;
					month = this->date.month - time2.date.month;
				}

				year = this->date.year - time2.date.year;
				this->NormalizeTime();
			}
			else
			{
				if (time2.date.second >= this->date.second)
				{
					second = time2.date.second - this->date.second;
				}
				else
				{
					time2.date.minut--;
					time2.date.second += 60;
					second = time2.date.second - this->date.second;
				}

				if (time2.date.minut >= this->date.minut)
				{
					minut = time2.date.minut - this->date.minut;
				}
				else
				{
					time2.date.hour--;
					time2.date.minut += 60;
					minut = time2.date.minut - this->date.minut;
				}

				if (time2.date.hour >= this->date.hour)
				{
					hour = time2.date.hour - this->date.hour;
				}
				else
				{
					time2.date.day--;
					time2.date.hour += 24;
					hour = time2.date.hour - this->date.hour;
				}

				if (time2.date.day >= this->date.day)
				{
					day = time2.date.day - this->date.day;
				}
				else
				{
					if (time2.date.month == 2)
					{
						if (time2.IsLeapYear())
						{
							time2.date.month--;
							time2.date.day += 28;
						}
						else
						{
							time2.date.month--;
							time2.date.day += 27;
						}
						day = time2.date.day - this->date.day;
					}
					else if (time2.date.month % 2 == 0 && time2.date.month < 8)
					{
						time2.date.month--;
						time2.date.day += 30;
						day = time2.date.day - this->date.day;
					}
					else if (time2.date.month % 2 == 0 && time2.date.month >= 8)
					{
						time2.date.month--;
						time2.date.day += 31;
						day = time2.date.day - this->date.day;
					}
					else if (time2.date.month % 2 == 1 && time2.date.month < 8)
					{
						time2.date.month--;
						time2.date.day += 31;
						day = time2.date.day - this->date.day;
					}
					else
					{
						time2.date.month--;
						time2.date.day += 30;
						day = time2.date.day - this->date.day;
					}
				}

				if (time2.date.month >= this->date.month)
				{
					month = time2.date.month - this->date.month;
				}
				else
				{
					time2.date.year--;
					time2.date.month += 12;
					month = time2.date.month - this->date.month;
				}
				year = time2.date.year - this->date.year;

				time2.NormalizeTime();
			}
			
			answer.SetData(year, month, day, hour, minut, second);
			answer.NormalizeTime();

			return answer;
		}
		DateTime operator * (DateTime& time2)
		{
			DateTime answer{};
			int year = this->date.year + time2.date.year;
			int month = this->date.month * time2.date.month;
			int day = this->date.day * time2.date.day;
			int hour = this->date.hour * time2.date.hour;
			int minut = this->date.minut * time2.date.minut;
			int second = this->date.second * time2.date.second;

			answer.SetData(year, month, day, hour, minut, second);
			answer.NormalizeTime();
			return answer;
		}
		DateTime& operator = (int randValue)
		{
			this->date.year = rand()%7/5 * rand()%2023;
			this->date.month = rand() % 7 / 5 * rand() % 13;
			this->date.day = rand() % 7 / 5 * rand() % 32;
			this->date.hour = rand() % 7 / 5 * rand() % 24;
			this->date.minut = rand() % 7 / 5 * rand() % 60;
			this->date.second = rand() % 7 / 5 * rand() % 60;

			return *this;
		}
		inline friend std::ostream& operator << (std::ostream& out, const DateTime& date);
		inline friend std::istream& operator >> (std::istream& in, DateTime& date);
		DateTime& operator +=(DateTime time1)
		{
			this->date.year = time1.date.year;
			this->date.month = time1.date.month;
			this->date.day = time1.date.day;
			this->date.hour = time1.date.hour;
			this->date.minut = time1.date.minut;
			this->date.second = time1.date.second;
			
			return *this;
		}

		bool operator ==(DateTime time1)
		{
			if (this->date.year != time1.date.year)
				return 0;
			if (this->date.month != time1.date.year)
				return 0;
			if (this->date.day != time1.date.day)
				return 0;
			if (this->date.hour!= time1.date.hour)
				return 0;
			if (this->date.minut != time1.date.minut)
				return 0;
			if (this->date.second!= time1.date.second)
				return 0;

			return 1;
		}
		bool operator < (DateTime time1)
		{
			if (this->date.year >= time1.date.year)
				return 0;
			if (this->date.month >= time1.date.year)
				return 0;
			if (this->date.day >= time1.date.day)
				return 0;
			if (this->date.hour >= time1.date.hour)
				return 0;
			if (this->date.minut >= time1.date.minut)
				return 0;
			if (this->date.second >= time1.date.second)
				return 0;

			return 1;
		}
		bool operator > (DateTime time1)
		{
			if (this->date.year <= time1.date.year)
				return 0;
			if (this->date.month <= time1.date.year)
				return 0;
			if (this->date.day <= time1.date.day)
				return 0;
			if (this->date.hour <= time1.date.hour)
				return 0;
			if (this->date.minut <= time1.date.minut)
				return 0;
			if (this->date.second <= time1.date.second)
				return 0;

			return 1;
		}

		float DistanceToDate(DateTime& time2)
		{
			DateTime temp = this->operator-(time2);
			float answer;
			int choise;

			temp.PrintExactDate();
			std::cout << std::endl;

			std::cout << "Chouse metric: " << "1)Year  2)Month  3)Day" << std::endl;
			std::cin >> choise;
			while (choise > 3 || choise < 1)
			{
				std::cout << "Your choise is incorrect, please, chouse from 1 to 3" << std::endl;
				std::cin >> choise;
			}

			switch (choise)
			{
			case 1:
				answer = (temp.date.year + (float)(temp.date.month / 12.0) + (float)(temp.date.day / 365.0));
				return answer;
			case 2:
				answer = (float)(temp.date.year * 12 + temp.date.month + (float)(temp.date.day / 30.0));
				return answer;
			case 3:
				answer = (float)((temp.date.year * 365.0) + (temp.date.month * 30.0) + temp.date.day);
				return answer;
			default:
				break;
			}
		}
	};
std::ostream& operator << (std::ostream& out, const DateTime& date)
{
	if (date.date.month > 9)
	{
		if (date.date.day > 9)
			out << date.date.day << "." << date.date.month << "." << date.date.year;
		else
			out << "0"<<date.date.day << "." << date.date.month << "." << date.date.year;
	}
	else
	{
		if (date.date.day > 9)
			out << date.date.day << ".0" << date.date.month << "." << date.date.year;
		else
			out << "0" << date.date.day << ".0" << date.date.month << "." << date.date.year;
	}
	return out;
}	
std::istream& operator >> (std::istream& in,  DateTime& date)
{
	in >> date.date.year;
	in >> date.date.month;
	in >> date.date.day;
	in >> date.date.hour;
	in >> date.date.minut;
	in >> date.date.second;

	return in;
}