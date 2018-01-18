#pragma once
#include "Book.h"
#include <map>


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



class Borrow
{
private:
	std::shared_ptr<Book> book;
	std::shared_ptr<Reader> reader;
	std::string borrow_date;

public:
	// CONSTRUCTOR
	Borrow() = delete;
	Borrow(const std::shared_ptr<Book>& book, const std::shared_ptr<Reader>& reader, const std::string& borrow_date);

	static std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> generate_borrow_list(std::unordered_set<std::shared_ptr<Reader>, ReaderHasher, ReaderComparatorShdPtr>& readers,
		std::unordered_set<std::shared_ptr<Book>, BookHasher, BookComparatorShdPtr>& books);

	// GETTERS & SETTERS
	std::shared_ptr<Reader> get_reader() const;

	std::shared_ptr<Book> get_book() const;

	std::string get_borrow_date() const;

	// COUT OPERATOR
	friend std::ostream& operator<< (std::ostream& out, const Borrow& b);

	// METHODS
	static std::map<std::shared_ptr<Reader>, double>createMap(std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> borrows);


};


struct BorrowHasherShdPtr
{
	size_t operator()(const std::shared_ptr<Borrow>& b) const
	{
		ReaderHasher rh;
		BookHasher bh;
		return rh(b->get_reader()) + 31 * bh(b->get_book()) + 31 * std::hash<std::string>()(b->get_borrow_date());
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









