
#include <iostream>
#include <iomanip>


double det(double a, double b, double c, double d) {
    
    return a * d - c * b;
}

int main()
{
    double a, b, c, d, e, f;

    std::cin >> a >> b >> c >> d >> e >> f;
    std::cout << std::setprecision(6);

    double D = det(a, b, c, d);

    double Dx = det(e, b, f, d);
    double Dy = det(a, e, c, f);

    if (D != 0) {

        double x = Dx / D;
        double y = Dy / D;

        std::cout << 2 << " " << x << " " << y << std::endl;
    }
    else {

        if (Dx != 0 || Dy != 0) {

            std::cout << 0 << std::endl;
        }

        else if (a == 0 && b == 0 && c == 0 && d == 0) {


            if (e != 0 || f != 0) {
                std::cout << 0 << std::endl;
            }
            else {
                std::cout << 5 << std::endl;
            } 
        }

        else if (a != 0 || b != 0) {


            if (a != 0 && b != 0) {


                double k = -a / b;
                double b_ = e / b;

                std::cout << 1 << " " << k << " " << b_ << std::endl;
            }
            else if (a == 0 && b != 0) {

                std::cout << 4 << " " << e / b << std::endl;
            }
            else { // 
                std::cout << 3 << " " << e / a << std::endl;
            }
        }
        else if (c != 0 || d != 0) {


            if (c != 0 && d != 0) {


                double k = -c / d;
                double b_ = f / d;

                std::cout << 1 << " " << k << " " << b_ << std::endl;
            }
            else if (c == 0 && d != 0) {

                std::cout << 4 << " " << f / d << std::endl;
            }
            else { // 
                std::cout << 3 << " " << f / c << std::endl;
            }

        }
    }

}

