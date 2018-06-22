#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>
#include <algorithm>
#include <vector>
#include "zmogus_studentas.h"
#include "funkc.h"
#include "catch.hpp"

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::sort;

int main() {
    vector <Student> stud;
    int in, method;
    //interfeisas su vartotoju
    cout << "Sveiki! Iveskite studentu skaiciu failo generavimui: " << endl;
    input(in);

/*
    cout << endl;
    cout << "Pasirinkite:" << endl <<
            "Galutinis balas bus skaiciuojamas naudojant" << endl
            << "Vidurki(1) " << endl << "Mediana(2)";
    input(method);
*/

    //baigiasi duomenu ivedimas
    fileWrite(in, "students"); //paduodamas studentų skaičius generavimui
    fileRead(stud);

    std::sort(stud.begin(), stud.end(), sortByFinalMaxToMin);
    //rusiavimas
    vector<Student>::iterator it;
    it = std::stable_partition(stud.begin(), stud.end(), is_Loser);
    vector<Student> Kietekai(it, stud.end());
    vector<Student> Luzeriai(stud.begin(), it);
    //rasymas i faila
    fileWriteRes(Kietekai, "Kietekai");
    fileWriteRes(Luzeriai, "Luzeriai");

    return 0;
}