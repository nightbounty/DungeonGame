#include <string>
#ifndef VECTOR2
#define VECTOR2
using namespace std;

class Vector2 {

    private:
        int x;
        int y;

    public:
        Vector2();
        Vector2(int x, int y);
        void Set(int x, int y);
        void SetX(int x);
        void SetY(int y);
        int GetX();
        int GetY();
        string ToString();

};

#endif
