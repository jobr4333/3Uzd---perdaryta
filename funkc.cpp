//
// Created by Base on 2018-06-21.
//

#ifndef INC_3_PER_NAUJA_FUNKC_H
#define INC_3_PER_NAUJA_FUNKC_H

//
// Created by Base on 2018-06-21.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <chrono>
#include <sstream>
#include <vector>
#include <cmath>
#include "funkc.h"

#include "zmogus_studentas.h"

using std::ofstream; using std::ifstream; using std::cout; using std::cin; using std:: endl;
using std::setw; using::std::left; using std::to_string; using std::setprecision;
//using std::vector;

int randomMark() {
    int mark{};
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 10);
    mark = dis(gen);
    return mark;
}

void fileWrite(int t, string fileName) {
    ofstream fw("../" + fileName + ".txt");
    int a[6];
    for (size_t i = 0; i < t; i++) {
        fw << "Name" + to_string(i) << " Surname" + to_string(i) << " ";
        /*for(auto u : a) {
            fw << randomMark() << " ";
        }*/
        fw << rand() % 9+1 << " " << rand() % 9+1 << " "<< rand() % 9+1  << " "  << rand() % 9+1  << " " << rand() % 9+1  << " " << " " << rand() % 9+1  << " ";
        fw << endl;
    }
}

void fileWriteRes(vector <Student> stud, string fileName){
    ofstream fw("../" + fileName+ ".txt");
    for(auto i = 0; i != stud.size(); i++) {
        fw << left << setw(15) << stud[i].get_name() << setw(15) << stud[i].get_surname() << " " << setprecision(3) << stud[i].get_finalMark() << endl;
    }
}

void fileRead(vector <Student> &stud) {
    auto start = std::chrono::high_resolution_clock::now(); //laiko matavimo start
    ifstream sk("../students.txt");
    string tempS;
    int num{};
    try {
        if (!sk.good()) throw 404;
        else if (sk.peek() == ifstream::traits_type::eof()) throw 2;
    }

    catch (int errNo) {
        cout << "Ivyko klaida. Klaidos NR: " << errNo << endl;
        cout << "Paaiskinimas:" << endl << "404 - failo nera." << endl << "2 - failas tuscias." << endl << "1 - failas tuscias, tik tarpai." << endl;
        exit(errNo);
    }

    if (sk.good()) {
        while(getline(sk, tempS)) {
            Student tempStud;
            std::istringstream iss(tempS);
            iss >> tempS;
            tempStud.set_name(tempS);
            iss >> tempS;
            tempStud.set_surname(tempS);
            while(iss >> num) {
                tempStud.set_mark(num);
            }

            tempStud.set_examMark(tempStud.get_mark(5));
            tempStud.final_mark();
            stud.push_back(tempStud);
        }
        sk.close();
    }
    auto finish = std::chrono::high_resolution_clock::now();//laiko matavimo finish
    std::chrono::duration<double> elapsed = finish - start;
    cout << left << setw(40) << "skaitymas vykdymo laikas "  << ": " << elapsed.count() << " s" << endl;
}


void input(int &num) {
    cin >> num;
    while(!cin.good()){
        cin.clear();
        cout << "Blogas ivedimas. Prasome is naujo ivesti studentu skaiciu failo generavimui: " << endl;
        cin.ignore(INT_MAX, '\n');
        cin >> num;
    }
}


#endif //INC_3_PER_NAUJA_FUNKC_H
