#include "failai.h"
#include <fstream>
#include <sstream>
#include <random>
#include <iostream>
#include <chrono>
#include <iomanip>

void skaitytiIsFailo(vector<Studentas>& studentai, string failoPavadinimas) {

    ifstream failas(failoPavadinimas);

    if (!failas.is_open()) {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string eilute;

    getline(failas, eilute);

    while (getline(failas, eilute)) {

        stringstream ss(eilute);
        Studentas studentas;

        ss >> studentas.vardas >> studentas.pavarde;

        vector<int> pazymiai;
        int pazymys;

        while (ss >> pazymys) {
            pazymiai.push_back(pazymys);
        }

        if (!pazymiai.empty()) {

            studentas.egzaminas = pazymiai.back();

            pazymiai.pop_back();

            studentas.nd = pazymiai;

            studentai.push_back(studentas);
        }
    }

    failas.close();

    cout << "Studentai nuskaityti is failo." << endl;
}


void generuotiFaila(string failoPavadinimas, int studentuKiekis) {

    ofstream failas(failoPavadinimas);

    if (!failas.is_open()) {
        cout << "Nepavyko sukurti failo." << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);

    auto pradzia = chrono::high_resolution_clock::now();

    failas << "Vardas Pavarde ";

    for (int i = 1; i <= 15; i++) {
        failas << "ND" << i << " ";
    }

    failas << "Egz." << endl;

    for (int i = 1; i <= studentuKiekis; i++) {

        failas << "Vardas" << i << " "
               << "Pavarde" << i << " ";

        for (int j = 0; j < 15; j++) {
            failas << dist(gen) << " ";
        }

        failas << dist(gen) << endl;
    }

    failas.close();

    auto pabaiga = chrono::high_resolution_clock::now();

    chrono::duration<double> trukme = pabaiga - pradzia;

    cout << fixed << setprecision(3);

    cout << "Failas " << failoPavadinimas
         << " sugeneruotas per "
         << trukme.count()
         << " s." << endl;
}


void padalintiStudentus(const vector<Studentas>& studentai,
                        vector<Studentas>& maziaukieti,
                        vector<Studentas>& kieti) {

    for (const Studentas& studentas : studentai) {

        double ndVidurkis = 0;

        for (int pazymys : studentas.nd) {
            ndVidurkis += pazymys;
        }

        ndVidurkis /= studentas.nd.size();

        double galutinis =
            0.4 * ndVidurkis +
            0.6 * studentas.egzaminas;

        if (galutinis < 5.0) {
            maziaukieti.push_back(studentas);
        }
        else {
            kieti.push_back(studentas);
        }
    }
}