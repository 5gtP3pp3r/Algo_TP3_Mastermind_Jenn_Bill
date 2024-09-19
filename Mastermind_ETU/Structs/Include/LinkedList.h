#pragma once
#include "Node.h"
#include <DataStructure.h>
#include <Iterator.h>



template <class T>
class LinkedList : public DataStructure<T>
{
public:
	LinkedList();
	~LinkedList();
	bool add(T* content);
	bool remove(T * content);
	void display() const override;
	Iterator<T> begin() const;
	Iterator<T> end() const;
};

template <class T>
LinkedList<T>::LinkedList()
{
	//TODO: Votre code de liste
}

template <class T>
LinkedList<T>::~LinkedList()
{
	//TODO: Votre code de liste
}


template <class T>
Iterator<T> LinkedList<T>::begin() const
{
	//Donné
	return Iterator<T>(this->getFirstNode());
}

template <class T>
Iterator<T> LinkedList<T>::end() const
{
	//TODO: return temporaire, complétez
	Iterator<T> iter;
	return iter;
}


template <class T>
bool LinkedList<T>::add(T* _content)
{
	//TODO: Votre code de liste
	return false;
}

template <class T>
bool LinkedList<T>::remove(T* _content)
{
	//TODO: Votre code de liste
	return false;
}

template <class T>
void LinkedList<T>::display() const
{
	//TODO: Votre code de liste
}

