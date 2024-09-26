#include "Mastermind.h"
#include "constants.h"


Mastermind::Mastermind(LinkedList<Combination>* _list)

													/******************************************************
													* Tout le travail a �t� compos� � 2 co�quipiers sauf  *
													* si pr�cis� autrement. (tests, surcharge Combinaison)*
													******************************************************/
{
	generateList(_list);	
	list = _list;
	fillTab();
	//list->display();
	/*for (int node = 0; node < LISTLENGTH; node++)						// Test d'affichage liste chain�e et tableau.
	{
		tabCombinations[node]->display();
	}*/
}

Mastermind::~Mastermind()
{
	for (short node = 0; node < LISTLENGTH; node++)
	{
		delete tabCombinations[node];									// Nous conservons les adresses des combinaisons dans un tableau afin de
	}																	// conserver une "poign�" dessus et pouvoir les d�truires � la fin du programmes.
}

/// <summary>
/// Retourne le nombre d'�l�ments dans la liste chain�e.
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
/// en relation avec les qualit�s de chaque couleur des combinaisons du tableau _tabVerdicts
/// </summary>
/// <param name="_toValidate"> Combinaison de la liste � valider. </param>
/// <param name="_tried"> Combinaison al�atoire � comparer avec chaque combinaisons de la liste � valider. </param>
/// <param name="_tabVerdicts"> Tableau contenant la qualit� de chaque couleurs de la combinaison "_tried". </param>
/// <returns> Retour bool�en sur la validit� des combinaisons de la liste. </returns>
bool Mastermind::isPossibleCombination(Combination* _toValidate, Combination* _tried, short* _tabVerdicts) const
{
	Color colorTried = NULL;												// D�claration de type couleur pour la combinaison 
	Color colorValidate = NULL;												// _tried et chaque combinaisons de la liste.
	bool isCondition3 = true;

	for (short value = 0; value < VERDICTS_LENGTH; value++)					// It�ration � la longueur de _tabVerdicts (4).
	{
		colorTried = _tried->getColor(value);								// Attribution des valeurs des couleurs en relation 
		colorValidate = _toValidate->getColor(value);						// avec les it�rations du tableau _tabVerdicts.

		if (_tabVerdicts[value] == 1 && colorTried != colorValidate)		// Si la qualit� est 1 (bonne couleur, bonne position) et les couleurs sont
		{																	// diff�rentes, la combinaison de la liste est invalide. Donc retir�e dans cleanList().
			return false;
		}
		if (_tabVerdicts[value] == 2 && colorTried == colorValidate)		// Si la qualit� est 2 (bonne couleur, mauvaise position) et les couleurs sont 
		{																	// identiques au meme index, la combinaison de la liste est invalide. Donc retir�e dans cleanList().
			return false;
		}
		if (_tabVerdicts[value] == 2 && colorTried != colorValidate)		// Si la qualit� est 2 (bonne couleur, mauvaise position), 
		{																	// et que les couleurs sont diff�rentes au meme index,
			if (!containsColorOnOtherIndex(_toValidate, colorTried, value))	// appel de la m�thode containsColorOnOtherIndex(), si la couleur
			{																// n'est pas � un autre index, la combinaison de
				return false;												// la liste est invalide. Donc retir�e dans cleanList().
			}
		}		
		if (_tabVerdicts[value] == 3)										// Si la qualit� est 3 (mauvaise couleur),
		{
			if (containsColor(_toValidate, colorTried))						// appel de la m�thode containsColor, si la couleur
			{																// est trouv�e, la combinaison est invalide. 
				return false;												// Donc retir�e dans cleanList().
			}
		}
	}
	return true;															// Si aucune condition ne s'applique, la combinaison
}																			// est bonne et restera dans la liste.

/// <summary>
/// Logique de retrait des combinaisons de la liste chain�e. It�re la liste et envoi � la m�thode
/// isPossibleCombinaison la combinaison pr�sente de la liste, la combinaison essay�e par le cpu et 
/// la qualit� entr�e par l'utilisateur. Retirera de la liste une combinaison invalide.
/// � chaque suppression, une valeur est incr�ment�e pour retourner le nombre de combinaisons retir�es.
/// </summary>
/// <param name="_ref"> Combinaison choisie par le cpu. </param>
/// <param name="_tabVerdicts"> Qualit� de la combinaison entr�e par l'utilisateur. </param>
/// <returns> Nombre de combinaisons retir�es. </returns>
int Mastermind::cleanList(Combination* _ref, short* _tabVerdicts)
{
	short removedCombinations = 0;										// D�claration d'une variable pour retourner le nombre de combinaison retir�es.
	short listLength = LISTLENGTH;										// D�claration d'une variable qui contient la longueur de la liste � l'origine.
	Combination* combToValidate = NULL;									// D�claration d'un type pointeur de Combination.

	for (short node = 0; node < listLength; node++)						// It�ration � la longueur de la liste
	{
		combToValidate = this->getElement(node);						// Attribution de la valeur de la combinaison pr�sente.
		if (!isPossibleCombination(combToValidate, _ref, _tabVerdicts))	// Appel de la m�thode isPossibleCombination avec les param�tres pertinents.
		{
			list->remove(combToValidate);								// Si la combinaison est invalide, on retire la combinaison de la liste,
			listLength--;												// d�cr�mente de 1 la longueur de la boucle puisqu'on a retir�e une combinaison,
			removedCombinations++;										// incr�mente de 1 le nombre de combinaisons retir�es
			node--;														// et, particulier, d�cr�mente de 1 l'index de la boucle     !** voir commentaire plus bas ligne 133 **!
		}                                                               // pour se repositionner et donc �viter de passer au dessus d'un noeud.
	}

	return removedCombinations;											// Retour du nombre de combinaisons retir�es.


   /******************************************* Explication de notre logique pour la m�thode cleanList() ***************************************************************
	
	Notre premier jet impliquait une boucle while et la d�claration de 2 variables de type Iterator<Combination>. 
	Nous utilisions un it�rateur "b" pour conserver la valeur de l'it�rateur "a" puisqu'on retirait la valeur de la 
	liste. (l'it�rateur "a" se retrouvait � pointer sur du "junk")
	
	Nous avons observ� le code et remarqu� que la m�thode getElement() it�re d�j� dans la liste et que getNbElement() nous donne aussi la longueur de la liste. 
	Nous les avons donc mis � profit. De plus, une m�canique particuli�re s'est impos�e : nous avons observ� une situation o� certaines combinaisons �taient 
	ignor�es lors des it�rations. Cette situation nous a amen� � d�coup�, d�bogu� et inspect� chaque it�ration pour constater un ph�nom�ne de sauts involontaires
	de combinaisons. Finalement, nous avons r�gl� le probl�me avec une d�cr�mentation de l'index de la boucle (node) (si une combinaison est retir�e de la liste). 
	
	Voici une repr�sentation graphique qui explique l'utilisation de la d�cr�mentation:
	
	Voici une liste de 7 index:						0   1   2   3   4   5   6

	Lorsqu'un index est retir� nous d�cr�mentons la longueur de la liste puisque nous utilisons getElement() qui red�fini un it�rateur sur une liste qui  
	a �t� raccourcie.
													0   1   2   3   4   5 

	Mais une situation sp�ciale s'observe:		    index retir�, valeur 3
													0   1   2   *   4   5
													liste raccourcie de 1
													0   1   2  <-3(4) <-4(5)
							incr�mentation de l'it�rateur dans getElement() (++iter) maintenant valeur 4
													0   1   2  "3"->4
								    le nouvel index 3, pr�c�demment 4, a donc �t� ignor�.
				      d�cr�mentation de l'index (node--) pour se remettre � la bonne position dans la liste.

	La boucle se d�place en "Back & Forth" lors d'une suppression et it�re normalement lorsqu'il n'y a pas de suppressions. Nous 
	avons choisi cette logique car elle r�utilise des m�thodes existantes et cela �vite de d�clar� 2 it�rateurs suppl�mentaires. 
	La m�thode est donc optimis�e, tr�s concise et verbeuse. Elle peut �tre lue et comprise comme un texte ;-).
    *****************************************************************************************************************************************************************/
}

/// <summary>
/// G�n�ration de la liste chain�e de combinaisons
/// </summary>
/// <param name="_list"> Liste d�clar�e dans ConsoleMenu mais vide, seulement instanci�e. </param>
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
					_list->add(new Combination(Color(c1), Color(c2), Color(c3), Color(c4)));	// d�claration et ajout d'une combinaison de 4 couleurs
				}																				// en relation avec la position des boucles.
			}
		}
	}
}

/// <summary>
/// Ajout des combinaison de la liste dans le tableau pr�vu pour conserver
/// les adresses permettant leur suppression dans le destructeur.
/// </summary>
/// <param name="_list"> Liste nouvellement cr��e. </param>
void Mastermind::fillTab()
{
	for (short index = 0; index < LISTLENGTH; index++)
	{
		tabCombinations[index] = this->getElement(index);
	}
}

								/********************************************************************************************
								Les deux m�thodes suivantes ont une logique semblable, mais les avoir mis en une seule m�thode
								aurais amen� le besoin d'un 4i�me param�tre et s�parer les 2 utilisations par un "if". Puisque
								les 2 m�thodes ont des param�tre diff�rent et une l�g�re diff�rence d� � un index ignor� ou
								pas, nous avons d�cid� de s�parer le travail dans 2 m�thodes (simple query responsibility).
								********************************************************************************************/


/// <summary>
/// V�rifie si une combinaison contient une couleur pr�cise, except� � un index sp�cifi�
/// </summary>
/// <param name="_toValidate"> Combinaison � v�rifier. </param>
/// <param name="_color"> Couleur � rechercher. </param>
/// <param name="_forbiddenIndex"> Index sp�cifi� dans la boucle cleanList(). </param>
/// <returns> Bool�en, est pr�sent ou pas. </returns>
bool Mastermind::containsColorOnOtherIndex(Combination* _toValidate, Color _color, short _forbiddenIndex) const
{
	Color colorValidate = NULL;												// Semblable � la m�me logique que la m�thode Contains() en c#, mais
																			// ne regarde pas la valeur � l'index pr�sent qui devient "interdit"
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
/// V�rifie si une combinaison contient une couleur pr�cise
/// </summary>
/// <param name="_toValidate"> Combinaison � v�rifier. </param>
/// <param name="_color"> Couleur � rechercher. </param>
/// <returns> Bool�en, est pr�sent ou pas. </returns>
bool Mastermind::containsColor(Combination* _toValidate, Color _color) const
{
	Color colorValidate = NULL;												// Exactement la m�me logique que la m�thode Contains() en c#.

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
