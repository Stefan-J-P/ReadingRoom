#include "Borrow.h"

// GETTERS & SETTERS =======================================================================================================
std::shared_ptr<Reader> Borrow::get_reader() const
{
	return reader;
}
// -------------------------------------------------------------
std::shared_ptr<Book> Borrow::get_book() const
{
	return book;
}
// -------------------------------------------------------------
std::string Borrow::get_borrow_date() const
{
	return borrow_date;
}

// ============================================================
std::map<std::shared_ptr<Reader>, double> Borrow::createMap(std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> borrows)
{
	std::map<std::shared_ptr<Reader>, double> m;

	for (const auto& b : borrows)
	{
		double fine = rand() % 10 + 1;
		if (b->get_reader()->get_age() < 18)
		{
			fine *= 0.5; //fine = fine * 0.5;
		}
		if (m.find(b->get_reader()) != m.end())
		{
			
			// add fine to each reader
			m[b->get_reader()] += fine;
		}
		else
		{
			m[b->get_reader()] = fine;
		}
		b->get_reader()->set_fine(b->get_reader()->get_fine() + fine);
	}
	return m;
}

// -------------------------------------------------------------

// CONSTRUCTOR ============================================================================================================
Borrow::Borrow(const std::shared_ptr<Book>& book, const std::shared_ptr<Reader>& reader, const std::string& borrow_date)
{
	this->book = book;
	this->reader = reader;
	this->borrow_date = borrow_date;
}

// GENERATE BORROW LIST ===================================================================================================
std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> Borrow::generate_borrow_list(
	std::unordered_set<std::shared_ptr<Reader>, ReaderHasher, ReaderComparatorShdPtr>& readers,
	std::unordered_set<std::shared_ptr<Book>, BookHasher, BookComparatorShdPtr>& books)
{

	std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> borrows;

	std::unordered_set<std::shared_ptr<Book>, BookHasher, BookComparatorShdPtr>::iterator it_books = books.begin();

	for (const auto& reader : readers)
	{
		const std::shared_ptr<Book> s1 = *it_books;
		borrows.insert(std::make_shared<Borrow>(
			Borrow(
				std::make_shared<Book>(*s1),
				std::make_shared<Reader>(*reader),
				"2017-01-02"
			)
			)
		);
		++it_books;
	}
	return borrows;
}

// COUT OPERATOR ========================================================================
std::ostream& operator<<(std::ostream& out, const Borrow& b)
{
	out << *b.get_book() << ' '
		<< *b.get_reader() << ' '
		<< b.get_borrow_date() << std::endl;
	return out;
}
