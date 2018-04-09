#pragma once
#include <string>
#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <regex>
#include <sstream>
#include <iomanip>
#include <tuple>


class Reader
{
private:
	std::string first_name;
	std::string last_name;
	int age;
	double fine;

public:
	// CONSTRUCTOR
	Reader();
	Reader(const std::string& first_name, const std::string& last_name, const int age, const double fine);

	// GETTERS & SETTERS
	std::string get_first_name() const;
	void set_first_name(const std::string& first_name);

	std::string get_last_name() const;
	void set_last_name(const std::string& last_name);

	int get_age() const;
	void set_age(const int age);

	double get_fine() const;
	void set_fine(const double fine);

	// OPERATOR COUT
	friend std::ostream& operator<<(std::ostream& out, const Reader& c);

	bool operator==(const Reader& r) const;


	 

};