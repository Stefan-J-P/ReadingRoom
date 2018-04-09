#include "My_Date.h"

// PRIVATE - MyDate to time_t ==========================================================
time_t my_date::to_time_t() const
{
	tm* temp_tm1 = new tm;

	time_t now = time(0);
	localtime_s(temp_tm1, &now);

	temp_tm1->tm_isdst = 0;
	temp_tm1->tm_hour = 0;
	temp_tm1->tm_min = 0;
	temp_tm1->tm_sec = 0;
	temp_tm1->tm_wday = 0;
	temp_tm1->tm_yday = 0;
	temp_tm1->tm_mday = 0;
	temp_tm1->tm_mon = 0;
	temp_tm1->tm_year = 0;

	time_t t = std::mktime(temp_tm1);
	return t;
}

// CONSTRUCTOR ==============================================================================
my_date::my_date()
{

}

// CONSTRUCTOR ==============================================================================
my_date::my_date(const int year, const int month, const int day)
{
	t_ = new tm;
	t_->tm_year = year - 1900;
	t_->tm_mon = month - 1;
	t_->tm_mday = day;
}



// OPERATOR - ===========================================================================
double my_date::operator-(const my_date& date) const
{
	time_t d1 = to_time_t();
	time_t d2 = date.to_time_t();

	return (d1 - d2) / sec_per_day;
}


// OPERATOR COUT ========================================================================
std::ostream& operator<<(std::ostream& out, const my_date& date)
{
	return out << date.t_->tm_mday << " / " << (date.t_->tm_mon + 1) << " / " << (date.t_->tm_year + 1900);
}











