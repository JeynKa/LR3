/** @file derevo.cpp */
#include <iostream>
#include <locale.h>
using namespace std;
void obhP (int node, int n, int *aa) /// functia obhoda v pramom poryadke (obhP), param: koren', kol-vp uzlov, massiv dereva 
{///
	cout<<node+1<<" ";///raspechatyvaem koren'
   int *b=new int[n];///sozdaem dop massiv B
   for (int i=0; i<n; i++)
	   b[i]=0;///zapolnaem 0
   for (int i=0; i<n; i++)
	   if (aa[i]==node+1)
		   b[i]=aa[i];///esly est' dety y korna, zapisyvaem ih v b
   for (int i=0; i<n; i++)
	   if (b[i]!=0) obhP(i,n,aa);///esly kakoi-libo element v b neraven 0, to vasyvaem obhO podavay koren'=nomery ne nylevogo elementa b
return;
}///
void obhO (int node, int n, int *aa) /// functia obhoda v obratnom poryadke (obhO), param: koren', kol-vp uzlov, massiv dereva 
{///
   int *b=new int[n];///tot ge algoritm, no raspechatka proishodit esly massiv b togdestvennyi 0
   for (int i=0; i<n; i++)
	   b[i]=0;
   for (int i=0; i<n; i++)
	   if (aa[i]==node+1)
		   b[i]=aa[i];
	for (int i=0; i<n; i++)
	   if (b[i]!=0) obhO(i,n,aa);
	cout<<node+1<<" ";
return;
}///
void obhS (int node, int n, int *aa) /// functia obhoda v simmetricnom poryadke (obhS), param: koren', kol-vp uzlov, massiv dereva 
{
   int *b=new int[n];
   for (int i=0; i<n; i++)///tot ge algoritm v nachale
	   b[i]=0;
   for (int i=0; i<n; i++)
	   if (aa[i]==node+1)
		   b[i]=aa[i];
	for (int i=0; i<n; i++) 
	   if (b[i]!=0) obhS(i,n,aa);///esly massiv b togdestvennyi 0
	int k=0;
	for (int i=0; i<n; i++)///esly y elementa net detei pechataem ego
		if (aa[i]==node+1) k++;
		if (k==0)
	cout<<node+1<<" ";
	if ((aa[node-1]!=aa[node])&(aa[node]!=0))///posle pervogo rebenka pechtaem roditela
	cout<<aa[node]<<" ";
	return;
}///
int main(void)/// functia main
{
	setlocale(0, "Russian");
	int n;
	cout<<"введите кол-во узлов=";
	cin>>n;
	cout<<"\n";
	int *a=new int[n];
	cout<<"введите эллементы: ";
	for (int i=0; i<n; i++)
	{
		cin>>a[i];
	}///vvodim derevo
	///vysyvaem funcii dla ego raspechatki
	cout<<"\n прямой обход \n";
	obhP(0,n,a);
	cout<<"\n обратный обход \n";
	obhO(0,n,a);
	cout<<"\n симметричный обход \n";
	obhS(0,n,a);
	system("pause");
}
