#ifndef OBJECT_H
#define OBJECT_H

#include "string"

class Object {
        int a;
        std::string b;
        int c;
public:
        Object() { a=0; b=""; c=0;};
        Object(int a, std::string b, int c) { setA(a); setB(b); setC(c);};
        Object(Object &a) { setA(a.getA()); setB(a.getB()); setC(a.getC());};
        virtual ~Object() {};
        void setA(int x) {a=x;};
        void setB(std::string x) {b=x;};
        void setC(int x) {c=x;};
        int getA() const {return a;};
        std::string getB() const {return b;};
        int getC() const {return c;};
        friend std::ostream& operator << (std::ostream &s, Object &obj);
        friend std::ifstream& operator >> (std::ifstream &s, Object &obj);
        void operator = (const Object &obj);
        bool operator == (const Object &obj);
        bool operator >= (const Object &obj);
        bool operator <= (const Object &obj);
        bool operator > (const Object &obj);
        bool operator < (const Object &obj);
    };

#endif // OBJECT_H
