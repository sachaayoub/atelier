

//EXERCICE 1

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <iterator>

template <typename It, typename T>
bool rechercher(It debut, It fin, const T& valeur) {
    while (debut != fin) {
        if (*debut == valeur) {
            return true;
        }
        ++debut;
    }
    return false;
}

void exercice1_main() {
    std::set<int> monEnsemble;
    for (int i = 1; i <= 100; ++i) {
        monEnsemble.insert(i);
    }

    bool trouveSet = rechercher(monEnsemble.begin(), monEnsemble.end(), 42);

    std::vector<std::string> vectStrings = { "Pomme", "Banane", "Orange" };
    bool trouveVectString = rechercher(vectStrings.begin(), vectStrings.end(), std::string("Banane"));

    float tabFloats[] = { 1.5f, 2.7f, 3.9f };
    bool trouveArrayFloat = rechercher(std::begin(tabFloats), std::end(tabFloats), 2.7f);

    std::cout << "\n// EXERCICE 1 //\n";
    std::cout << "Set: " << (trouveSet ? "Oui" : "Non") << "\n";
    std::cout << "String: " << (trouveVectString ? "Oui" : "Non") << "\n";
    std::cout << "Float: " << (trouveArrayFloat ? "Oui" : "Non") << "\n";
}


//EXERCICE 2

#include <iostream>
#include <stdexcept>
#include <ios>
#include <limits>

class Test {
public:
    static int tableau[10];
public:
    static int division(int indice, int diviseur) {
        if (indice < 0 || indice >= 10) {
            throw std::out_of_range("Indice hors limites.");
        }
        if (diviseur == 0) {
            throw std::runtime_error("Division par zero.");
        }
        return tableau[indice] / diviseur;
    }
};

int Test::tableau[] = { 17, 12, 15, 38, 29, 157, 89, -22, 0, 5 };

void exercice2_main() {
    int x, y;
    bool reussi = false;

    std::cout << "\n// EXERCICE 2 //\n";
    while (!reussi) {
        std::cout << "Indice: ";
        if (!(std::cin >> x)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cout << "Diviseur: ";
        if (!(std::cin >> y)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        try {
            int resultat = Test::division(x, y);
            std::cout << "Resultat: " << resultat << "\n";
            reussi = true;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Erreur: Indice. Reessayer.\n";
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Erreur: Zero. Arret.\n";
            throw;
        }
        catch (...) {
            std::cerr << "Erreur inconnue. Reessayer.\n";
        }
    }
}


//EXERCICE 3

#include <iostream>
#include <stdexcept>
#include <cstring>

class vect {
protected:
    int nelem;
    int* adr;
public:
    vect(int n) : nelem(n) {
        if (n <= 0) throw std::invalid_argument("Taille doit etre positive.");
        adr = new int[nelem];
    }
    virtual ~vect() {
        delete[] adr;
    }
    int& operator[](int indice) {
        if (indice < 0 || indice >= nelem) {
            throw std::out_of_range("Indice hors limites.");
        }
        return adr[indice];
    }
};

class vectok : public vect {
public:
    vectok(int n) : vect(n) {}

    ~vectok() {}

    vectok(const vectok& autre) : vect(autre.nelem) {
        std::memcpy(adr, autre.adr, nelem * sizeof(int));
    }

    vectok& operator=(const vectok& autre) {
        if (this != &autre) {
            if (nelem != autre.nelem) {
                delete[] adr;
                nelem = autre.nelem;
                adr = new int[nelem];
            }
            std::memcpy(adr, autre.adr, nelem * sizeof(int));
        }
        return *this;
    }

    int taille() const {
        return nelem;
    }
};

void print_vectok(const vectok v) {
    std::cout << "Taille (fct): " << v.taille() << "\n";
}

void exercice3_main() {
    std::cout << "\n// EXERCICE 3 //\n";

    try {
        vectok v1(3);
        v1[0] = 10;
        v1[1] = 20;
        v1[2] = 30;

        std::cout << "v1[0]: " << v1[0] << "\n";
        std::cout << "Taille v1: " << v1.taille() << "\n";

        std::cout << "-- Copie valeur --\n";
        print_vectok(v1);

        std::cout << "-- Affectation --\n";
        vectok v2(2);
        v2[0] = 100;
        v2 = v1;
        std::cout << "v2[0] ap: " << v2[0] << "\n";
        std::cout << "Taille v2 ap: " << v2.taille() << "\n";
        v1[0] = 99;
        std::cout << "v2[0] v1 mod: " << v2[0] << "\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Erreur (Ex3): " << e.what() << "\n";
    }
}


//EXERCICE 4

#include <iostream>

class A {
public:
    int n;
    float x;
public:
    A(int p = 2) : n(p), x(1) {
        std::cout << "** const A: " << n << " " << x << "\n";
    }
};

class B {
public:
    int n;
    float y;
public:
    B(float v = 0.0) : n(1), y(v) {
        std::cout << "** const B: " << n << " " << y << "\n";
    }
};

class C : public B, public A {
public:
    int n;
    int p;
public:
    C(int n1 = 1, int n2 = 2, int n3 = 3, float v = 0.0) : A(n1), B(v) {
        n = n3;
        p = n1 * n2;
        std::cout << "** const C: " << n << " " << p << "\n";
    }
};

void exercice4_main() {
    std::cout << "\n// EXERCICE 4 //\n";

    std::cout << "-- c1; --\n";
    C c1;

    std::cout << "-- c2(10, 11, 12, 5.0); --\n";
    C c2(10, 11, 12, 5.0);
}


//EXERCICE 5

#include <iostream>

template <typename T>
T carre(T valeur) {
    return valeur * valeur;
}

void exercice5_main() {
    std::cout << "\n// EXERCICE 5 //\n";

    int i = 5;
    double d = 3.5;

    std::cout << "Carre int: " << carre(i) << "\n";
    std::cout << "Carre double: " << carre(d) << "\n";
}


//EXERCICE 6

#include <iostream>

template <class T>
class point {
public:
    T x, y;
public:
    point(T abs, T ord) : x(abs), y(ord) {}
    void affiche() {
        std::cout << "Coords: " << x << " " << y << "\n";
    }
};

void exercice6_main() {
    std::cout << "\n// EXERCICE 6 //\n";

    point<char> p(60, 65);
    std::cout << "Test a:\n";
    p.affiche();

    std::cout << "Test b (solution):\n";
    std::cout << "Coords: " << (int)p.x << " " << (int)p.y << "\n";
}


//EXERCICE 7

#include <iostream>
#include <stdexcept>

class erreur {
public:
    int num;
};

class A {
public:
    A(int n) {
        if (n == 1) {
            erreur er;
            er.num = 999;
            throw er;
        }
    }
};

void f() {
    try {
        A a(1);
    }
    catch (erreur er) {
        std::cout << "dans f: " << er.num << "\n";
        throw er;
    }
}

void exercice7_main() {
    std::cout << "\n// EXERCICE 7 //\n";
    try {
        f();
    }
    catch (erreur er) {
        std::cout << "dans main: " << er.num << "\n";
    }
    std::cout << "suite main\n";
}


//EXERCICE 8

#include <iostream>
#include <stdexcept>
#include <cstring>

class Stack {
private:
    int* data;
    int capacity;
    int topIndex;
public:
    Stack(int size = 20) : capacity(size), topIndex(-1) {
        data = new int[capacity];
    }

    Stack(const Stack& autre) = delete;
    Stack& operator=(const Stack& autre) = delete;

    ~Stack() {
        delete[] data;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    Stack& operator<<(int n) {
        if (!isFull()) {
            data[++topIndex] = n;
        }
        else {
            std::cerr << "ERREUR: Pile pleine. Ajout annule.\n";
        }
        return *this;
    }

    Stack& operator>>(int& n) {
        if (!isEmpty()) {
            n = data[topIndex--];
        }
        else {
            std::cerr << "ERREUR: Pile vide. Valeur inch.\n";
        }
        return *this;
    }

    int operator++() {
        return isFull() ? 1 : 0;
    }

    int operator--() {
        return isEmpty() ? 1 : 0;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Pile vide.\n";
            return;
        }
        std::cout << "Pile: [";
        for (int i = 0; i <= topIndex; ++i) {
            std::cout << data[i] << (i < topIndex ? ", " : "");
        }
        std::cout << "]\n";
    }
};

void exercice8_main() {
    std::cout << "\n// EXERCICE 8 //\n";

    Stack p;
    int n1 = 0, n2 = 0, n3 = 0;

    std::cout << "Push: ";
    p << 10 << 20 << 30;
    p.display();

    p << 40 << 50 << 60;
    p.display();

    std::cout << "Pop: ";
    p >> n3 >> n2 >> n1;
    std::cout << "Recupere: n1=" << n1 << ", n2=" << n2 << ", n3=" << n3 << "\n";
    p.display();

    std::cout << "Pleine (++p): " << ++p << "\n";

    int temp;
    while (!--p) {
        p >> temp;
    }

    std::cout << "Vide (--p): " << --p << "\n";

    std::cout << "Pop vide: ";
    p >> temp;
}


int main() {
    try {
        std::cout << "===\n";
        exercice1_main();
        std::cout << "===\n";
        std::cout << "\n// EXECUTION EXERCICE 2 REQUIERT UNE INTERACTION. IL EST COMMENTÉ. //\n";
        exercice3_main();
        std::cout << "===\n";
        exercice4_main();
        std::cout << "===\n";
        exercice5_main();
        std::cout << "===\n";
        exercice6_main();
        std::cout << "===\n";
        exercice7_main();
        std::cout << "===\n";
        exercice8_main();
        std::cout << "===\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Erreur fatale: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        std::cerr << "Erreur inconnue fatale.\n";
        return 1;
    }

    return 0;
}