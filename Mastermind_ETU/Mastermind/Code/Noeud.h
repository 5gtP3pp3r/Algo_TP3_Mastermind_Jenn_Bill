#pragma once

template <class T>
class Noeud
{
public:
	Noeud();
	~Noeud();
	Noeud<T> * GetSuivant();
	void SetSuivant(Noeud<T> * _suivant);
	Noeud<T> * GetPrecedent();
	void SetPrecedent(Noeud<T> * _precedent);
	T * GetContent();
	void SetContent(T * _content);
	
private:
	T * content;
	Noeud<T> * suivant;
	Noeud<T> * precedent;

};

#include "Noeud.hpp"


