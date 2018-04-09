#include "Borrow.h"

int main()
{
/*
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
		std::make_shared<Book>(Book("Verdens beste land", "Nina Witoszek", 20)),
		std::make_shared<Book>(Book("Origin", "Dan Brown", 20))
	};

	// COLLECTION BORROW
	std::unordered_set<std::shared_ptr<Borrow>, BorrowHasherShdPtr, BorrowComparatorShdPtr> borrows
		= Borrow::generate_borrow_list(readers, books);

	for (const auto& b : borrows)
	{
		std::cout << *b << std::endl;
	}

	std::map<std::shared_ptr<Reader>, double> mm = Borrow::make_borrow(borrows);

	for (const auto& x : mm)
	{
		std::cout << *x.first << ' ' << x.second << std::endl;
	}*/

	// DATE & TIME ====================================================================


	
//	std::tuple<int, int, int> date = Borrow::generate_date();
//	std::cout << std::get<0>(date) << '/' << std::get<1>(date) << '/' << std::get<2>(date) << std::endl;


	
	Reader r1;

	//r1.add_new_reader();

	std::cout << r1 << std::endl;

	//my_date d1(2018, 03, 13);

	//std::cout << Borrow::generate_date();



	std::cin.get();
	return 0;
}






/*
Zaimplementuj mapê, w której jako klucz umieœcisz czytelnika, 
a jako wartoœæ wysokoœæ kary, któr¹ czytelnik ma zap³aciæ. 

Nastêpnie zaimplementuj metodê, która pobierze aktualn¹ datê i na podstawie prostego za³o¿enia, 
¿e po 2 tygodniach od wypo¿yczenia ka¿dy kolejny dzieñ to 5 z³ kary, 
bêdzie ustawiaæ w mapie wartoœæ kary, któr¹ czytelnik musi zap³aciæ. 
Dla czytelników poni¿ej 18 roku ¿ycia wartoœæ kary jest zmniejszana o 50%. 

Pamiêtaj, ¿e wypo¿yczona mo¿e byæ tylko jedna ksi¹¿ka, a jeden czytelnik mo¿e wypo¿yczyæ wiele ksi¹¿ek. 
Na koniec z mapy wypisz wszystkich czytelników, którzy musz¹ zap³aciæ karê oraz wysokoœæ tej kary.


*/
















