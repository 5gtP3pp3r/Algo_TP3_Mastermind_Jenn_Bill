#pragma once
#include <iostream>
using namespace std;

class Color{
public:
    Color(void);
    Color(short _c);
    ~Color(void);

    friend ostream& operator<<(ostream& sortie, const Color& c);

    bool operator==(const Color& _c);

    bool operator>(const Color& _c);

    bool operator<(const Color& _c);

    bool operator!=(const Color& _c);

    void operator=(const Color& _c);
 
    short convertToNumeric();

    void setColor(short _c);
    short getColor();

private:
    short color;
};

