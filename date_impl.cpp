#include"date.h"

 static string monthNames[13] = {"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"} ;
Date::Date()
	  {
		  year=2000;
		  month=1;
		  day=1;
	  }
Date::Date(int m,int d,int y)
{
	if(y<=2100&&y>=1800)
	year=y;
	if(d>=1&&d<=30)
	day=d;
	if(m<=12&&m>=1)
	month=m;
	else
	{
		year=2000;
		month=1;
		day=1;
	}
}
Date::Date(Date& d)
{
	 d.year=2000;
	 d.month=1;
	 d.day=1;
}
ostream& operator<<(ostream& osObject, const Date& d)
{
	osObject<<monthNames[d.month]<<" "<<d.day<<" , "<<d.year<<endl;
		return osObject;
}
bool Date:: operator==(const Date& d) const
{
	if(this->day==d.day&&this->month==d.month&&this->year==d.year)
		return true;
	else
		return false;
}
istream& operator>>(istream& isObject,  Date& date)
{
	int d=date.day;
	int m=date.month;
	int y=date.year;
	char a,b;
	cout<<"Enter date in \"day-month-year\" format:"<<endl;
	
	isObject>>d>>a>>m>>b>>y;
	if(d>=1&&d<=30&&a=='-'&&(m>=1&&m<=12)&&b=='-'&&(y>=1000&&y<=9999))
		{
			date.month=m;
			date.day=d;
			date.year=y;
		}
	return isObject;
}
Date& Date:: operator=(const Date& obj)
{
	this->day=obj.day;
	this->month=obj.month;
	this->year=obj.year;
	return *this;
}
Date& Date:: operator+( int i)
{
	if(this->day+i<=30)
	{
	   this->day=this->day+i;
	}
	else if(this->day+i>30)
	{
			this->month+1;
		    if(this->month+1>12)
		   {
			this->year=this->year+1;
			this->month=1;
			this->day=(this->day+i)-30;
		   }

	}
	return *this;
}
Date& Date::operator--()
{
	if(this->day>=2)
		this->day=this->day-1;
	else
	{
		this->day=30;
		this->month=this->month-1;
		if(this->month<=1)
		{
			this->month=12;
			this->year=this->year-1;
		}
	}
	return*this;
}
const Date Date::operator -- (int val) // postfix decrement operator
{
	if (this->day == 1)
	{
		this->day = 30;
		if (this->month == 1)
		{
			this->month = 12;
			this->year=this->year-1;
		}
		else
			this->month=this->month-1;
	}
	else
		this->day=this->day-1;
	
	return *this; 
}
int Date::operator [] (int index) const
{
	if(index==0)
		return this->day;
	else if(index==1)
		return this->month;
    else if(index==2)
		return this->year;
	else
		cout << "index can only be 0, 1 or 2" << endl;
}
