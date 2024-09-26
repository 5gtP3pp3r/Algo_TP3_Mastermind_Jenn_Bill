#include "Mastermind.h"
#include "constants.h"


Mastermind::Mastermind(LinkedList<Combination>* _list)

													/******************************************************
													* Tout le travail a été composé à 2 coéquipiers sauf  *
													* si précisé autrement. (tests, surcharge Combinaison)*
													******************************************************/
{
	generateList(_list);	
	list = _list;
	fillTab();
	//list->display();
	/*for (int node = 0; node < LISTLENGTH; node++)						// Test d'affichage liste chainée et tableau.
	{
		tabCombinations[node]->display();
	}*/
}

Mastermind::~Mastermind()
{
	for (short node = 0; node < LISTLENGTH; node++)
	{
		delete tabCombinations[node];									// Nous conservons les adresses des combinaisons dans un tableau afin de
	}																	// conserver une "poigné" dessus et pouvoir les détruires à la fin du programmes.
}

/// <summary>
/// Retourne le nombre d'éléments dans la liste chainée.
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
/// en relation avec les qualités de chaque couleur des combinaisons du tableau _tabVerdicts
/// </summary>
/// <param name="_toValidate"> Combinaison de la liste à valider. </param>
/// <param name="_tried"> Combinaison aléatoire à comparer avec chaque combinaisons de la liste à valider. </param>
/// <param name="_tabVerdicts"> Tableau contenant la qualité de chaque couleurs de la combinaison "_tried". </param>
/// <returns> Retour booléen sur la validité des combinaisons de la liste. </returns>
bool Mastermind::isPossibleCombination(Combination* _toValidate, Combination* _tried, short* _tabVerdicts) const
{
	Color colorTried = NULL;												// Déclaration de type couleur pour la combinaison 
	Color colorValidate = NULL;												// _tried et chaque combinaisons de la liste.
	bool isCondition3 = true;

	for (short value = 0; value < VERDICTS_LENGTH; value++)					// Itération à la longueur de _tabVerdicts (4).
	{
		colorTried = _tried->getColor(value);								// Attribution des valeurs des couleurs en relation 
		colorValidate = _toValidate->getColor(value);						// avec les itérations du tableau _tabVerdicts.

		if (_tabVerdicts[value] == 1 && colorTried != colorValidate)		// Si la qualité est 1 (bonne couleur, bonne position) et les couleurs sont
		{																	// différentes, la combinaison de la liste est invalide. Donc retirée dans cleanList().
			return false;
		}
		if (_tabVerdicts[value] == 2 && colorTried == colorValidate)		// Si la qualité est 2 (bonne couleur, mauvaise position) et les couleurs sont 
		{																	// identiques au meme index, la combinaison de la liste est invalide. Donc retirée dans cleanList().
			return false;
		}
		if (_tabVerdicts[value] == 2 && colorTried != colorValidate)		// Si la qualité est 2 (bonne couleur, mauvaise position), 
		{																	// et que les couleurs sont différentes au meme index,
			if (!containsColorOnOtherIndex(_toValidate, colorTried, value))	// appel de la méthode containsColorOnOtherIndex(), si la couleur
			{																// n'est pas à un autre index, la combinaison de
				return false;												// la liste est invalide. Donc retirée dans cleanList().
			}
		}		
		if (_tabVerdicts[value] == 3)										// Si la qualité est 3 (mauvaise couleur),
		{
			if (containsColor(_toValidate, colorTried))						// appel de la méthode containsColor, si la couleur
			{																// est trouvée, la combinaison est invalide. 
				return false;												// Donc retirée dans cleanList().
			}
		}
	}
	return true;															// Si aucune condition ne s'applique, la combinaison
}																			// est bonne et restera dans la liste.

/// <summary>
/// Logique de retrait des combinaisons de la liste chainée. Itère la liste et envoi à la méthode
/// isPossibleCombinaison la combinaison présente de la liste, la combinaison essayée par le cpu et 
/// la qualité entrée par l'utilisateur. Retirera de la liste une combinaison invalide.
/// À chaque suppression, une valeur est incrémentée pour retourner le nombre de combinaisons retirées.
/// </summary>
/// <param name="_ref"> Combinaison choisie par le cpu. </param>
/// <param name="_tabVerdicts"> Qualité de la combinaison entrée par l'utilisateur. </param>
/// <returns> Nombre de combinaisons retirées. </returns>
int Mastermind::cleanList(Combination* _ref, short* _tabVerdicts)
{
	short removedCombinations = 0;										// Déclaration d'une variable pour retourner le nombre de combinaison retirées.
	short listLength = LISTLENGTH;										// Déclaration d'une variable qui contient la longueur de la liste à l'origine.
	Combination* combToValidate = NULL;									// Déclaration d'un type pointeur de Combination.

	for (short node = 0; node < listLength; node++)						// Itération à la longueur de la liste
	{
		combToValidate = this->getElement(node);						// Attribution de la valeur de la combinaison présente.
		if (!isPossibleCombination(combToValidate, _ref, _tabVerdicts))	// Appel de la méthode isPossibleCombination avec les paramètres pertinents.
		{
			list->remove(combToValidate);								// Si la combinaison est invalide, on retire la combinaison de la liste,
			listLength--;												// décrémente de 1 la longueur de la boucle puisqu'on a retirée une combinaison,
			removedCombinations++;										// incrémente de 1 le nombre de combinaisons retirées
			node--;														// et, particulier, décrémente de 1 l'index de la boucle     !** voir commentaire plus bas ligne 133 **!
		}                                                               // pour se repositionner et donc éviter de passer au dessus d'un noeud.
	}

	return removedCombinations;											// Retour du nombre de combinaisons retirées.


   /******************************************* Explication de notre logique pour la méthode cleanList() ***************************************************************
	
	Notre premier jet impliquait une boucle while et la déclaration de 2 variables de type Iterator<Combination>. 
	Nous utilisions un itérateur "b" pour conserver la valeur de l'itérateur "a" puisqu'on retirait la valeur de la 
	liste. (l'itérateur "a" se retrouvait à pointer sur du "junk")
	
	Nous avons observé le code et remarqué que la méthode getElement() itère déjà dans la liste et que getNbElement() nous donne aussi la longueur de la liste. 
	Nous les avons donc mis à profit. De plus, une mécanique particulière s'est imposée : nous avons observé une situation où certaines combinaisons étaient 
	ignorées lors des itérations. Cette situation nous a amené à découpé, débogué et inspecté chaque itération pour constater un phénomène de sauts involontaires
	de combinaisons. Finalement, nous avons réglé le problème avec une décrémentation de l'index de la boucle (node) (si une combinaison est retirée de la liste). 
	
	Voici une représentation graphique qui explique l'utilisation de la décrémentation:
	
	Voici une liste de 7 index:						0   1   2   3   4   5   6

	Lorsqu'un index est retiré nous décrémentons la longueur de la liste puisque nous utilisons getElement() qui redéfini un itérateur sur une liste qui  
	a été raccourcie.
													0   1   2   3   4   5 

	Mais une situation spéciale s'observe:		    index retiré, valeur 3
													0   1   2   *   4   5
													liste raccourcie de 1
													0   1   2  <-3(4) <-4(5)
							incrémentation de l'itérateur dans getElement() (++iter) maintenant valeur 4
													0   1   2  "3"->4
								    le nouvel index 3, précédemment 4, a donc été ignoré.
				      décrémentation de l'index (node--) pour se remettre à la bonne position dans la liste.

	La boucle se déplace en "Back & Forth" lors d'une suppression et itère normalement lorsqu'il n'y a pas de suppressions. Nous 
	avons choisi cette logique car elle réutilise des méthodes existantes et cela évite de déclaré 2 itérateurs supplémentaires. 
	La méthode est donc optimisée, très concise et verbeuse. Elle peut être lue et comprise comme un texte ;-).
    *****************************************************************************************************************************************************************/
}

/// <summary>
/// Génération de la liste chainée de combinaisons
/// </summary>
/// <param name="_list"> Liste déclarée dans ConsoleMenu mais vide, seulement instanciée. </param>
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
/// Ajout des combinaison de la liste dans le tableau prévu pour conserver
/// les adresses permettant leur suppression dans le destructeur.
/// </summary>
/// <param name="_list"> Liste nouvellement créée. </param>
void Mastermind::fillTab()
{
	for (short index = 0; index < LISTLENGTH; index++)
	{
		tabCombinations[index] = this->getElement(index);
	}
}

								/********************************************************************************************
								Les deux méthodes suivantes ont une logique semblable, mais les avoir mis en une seule méthode
								aurais amené le besoin d'un 4ième paramètre et séparer les 2 utilisations par un "if". Puisque
								les 2 méthodes ont des paramètre différent et une légère différence dû à un index ignoré ou
								pas, nous avons décidé de séparer le travail dans 2 méthodes (simple query responsibility).
								********************************************************************************************/


/// <summary>
/// Vérifie si une combinaison contient une couleur précise, excepté à un index spécifié
/// </summary>
/// <param name="_toValidate"> Combinaison à vérifier. </param>
/// <param name="_color"> Couleur à rechercher. </param>
/// <param name="_forbiddenIndex"> Index spécifié dans la boucle cleanList(). </param>
/// <returns> Booléen, est présent ou pas. </returns>
bool Mastermind::containsColorOnOtherIndex(Combination* _toValidate, Color _color, short _forbiddenIndex) const
{
	Color colorValidate = NULL;												// Semblable à la même logique que la méthode Contains() en c#, mais
																			// ne regarde pas la valeur à l'index présent qui devient "interdit"
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

/// <summary>
/// Vérifie si une combinaison contient une couleur précise
/// </summary>
/// <param name="_toValidate"> Combinaison à vérifier. </param>
/// <param name="_color"> Couleur à rechercher. </param>
/// <returns> Booléen, est présent ou pas. </returns>
bool Mastermind::containsColor(Combination* _toValidate, Color _color) const
{
	Color colorValidate = NULL;												// Exactement la même logique que la méthode Contains() en c#.

	for (short value = 0; value < VERDICTS_LENGTH; value++)
	{
		colorValidate = _toValidate->getColor(value);

		if (colorValidate == _color)
		{
			return true;
		}
	}

	return false;
}
