#include<iostream>
#include<string>
using namespace std;
class Date
{
private:
	int year,month,day;
	static string monthNames[13];
public:
	Date();
	Date::Date(Date& d);
	Date(int,int,int);
	friend ostream& operator<<(ostream& ,const Date&);
	bool operator==(const Date& d) const;
	friend istream& operator>>(istream& , Date&);
	Date& operator=(const Date& );
	Date& operator+(int);
	Date& operator--();
	const Date operator--(int);
	int operator[](int) const;
};