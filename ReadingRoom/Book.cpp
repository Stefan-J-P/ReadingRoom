#include "Book.h"


// CONSTRUCTOR - non parameter =============================================================
Book::Book()
{
	std::string new_title;
	std::string new_author;

	std::cout << "Enter title of new book" << std::endl;
	std::getline(std::cin, new_title);

	std::cout << "Enter name of the new author" << std::endl;
	std::getline(std::cin, new_author);

	set_title(new_title);
	set_author(new_author);
	set_prolongation_price(0);
}

// CONSTRUCTOR - parameter =================================================================
Book::Book(const std::string& title, const std::string& author, const double prolo_price)
{
	set_title(title);
	set_author(author);
	set_prolongation_price(prolo_price);
}


// GETTERS & SETTERS =======================================================================
std::string Book::get_title() const
{
	return title;
}

void Book::set_title(const std::string& title)
{
	this->title = title;
}

// -----------------------------------------------------------------------------------------
std::string Book::get_author() const
{
	return author;
}

void Book::set_author(const std::string& author)
{
	this->author = author;
}

// -----------------------------------------------------------------------------------------
double Book::get_prolongation_price() const
{
	return prolongation_price;
}

void Book::set_prolongation_price(const double prolo_price)
{
	this->prolongation_price = prolo_price;
}

// COMPARISON OPERATOR =====================================================================
bool Book::operator==(const Book& b) const
{
	return	this->get_author() == b.get_author() &&
		this->get_title() == b.get_title() &&
		this->get_prolongation_price() == b.get_prolongation_price();
}

// =========================================================================================
std::ostream& operator<<(std::ostream& out, const Book& b)
{
	out << b.get_title() << ' '
		<< b.get_author() << ' '
		<< b.get_prolongation_price() << std::endl;
	return out;
}
