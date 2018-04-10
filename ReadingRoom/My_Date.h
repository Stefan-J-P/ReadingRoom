#pragma once

#include "Header.h"



class my_date
{
private:
	tm* t_;
	static const int sec_per_day = 60 * 60 * 24;

	explicit my_date(std::tuple<int, int, int> date_tuple);
	
	time_t to_time_t() const;
	static std::tuple<int, int, int> convert_str_to_int_date(const std::string& date_str);
	static bool is_leap_year(const int year);
	static bool is_date_correct(const int year, const int month, const int day);

public:
	my_date(const int year, const int month, const int day);
	explicit my_date(const std::string& date_str);
	my_date(const my_date& md);

	int get_year() const;
	int get_month() const;
	int get_day() const;

	double operator-(const my_date& date) const;
	bool operator==(const my_date& my_d) const;

	friend std::ostream& operator<<(std::ostream& out, const my_date& date);

};