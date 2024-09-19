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
	//TODO: Compléter
}

template <class T>
Iterator<T>::Iterator()
{
	//TODO: Compléter, placer l'itérateur sur ... rien
}

template <class T>
Iterator<T>::~Iterator()
{
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	//TODO: Compléter
	
	//Code temporaire pour la compilation
	return false;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	//TODO: Compléter
	
	//Code temporaire pour la compilation
	return false;
}

template <class T>
Iterator<T> Iterator<T>::operator++()
{
	//TODO: Compléter
	
	//Code temporaire pour la compilation
	Iterator<T> iter;
	return iter;
}

template <class T>
T* Iterator<T>::operator & ()
{
	//TODO: Compléter
	
	//Code temporaire pour la compilation
	return NULL;
}

