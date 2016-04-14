#include "Slav.h"
#include <fstream>
#include <string>
#include <iterator>
#include <cstdlib>
#include <iostream>
using namespace std;

vector <string> Slav::names;
int Slav::_counter = 0;

void Slav::init()
{
	srand(time(NULL));
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Slav::Slav()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_id = _counter++;
}
sex Slav::MaleOrFemale()
{
	if(_name[_name.length()-1]=='a')
		return female;
	else
		return male;
}
string Slav::description()
{	
	return string("  ") + _name + " [" + to_string(_id) + "]";
}
