#include <iostream>
#include <ctime>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;

double obliczWartoscFunkcjiKwadratowej(double a, double b, double c, double x) 
{
	return a * pow(x, 2) + b * x + c;
}

double minimumFunkcjiKwadratowej(double a, double b, double c, double xp, double xk,int n)
{
    assert(xp < xk);
    assert(a >= 0);
    srand(time(0));

    double najmniejszaWartoscY = obliczWartoscFunkcjiKwadratowej(a, b, c, xp);
    double szukanyX = xp;
    int maxStag = n; // gdy przez maxStag iteracji nie znajdziemy lepszego wyniku kończymy poszukiwania
    int liczStag = 0;
    int m = 10 * n;
    for (int i = 0; i < m; i++)
    {
        double aktualnyX = xp + (double)(rand()) / (RAND_MAX / (xk -( xp)));
        double aktualnyY = obliczWartoscFunkcjiKwadratowej(a, b, c, aktualnyX);

        if (aktualnyY < najmniejszaWartoscY)
        {
            najmniejszaWartoscY = aktualnyY;
            szukanyX = aktualnyX;
            liczStag = 0;
        }
        else
        {
            liczStag++;
        }
        if (liczStag >= maxStag)
        {
            break;
        }
    }
    return szukanyX;
   
}

int main()
{
    int n;
    cout << "Podaj liczbe iteracji bez poprawy wyniku: " << endl;
    cin >> n;

    cout << fixed << setprecision(5) << endl;

    double a = 1.0;  
    double b = 2.0;
    double c = 1.0;
    double xp = -5.0;
    double xk = 5.0;
   
    double szukanyX = minimumFunkcjiKwadratowej(a, b, c, xp, xk, n);
    double szukanyY = obliczWartoscFunkcjiKwadratowej(a, b, c, szukanyX);

    cout << "Najmniejsza wartosc y: " << szukanyY<< " dla argumentu x: " << szukanyX << endl;
}
