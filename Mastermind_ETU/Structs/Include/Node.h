#pragma once

template <class T>
class Node
{
	public:
		Node();
		~Node();
		Node<T>* getNext() const;
		void setNext(Node<T>* _next);
		Node<T>* getPrevious() const;
		void setPrevious(Node<T>* _previous);
		T* getContent() const;
		void setContent(T* _content);

	private:
		Node<T>* next = nullptr;
		Node<T>* previous = nullptr;
		T* content = nullptr;
};

template <class T>
Node<T>::Node()
{
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
void Node<T>::setNext(Node* _nextNode)
{
	next = _nextNode;
}

template <class T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

template <class T>
void Node<T>::setPrevious(Node* _previous)
{
	previous = _previous;
}

template <class T>
Node<T>* Node<T>::getPrevious() const
{
	return previous;
}

template <class T>
void Node<T>::setContent(T* _content)
{
	content = _content;
}

template <class T>
T* Node<T>::getContent() const
{
	return content;
}

