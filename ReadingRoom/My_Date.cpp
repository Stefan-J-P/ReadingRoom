#include "My_Date.h"
#include "my_exception.h"

// CONSTRUCTOR TUPLE =============================================================================
my_date::my_date(std::tuple<int, int, int> date_tuple)
{
	if (!is_date_correct(std::get<0>(date_tuple), std::get<1>(date_tuple), std::get<2>(date_tuple)))
	{
		std::string date_str = "";
		date_str += std::to_string(std::get<0>(date_tuple));
		date_str += "-";
		date_str += std::to_string(std::get<1>(date_tuple));
		date_str += "-";
		date_str += std::to_string(std::get<2>(date_tuple));	//poberanie z tuple do string
		throw my_exception("INCORRECT DATE: " + date_str);
	}
	t_ = new tm;
	t_->tm_year = std::get<0>(date_tuple) - 1900;
	t_->tm_mon = std::get<1>(date_tuple) - 1;
	t_->tm_mday = std::get<2>(date_tuple);
}

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


// CONVERT STRING TO INT DATE =========================================================
std::tuple<int, int, int> my_date::convert_str_to_int_date(const std::string& date_str)
{

	if (!std::regex_match(date_str, std::regex(R"(\d{4}-\d{2}-\d{2})")))
	{
		throw my_exception("INCORRECT DATE: " + date_str);
	}

	std::stringstream ss;
	ss.str(date_str);	// insert string to stream

	std::vector<int> v;

	std::string str;
	while (std::getline(ss, str, '-'))	// separate string after '-' and insert to string
	{
		v.emplace_back(std::stoi(str));	// stoi --> string to int , ladujemy do vectora
	}

	if (!is_date_correct(v[0], v[1], v[2]))
	{
		throw my_exception("INCORRECT DATE: " + date_str);
	}
	return std::make_tuple(v[0], v[1], v[2]);
}

// IS LEAP YEAR =========================================================================
bool my_date::is_leap_year(const int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// IS DATE CORRECT ======================================================================
bool my_date::is_date_correct(const int year, const int month, const int day)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return day >= 1 && day <= 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return day >= 1 && day <= 30;
	case 2:
		return (is_leap_year(year) && day >= 1 && day <= 29) || (!is_leap_year(year) && day >= 1 && day <= 28);
	default:
		return false;
	}
}

// CONSTRUCTORS ==============================================================================
my_date::my_date(const int year, const int month, const int day) : my_date(std::make_tuple(year, month, day)) {}
my_date::my_date(const std::string& date_str) : my_date(convert_str_to_int_date(date_str)) {}

// COPY CONSTRUCTOR
my_date::my_date(const my_date& md)
{
	this->t_ = new tm;
	
	t_->tm_isdst = md.t_->tm_isdst;
	t_->tm_hour = md.t_->tm_hour;
	t_->tm_min = md.t_->tm_min;
	t_->tm_sec = md.t_->tm_sec;
	t_->tm_wday = md.t_->tm_wday;
	t_->tm_yday = md.t_->tm_yday;
	t_->tm_sec = md.t_->tm_sec;
	t_->tm_mday = md.t_->tm_mday;
	t_->tm_mon = md.t_->tm_mon;
	t_->tm_year = md.t_->tm_year;

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
	std::string month_str = "";


	if (date.t_->tm_mon <= 8)
	{
		month_str += "0";
	}


	month_str += std::to_string((date.t_->tm_mon + 1));

	return out << date.t_->tm_mday << " / " << month_str << " / " << (date.t_->tm_year + 1900);
}











