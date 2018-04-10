#pragma once
#include "Reader.h"

//struct BookComparatorShdPtr;


class Book
{
private:
	std::string title;
	std::string author;
	double prolongation_price;
public:
	// CONSTRUCTOR
	Book();
	Book(const std::string& title, const std::string& author, const double prolo_price);

	// GETTERS & SETTERS
	std::string get_title() const;
	void set_title(const std::string& title);

	std::string get_author() const;
	void set_author(const std::string& author);

	double get_prolongation_price() const;
	void set_prolongation_price(const double prolo_price);

	// OPERATOR COUT
	friend std::ostream& operator<< (std::ostream& out, const Book& k);

	bool operator==(const Book& b) const;

};


struct BookHasher
{
	size_t operator()(const std::shared_ptr<Book>& b) const
	{
		return std::hash<std::string>()(b->get_title()) + std::hash<std::string>()(b->get_author());
	}

};



struct BookComparatorShdPtr
{
	bool operator()(const std::shared_ptr<Book>& b1, const std::shared_ptr<Book>& b2) const
	{
		return	b1->get_title() == b2->get_title() &&
			b1->get_author() == b2->get_author() &&
			b1->get_title() == b2->get_title();
	}
};


