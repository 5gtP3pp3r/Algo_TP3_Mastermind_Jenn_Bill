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
		delete tabCombinations[node];
	}
}

int Mastermind::getNbElements() const
{
	return this->list->getLength();
}

/// <summary>
/// Retourne un élément de la liste en position index
/// </summary>
/// <param name="index">La position de l'élément à retourner</param>
/// <returns>L'élément qui est à la position index</returns>
Combination* Mastermind::getElement(int _index) const
{
	short index = 0;
	Iterator<Combination> iter = list->begin();

	while (index < _index)
	{
		++iter;
		index++;
	}

	return &iter;
}

bool Mastermind::isPossibleCombination(Combination* _toValidate, Combination* _tried, short* _tabVerdicts) const
{
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
			if (!containsColor(_toValidate, colorTried, value, false))
			{
				return false;
			}
		}
		if (_tabVerdicts[value] == 3)
		{
			if (containsColor(_toValidate, colorTried, value, true))
			{
				return false;
			}
		}
	}
	return true;
}

int Mastermind::cleanList(Combination* _ref, short* _tabVerdicts)
{
	short removedCombinations = 0;
	short listLength = this->getNbElements();

	for (short node = 0; node < listLength; node++)
	{
		Combination* combToValidate = this->getElement(node);
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

bool Mastermind::containsColor(Combination* _toValidate, Color _color, short _forbiddenIndex, bool isCondition3) const
{
	Color colorValidate = NULL;

	for (short value = 0; value < VERDICTS_LENGTH; value++)
	{
		colorValidate = _toValidate->getColor(value);

		if (colorValidate == _color && isCondition3)
		{
			return true;
		}
		if (colorValidate == _color && value != _forbiddenIndex)
		{
			return true;
		}
	}
	return false;
}
