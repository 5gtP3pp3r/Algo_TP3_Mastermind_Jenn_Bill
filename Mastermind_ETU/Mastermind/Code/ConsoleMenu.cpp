#include "ConsoleMenu.h"
#include "ConsoleColor.h"
#include "Mastermind.h"
#include "constants.h"
#include <iostream>
#include <time.h>  

ConsoleMenu::ConsoleMenu()
{
    ;
}

ConsoleMenu::~ConsoleMenu()
{
    ;
}

/// <summary>
/// La méthode Run est le point central de notre programme.
/// </summary>
void ConsoleMenu::run()
{
    LinkedList<Combination>* list = new LinkedList<Combination>;
    bool gameContinue = true;

    while (gameContinue) {

        Mastermind mastermind(list);
        //list->display();  // Test si la liste existe.
        Color tabColors[COMBINATION_LENGTH]; //4 couleurs parmi un choix de 8

        if (readSequence(tabColors))
        {
            short nbTries = 0;

            cout << endl << endl << "##############################Debut de la partie##############################" << endl << endl;
            while (true) {

                if (nbTries == MAX_TRIES) {
                    cout << "Le nombre maximum d'essais a atteint la limite (8). Je perds..." << endl << endl;
                    break;
                }
                int iNbElements = mastermind.getNbElements();
                if (iNbElements == 0) { //Il ne reste plus de combinaison dans la liste, l'utilisateur a fait assurément une erreur car Mastermind ne se trompe pas!
                    cout << "La liste de combinaisons possibles est epuisee." << endl << endl;;
                    break;
                }
                nbTries++;


                cout << "NbElements:" << iNbElements << endl;

                //Obtention de la combinaison de couleur de référence
                srand((unsigned int)time(NULL));
                int nbElements = mastermind.getNbElements();
                int nombreAleatoire = rand() % nbElements;
                Combination* pickedCombination = mastermind.getElement(nombreAleatoire);
                
                cout << green << "--------Couleurs a deviner:        " << tabColors[0] << " "
                    << tabColors[1] << " "
                    << tabColors[2] << " "
                    << tabColors[3] << " "
                    << "--------"
                    << endl;


                cout << blue << endl << "Choix du Mastermind (" << "essai #" << nbTries << "):    " << pickedCombination->getColor(0) << " "
                    << pickedCombination->getColor(1) << " "
                    << pickedCombination->getColor(2) << " "
                    << pickedCombination->getColor(3) << " "
                    << endl << endl;

                short tabVerdicts[VERDICTS_LENGTH];

                readVerdicts(pickedCombination, tabVerdicts);

                if (isGameOver(tabVerdicts))
                {
                    displayResult(nbTries);
                    gameContinue = false;
                    break;
                }
                else
                {
                    //------------------------Epuration de la liste des combinaisons qui ne respectent pas les critères-----------------------------
                    cout << mastermind.cleanList(pickedCombination, tabVerdicts) << " combinaisons supprimees." << endl;
                }
            }
        }
        else
        {
            gameContinue = false;
            cout << "Au revoir!" << endl;
        }
    }

    delete list;
}

/// <summary>
/// Permet de choisir une séquence de 4 couleurs afin de débuter le jeu
/// </summary>
/// <param name="tabCouleurs">Tableau des 4 couleurs à choisir pour le jeu</param>
/// <returns>Retourne true si on a choisi une séqunec pour jouer et false si on désire quitter la partie</returns>
bool ConsoleMenu::readSequence(Color tabColors[])
{
    cout << "Veuillez entrer une sequence de 4 couleurs parmi les suivantes:" << endl << endl;
    cout << "    1-Rouge" << endl;
    cout << "    2-Vert" << endl;
    cout << "    3-Bleu" << endl;
    cout << "    4-Jaune" << endl;
    cout << "    5-Noir" << endl;
    cout << "    6-Orange" << endl;
    cout << "    7-Mauve" << endl;
    cout << "    8-Blanc" << endl;

    string choix;
    do {
        cout << "Entrer la suite de chiffres, 0 pour sortir: ";
        cin >> choix;

        if (choix == "0")
            return false;

        if (choix.length() == COMBINATION_LENGTH) {
            tabColors[0].setColor(atoi(choix.substr(0, 1).c_str()));
            tabColors[1].setColor(atoi(choix.substr(1, 1).c_str()));
            tabColors[2].setColor(atoi(choix.substr(2, 1).c_str()));
            tabColors[3].setColor(atoi(choix.substr(3, 1).c_str()));

        }
    } while (choix.length() != COMBINATION_LENGTH || tabColors[0] > NB_COLORS || tabColors[1] > NB_COLORS || tabColors[2] > NB_COLORS || tabColors[3] > NB_COLORS);

    cout << "Couleurs choisies: " << tabColors[0] << " "
        << tabColors[1] << " "
        << tabColors[2] << " "
        << tabColors[3] << " "
        << endl;

    return true;
}

bool ConsoleMenu::isGameOver(short tabVerdicts[])
{
    bool isGameOver = false;
    if (tabVerdicts[0] == VERDICT_RIGHT_PLACE 
        && tabVerdicts[1] == VERDICT_RIGHT_PLACE 
        && tabVerdicts[2] == VERDICT_RIGHT_PLACE 
        && tabVerdicts[3] == VERDICT_RIGHT_PLACE) {
        return true;
    }
    return isGameOver;
}

void ConsoleMenu::readVerdicts(Combination* currentCombination, short tabVerdicts[])
{
    //Lecteur des 4 verdicts de l'usager
    for (int i = 0; i < VERDICTS_LENGTH; i++) {
        do {
            string entree;

            Color c = currentCombination->getColor(i);

            cout << white << endl << "Couleur " << i + 1 << " - " << currentCombination->getColor(i) << endl;
            cout << "Choisir (1-Bonne place 2-Bonne couleur 3-Mauvaise couleur): ";

            cin >> entree;
            tabVerdicts[i] = atoi(entree.c_str());
        } while (tabVerdicts[i] != VERDICT_RIGHT_PLACE 
            && tabVerdicts[i] != VERDICT_GOOD_COLOR_WRONG_PLACE 
            && tabVerdicts[i] != VERDICT_NO_COLOR);
    }
}

void ConsoleMenu::displayResult(short nbCoups)
{   
    cout << endl << "J'ai trouve la reponse apres " << nbCoups;
    if (nbCoups == 1) {
        cout << " essai. Merci d'avoir joue avec moi." << endl << endl;
    }
    else {
        cout << " essais. Merci d'avoir joue avec moi." << endl << endl;
    }
    cout << "----The Mastermind----" << endl << endl;
        
}
