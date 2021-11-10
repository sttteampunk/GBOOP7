#include <iostream>

using namespace std;

void obzac()
{
	cout << "\n\n//==============================================================================//\n\n";
}

class Date
{
private:
	int day, month, year;
public:
	Date() : day(0), month(0), year(0) {}
	Date(int inputDay, int inputMonth, int inputYear) : day(inputDay), month(inputMonth), year(inputYear) {}

	int getDay()
	{
		return day;
	}

	int getMonth()
	{
		return month;
	}

	int getYear()
	{
		return year;
	}

	friend ostream& operator<<(ostream& out, const Date& date);
};

ostream& operator<<(ostream& out, const Date& date)
{
	out << "\n" << date.day << "/" << date.month << "/" << date.year;
	return out;
}

Date findLaterDate(const unique_ptr<Date>& date1, const unique_ptr<Date>& date2)
{
	if (date1->getYear() > date2->getYear()) return *date1;
	else if (date1->getYear() < date2->getYear()) return *date2;

	if (date1->getMonth() > date2->getMonth()) return *date1;
	else if (date1->getMonth() < date2->getMonth()) return *date2;

	if (date1->getDay() > date2->getDay()) return *date1;
	else if (date1->getDay() < date2->getDay()) return *date2;

	return *date1;
}

void swapDates(unique_ptr<Date>& date1, unique_ptr<Date>& date2)
{
	swap(date1, date2);
}


int main()
{
	{
		//tsk1
		obzac();
		unique_ptr<Date> today(new Date(10, 11, 2021));
		cout << "\n" << today->getDay() << ".0" << today->getMonth() << "." << today->getYear();
		cout << *today;
		unique_ptr<Date> date(new Date());
		swap(today, date);
		cout << *date;
		today = nullptr;
		if (date == nullptr) cout << "\nPointer \"date\" is null";
		else cout << "\nPointer \"date\" is not null";
		if (today == nullptr) cout << "\nPointer \"today\" is null";
		else cout << "\nPointer \"today\" is not null";
		obzac();
	}

	{
		//task2
		obzac();
		unique_ptr<Date> date1(new Date(17, 3, 19));
		unique_ptr<Date> date2(new Date(16, 3, 19));
		cout << "\n\nLater date is: " << findLaterDate(date1, date2);
		cout << "\n\nOld dates:" << *date1;
		cout << *date2;
		swapDates(date1, date2);
		cout << "\nNew dates (swapped):" << *date1;
		cout << *date2;
		obzac();
	}
	return 0;
}