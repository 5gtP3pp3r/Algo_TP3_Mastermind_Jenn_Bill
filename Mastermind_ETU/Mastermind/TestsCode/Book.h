#pragma once
#include <string>

using namespace std;

//Utilisez ce Book pour l'EFCS
class Book
{
	public:
		Book(unsigned int _id = -1, string _title = "", unsigned int _year = 0);
		~Book();
		void display() const;
		unsigned int getId();

		bool operator < (Book& book) const;
		bool operator > (Book& book) const;
		bool operator == (Book& book) const;
		bool operator != (Book& book) const;
		

	private:
		unsigned int id;
		string title;
		unsigned int year;
};

