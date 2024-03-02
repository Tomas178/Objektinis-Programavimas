#include "funkcijos.h"

double Vidurkis(int nd_kiekis, int nd_suma, int egzaminas){
    if(nd_kiekis > 0)
        return 0.4*nd_suma/nd_kiekis + 0.6*egzaminas;
    else
        return 0.6*egzaminas;
}

double medianosSkaiciavimas(const vector<int>& namu_darbai, int nd_kiekis, int egzaminas){
    if(nd_kiekis % 2 == 0 && nd_kiekis > 0)
        return (namu_darbai[nd_kiekis/2-1] + namu_darbai[nd_kiekis/2])/2.0*0.4 + 0.6*egzaminas;
    else if(nd_kiekis % 2 != 0 && nd_kiekis > 0)
        return namu_darbai[nd_kiekis/2]*0.4 + 0.6*egzaminas;
    else 
        return 0.6*egzaminas;
}

bool palygintiPagalVarda(const Studentokai &a, const Studentokai &b) {
    return a.vardas < b.vardas;
}

bool palygintiPagalPavarde(const Studentokai &a, const Studentokai &b) {
    return a.pavarde < b.pavarde;
}

bool palygintiPagalVidurki(const Studentokai &a, const Studentokai &b) {
    return a.vidurkis < b.vidurkis;
}

bool palygintiPagalMediana(const Studentokai &a, const Studentokai &b) {
    return a.mediana < b.mediana;
}

void GeneruotiFaila(int kiekis, int nd_kiekis){
    string FailoPavadinimas = "Studentai" + to_string(kiekis) + ".txt";
    ofstream RF(FailoPavadinimas);
    try
    {
        if (!RF.is_open()) { 
            throw runtime_error("Nepavyko atidaryti failo: " + FailoPavadinimas);
        }

        auto start = chrono::high_resolution_clock::now();

        RF << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
        for(int i = 1; i <= nd_kiekis; i++){
            RF << setw(7) << "ND" + to_string(i);
        }
        RF << setw(7) << "Egz." << "\n";

        for(int i = 1; i <= kiekis; i++){
            RF << left << setw(20) << "Vardas"+to_string(i) << setw(20) << "Pavarde"+to_string(i);
            for(int j = 0; j < nd_kiekis+1; j++){
                RF << setw(7) << rand()%10+1;
            }
            RF << "\n";
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        RF.close();
        cout << "Failas: " << FailoPavadinimas << " sugeneruotas sekmingai:)" << endl;
        cout << "Failas sugeneruotas per: " << duration/1000.0 << " sekundes" << endl;
    }
    catch(const exception &e)
    {
        cerr << e.what() << '\n';
    }  
}