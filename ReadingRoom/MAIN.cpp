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
Zaimplementuj map�, w kt�rej jako klucz umie�cisz czytelnika, 
a jako warto�� wysoko�� kary, kt�r� czytelnik ma zap�aci�. 

Nast�pnie zaimplementuj metod�, kt�ra pobierze aktualn� dat� i na podstawie prostego za�o�enia, 
�e po 2 tygodniach od wypo�yczenia ka�dy kolejny dzie� to 5 z� kary, 
b�dzie ustawia� w mapie warto�� kary, kt�r� czytelnik musi zap�aci�. 
Dla czytelnik�w poni�ej 18 roku �ycia warto�� kary jest zmniejszana o 50%. 

Pami�taj, �e wypo�yczona mo�e by� tylko jedna ksi��ka, a jeden czytelnik mo�e wypo�yczy� wiele ksi��ek. 
Na koniec z mapy wypisz wszystkich czytelnik�w, kt�rzy musz� zap�aci� kar� oraz wysoko�� tej kary.


*/
















