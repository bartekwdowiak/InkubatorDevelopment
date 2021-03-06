#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* Given a number, return the maximum number that could be formed with digits of the number given.
* For example: number = 7389, return 9873
*/
int form_the_largest_number(int number)
{
	int n = number, arrayPos = -1, digit, result = 0;
	int length = (int)floor(log10((float)number)) + 1;	//ilosc cyfr w podanej liczbie
	int *tab=malloc(sizeof(tab)*length);				//dynamiczna alokacja pamieci pod tablice

	while(number != 0){									//zapisanie inta w tablicy po cyfrze
		digit = number % 10;
        number = number / 10;
		tab[++arrayPos]=digit;
	}

	for(int i=9; i>=0; i--){							//wyszukiwanie kolejnych cyfr (9,8,..)
		for(int j=0; j<=arrayPos; j++){
			if(tab[j]==i){
				result+=i;								//dodanie cyfry
				result *= 10;							//pomnozenie wyniku przez 10 zeby "przesunac" dodana cyfre w lewo
			}
		}
	}
	
	free(tab);
	return result/10;									//wynik w tym miejscu jest pomnozony przez 10 o jeden raz za duzo
}

void test_cases()
{
	int result = form_the_largest_number(213);
	assert(result == 321);

	result = form_the_largest_number(7389);
	assert(result == 9873);

	result = form_the_largest_number(63729);
	assert(result == 97632);

	result = form_the_largest_number(566797);
	assert(result == 977665);
}

int main()
{
	test_cases();

}
