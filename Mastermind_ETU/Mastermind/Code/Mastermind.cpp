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
	}																	// conserver une "poigné" dessus et pouvoir les détruire à la fin du programmes.
}

/// <summary>
/// Retourne le nombre d'éléments dans la liste chainées.
/// </summary>
/// <returns> Le nombre d'éléments. </returns>
int Mastermind::getNbElements() const
{
	return this->list->getLength();										// La méthode existe déjà dans DataStructure.
}

/// <summary>
/// Retourne un élément de la liste en position index
/// </summary>
/// <param name="index">La position de l'élément à retourner</param>
/// <returns>L'élément qui est à la position index</returns>
Combination* Mastermind::getElement(int _index) const
{
	short index = 0;
	Iterator<Combination> iter = list->begin();							// Déclaration d'un itérateur

	while (index < _index)												// Incrémentation de l'itérateur jusqu'à l'index désiré.
	{
		++iter;
		index++;
	}

	return &iter;														// retour de la valeur de l'itérateur.
}

/// <summary>
/// Logique de comparaison de la combinaison choisi par le cpu avec chaque combinaison de la liste
/// en relation avec les qualités de chaque couleur des combinaison du tableau _tabVerdicts
/// </summary>
/// <param name="_toValidate"> Combinaison de la liste à valider. </param>
/// <param name="_tried"> Combinaison aléatoire à comparer avec chaque combinaisons de la liste à valider. </param>
/// <param name="_tabVerdicts"> Tableau contenant la qualité de chaque couleurs de la combinaison "_tried". </param>
/// <returns> Retour booléen sur la validité des combinaisons de la liste. </returns>
bool Mastermind::isPossibleCombination(Combination* _toValidate, Combination* _tried, short* _tabVerdicts) const
{
	Color colorTried = NULL;											// Déclarations de type couleur pour la combinaison 
	Color colorValidate = NULL;											// _tried et chaque combinaisons de la liste.
	bool isCondition3 = true;

	for (short value = 0; value < VERDICTS_LENGTH; value++)				// Itération à la longueur de _tabVerdicts (4).
	{
		colorTried = _tried->getColor(value);							// Attribution des valeurs des couleurs en relation 
		colorValidate = _toValidate->getColor(value);					// avec les itérations du tableau _tabVerdicts.

		if (_tabVerdicts[value] == 1 && colorTried != colorValidate)	// Si la qualité est 1, bonne couleur, bonne position, mais que la couleur ne
		{																// concordent pas, la combinaison de la liste sera false. Donc retirée dans cleanList().
			return false;
		}
		if (_tabVerdicts[value] == 2 && colorTried == colorValidate)	// Si la qualité est 2, bonne couleur, mauvaise position, mais que la couleur est 
		{																// la même, la combinaison de la liste sera false. Donc retirée dans cleanList().
			return false;
		}
		if (_tabVerdicts[value] == 2 && colorTried != colorValidate)	// Si la qualité est 2, bonne couleur, mauvaise 
		{																// position, mais que la couleur n'est la même,
			if (!containsColor(_toValidate, colorTried, value))			// appel de la méthode containsColor, si la couleur
			{															// n'apparait pas à un autre index, la combinaison de
				return false;											// la liste sera false. Donc retirée dans cleanList().
			}
		}		
		if (_tabVerdicts[value] == 3)									// Si la qualité est 3, cette couleur n'est pas dans la combinaison,
		{
			if (containsColor(_toValidate, colorTried, value))			// appel de la méthode containsColor, si la couleur
			{															// apparait pas à un autre index, la combinaison de
				return false;											// la liste sera false. Donc retirée dans cleanList().
			}
		}
	}
	return true;														// Si aucune condition ne s'applique, la combinaison
}																		//  est bonne, donc ignoré dans la méthode cleanList().

/// <summary>
/// Logique de retrait des combinaisons de la liste chainée. Itère la liste et envois à la méthode
/// isPossibleCombinaison la combinaison présente de la liste, la combinaison essayé par le cpu et 
/// la qualité entré par l'utilisateur. retirera de la liste une combinaison qui aura une valeur false.
/// À chaque suppression, une va;eur est incrémenté pour retourner le nombre de combinaisons retirées.
/// </summary>
/// <param name="_ref"> Combinaison choisi par le cpu. </param>
/// <param name="_tabVerdicts"> qualité de la combinaison entré par l'utilisateur. </param>
/// <returns> nombre de combinaisons retirées. </returns>
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
