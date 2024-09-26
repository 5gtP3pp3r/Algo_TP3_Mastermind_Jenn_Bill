#include "Combination.h"
#include "constants.h"


Combination::Combination(Color c1, Color c2, Color c3, Color c4)

/******************************************************************************************************************
*Cette surcharge d'op�rateur a �t� impl�ment� simplement pour le plaisir de bien monter la liste chain�e selon    *
*la logique qu'elle doit utiliser. Soit la comparaison < et > pour l'insertion des objets � la bonne positions.   *
*N'est pas n�cessaire � la compl�tion du TP3 Mastermind car les combinaisons ne sont pas compar�es avec leur      *
*valeur num�rique. La composition des surcharges est simplement un plaisir personnel pour voir les bons r�sultats.*
*Surcharges compos� par William.
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
/// Surcharge de l'op�rateur "<"
/// </summary>
/// <param name="_combination"> R�f�rence de la combinaison � comparer avec la combinaison pr�sente "this". </param>
/// <returns> bool�en vrai ou faux. </returns>
bool Combination::operator < (const Combination& _combination) const
{																					// D�claration leftHand repr�sente "this" ou 
	int leftHand = 0;																// D�claration rightHand
	int rightHand = 0;																// la combinaison de gauche dans une �quation.
	int multiplier = 1000;															// D�claration d'une "puissance". La valeur d'une combinaison
	for (short color = 0; color < COMBINATION_LENGTH; color++)						// sera comparable � un nombre de 3 puissances (3, 2, 1, 0)	
	{
		leftHand += this->tabColors[color].convertToNumeric() * multiplier;
		rightHand += _combination.tabColors[color].convertToNumeric() * multiplier;	// Conversion de la couleur de l'index pr�sent en sa valeur num�rique
		multiplier /= 10;															// Division de la puissance pour changer la valeur de la couleur
	}																				// dans la combinaison exemple: rouge, rouge, rouge, rouge = 1111.

	return leftHand < rightHand;
}

/// <summary>
/// Surcharge de l'op�rateur ">" est par d�finition le contraire de "<"
/// </summary>
/// <param name="_combination"> R�f�rence de la combinaison � comparer avec la combinaison pr�sente "this". </param>
/// <returns> bool�en vrai ou faux. </returns>
bool Combination::operator > (const Combination& _combination) const
{
	return !(*this < _combination);													// R�utilisation de la m�me logique que la surcharge "!=" fournie.
}

/// <summary>
/// Surcharge de l'op�rateur "=="
/// </summary>
/// <param name="_combination"> R�f�rence de la combinaison � comparer avec la combinaison pr�sente "this". </param>
/// <returns> bool�en vrai ou faux. </returns>
bool Combination::operator == (const Combination& _combination) const
{
	for (int color = 0; color < COMBINATION_LENGTH; ++color)						// Un simple retour == retournait une boucle 
	{																				// infinie pour des raisons inconnues.
		if (this->tabColors[color] != _combination.tabColors[color])
		{																			// Une it�ration dans les combinaisons compare chaque
			return false;															// couleur par leur type de base et retourne faux si																					
		}																			// Une in�galit� est d�couverte.
	}
	return true;
}

/// <summary>
/// Surcharge de l'op�rateur "!=" par d�finition le contraire de "=="
/// </summary>
/// <param name="_combination"> R�f�rence de la combinaison � comparer avec la combinaison pr�sente "this". </param>
/// <returns> bool�en vrai ou faux. </returns>
bool Combination::operator != (const Combination& _combination) const
{
	return !(*this == _combination);
}

/// <summary>
/// Affiche une combinaison avec ses couleurs.
/// </summary>
void Combination::display() const
{
	cout << "[" << tabColors[0] << ", "												// Red�finition de display pour un teste d'affichage
		<< tabColors[1] << ", "														// des combinaison de la liste plus lisible.
		<< tabColors[2] << ", "
		<< tabColors[3] << "]" << endl;
	/*cout << tabColors[0] << endl;
	cout << tabColors[1] << endl;
	cout << tabColors[2] << endl;
	cout << tabColors[3] << "]" << endl;*/
}
