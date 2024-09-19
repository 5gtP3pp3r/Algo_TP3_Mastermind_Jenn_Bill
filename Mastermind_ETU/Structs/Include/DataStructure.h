#pragma once
#include <Node.h>
#include <string>
using namespace std;
template <class T>
class DataStructure
{
	public:
		DataStructure();
		~DataStructure();
		virtual void display() const = 0;
		int getNumNodes() const;
		Node<T>* getFirstNode() const;
	protected:
		void setFirstNode(Node<T>* node);
	private:
		Node<T>* firstNode;
};

template <class T>
DataStructure<T>::DataStructure() : firstNode(NULL)
{
}

template <class T>
DataStructure<T>::~DataStructure()
{
}

//TODO: À renommer, voir énoncé
template <class T>
int DataStructure<T>::getNumNodes() const
{
	return 0;
}

template <class T>
void DataStructure<T>::setFirstNode(Node<T>* node)
{
	this->firstNode = node;
}

template <class T>
Node<T>* DataStructure<T>::getFirstNode() const
{
	return this->firstNode;
}

