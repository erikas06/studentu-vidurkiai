#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas;
};

int main () {
    vector <Studentas> studentai;
    while (true) {
        Studentas studentas;

        cout << "Iveskite studento varda: ";
        cin >> studentas.vardas;

        cout <<"Iveskite studento pavarde: ";
        cin >> studentas.pavarde;

        cout << "Iveskite studento namu darbu pazymius (norint pabaigti - iveskite 0):" << endl;

        int pazymys;

        while (true) {
            cin >> pazymys;

            if (pazymys == 0 && !studentas.nd.empty()) {
                break;

            }
            if (pazymys >= 1 && pazymys <= 10) {
                studentas.nd.push_back(pazymys);
            } else {
                cout << "Pazymys turi buti nuo 1 iki 10." << endl;
            }
        }
        cout <<" Iveskite studento egzamino pazymi: ";
        
        while (true) {
            cin >> studentas.egzaminas;

            if (studentas.egzaminas >= 1 && studentas.egzaminas <= 10 ) {
                break;
            }
            cout << "Pazymys turi buti nuo 1 iki 10." << endl;
        }
        studentai.push_back(studentas);

        char pasirinkimas;
        cout << "Ar norite ivesti dar viena studenta? (t/n): ";
        cin >> pasirinkimas;

        if(pasirinkimas == 'n') {
            break;
        }
    }
    
    for (Studentas studentas : studentai) {
        double ndVidurkis = 0;
    
        for (int pazymys : studentas.nd) {
            ndVidurkis += pazymys;
    }
    
        ndVidurkis /= studentas.nd.size();

        cout << studentas.vardas << " " << studentas.pavarde
           << " ND vidurkis: " << ndVidurkis << endl;
    }



}

    


 