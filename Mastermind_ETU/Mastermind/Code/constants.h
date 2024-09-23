#pragma once

//Nombre de couleurs maximales dans le jeu
const int NB_COLORS = 8;

//Longueur d'une combinaison
const int COMBINATION_LENGTH = 4;

//Longueur maximum de la liste et tableau des combinaisons
// NB_COLORS exposant COMBINATION_LENGTH (8^4 ou (8*8*8*8)) = 4096
const int LISTLENGTH = pow(NB_COLORS, COMBINATION_LENGTH);

//Longueur du tableau des verdicts
const int VERDICTS_LENGTH = 4;

//Nombre d'essais maximal du Mastermind
const int MAX_TRIES = 8;

//Les indicateurs de verdict
const int VERDICT_RIGHT_PLACE = 1;
const int VERDICT_GOOD_COLOR_WRONG_PLACE = 2;
const int VERDICT_NO_COLOR = 3;


