#pragma once
#include "IterateurBase.h"
#include "ListeDouble.h"
#include "Noeud.h"

template <class T>
//On h�rite de l'it�rateur de base
//TODO : D�commenter pour activer l'h�ritage
class Iterateur : public IterateurBase<T>
{
public:
	Iterateur();
	Iterateur(Noeud<T>* courant);
	~Iterateur();
	void operator++();
	void operator--();
	bool operator==(const Iterateur<T>& iter);
	bool operator!=(const Iterateur<T>& iter);
	T* operator -> ();
	T& operator*();
	Noeud<T>* getCourant();
private:
	Noeud<T>* courant;
};

template <class T>
Iterateur<T>::Iterateur(Noeud<T>* _courant)
{
	courant = _courant;
}

template <class T>
Iterateur<T>::Iterateur()
{
	courant = nullptr;
}

template <class T>
Iterateur<T>::~Iterateur()
{
}


template <class T>
bool Iterateur<T>::operator!=(const Iterateur<T>& iter)
{
	return courant != iter.courant;
}

template <class T>
bool Iterateur<T>::operator==(const Iterateur<T>& iter)
{
	return courant == iter.courant;
}

template <class T>
void Iterateur<T>::operator++()
{
	if (courant != nullptr)
	{
		courant = courant->GetSuivant();
	}
	//return Iterateur<T>(courant);
}

template <class T>
void Iterateur<T>::operator--()
{
	if (courant != nullptr)
	{
		courant = courant->GetPrecedent();
	}
	//return Iterateur<T>(courant);
}

template <class T>
T* Iterateur<T>::operator -> ()
{
	T* currentContent = nullptr;
	if (courant != nullptr)
		currentContent = courant->GetContent();
	return currentContent;
}

template <class T>
T& Iterateur<T>::operator * ()
{
	T* currentContent = nullptr;
	if (courant != nullptr)
		currentContent = courant->GetContent();
	return *currentContent;
}

template <class T>
Noeud<T>* Iterateur<T>::getCourant()
{
	return courant;
}