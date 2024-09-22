#include "Combination.h"
#include "constants.h"


Combination::Combination(Color c1, Color c2, Color c3, Color c4)
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
}

bool Combination::operator < (const Combination& _combination) const
{
	int left = 0;
	int multiplier = 1000;
	for (short color = 0; color < COMBINATION_LENGTH; color++)
	{
		left += tabColors[color].convertToNumeric() * multiplier;
		multiplier /= 10;
	}

	int right = 0;
	multiplier = 1000;
	for (short color = 0; color < COMBINATION_LENGTH; color++)
	{
		right += _combination.tabColors[color].convertToNumeric() * multiplier;
		multiplier /= 10;
	}

	return left < right;
}

bool Combination::operator > (const Combination& _combination) const
{
	int left = 0;
	int multiplier = 1000;
	for (short color = 0; color < COMBINATION_LENGTH; color++)
	{
		left += tabColors[color].convertToNumeric() * multiplier;
		multiplier /= 10;
	}

	int right = 0;
	multiplier = 1000;
	for (short color = 0; color < COMBINATION_LENGTH; color++)
	{
		right += _combination.tabColors[color].convertToNumeric() * multiplier;
		multiplier /= 10;
	}

	return left > right;
}

bool Combination::operator == (const Combination& _combination) const
{
	for (int color = 0; color < COMBINATION_LENGTH; ++color)
	{
		if (this->tabColors[color] != _combination.tabColors[color])
		{
			return false;
		}
	}
	return true;
}

bool Combination::operator != (const Combination& _combination) const
{
	return !(*this == _combination);
}

void Combination::display() const
{
	cout << "[" << tabColors[0] << ", "
		<< tabColors[1] << ", "
		<< tabColors[2] << ", "
		<< tabColors[3] << "]" << endl;
	/*cout << tabColors[0] << endl;
	cout << tabColors[1] << endl;
	cout << tabColors[2] << endl;
	cout << tabColors[3] << "]" << endl;*/
}
