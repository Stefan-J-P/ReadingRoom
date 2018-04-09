#pragma once
#include "Borrow.h"
#include <ctime>

class my_date
{
private:
	tm* t_;
	static const int sec_per_day = 60 * 60 * 24;

	time_t to_time_t() const;

public:
	my_date();
	my_date(const int year, const int month, const int day);
	explicit my_date(const std::string& date_str);

	double operator-(const my_date& date) const;

	friend std::ostream& operator<<(std::ostream& out, const my_date& date);

};