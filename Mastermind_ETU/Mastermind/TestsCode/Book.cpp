#include "stdafx.h"
#include <iostream>
#include "Book.h"

//Utilisez ce Book pour l'EFCS
Book::Book(unsigned int _id, string _title, unsigned int _year)
	: id(_id), title(_title), year(_year)
{

}

Book::~Book()
{
}

unsigned int Book::getId()
{
	return this->id;
}

bool Book::operator < (Book& book) const
{
	return this->id < book.id;
}

bool Book::operator > (Book& book) const
{
	return this->id > book.id;
}

bool Book::operator == (Book& book) const
{
	return this->id == book.id;
}

bool Book::operator != (Book& book) const
{
	return this->id != book.id;
}


void Book::display() const
{
		cout << "Id : " << this->id << endl;
		cout << "Title : " << this->title << endl;
		cout << "Year : " << this->year << endl;
		cout << "*****" << endl;
}