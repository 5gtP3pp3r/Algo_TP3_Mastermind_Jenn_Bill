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
	;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* currentNode = this->getFirstNode();
	Node<T>* nextNode = nullptr;
	while (currentNode != nullptr)
	{
		nextNode = currentNode->getNext();
		delete currentNode;
		currentNode = nextNode;
	}
}


template <class T>
Iterator<T> LinkedList<T>::begin() const
{
	return Iterator<T>(this->getFirstNode());
}

template <class T>
Iterator<T> LinkedList<T>::end() const
{
	Node<T>* currentNode = this->getFirstNode();
	Iterator<T> iter;
	While(currentNode != nullptr)
	{
		if (currentNode->getNext() == nullptr)
		{
			iter = currentNode;
		}
	}
	return iter;
}


template <class T>
bool LinkedList<T>::add(T* _content)
{
	if (content == nullptr)
	{
		return false;
	}

    Node<T>* currentNode = this->getFirstNode();
	Node<T>* newNode = new Node<T>;
	newNode->setContent(content);
	newNode->setNext(nullptr);
	
	if (currentNode == nullptr || *content < *currentNode->getContent())
	{
		newNode->setNext(currentNode);
		this->setFirstNode(newNode);

		return true;
	}

	Node<T>* nextNode = nullptr; 
	while (currentNode != nullptr)
	{
		if (*content == *currentNode->getContent())
		{ 
			delete newNode;
			return false;
		}

		nextNode = currentNode->getNext();												
		if (nextNode == nullptr || *content < *nextNode->getContent())
		{			
			newNode->setNext(nextNode);
			currentNode->setNext(newNode);

			return true;
		}
		currentNode = nextNode;
	}
	delete newNode;
	return false;
}

template <class T>
bool LinkedList<T>::remove(T* _content)
{
	Node<T>* currentNode = this->getFirstNode();
	if (currentNode == nullptr || content == nullptr)
	{
		return false;
	}

	if (*content == *currentNode->getContent())
	{
		Node<T>* nextNode = currentNode->getNext();		 
		this->setFirstNode(nextNode);

		delete currentNode;		
		return true;
	}

	Node<T>* nextNode = nullptr;
	while (currentNode->getNext() != nullptr)
	{
		nextNode = currentNode->getNext();
		if (*content == *nextNode->getContent())
		{
			currentNode->setNext(nextNode->getNext());

			delete nextNode;
			return true;
		}
		currentNode = nextNode;
	}
	return false;
}

template <class T>
void LinkedList<T>::display() const
{
	Node<T>* currentNode = this->getFirstNode();
	if (!currentNode)
	{
		cout << "La liste est vide" << endl << endl;
	}
	while (currentNode != nullptr)
	{
		currentNode->getContent()->display();
		currentNode = currentNode->getNext();
	}
}

