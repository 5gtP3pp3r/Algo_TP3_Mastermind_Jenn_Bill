#include "Color.h"


Color::Color(void)
{
    color = 0;
}
Color::Color(short _c)
{
    color = _c;
}
Color::~Color(void){}

ostream& operator<<(ostream& sortie, const Color& c)
{
    
    switch(c.color){
        case 1:
            sortie<<"Rouge";
            break;
        case 2:
            sortie<<"Vert";
            break;
        case 3:
            sortie<<"Bleu";
            break;
        case 4:
            sortie<<"Jaune";
            break;
        case 5:
            sortie<<"Noir";
            break;
        case 6:
            sortie<<"Orange";
            break;
        case 7:
            sortie<<"Mauve";
            break;
        case 8:
            sortie<<"Blanc";
            break;
    };
    return sortie;
}

bool Color::operator==(const Color& c)
{ 
    return color == c.color;
}

bool Color::operator>(const Color& c){
    return color > c.color;
}

bool Color::operator<(const Color& c){
    return color < c.color;
}

bool Color::operator!=(const Color& c){
    return color != c.color;
}

void Color::operator=(const Color& c){
    color = c.color;
}

short Color::convertToNumeric(){
    return color;
}

void Color::setColor(short _c){
    color = _c;
}

short Color::getColor()
{
    return this->color;
}
