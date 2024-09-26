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
	;
}

template <class T>
Iterator<T>::~Iterator()
{
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return this->current != iter.current;      
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return this->current == iter.current;						
}

template <class T>
Iterator<T> Iterator<T>::operator++()
{
	if (this->current == nullptr)
	{
		return NULL;
	}

	if (this->current != nullptr) 
	{
		this->current = this->current->getNext(); 
	}
	return Iterator<T>(this->current);
}

template <class T>
T* Iterator<T>::operator & ()
{
	if (this->current == NULL) 
	{
		return NULL;
	}
	return this->current->getContent();
}

