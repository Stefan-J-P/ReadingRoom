#include "Borrow.h"

// CONSTRUCTOR ============================================================================================================
Borrow::Borrow(const std::shared_ptr<Book>& book, const std::shared_ptr<Reader>& reader, const my_date& borrow_date)
	: book(book), reader(reader), borrow_date(borrow_date) {}


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
my_date Borrow::get_borrow_date() const
{
	return borrow_date;
}

// ADD FINE =============================================================================================================
std::map<std::shared_ptr<Reader>, double> Borrow::add_fine(std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> borrows)
{
	std::map<std::shared_ptr<Reader>, double> m;

	
	for (const auto& b : borrows)
	{
		double fine = 20;
		if (b->get_reader()->get_age() < 18)	// check if reader is under 18 years old
		{
			fine *= 0.5;	// reduce fine by 50%
		}
		if (m.find(b->get_reader()) != m.end())	
		{
			// add fine to each reader
			m[b->get_reader()] += fine;
		}
		else
		{
			m[b->get_reader()] = fine;	// add fine to the reader (if he's over 18)
		}
		b->get_reader()->set_fine(b->get_reader()->get_fine() + fine);
	}
	return m;
}


// GENERATE BORROW LIST ===================================================================================================
std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> Borrow::generate_borrow_list(
	std::unordered_set<std::shared_ptr<Reader>, ReaderHasher, ReaderComparatorShdPtr>& readers,
	std::unordered_set<std::shared_ptr<Book>, BookHasher, BookComparatorShdPtr>& books)
{
	// Generate borrow list from manually created set of readers and books

	std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> borrows;
	std::unordered_set<std::shared_ptr<Book>, BookHasher, BookComparatorShdPtr>::iterator it_books = books.begin();

	for (const auto& reader : readers)
	{
		const std::shared_ptr<Book> s1 = *it_books;

		borrows.insert(std::make_shared<Borrow>(Borrow(std::make_shared<Book>(*s1), std::make_shared<Reader>(*reader), Borrow::generate_date())));
		++it_books;
	}
	return borrows;
}

// GENERATE DATE ========================================================================
my_date Borrow::generate_date()
{
	// Generate date from data entered by user in string format
	std::string current_date = "";
	
	do 
	{
		std::cout << "Enter borrow date" << std::endl;
		std::getline(std::cin, current_date);
		
	} while (!std::regex_match(current_date, std::regex(R"(\d{4}-\d{2}-\d{2})")));

	return my_date(current_date);
}



// COUT OPERATOR ========================================================================
std::ostream& operator<<(std::ostream& out, const Borrow& b)
{
	out << *b.get_book() << ' '
		<< *b.get_reader() << ' '
		<< b.get_borrow_date() << std::endl;
	return out;
}
