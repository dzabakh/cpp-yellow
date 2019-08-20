#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>
using namespace std;

bool operator==(const Date& i_lhs, const Date& i_rhs){
	return i_lhs.year == i_rhs.year && i_lhs.month == i_rhs.month && i_lhs.day == i_rhs.day;
}

bool operator==(const Time& i_lhs, const Time& i_rhs){
	return i_lhs.hours == i_rhs.hours && i_lhs.minutes == i_rhs.minutes;
}

bool operator<(const Date& i_lhs, const Date& i_rhs){
	if (i_lhs.year == i_rhs.year){
		if (i_lhs.month == i_rhs.month){
			if (i_lhs.day == i_rhs.day){
				return false;
			}
			else return (i_lhs.day < i_rhs.day) ? true : false;
		}
		else return (i_lhs.month < i_rhs.month) ? true: false;
	}
	else return (i_lhs.year < i_rhs.year) ? true : false;
}

bool operator<(const Time& i_lhs, const Time& i_rhs){
	if (i_lhs.hours == i_rhs.hours){
		if (i_lhs.minutes == i_rhs.minutes){
			return false;
		}
		else return (i_lhs.minutes < i_rhs.minutes) ? true: false;
	}
	else return (i_lhs.hours < i_rhs.hours) ? true : false;
}

ostream& operator<<(ostream& out, const Time& i_time){
	out << i_time.hours << ":" << i_time.minutes;
	return out;
}

ostream& operator<<(ostream& out, const Date& i_date){
	out << i_date.year << "." << i_date.month << "." << i_date.day;
	return out;
}

#define SORT_BY(field) [](const AirlineTicket& lhs, const AirlineTicket& rhs){ return lhs.field < rhs.field;}