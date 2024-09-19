#include <Node.h>
#include <iterator.h>


//Rien à coder dans cette classe, elle est amie (friend) à l'itérateur,
//Elle a donc accès à ses membres privés
template <class T>
#pragma once
class IterAccess
{
	public:
		IterAccess(Iterator<T> iter);
		Node<T> * getCurrentNode() const;
	private:
		Iterator<T> iter;

};

template <class T>
IterAccess<T>::IterAccess(Iterator<T> iter)
{
	this->iter = iter;
}


template <class T>
Node<T> * IterAccess<T>::getCurrentNode() const
{
	return iter.current;
}