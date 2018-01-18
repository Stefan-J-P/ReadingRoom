#include "Borrow.h"

int main()
{
	Reader c1;
	Book k1;

	// COLLECTION READER
	std::unordered_set<std::shared_ptr<Reader>, ReaderHasher, ReaderComparatorShdPtr> readers = {
		std::make_shared<Reader>(Reader("Michael", "Jordan", 33, 0.0)),
		std::make_shared<Reader>(Reader("Donald", "Trump", 58, 0.0)),
		std::make_shared<Reader>(Reader("Wladimir", "Putin", 60, 0.0)),
		std::make_shared<Reader>(Reader("Lindsey", "Lohan", 31, 0.0)),
		std::make_shared<Reader>(Reader("Kim", "Kardashian", 35, 0.0)),
		std::make_shared<Reader>(Reader("Justin", "Timberlake", 60, 0.0)),
		std::make_shared<Reader>(Reader("Ingvild", "Deila", 50, 0.0))
	};

	// COLLECTION BOOK
	std::unordered_set<std::shared_ptr<Book>, BookHasher, BookComparatorShdPtr> books = {
		std::make_shared<Book>(Book("Little Fires", "Celeste Ng", 20)),
		std::make_shared<Book>(Book("Into the water", "Paula Hawkins", 20)),
		std::make_shared<Book>(Book("The hate you give", "Angie Thomas", 20)),
		std::make_shared<Book>(Book("Turtles all the way down", "John Green", 20)),
		std::make_shared<Book>(Book("Before we were yours", "Lisa Wingate", 20)),
		std::make_shared<Book>(Book("Eleanor Oliphant is completely fine", "Gail Honeyman", 20)),
		std::make_shared<Book>(Book("A court of wings and rain", "Sarah J Maas", 20)),
		std::make_shared<Book>(Book("Norse mythology", "Molier", 20)),
		std::make_shared<Book>(Book("Chlopi", "Neil Gaiman", 20)),
		std::make_shared<Book>(Book("Origin", "Dan Brown", 20))
	};

	// COLLECTION BORROW
	std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> borrows
		= Borrow::generate_borrow_list(readers, books);

	for (const auto& b : borrows)
	{
		std::cout << *b << std::endl;
	}

	std::map<std::shared_ptr<Reader>, double> mm = Borrow::createMap(borrows);

	for (const auto& x : mm)
	{
		std::cout << *x.first << ' ' << x.second << std::endl;
	}




	std::cin.get();
	return 0;
}

