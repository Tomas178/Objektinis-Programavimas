#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include <string>

using namespace std;

struct Studentokai {
    string vardas;
    string pavarde;
    vector<int> namu_darbai;
    int egzaminas;
    double mediana;
    double vidurkis;
};

extern int norima_isvedimo_vieta;
extern int programos_veikimas;
extern int norimas_rikiavimas;
extern char programos_tesinys;
extern char choice3;

extern vector<string> Vardai;
extern vector<string> Pavardes;


double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas);
double medianosSkaiciavimas(const vector<int>& namu_darbai, int nd_kiekis, int egzaminas);
bool palygintiPagalVarda(const Studentokai &a, const Studentokai &b);
bool palygintiPagalPavarde(const Studentokai &a, const Studentokai &b);
bool palygintiPagalVidurki(const Studentokai &a, const Studentokai &b);
bool palygintiPagalMediana(const Studentokai &a, const Studentokai &b);

#endif
