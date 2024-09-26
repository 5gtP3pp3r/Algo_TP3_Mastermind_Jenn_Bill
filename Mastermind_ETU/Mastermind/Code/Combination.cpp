#include "Combination.h"
#include "constants.h"


Combination::Combination(Color c1, Color c2, Color c3, Color c4)

/******************************************************************************************************************
*Cette surcharge d'opérateur a été implémenté simplement pour le plaisir de bien monter la liste chainée selon    *
*la logique qu'elle doit utiliser. Soit la comparaison < et > pour l'insertion des objets à la bonne positions.   *
*N'est pas nécessaire à la complétion du TP3 Mastermind car les combinaisons ne sont pas comparées avec leur      *
*valeur numérique. La composition des surcharges est simplement un plaisir personnel pour voir les bons résultats.*
*Surcharges composé par William.
******************************************************************************************************************/
{
	tabColors[0] = c1;
	tabColors[1] = c2;
	tabColors[2] = c3;
	tabColors[3] = c4;
}

Color Combination::getColor(int index)
{
	if (index < 0 || index > 3) throw invalid_argument("Votre index n'est pas entre 0 et 3");
	return tabColors[index];
}

Combination::~Combination()
{
	;
}


/// <summary>
/// Surcharge de l'opérateur "<"
/// </summary>
/// <param name="_combination"> Référence de la combinaison à comparer avec la combinaison présente "this". </param>
/// <returns> booléen vrai ou faux. </returns>
bool Combination::operator < (const Combination& _combination) const
{																					// Déclaration leftHand représente "this" ou 
	int leftHand = 0;																// Déclaration rightHand
	int rightHand = 0;																// la combinaison de gauche dans une équation.
	int multiplier = 1000;															// Déclaration d'une "puissance". La valeur d'une combinaison
	for (short color = 0; color < COMBINATION_LENGTH; color++)						// sera comparable à un nombre de 3 puissances (3, 2, 1, 0)	
	{
		leftHand += this->tabColors[color].convertToNumeric() * multiplier;
		rightHand += _combination.tabColors[color].convertToNumeric() * multiplier;	// Conversion de la couleur de l'index présent en sa valeur numérique
		multiplier /= 10;															// Division de la puissance pour changer la valeur de la couleur
	}																				// dans la combinaison exemple: rouge, rouge, rouge, rouge = 1111.

	return leftHand < rightHand;
}

/// <summary>
/// Surcharge de l'opérateur ">" est par définition le contraire de "<"
/// </summary>
/// <param name="_combination"> Référence de la combinaison à comparer avec la combinaison présente "this". </param>
/// <returns> booléen vrai ou faux. </returns>
bool Combination::operator > (const Combination& _combination) const
{
	return !(*this < _combination);													// Réutilisation de la même logique que la surcharge "!=" fournie.
}

/// <summary>
/// Surcharge de l'opérateur "=="
/// </summary>
/// <param name="_combination"> Référence de la combinaison à comparer avec la combinaison présente "this". </param>
/// <returns> booléen vrai ou faux. </returns>
bool Combination::operator == (const Combination& _combination) const
{
	for (int color = 0; color < COMBINATION_LENGTH; ++color)						// Un simple retour == retournait une boucle 
	{																				// infinie pour des raisons inconnues.
		if (this->tabColors[color] != _combination.tabColors[color])
		{																			// Une itération dans les combinaisons compare chaque
			return false;															// couleur par leur type de base et retourne faux si																					
		}																			// Une inégalité est découverte.
	}
	return true;
}

/// <summary>
/// Surcharge de l'opérateur "!=" par définition le contraire de "=="
/// </summary>
/// <param name="_combination"> Référence de la combinaison à comparer avec la combinaison présente "this". </param>
/// <returns> booléen vrai ou faux. </returns>
bool Combination::operator != (const Combination& _combination) const
{
	return !(*this == _combination);
}

/// <summary>
/// Affiche une combinaison avec ses couleurs.
/// </summary>
void Combination::display() const
{
	cout << "[" << tabColors[0] << ", "												// Redéfinition de display pour un teste d'affichage
		<< tabColors[1] << ", "														// des combinaison de la liste plus lisible.
		<< tabColors[2] << ", "
		<< tabColors[3] << "]" << endl;
	/*cout << tabColors[0] << endl;
	cout << tabColors[1] << endl;
	cout << tabColors[2] << endl;
	cout << tabColors[3] << "]" << endl;*/
}
