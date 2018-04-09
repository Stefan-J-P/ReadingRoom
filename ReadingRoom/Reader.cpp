#include "Reader.h"

Reader::Reader()
{
	std::string fn;
	std::string ln;
	int l_age = 0;


	std::cout << "Enter reader's first name" << std::endl;
	//std::cin >> r1.get_first_name();	pobieranie przez cin, tylko do pierwszej spacji
	std::getline(std::cin, fn);

	std::cout << "Enter reader's last name" << std::endl;
	//std::cin >> r1.get_last_name();
	std::getline(std::cin, ln);

	std::cout << "Enter reader's age" << std::endl;
	std::cin >> l_age;
	std::cin.get();

	set_first_name(fn);
	set_last_name(ln);
	set_age(l_age);
	set_fine(0);
}

// CONSTRUCTOR ============================================================================
Reader::Reader(const std::string& imie, const std::string& nazwisko, const int wiek, const double wysKary)
{
	set_first_name(imie);
	set_last_name(nazwisko);
	set_age(wiek);
	set_fine(wysKary);
}

// GETTERS & SETTERS ======================================================================
std::string Reader::get_first_name() const
{
	return first_name;
}

void Reader::set_first_name(const std::string& f_name)
{
	this->first_name = f_name;
}

// ----------------------------------------------------------------------------------------
std::string Reader::get_last_name() const
{
	return last_name;
}

void Reader::set_last_name(const std::string& l_name)
{
	this->last_name = l_name;
}

// ----------------------------------------------------------------------------------------
int Reader::get_age() const
{
	return age;
}

void Reader::set_age(const int age)
{
	this->age = age;
}

// ----------------------------------------------------------------------------------------
double Reader::get_fine() const
{
	return fine;
}

void Reader::set_fine(const double fine_amount)
{
	this->fine = fine_amount;
}


// =================================================================
bool Reader::operator==(const Reader& r) const
{
	return	this->get_first_name() == r.get_first_name() &&
		this->get_last_name() == r.get_last_name() &&
		this->get_age() == r.get_age() &&
		this->get_fine() == r.get_fine();
}


// OPERATOR COUT =========================================================================
std::ostream& operator<<(std::ostream& out, const Reader& c)
{
	out << c.get_first_name() << ' '
		<< c.get_last_name() << ' '
		<< c.get_age() << ' '
		<< c.get_fine() << std::endl;
	return out;
}
