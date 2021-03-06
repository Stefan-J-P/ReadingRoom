#pragma once
#include "Book.h"
#include <map>
#include "My_Date.h"



struct ReaderHasher
{
	size_t operator()(const std::shared_ptr<Reader>& r) const
	{
		return std::hash<std::string>()(r->get_last_name()) + 31 * std::hash<std::string>()(r->get_first_name());
	}
};

struct ReaderComparatorShdPtr
{
	bool operator()(const std::shared_ptr<Reader>& c1, const std::shared_ptr<Reader>& c2) const
	{
		if (c1->get_first_name() == c2->get_first_name())
		{
			if (c1->get_last_name() == c2->get_last_name())
			{
				return c1->get_age() < c2->get_age();
			}
			return c1->get_last_name() < c2->get_last_name();
		}
		return c1->get_age() < c2->get_age();
	}
};

struct BorrowHasherShdPtr;
struct BorrowComparatorShdPtr;


struct MyDateHasher
{
	size_t operator()(const my_date& my_d) const
	{
		return std::hash<int>()(my_d.get_year()) + 31 * std::hash<int>()(my_d.get_month()) + 31 * std::hash<int>()(my_d.get_day());
	}
};


class Borrow
{
private:
	std::shared_ptr<Book> book;
	std::shared_ptr<Reader> reader;
	my_date borrow_date;


public:
	// CONSTRUCTOR
	Borrow() = default;
	Borrow(const std::shared_ptr<Book>& book, const std::shared_ptr<Reader>& reader, const my_date& borrow_date);

	static std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> generate_borrow_list(std::unordered_set<std::shared_ptr<Reader>, ReaderHasher, ReaderComparatorShdPtr>& readers,
		std::unordered_set<std::shared_ptr<Book>, BookHasher, BookComparatorShdPtr>& books);

	// GETTERS & SETTERS
	std::shared_ptr<Reader> get_reader() const;

	std::shared_ptr<Book> get_book() const;

	my_date get_borrow_date() const;

	// COUT OPERATOR
	friend std::ostream& operator<< (std::ostream& out, const Borrow& b);

	// METHODS
	static std::map<std::shared_ptr<Reader>, double>add_fine(std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> borrows);
	static my_date generate_date();

};


struct BorrowHasherShdPtr
{
	size_t operator()(const std::shared_ptr<Borrow>& b) const
	{
		ReaderHasher rh;
		BookHasher bh;
		MyDateHasher mdh;
		return rh(b->get_reader()) + 31 * bh(b->get_book()) + 31 * mdh(b->get_borrow_date());
	}
};

struct BorrowComparatorShdPtr
{
	bool operator()(const std::shared_ptr<Borrow>& b1, const std::shared_ptr<Borrow>& b2) const
	{
		return	*b1->get_reader() == *b2->get_reader() &&
			*b1->get_book() == *b2->get_book() &&
			b1->get_borrow_date() == b2->get_borrow_date();
	}
};









