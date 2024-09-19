#pragma once
#include "Node.h"
#include "Book.h"
#include <string>
#include "DataStructure.h"
using namespace std;

template <class T>
class LinkedList : public DataStructure<T>
{
public:
	LinkedList();
	~LinkedList();
	bool add(T* content);
	bool remove(T* content);
	void display() const override;
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
bool LinkedList<T>::add(T* content)
{
	// Livre null
	if (content == nullptr)
	{
		return false;
	}

    Node<T>* currentNode = this->getFirstNode();
	Node<T>* newNode = new Node<T>;
	newNode->setContent(content);
	newNode->setNext(nullptr);
	
	// Ajout en tête de liste
	if (currentNode == nullptr || *content < *currentNode->getContent())
	{
		newNode->setNext(currentNode);
		this->setFirstNode(newNode);

		return true;
	}

	// * Voir commentaire ligne 71.
	Node<T>* nextNode = nullptr; 
	// Ajout à travers et à la fin de la liste.
	while (currentNode != nullptr)
	{
		// Dès qu'un livre est déjà présent à l'index présent retourne false.
		if (*content == *currentNode->getContent())
		{ 
			delete newNode;
			return false;
		}
		// Cette initialisation peut paraitre surplus, mais elle aide à 
		// une lecture et compréhension plus facile du code, plus verbeux.
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
bool LinkedList<T>::remove(T* content)
{
	// Liste ou livre null.
	Node<T>* currentNode = this->getFirstNode();
	if (currentNode == nullptr || content == nullptr)
	{
		return false;
	}

	// Retrait premier de la liste.
	if (*content == *currentNode->getContent())
	{
		Node<T>* nextNode = currentNode->getNext();		 
		this->setFirstNode(nextNode);

		delete currentNode;		
		return true;
	}

	// * Même commentaire que la ligne 71.
	Node<T>* nextNode = nullptr;
	// Retrait à travers ou le dernier de la liste.
	while (currentNode->getNext() != nullptr)
	{
		// * "
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

