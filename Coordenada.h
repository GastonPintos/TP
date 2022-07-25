#ifndef COORDENADA_H
#define COORDENADA_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class coordenada{
    private:
        int coordHorizontal;
        int coordVertical;

    public:
        coordenada(){coordHorizontal=0; coordVertical=0;};
        coordenada(int horizontal, int vertical) {coordHorizontal=horizontal; coordVertical=vertical;};

        int GetHorizontal(){ return coordHorizontal; };
        int GetVertical() { return coordVertical; };

        void SetHorizontal(int horizontal) { coordHorizontal = horizontal;};
        void SetVertical(int vertical ) { coordVertical = vertical;};

        friend coordenada& operator +(const coordenada &p1,const coordenada &p2)
        {
            return *(new coordenada(p1.coordHorizontal + p2.coordHorizontal, p1.coordVertical + p2.coordVertical) );
        };

        friend ostream& operator<<(ostream& os, const coordenada& coord){
            os << "(" << coord.coordHorizontal << " " << coord.coordVertical << ")";
            return os;
        };
};

#endif