#pragma once
#include <iostream>
#include "stdafx.h"
#include "Node.h"
#include <string>
#include <DataStructure.h>
#include <Iterator.h>
using namespace std;

										/*******************************************************
										Les méthodes de LinkedList.h on été implémentées par les 
										méthode du travail de William qui ont passées les tests.
										*******************************************************/

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
	// retourne simplement le premier Node de la liste.
	return Iterator<T>(this->getFirstNode());
}

template <class T>
Iterator<T> LinkedList<T>::end() const
{
	Node<T>* currentNode = this->getFirstNode(); 
	if (currentNode == nullptr) 
	{		
		return Iterator<T>(NULL);
	}

	while (currentNode != nullptr) 
	{
		currentNode = currentNode->getNext();
	}
	// Retourne la plage mémoire du next du dernier node, c'est null 
	// (du garbage), mais c'est le bon spot APRÈS le dernier node.
	// Mais c'est particulier... On ne peut pas simplement retourner un 
	// Iterator<T> qui contient un pointeur à NULL....
	return Iterator<T>(currentNode);
}

template <class T>
bool LinkedList<T>::add(T* _content)
{
	if (_content == nullptr)
	{
		return false;
	}

    Node<T>* currentNode = this->getFirstNode();
	Node<T>* newNode = new Node<T>;
	newNode->setContent(_content);
	newNode->setNext(nullptr);
	
	if (currentNode == nullptr || *_content < *currentNode->getContent())
	{
		newNode->setNext(currentNode);
		this->setFirstNode(newNode);

		return true;
	}

	Node<T>* nextNode = nullptr; 
	while (currentNode != nullptr)
	{
		if (*_content == *currentNode->getContent())
		{ 
			delete newNode;
			return false;
		}

		nextNode = currentNode->getNext();												
		if (nextNode == nullptr || *_content < *nextNode->getContent())
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
	if (currentNode == nullptr || _content == nullptr)
	{
		return false;
	}

	if (*_content == *currentNode->getContent())
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
		if (*_content == *nextNode->getContent())
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
	int rank = 1;
	while (currentNode != nullptr)
	{
		cout << rank << " ";
		currentNode->getContent()->display();
		currentNode = currentNode->getNext();
		rank++;
	}
}

