#include "Mastermind.h"
#include "constants.h"


Mastermind::Mastermind(LinkedList<Combination>* _list)
{
	generateList(_list);
	fillTab(_list);
	list = _list;
	//list->display();
	for (int node = 0; node < LISTLENGTH; node++)
	{
		tabCombinations[node]->display();
	}
}

Mastermind::~Mastermind()
{
	for (int combi = 0; combi < LISTLENGTH; combi++)
	{
		delete tabCombinations[combi];
	}
}

int Mastermind::getNbElements() const
{
	return this->list->getLength();
}

/// <summary>
/// Retourne un �l�ment de la liste en position index
/// </summary>
/// <param name="index">La position de l'�l�ment � retourner</param>
/// <returns>L'�l�ment qui est � la position index</returns>
Combination* Mastermind::getElement(int _index) const
{
	int index = 0;
	Iterator<Combination> iter = list->begin();
	while (index < _index)
	{
		++iter;
		index++;
	}

	return &iter;
}

bool Mastermind::isPossibleCombination(Combination* _toValidate, Combination* _tried, short* _tabVerdicts)
{
	//A COMPLETER
	//V�rifiez si la combinaison toValidate doit �tre gard�e ou non de la liste, en fonction d'une combinaison essay�e et d'un tableau de 4 verdicts.
	//Pour chacune des couleurs pr�sentes dans toValidate, 3 verdicts possibles doivent �tre pris en consid�ration pour �liminer ou non la combinaison, 
	//il s'agit de "Bonne couleur, bonne place" (valeur 1), "Bonne couleur, mauvaise place" (valeur 2) et "Mauvaise couleur" (valeur 3).

	//Voici un �bauche d'algorithme qui devrait vous aider � compl�ter cette m�thode:
	//Pour chacune des couleurs de la combinaison toValidate, v�rifiez:

	//Si le verdict est 1 (Bonne couleur, bonne place) et que la combinaison de couleurs � valider n'a pas la couleur � la m�me place que 
	//la combinaison essay�e, il faut la retirer de la liste.

	//Si le verdict est 2 (Bonne couleur, mauvaise place) et que la combinaison de couleurs � valider n'a pas la couleur � un autre emplacement que
	//celui de la combinaison essay�e, il faut la retirer de la liste.

	//Si le verdict est 3 (Mauvaise couleur) et que la combinaison de couleurs � valider a la couleur, il faut la retirer de la liste.

	//Retournez true si la combinaison est valide (respecte les verdicts) et false dans le cas contraire.

	/*bonneComb   (rouge, noir ,jaune , vert)
	_toValidate [Rouge, Rouge, Rouge, Vert]

	_tried      (rouge, jaune, noir, mauve)
	_tabVerdicts(  1  ,   3  ,   2 ,   3 )*/

	Color colorTried = NULL;
	Color colorValidate = NULL;

	for (short value = 0; value < VERDICTS_LENGTH; value++)
	{
		colorTried = _tried->getColor(value);
		colorValidate = _toValidate->getColor(value);

		if (_tabVerdicts[value] == 1 && colorTried != colorValidate) 
		{
			return false;
		}
		if (_tabVerdicts[value] == 2 && colorTried != colorValidate)
		{
			if (!contains(_toValidate, colorTried, value))
			{
				return false;
			}			
		}
		if (_tabVerdicts[value] == 3)
		{
			if (contains(_toValidate, colorTried, value))
			{
				return false;
			}
		}
	}
	return true;
}

int Mastermind::cleanList(Combination* _ref, short* _tabVerdicts)
{
	//A COMPLETER
	//�pure la liste de combinaisons de couleurs en fonction de la combinaison re�ue et des 4 verdicts (valeurs 1 � 3).
	//Pour chacune des combinaisons de la liste, v�rifier si elle doit �tre retir�e ou non de liste.
	//Le nombre de combinaisons supprim�es doit �tre retourn�.

	//Cette fonction appelle isPossibleCombination pour savoir si la combinaison inspect�e est � garder ou non

	//TODO: Compl�ter

	Iterator<Combination> iter = list->begin();
	while (iter != nullptr)
	{
		if (!isPossibleCombination(&iter, _ref, _tabVerdicts))
		{
			list->remove(&iter);
		}
		++iter;
	}

	return 0;
}

void Mastermind::generateList(LinkedList<Combination>* _list)
{
	for (short c1 = 1; c1 < NB_COLORS + 1; c1++)
	{
		for (short c2 = 1; c2 < NB_COLORS + 1; c2++)
		{
			for (short c3 = 1; c3 < NB_COLORS + 1; c3++)
			{
				for (short c4 = 1; c4 < NB_COLORS + 1; c4++)
				{
					_list->add(new Combination(Color(c1), Color(c2), Color(c3), Color(c4)));
				}
			}
		}
	}
}

void Mastermind::fillTab(LinkedList<Combination>* _list)
{
	Node<Combination>* currentNode = _list->getFirstNode();
	for (int node = 0; node < LISTLENGTH; node++)
	{
		tabCombinations[node] = currentNode->getContent();
		currentNode = currentNode->getNext();
	}
}

bool Mastermind::contains(Combination* _toValidate, Color _color, short _forbiddenIndex)
{
	Color colorValidate = NULL;

	for (short value = 0; value < VERDICTS_LENGTH; value++)
	{
		colorValidate = _toValidate->getColor(value);

		if (colorValidate == _color && value != _forbiddenIndex)
		{
			return true;
		}
	}
	return false;
}
