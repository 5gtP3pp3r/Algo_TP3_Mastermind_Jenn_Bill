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
	short removedCombinations = 0;										// Déclaration d'une variable qui sera incrémenté au besoin.
	short listLength = this->getNbElements();							// Déclaration d'une variable qui va conserver la longueur de la liste.
	Combination* combToValidate = NULL;									// Déclaration d'un type pointeur de Combination.

	for (short node = 0; node < listLength; node++)						// Itération à la longueur de la liste
	{
		combToValidate = this->getElement(node);
		if (!isPossibleCombination(combToValidate, _ref, _tabVerdicts))	// Appel de la méthode isPossibleCombination avec les paramètres pertinents.
		{
			list->remove(combToValidate);								// Si la condition est fausse, on retire la combinaison de la liste,
			listLength--;												// décrémentation de la longueur de la boucle,
			removedCombinations++;										// incrémentation de la variable représentant le nombre de combinaisons retirées
			node--;														// et, particulier, décrémentation de l'index de la boucle.
		}
	}

	return removedCombinations;											// Retour du nombre de combinaisons retirées.


   /****************************************************************************************************************************************************
	Explications de notre logique pour la méthode cleanList(). Notre premier jet impliquait une boucle while et la déclaration de 2 variable de type 
	Iterator<Combination>. nous utilisions dons les 2 itérateur pour pour pouvoir conserver la valeur de l'itérateur même si on retire sa valeur de la 
	list. Nous avons observé le code et remarqué que la méthode getElement() itère déjà dans la liste et que getNbElement() nous donne aussi la longueur
	de la liste. nous les avons donc mis à profit. Une mécanique particulière c'est imposé et nous avons observé une situations où certaine combinaisons 
	étaient ignorées lors des itérations. Nous avons donc découpé, débogué et inspecter chaque itération pour voir un phénomène de saut involontaire de
	combinaison. Nous avons donc réglé le problème avec une décrémentation de l'index de la boucle (node) seulement si une combinaison est retiré de la
	liste. Voici donc une représentation graphique de la raison de l'utilisation de la décrémentation:
	
	Voici une liste de 7 index:						0   1   2   3   4   5   6

	Lorsqu'un index est retiré nous décrémentons la longueur de la liste puisque nous utilisons getElement() qui redéfini un itérateur sur une liste qui  
	a été raccourcie.
													0   1   2   3   4   5 

	Mais une situation spécial s'observe:		    index retiré, valeur 3
													0   1   2   *   4   5
													liste raccourcie de 1
													0   1   2  <-3(4) <-4(5)
							incrémentation de l'itérateur dans getElement() (++iter) maintenant valeur 4
													0   1   2  "3"  4
								    le nouvel index 3, précédemment 4, a donc été ignoré.
				      décrémentation de l'index (node--) pour se remettre à la bonne position dans la liste.

	La boucle se déplace donc "Back & Forth" lorsqu'il y a suppression et itère normalement lorsqu'il n'y a pas de suppression. Nous avons choisis cette 
	logique car elle réutilise des ressources existantes et n'avons pas à déclaré 2 autres itérateurs pour une mécanique d'échange de valeurs suite à une 
	suppression. La méthode est donc environ 3 fois plus courte, très concise et verbeuse. Elle peut être lue et comprise comme un texte.
    ****************************************************************************************************************************************************/
}

/// <summary>
/// Génération de la liste chainées de combinaisons
/// </summary>
/// <param name="_list"> Liste déclaré dans ConsoleMenu mais vide, seulement instanciée. </param>
void Mastermind::generateList(LinkedList<Combination>* _list)
{
	for (short c1 = 1; c1 < NB_COLORS + 1; c1++)						// Puissance "3". Une boucle par "puissance" de la combinaison.  
	{
		for (short c2 = 1; c2 < NB_COLORS + 1; c2++)					// Puissance "2"
		{
			for (short c3 = 1; c3 < NB_COLORS + 1; c3++)				// Puissance "1"
			{
				for (short c4 = 1; c4 < NB_COLORS + 1; c4++)			// Puissance "0"
				{
					_list->add(new Combination(Color(c1), Color(c2), Color(c3), Color(c4)));	// déclaration et ajout d'une combinaison de 4 couleurs
				}																				// en relation avec la position des boucles.
			}
		}
	}
}

/// <summary>
/// Ajout des combinaison de la liste dans le tableau prévue pour conserver
/// les adresse pour permettre leur suppression dans le destructeur.
/// </summary>
/// <param name="_list"> Liste nouvellement créé. </param>
void Mastermind::fillTab(LinkedList<Combination>* _list)
{
	Node<Combination>* currentNode = _list->getFirstNode();

	for (short node = 0; node < LISTLENGTH; node++)
	{
		tabCombinations[node] = currentNode->getContent();
		currentNode = currentNode->getNext();
	}
}

/// <summary>
/// Vérifie si une combinaison contient une couleur spécifiée
/// </summary>
/// <param name="_toValidate"> Combinaison à vérifier </param>
/// <param name="_color"> Couleur à rechercher. </param>
/// <param name="_forbiddenIndex"> Index présent dans la boucle cleanList(). </param>
/// <returns> Booléen, est présent ou pas. </returns>
bool Mastermind::containsColor(Combination* _toValidate, Color _color, short _forbiddenIndex) const
{
	Color colorValidate = NULL;											// Exactement la même logique que la méthode Contains() en c#.

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
