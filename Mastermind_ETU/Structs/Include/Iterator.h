#pragma once
#include <Node.h>

template <class T>
class IterAccess;

template <class T>
class Iterator
{
public:	
	Iterator();
	Iterator(Node<T> * _current);
	~Iterator();
	Iterator<T> operator++();
	bool operator!=(const Iterator<T>& iter);
	bool operator==(const Iterator<T>& iter);
	T* operator & ();
	
	friend class IterAccess<T>;
private:	
	Node<T> * current;
};


template <class T>
Iterator<T>::Iterator(Node<T> * _current)
{
	this->current = _current;
}

template <class T>
Iterator<T>::Iterator()
{
	this->current = nullptr;
}

template <class T>
Iterator<T>::~Iterator()
{
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	//return this->current->getContent() != iter;        Non fonctionnel, reste à trouver la bonne logique de comparaison.
	return true;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	//return this->current == iter;						* same
	return true;
}

template <class T>
Iterator<T> Iterator<T>::operator++()
{
	return current->getNext();
}

template <class T>
T* Iterator<T>::operator & ()
{
	return current->getContent();
}

