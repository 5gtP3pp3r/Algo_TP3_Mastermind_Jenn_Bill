#include "Mastermind.h"
#include "constants.h"


Mastermind::Mastermind(LinkedList<Combination>* _list)
{
	generateList(_list);
	fillTab(_list);
	list = _list;
	//list->display();
	/*for (int node = 0; node < LISTLENGTH; node++)
	{
		tabCombinations[node]->display();
	}*/
}

Mastermind::~Mastermind()
{
	for (short node = 0; node < LISTLENGTH; node++)
	{
		delete tabCombinations[node];									// Nous conservons les adresses des combinaisons dans un tableau afin de
	}																	// conserver une "poign�" dessus et pouvoir les d�truire � la fin du programmes.
}

/// <summary>
/// Retourne le nombre d'�l�ments dans la liste chain�es.
/// </summary>
/// <returns> Le nombre d'�l�ments. </returns>
int Mastermind::getNbElements() const
{
	return this->list->getLength();										// La m�thode existe d�j� dans DataStructure.
}

/// <summary>
/// Retourne un �l�ment de la liste en position index
/// </summary>
/// <param name="index">La position de l'�l�ment � retourner</param>
/// <returns>L'�l�ment qui est � la position index</returns>
Combination* Mastermind::getElement(int _index) const
{
	short index = 0;
	Iterator<Combination> iter = list->begin();							// D�claration d'un it�rateur

	while (index < _index)												// Incr�mentation de l'it�rateur jusqu'� l'index d�sir�.
	{
		++iter;
		index++;
	}

	return &iter;														// retour de la valeur de l'it�rateur.
}

/// <summary>
/// Logique de comparaison de la combinaison choisi par le cpu avec chaque combinaison de la liste
/// en relation avec les qualit�s de chaque couleur des combinaison du tableau _tabVerdicts
/// </summary>
/// <param name="_toValidate"> Combinaison de la liste � valider. </param>
/// <param name="_tried"> Combinaison al�atoire � comparer avec chaque combinaisons de la liste � valider. </param>
/// <param name="_tabVerdicts"> Tableau contenant la qualit� de chaque couleurs de la combinaison "_tried". </param>
/// <returns> Retour bool�en sur la validit� des combinaisons de la liste. </returns>
bool Mastermind::isPossibleCombination(Combination* _toValidate, Combination* _tried, short* _tabVerdicts) const
{
	Color colorTried = NULL;											// D�clarations de type couleur pour la combinaison 
	Color colorValidate = NULL;											// _tried et chaque combinaisons de la liste.
	bool isCondition3 = true;

	for (short value = 0; value < VERDICTS_LENGTH; value++)				// It�ration � la longueur de _tabVerdicts (4).
	{
		colorTried = _tried->getColor(value);							// Attribution des valeurs des couleurs en relation 
		colorValidate = _toValidate->getColor(value);					// avec les it�rations du tableau _tabVerdicts.

		if (_tabVerdicts[value] == 1 && colorTried != colorValidate)	// Si la qualit� est 1, bonne couleur, bonne position, mais que la couleur ne
		{																// concordent pas, la combinaison de la liste sera false. Donc retir�e dans cleanList().
			return false;
		}
		if (_tabVerdicts[value] == 2 && colorTried == colorValidate)	// Si la qualit� est 2, bonne couleur, mauvaise position, mais que la couleur est 
		{																// la m�me, la combinaison de la liste sera false. Donc retir�e dans cleanList().
			return false;
		}
		if (_tabVerdicts[value] == 2 && colorTried != colorValidate)	// Si la qualit� est 2, bonne couleur, mauvaise 
		{																// position, mais que la couleur n'est la m�me,
			if (!containsColor(_toValidate, colorTried, value))			// appel de la m�thode containsColor, si la couleur
			{															// n'apparait pas � un autre index, la combinaison de
				return false;											// la liste sera false. Donc retir�e dans cleanList().
			}
		}		
		if (_tabVerdicts[value] == 3)									// Si la qualit� est 3, cette couleur n'est pas dans la combinaison,
		{
			if (containsColor(_toValidate, colorTried, value))			// appel de la m�thode containsColor, si la couleur
			{															// apparait pas � un autre index, la combinaison de
				return false;											// la liste sera false. Donc retir�e dans cleanList().
			}
		}
	}
	return true;														// Si aucune condition ne s'applique, la combinaison
}																		//  est bonne, donc ignor� dans la m�thode cleanList().

/// <summary>
/// Logique de retrait des combinaisons de la liste chain�e. It�re la liste et envois � la m�thode
/// isPossibleCombinaison la combinaison pr�sente de la liste, la combinaison essay� par le cpu et 
/// la qualit� entr� par l'utilisateur. retirera de la liste une combinaison qui aura une valeur false.
/// � chaque suppression, une va;eur est incr�ment� pour retourner le nombre de combinaisons retir�es.
/// </summary>
/// <param name="_ref"> Combinaison choisi par le cpu. </param>
/// <param name="_tabVerdicts"> qualit� de la combinaison entr� par l'utilisateur. </param>
/// <returns> nombre de combinaisons retir�es. </returns>
int Mastermind::cleanList(Combination* _ref, short* _tabVerdicts)
{
	short removedCombinations = 0;
	short listLength = this->getNbElements();
	Combination* combToValidate = NULL;

	for (short node = 0; node < listLength; node++)
	{
		combToValidate = this->getElement(node);
		if (!isPossibleCombination(combToValidate, _ref, _tabVerdicts))
		{
			list->remove(combToValidate);
			listLength--;
			removedCombinations++;
			node--;
		}
	}

	return removedCombinations;
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

	for (short node = 0; node < LISTLENGTH; node++)
	{
		tabCombinations[node] = currentNode->getContent();
		currentNode = currentNode->getNext();
	}
}

bool Mastermind::containsColor(Combination* _toValidate, Color _color, short _forbiddenIndex) const
{
	Color colorValidate = NULL;

	for (short value = 0; value < VERDICTS_LENGTH; value++)
	{
		colorValidate = _toValidate->getColor(value);

		if (colorValidate == _color && value != _forbiddenIndex )
		{
			return true;
		}
	}
	return false;
}
