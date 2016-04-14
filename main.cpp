// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Slav.h"
#include <ctime>
#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);
void gender(Slav *, int);
int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);
	gender(slavs,n);
	delete [] slavs;
}
void gender(Slav* slavs, int n)
{
	map<sex, vector< Slav *>> mapOfGender;
	for(int i=0;i<n;i++)
		{
		if(slavs[i].MaleOrFemale()==female)
			mapOfGender[female].push_back(&slavs[i]);
		else
			mapOfGender[male].push_back(&slavs[i]);
		}
	
	vector< Slav *>::iterator it_mapOfGender=mapOfGender[female].begin();
	for(;it_mapOfGender!=mapOfGender[female].end();it_mapOfGender++)
	{
		cout<<"female: "<<(*it_mapOfGender)->description()<<endl;
	}
	vector< Slav *>::iterator it2_mapOfGender=mapOfGender[male].begin();
	for(;it2_mapOfGender!=mapOfGender[male].end();it2_mapOfGender++)
	{
		cout<<"male: "<<(*it2_mapOfGender)->description()<<endl;
	}	
}
void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");
	srand(time(NULL));
	// Umieść Słowian w losowej kolejności w wektorze.

	for(int i=0;i<n;i++)
		{
		int where=rand()%((vectorOfSlavs.size()+1));
		vectorOfSlavs.insert(vectorOfSlavs.begin()+where, &slavs[i]);
		}
	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
	vector <Slav *>::iterator it_tab=vectorOfSlavs.begin();
	for(;it_tab!=vectorOfSlavs.end(); it_tab++)
		cout<<(**it_tab).description()<<endl;
	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieś wszystkich Słowian z wektoru do zbioru.
	for(int i=0;i<n;i++)
	{
		setOfSlavs.insert(vectorOfSlavs.back());
		vectorOfSlavs.pop_back();
		
	}
	REPORT_CONTAINERS;
	printf("## map\n");
	set< Slav *>::iterator it=setOfSlavs.begin();
	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	for(;it!=setOfSlavs.end();it=setOfSlavs.erase(it))
	{
		
		mapOfSlavs[*it]=*(it=setOfSlavs.erase(it));
		
		
	}
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
	map< Slav *, Slav *>::iterator it_mapOfSlavs=mapOfSlavs.begin();
	for(int i=0;i<n/2;i++)
	{
		cout<<((it_mapOfSlavs->first))->description()<<"   "<<((it_mapOfSlavs)->second)->description()<<endl;
	it_mapOfSlavs++;
	}
		
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
	for(int i=0;i<n;i++)
		queueOfSlavs.push(&(slavs[i]));
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.
	for(int i=0;i<n;i++)
		{
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();
		}
	REPORT_ADAPTERS;

	for(int i=0;i<n;i++)
		{
		cout<<stackOfSlavs.top()->description()<<endl;
		stackOfSlavs.pop();
		
		}

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
