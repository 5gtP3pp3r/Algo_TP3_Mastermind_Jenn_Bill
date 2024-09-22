#include "Mastermind.h"
#include "constants.h"


Mastermind::Mastermind(LinkedList<Combination>* _list)
{
	generateList(_list);
	list = _list;
	//list->display();
}

Mastermind::~Mastermind()
{
	Node<Combination>* currentCombination = list->getFirstNode();
	Node<Combination>* nextCombination = nullptr;

	int listLength = pow(NB_COLORS, COMBINATION_LENGTH); // NB_COLORS exposant COMBINATION_LENGTH (8^4 ou (8*8*8*8)) = 4096

	for (int node = 0; node < listLength; node++)
	{
		nextCombination = currentCombination->getNext();
		delete currentCombination;
	}
}


int Mastermind::getNbElements() const
{
	//TODO: Compléter
	return 0;
}

/// <summary>
/// Retourne un élément de la liste en position index
/// </summary>
/// <param name="index">La position de l'élément à retourner</param>
/// <returns>L'élément qui est à la position index</returns>
Combination* Mastermind::getElement(int index) const
{
	//TODO: Compléter
	return NULL;
}

bool Mastermind::isPossibleCombination(Combination* _toValidate, Combination* _tried, short* _tabVerdicts)
{
	//A COMPLETER
	//Vérifiez si la combinaison toValidate doit être gardée ou non de la liste, en fonction d'une combinaison essayée et d'un tableau de 4 verdicts.
	//Pour chacune des couleurs présentes dans toValidate, 3 verdicts possibles doivent être pris en considération pour éléminer ou non la combinaison, 
	//il s'agit de "Bonne couleur, bonne place" (valeur 1), "Bonne couleur, mauvaise place" (valeur 2) et "Mauvaise couleur" (valeur 3).

	//Voici un ébauche d'algorithme qui devrait vous aider à compléter cette méthode:
	//Pour chacune des couleurs de la combinaison toValidate, vérifiez:

	//Si le verdict est 1 (Bonne couleur, bonne place) et que la combinaison de couleurs à valider n'a pas la couleur à la même place que 
	//la combinaison essayée, il faut la retirer de la liste.

	//Si le verdict est 2 (Bonne couleur, mauvaise place) et que la combinaison de couleurs à valider n'a pas la couleur à un autre emplacement que
	//celui de la combinaison essayée, il faut la retirer de la liste.

	//Si le verdict est 3 (Mauvaise couleur) et que la combinaison de couleurs à valider a la couleur, il faut la retirer de la liste.

	//Retournez true si la combinaison est valide (respecte les verdicts) et false dans le cas contraire.


	bool keepCombination = true;

	//TODO: Compléter l'algorithme ici

	return keepCombination;
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

int Mastermind::cleanList(Combination* _ref, short* _tabVerdicts)
{
	//A COMPLETER
	//Épure la liste de combinaisons de couleurs en fonction de la combinaison reçue et des 4 verdicts (valeurs 1 à 3).
	//Pour chacune des combinaisons de la liste, vérifier si elle doit être retirée ou non de liste.
	//Le nombre de combinaisons supprimées doit être retourné.

	//Cette fonction appelle isPossibleCombination pour savoir si la combinaison inspectée est à garder ou non

	//TODO: Compléter

	return 0;
}
