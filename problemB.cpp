#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int ilePrzedzialowLiczyc;
	
	int rok[50], mies, dzien, godz, min, sek;
	
	int DniRoku[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	int DniRokuP[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
	
	cin>>ilePrzedzialowLiczyc;
	
	int pom = ilePrzedzialowLiczyc * 2;
	
	long long Ldni[pom], Sekundy1[pom], Sekundy2[pom], Sekundy3[pom], KompletDni[pom], DniP = 0;
	
	for(int i=0; i<pom; i++)
	{
		cin>>rok[i];
	
		cin>>mies;
	
		cin>>dzien;
	
		dzien = dzien - 1;
	
		cin>>godz;

		cin>>min;

		cin>>sek;
		
	
		for(int j=1; j<=12; j++)
		{
			if(mies == j)
			{
				if(rok[i]%4 == 0 && rok[i]%100 != 0 || rok[i]%400 == 0)
				KompletDni[i] = DniRokuP[j-1] + dzien;
		
				else
				KompletDni[i] = DniRoku[j-1] + dzien;
			}
		}
	
		
		if(i%2 == 0)
		{
			Sekundy1[i] = KompletDni[i] * 86400 + godz * 60 * 60 + min * 60 + sek;
		
			if(rok[i]%4==0 && rok[i]%100!=0 || rok[i]%400==0)
			Sekundy3[i] = 366 * 86400 - Sekundy1[i];
	
			else
			Sekundy3[i] = 365 * 86400 - Sekundy1[i];
		}
				
		if(i%2 == 1)
		{
			if(rok[i] == rok[i-1])
			{
				Sekundy2[i] = KompletDni[i] * 86400 + godz * 60 * 60 + min * 60 + sek;
				Ldni[i] = (Sekundy2[i] - Sekundy1[i-1])/86400;
			}
			
			
			if(rok[i] != rok[i-1])
			{
				if((rok[i] - rok[i-1]) > 1)
				{
					for(int j=rok[i-1] + 1; j<rok[i]; j++)
					{
						if(j%4==0 && j%100!=0 || j%400==0)
						DniP += 366 * 86400;
			
						else
						DniP += 365 * 86400;
					}
				}
				Sekundy2[i] = KompletDni[i] * 86400 + godz * 60 * 60 + min * 60 + sek;
				Ldni[i] = (DniP + Sekundy3[i-1] + Sekundy2[i])/86400;
				DniP=0;				
			}
				
		}
		mies = 0; 
		godz = 0;
		min = 0;
		sek = 0;
	}
	for(int i=0; i<pom; i++)
	if(i%2 != 0)
	cout<<Ldni[i]<<endl;
	
	system("pause");
}
