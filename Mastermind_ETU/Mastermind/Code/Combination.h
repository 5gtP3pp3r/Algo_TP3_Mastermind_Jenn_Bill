#pragma once
#include "Color.h"

class Combination
{
public:
	Combination(Color _c1, Color _c2, Color _c3, Color _c4);
	~Combination();
	void display() const;

	Color getColor(int index);

	bool operator < (const Combination& _combinaison) const;
	bool operator > (const Combination& _combinaison) const;
	bool operator == (const Combination& _combinaison) const;
    bool operator != (const Combination& _combinaison) const;

private:
	static const unsigned int NB_COLORS = 4;
	Color tabColors[NB_COLORS];
};

