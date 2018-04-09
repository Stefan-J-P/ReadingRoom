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
my_date Borrow::get_borrow_date() const
{
	return borrow_date;
}

// ============================================================
std::map<std::shared_ptr<Reader>, double> Borrow::make_borrow(std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> borrows)
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
Borrow::Borrow(const std::shared_ptr<Book>& book, const std::shared_ptr<Reader>& reader, const my_date& borrow_date)
: book(book), reader(reader), borrow_date(borrow_date) {}

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

// GENERATE DATE ========================================================================
my_date Borrow::generate_date()
{

	std::string current_date="";
	
	do 
	{
		std::cout << "Enter borrow date" << std::endl;
		std::getline(std::cin, current_date);
		
	} while (!std::regex_match(current_date, std::regex(R"(\d{4}-\d{2}-\d{2})")));

	return my_date(current_date);

	/*std::stringstream ss;
	ss.str(current_date);

	std::vector<int> v;
	std::string str_temp;

	while (std::getline(ss, str_temp, '-'))
	{
		v.emplace_back(std::stoi(str_temp));
	}

	return std::make_tuple(v[0], v[1], v[2]);*/
}



// COUT OPERATOR ========================================================================
std::ostream& operator<<(std::ostream& out, const Borrow& b)
{
	out << *b.get_book() << ' '
		<< *b.get_reader() << ' '
		<< b.get_borrow_date() << std::endl;
	return out;
}
