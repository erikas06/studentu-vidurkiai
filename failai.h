#ifndef FAILAI_H
#define FAILAI_H

#include "studentas.h"
#include <vector>
#include <string>

using namespace std;

void skaitytiIsFailo(vector<Studentas>& studentai, string failoPavadinimas);

void generuotiFaila(string failoPavadinimas, int studentuKiekis);

#endif