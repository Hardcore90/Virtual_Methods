#include <iostream>
#include <math.h>

using namespace std;

class Function
{
protected:
    double a, b, c;
public:
    virtual double evaluate(double x) = 0;
    void setParams(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
class Parabola : public Function
{
public:
    double evaluate(double x)
    {
        return a * x * x + b * x + c;
    }
};
class Hyperbola : public Function
{
public:
    double evaluate(double x)
    {
        return a / (x - b) + c;
    }
};
class Ellipse : public Function
{
public:
    double evaluate(double x)
    {
        return sqrt(a - x * x * b) + c;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Function* f;
    double a, b, c;
    cout << "1. Эллипс" << endl;
    cout << "2. Парабола" << endl;
    cout << "3. Гипербола" << endl;
    cout << "Выбирете функцию(введите цифру): ";
    char digit;
    cin >> digit;
    switch (digit)
    {
    case '1': 
    {f = new Ellipse;
    break;
    }
    case '2': 
    {f = new Parabola;
    break;
    }
    case '3': 
    {f = new Hyperbola;
    break;
    }
    }
    cout << "Введите координаты: ";
    cin >> a >> b >> c;
    f ->setParams(a, b, c);
    cout << "Введите аргумент: ";
    cin >> a;
    cout << "f(" << a << ")=" << f->evaluate(a) << endl;
    cin.get();
    delete f;
    system("pause");
    return 0;
}