#pragma once
#include "Combination.h"
#include "Color.h"

//Ctrl-click pour aller dans votre
#include <LinkedList.h>

const int NB_POSSIBLE_COMBINATIONS = 4096;

class Mastermind
{
public:
  
    Mastermind(LinkedList<Combination>* _list);
    ~Mastermind();

    int getNbElements() const;
    Combination* getElement(int _index) const;

    int cleanList(Combination* _ref, short* _tabVerdicts);

private:

	bool isPossibleCombination(Combination* _toValidate, Combination* _ref, short* _tabVerdicts) const;
    Combination* tabCombinations[NB_POSSIBLE_COMBINATIONS];
    LinkedList<Combination>* list; //Contient toutes les combinaisons de couleurs possibles, selon le contexte.

    void generateList(LinkedList<Combination>* _list);
    void fillTab(LinkedList<Combination>* _list);
    bool containsColorWithForbiddenIndex(Combination* _toValidate, Color _color, short _forbiddenIndex) const;
    bool containsColor(Combination* _toValidate, Color _color) const;
};
