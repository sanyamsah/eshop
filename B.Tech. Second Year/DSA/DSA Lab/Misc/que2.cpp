#include <iostream>
using namespace std;
double volume(double a)
{
    return (4 / 3.0) * 3.14 * a * a * a;
}
double volume(double ra, double ht)
{
    return 3.14 * ra * ra * ht;
}
double volume(double le, double br, double he)
{
    return le * br * he;
}

int main()
{
    double r, r1, h, l, b, h1;
    cout << "Enter the radius of sphere: " << endl;
    cin >> r;
    cout << "Enter the radius and height of the cylinder: " << endl;
    cin >> r1 >> h;
    cout << "Enter the length,breadth and height of the cuboid: " << endl;
    cin >> l >> b >> h1;
    cout << "The volume of sphere: " << volume(r) << endl;
    cout << "The volume of cylinder: " << volume(r1, h) << endl;
    cout << "The volume of cuboid: " << volume(b, h1) << endl;
    return 0;
}