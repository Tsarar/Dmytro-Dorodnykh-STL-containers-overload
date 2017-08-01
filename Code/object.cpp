#include "object.h"
#include <iostream>

        std::ostream& operator << (std::ostream &s, Object &obj) {
                    s << "\nA: " << obj.getA();
                    s << "\nB: " << obj.getB();
                    s << "\nC: " << obj.getC() << "\n";
                    return s;
                };

        std::ifstream& operator >> (std::ifstream &s, Object &obj) {
                int buf;
                std::string bufS;

                std::cout << "Enter A\n";
                std::cin >> buf;
                obj.setA(buf);

                std::cout << "Enter B\n";
                std::cin >> bufS;
                obj.setB(bufS);

                std::cout << "Enter C\n";
                std::cin >> buf;
                obj.setC(buf);

                return s;
        };

        void Object::operator = (const Object &obj)
            {
                this->setA(obj.getA());
                this->setB(obj.getB());
                this->setC(obj.getC());
            };

        bool Object::operator == (const Object &obj)
            {
                return ((this->getA())==(obj.getA())) ?  true : false;
            };

        bool Object::operator >= (const Object &obj)
            {
                return ((this->getA())>=(obj.getA())) ?  true : false;
            };

        bool Object::operator <= (const Object &obj)
            {
                return ((this->getA())<=(obj.getA())) ?  true : false;
            };

        bool Object::operator > (const Object &obj)
            {
                return ((this->getA())>(obj.getA())) ?  true : false;
            };

        bool Object::operator < (const Object &obj)
            {
                return ((this->getA())<(obj.getA())) ?  true : false;
            };
