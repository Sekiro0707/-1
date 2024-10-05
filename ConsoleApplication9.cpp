#include <iostream>
#include <numeric>  
using namespace std;

class fakt {
private:
    int n1;
    int d1;


    void red() {
        int gcd = std::gcd(n1, d1);
        n1 /= gcd;
        d1 /= gcd;
    }

public:
    fakt() : n1(0), d1(1) {}
    fakt(int n, int d) {
        if (d == 0) {
            throw invalid_argument("Знаменник не може бути нульовим");
        }
        n1 = n;
        d1 = d;
        red();
    }

    void setFraction(int n, int d) {
        if (d == 0) {
            throw invalid_argument("Знаменник не може бути нульовим");
        }
        n1 = n;
        d1 = d;
        red();
    }

    fakt add(const fakt& other) const {
        int num = n1 * other.d1 + other.n1 * d1;
        int den = d1 * other.d1;
        return fakt(num, den);
    }

    fakt subtract(const fakt& other) const {
        int num = n1 * other.d1 - other.n1 * d1;
        int den = d1 * other.d1;
        return fakt(num, den);
    }

    fakt multiply(const fakt& other) const {
        int num = n1 * other.n1;
        int den = d1 * other.d1;
        return fakt(num, den);
    }

    fakt divide(const fakt& other) const {
        if (other.n1 == 0) {
            throw invalid_argument("Ділення на нуль");
        }
        int num = n1 * other.d1;
        int den = d1 * other.n1;
        return fakt(num, den);
    }

    void print() const {
        if (d1 == 1) {
            cout << n1 << endl;
        }
        else {
            cout << n1 << "/" << d1 << endl;
        }
    }
};

int main() {
    try {
        fakt f1(3, 4);
        fakt f2(2, 5);

        cout << "f1 = ";
        f1.print();
        cout << "f2 = ";
        f2.print();

        fakt sum = f1.add(f2);
        cout << "Сума: ";
        sum.print();

        fakt diff = f1.subtract(f2);
        cout << "Різниця: ";
        diff.print();

        fakt prod = f1.multiply(f2);
        cout << "Добуток: ";
        prod.print();

        fakt quot = f1.divide(f2);
        cout << "Частка: ";
        quot.print();

    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}
