#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{

    double f = 2.14159;
    std::cout << std::setprecision(3) << f << '\n';
    std::cout << std::setprecision(4) << f << '\n';
    std::cout << std::setprecision(6) << f << '\n';
    std::cout << std::setprecision(9) << f << '\n' << '\n';
    std::cout << std::fixed;
    std::cout << std::setprecision(3) << f << '\n';
    std::cout << std::setprecision(6) << f << '\n';
    std::cout << std::setprecision(5) << f << '\n';
    std::cout << std::setprecision(9) << f << '\n';


    double a = 30;
    double b = 10000.0;
    double pi = 3.1416;
    std::cout.precision (5);
    std::cout <<   std::showpoint << a << '\t' << b << '\t' << pi << '\n';
    std::cout << std::noshowpoint << a << '\t' << b << '\t' << pi << '\n';


    int n = -77;
    std::cout.width(6); std::cout << std::internal << n << '\n';
    std::cout.width(6); std::cout << std::left << n << '\n';
    std::cout.width(6); std::cout << std::right << n << '\n';

    int i, j=5;
    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    /* Print 5 random numbers from 0 to 50 */
    for( i = 0 ; i < j ; i++ ) {
        printf("%d\n", rand() % 50);
    }


//    char ch;
//    cout << "Please enter the char: " << endl;
//    cin.get(ch);
//    cout << "the char is " << ch << endl;



    return 0;
}
