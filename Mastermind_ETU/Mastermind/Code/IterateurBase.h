#include "Noeud.h"
#pragma once
template <class T>
class IterateurBase{
public:

	//méthodes usuelles vues en classe pour un itérateur
	virtual void operator++() = 0;
	virtual void operator--() = 0;
	virtual T* operator->() = 0;
	virtual T& operator*() = 0;
	//un ajout pratique dans le cadre de ce TP
	virtual Noeud<T>* getCourant() = 0;
};
