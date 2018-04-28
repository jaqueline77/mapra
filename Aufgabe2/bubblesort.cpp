#include <cmath>
#include "unit.h"


using namespace std;

int main()
{
	
	unsigned int *feld;
	size_t l=5;
	for(int k=1; k<=AnzahlBeispiele; k++)
	{
		start(k, l, feld);
		for(int i=0; i<l; i++)
		{
			for(int j=l-1; j>i; j--)
			{
				if(feld[j-1]>feld[j])
				{
					tausche(feld, j-1, j);
				}
			}
			
		}
		ergebnis(feld);
		
		
	}
	return 0;
}
