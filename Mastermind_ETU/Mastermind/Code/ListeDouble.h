#pragma once
#include "ListeBase.h"
#include "EmptyListException.h"
#include "Iterateur.h"

using namespace std;

template <class T>
//On hérite de la liste de base
//TODO : Décommenter pour activer l'héritage
class ListeDouble : public ListeBase<T>
{
//TODO : Définissez votre liste double, TOUTES les méthodes à surcharger sont dans ListeBase<T>
public :
	ListeDouble();
	~ListeDouble();
	void vider();

	bool ajouter(T* _content);
	bool retirer(T* _content);
	bool retirer(Noeud<T>* _content);
	bool isEmpty() const;
	int getNbElements() const;
	Iterateur<T> begin();
	Iterateur<T> end();
	typedef Iterateur<T> iterateur;

private:
	Noeud<T>* premierNoeud;
};

template <class T>
ListeDouble<T>::ListeDouble()
{
	premierNoeud = nullptr;
}

template <class T>
ListeDouble<T>::~ListeDouble()
{
	this->vider();
}
template <class T>
Iterateur<T> ListeDouble<T>::begin()
{
	return Iterateur<T>(premierNoeud);
}

template <class T>
Iterateur<T> ListeDouble<T>::end()
{
	//Noeud<T>* ret = nullptr;
	//if (premierNoeud != nullptr)
	//{
	//	//Un seul noeud
	//	if (premierNoeud->GetSuivant() == premierNoeud)
	//	{
	//		ret = premierNoeud;
	//	}

	//	else
	//	{
	//		ret = premierNoeud->GetSuivant();
	//		while (ret->GetSuivant() != premierNoeud)
	//		{
	//			ret = ret->GetSuivant();
	//		}
	//	}
	//}
	//return ret;
	return Iterateur<T>(NULL);
}

template <class T>
bool ListeDouble<T>::ajouter(T* _content)
{
	bool bDebut = false;
	bool retour = true;
	Noeud<T>* ptrNoeud;

	if (premierNoeud == nullptr)
	{
		bDebut = true;

		Noeud<T>* nouveauNoeud = new Noeud<T>();
		nouveauNoeud->SetContent(_content);
		nouveauNoeud->SetSuivant(NULL);
		nouveauNoeud->SetPrecedent(NULL);
		premierNoeud = nouveauNoeud;
	}

	else if (*(premierNoeud->GetContent()) > * _content)
	{
		bDebut = true;	//comme le push de la pile
		Noeud<T>* nouveauNoeud = new Noeud<T>();
		nouveauNoeud->SetContent(_content);
		nouveauNoeud->SetSuivant(premierNoeud);
		premierNoeud->SetPrecedent(nouveauNoeud);
		premierNoeud = nouveauNoeud;
		premierNoeud->SetPrecedent(NULL);
		/*Noeud<T>* temp = premierNoeud->GetSuivant();
		while (temp->GetSuivant() != premierNoeud->GetSuivant())
		{
			temp = temp->GetSuivant();
		}

		premierNoeud->SetPrecedent(temp);
		temp->SetSuivant(premierNoeud);*/
	}

	if (!bDebut)
	{
		if (*(premierNoeud->GetContent()) == *_content)
		{
			return false;
		}
		else
		{
			ptrNoeud = premierNoeud;
			//Tant qu'on n'est pas rendu à la fin ET que le livre n'est pas à sa place
			while (ptrNoeud->GetSuivant() != premierNoeud &&
				*(ptrNoeud->GetSuivant()->GetContent()) < *_content)
			{
				ptrNoeud = ptrNoeud->GetSuivant();
			}
			//Nous sommes rendus à la fin
			if (ptrNoeud->GetSuivant() == premierNoeud)
			{
				Noeud<T>* nouveauNoeud = new Noeud<T>;
				nouveauNoeud->SetContent(_content);
				ptrNoeud->SetSuivant(nouveauNoeud);
				nouveauNoeud->SetSuivant(NULL);
				nouveauNoeud->SetPrecedent(ptrNoeud);
				//premierNoeud->SetPrecedent(nouveauNoeud);
			}
			else
			{
				// doublon ?
				if (*(ptrNoeud->GetSuivant()->GetContent()) == *_content)
				{
					retour = false;
				}
				else
				{
					//Ajout entre 2 noeuds
					Noeud<T>* nouveauNoeud = new Noeud<T>;
					nouveauNoeud->SetContent(_content);

					nouveauNoeud->SetSuivant(ptrNoeud->GetSuivant());
					ptrNoeud->GetSuivant()->SetPrecedent(nouveauNoeud);

					ptrNoeud->SetSuivant(nouveauNoeud);
					nouveauNoeud->SetPrecedent(ptrNoeud);
				}
			}
		}
	}
	return retour;
}

//HERE, retirer + destructeur
template <class T>
bool ListeDouble<T>::retirer(T* _content)
{
	bool retour = true;

	//liste vide
	if (premierNoeud == nullptr)
	{
		return false;
	}

	//debut de liste, on doit bouger le premier noeud
	else if (*(premierNoeud->GetContent()) == *_content)
	{
		//Noeud<T>* temp = premierNoeud->GetPrecedent();
		Noeud<T>* noeudAEnlever = premierNoeud;

		//plus qu'un noeud
		if (premierNoeud->GetSuivant() != NULL)
		{
			premierNoeud = premierNoeud->GetSuivant();
			premierNoeud->SetPrecedent(NULL);
			//temp->SetSuivant(premierNoeud);
			delete noeudAEnlever;
		}

		//un seul noeud
		else
		{
			delete premierNoeud;
			premierNoeud = nullptr;
		}

	}

	//milieu de liste ou on ne le trouve pas
	else
	{
		Noeud<T>* ptrNoeud = premierNoeud;

		//Le cas du début de liste a été traité, on regarde le suivant
		while (ptrNoeud->GetSuivant() != premierNoeud &&
			*(ptrNoeud->GetSuivant()->GetContent()) != *_content)
		{
			ptrNoeud = ptrNoeud->GetSuivant();
		}

		//on s'est rendu à la fin
		if (ptrNoeud->GetSuivant() == NULL)
		{
			retour = false;	
		}

		//TODO : FIN DE LISTE EST UN CAS DIFFÉRENT

		//On enleve le noeud, ptrNoeud est placé juste avant
		else
		{
			Noeud<T>* noeudAEnlever = ptrNoeud->GetSuivant();

			//on attache ptrNoeud au noeud suivant le noeud à enlever
			ptrNoeud->SetSuivant(ptrNoeud->GetSuivant()->GetSuivant());
			if(ptrNoeud->GetSuivant() != NULL)
				ptrNoeud->GetSuivant()->SetPrecedent(ptrNoeud);
			delete noeudAEnlever;
		}

	}

	return retour;
}


template <class T>
bool ListeDouble<T>::retirer(Noeud<T>* _noeud)
{
	T * _content = _noeud->GetContent();
	return this->retirer(_content);	
}


template <class T>
int ListeDouble<T>::getNbElements() const
{
	int nbNoeuds = 0;

	if (premierNoeud != nullptr)
	{
		nbNoeuds++;
		Noeud<T>* temp = premierNoeud;
		while (temp->GetSuivant() != NULL)
		{
			nbNoeuds++;
			temp = temp->GetSuivant();
		}
	}


	return nbNoeuds;
}

template <class T>
bool ListeDouble<T>::isEmpty() const
{
	return false;
}

template <class T>
void ListeDouble<T>::vider()
{
	while (premierNoeud != nullptr)
	{
		Noeud<T>* noeudAEnlever = premierNoeud;
		premierNoeud = premierNoeud->GetSuivant();
		delete noeudAEnlever;
	}
}