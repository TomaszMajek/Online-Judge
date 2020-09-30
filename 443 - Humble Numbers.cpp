#include <iostream>
#include <math.h>

using namespace std;

void quick_sort(long long *tab, int lewy, int prawy)
{
	if (prawy <= lewy) return;

	int i = lewy - 1, j = prawy + 1,
		pivot = tab[(lewy + prawy) / 2]; //wybieramy punkt odniesienia

	while (1)
	{
		//szukam elementu wiekszego lub rownego piwot stojacego
		//po prawej stronie wartosci pivot
		while (pivot > tab[++i]);

		//szukam elementu mniejszego lub rownego pivot stojacego
		//po lewej stronie wartosci pivot
		while (pivot < tab[--j]);

		//jesli liczniki sie nie minely to zamień elementy ze soba
		//stojace po niewlasciwej stronie elementu pivot
		if (i <= j)
			//funkcja swap zamienia wartosciami tab[i] z tab[j]
			swap(tab[i], tab[j]);
		else
			break;
	}

	if (j > lewy)
		quick_sort(tab, lewy, j);
	if (i < prawy)
		quick_sort(tab, i, prawy);
}

int main() 
{

	long long *x, q = 0;
	x= new long long[5843];
	int n, i = 0, j = 0, k = 0, l = 0;
	double liczba;

	for (i = 0; i < 12; i++)
	{ 
		for (j = 0; j < 14; j++)
		{ 
			for (k = 0; k < 20; k++)
			{ 
				for (l = 0; l < 31; l++) 
				{
					liczba = pow(2, l)*pow(3, k)*pow(5, j)*pow(7, i);
					if (liczba <= 2000000000) {
						x[q] = liczba;
						q++;
					}
				}
			}
		}
	}

	quick_sort(x, 0, 5842);

	while (cin >> n) 
	{

		if (n==0)
		{
			return 0;
		}

	cout <<"The "<< n ;
	if (n % 10 == 1 && n % 100 != 11)
	{ 
		cout <<"st";
	}
	else if (n % 10 == 2 && n % 100 != 12)
	{
		cout << "nd";
	}
	else if (n % 10 == 3 && n % 100 != 13)
	{ 
		cout << "rd";
	}
	else
	{ 
		cout << "th";
	}
	cout << " humble number is " << x[n] << "." << endl;
	}

}