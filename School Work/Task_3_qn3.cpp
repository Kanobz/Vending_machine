#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void print_real(float number, int fieldspace, int precision);

template <typename T>
void update_scale(T &m1, T &m2, T m3 = 10)
{
    T original_m1 = m1;
    T original_m2 = m2;

    m1 = (original_m1 + original_m2) * m3;
    m2 = (original_m1 - original_m2) * m3;
}

int main(void)
{
    float a, b;
    cout << "Please input two real numbers: ";
    cin >> a >> b;

    print_real(a, 7, 3);
    print_real(b, 7, 3);

    // calling the update_scale function with ONLY a and b
    update_scale(a, b);

    print_real(a, 7, 3);
    print_real(b, 7, 3);

    return 0;
}

// completed body of the function
void print_real(float number, int fieldspace, int precision)
{
    cout << fixed << setprecision(precision) << setw(fieldspace) << number << endl;
}
