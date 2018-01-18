#include "Reader.h"

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

void Reader::set_first_name(const std::string& imie)
{
	this->first_name = imie;
}

// ----------------------------------------------------------------------------------------
std::string Reader::get_last_name() const
{
	return last_name;
}

void Reader::set_last_name(const std::string& nazwisko)
{
	this->last_name = nazwisko;
}

// ----------------------------------------------------------------------------------------
int Reader::get_age() const
{
	return age;
}

void Reader::set_age(const int wiek)
{
	this->age = wiek;
}

// ----------------------------------------------------------------------------------------
double Reader::get_fine() const
{
	return fine;
}

void Reader::set_fine(const double wysKary)
{
	this->fine = wysKary;
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
