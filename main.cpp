#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas;
};

int main () {
    Studentas studentas;
    cout << "Iveskite studento varda";
    cin >> studentas.vardas;
    cout << "Iveskite studento pavarde";
    cin >> studentas.pavarde;
    cout << "Iveskite studento namu darbu pazymius (ivesti 0 - pabaigti):" << endl;
    int pazymys;

    while (true) {
        cin >> pazymys; 
        if (pazymys == 0)  {
            break;  
        }

        if (pazymys >=1 && pazymys <= 10) {
            studentas.nd.push_back(pazymys);
        } else {
            cout << "Pazymys turi buti nuo 1 iki 10." << endl;

        }

    }
    cout << "Iveskite studento egzamino pazymi: ";

    while (true) {
        cin  >> studentas.egzaminas;

        if (studentas.egzaminas >=1 && studentas.egzaminas <= 10) {
            break;

        }
        cout << "Pazymys turi buti nuo 1 iki 10." << endl;


    }
    double ndVidurkis = 0;

    for (int pazymys : studentas.nd) {
        ndVidurkis = ndVidurkis + pazymys;
    }
    ndVidurkis = ndVidurkis / studentas.nd.size();

    double galutinis = 0.4 * ndVidurkis + 0.6 * studentas.egzaminas;

    cout << fixed << setprecision(2);
    cout << "Galutinis pazymys : " << galutinis << endl;
    

}

    

