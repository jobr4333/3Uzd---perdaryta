//
// Created by Base on 2018-06-21.
//
#include "zmogus_studentas.h"
#include <iostream>
#include <algorithm>
#include <iomanip>


double Student::final_mark(){
    finalMark = (examMark*0.6) + (avg()*0.4);
    return finalMark;
}

double Student::avg() {
    double average{};
    for(auto it = marks.begin(); it < marks.end(); it++) {
        average += *it;
    }
    //std::cout << std::setprecision(2) << "avg(): average " << " ";
    average = average/marks.size();
    return average;
}

bool Student::operator == (Student&a){
    return get_finalMark() == a.get_finalMark();
}

bool Student::operator > (Student&a){
    return get_finalMark() > a.get_finalMark();
}

bool Student::operator < (Student&a){
    return get_finalMark() < a.get_finalMark();
}

bool Student::operator != (Student&a){
    return get_finalMark() != a.get_finalMark();
}
bool sortByFinal(Student &a, Student &b) {
    return a.get_finalMark() < b.get_finalMark();
}

bool sortByFinalMaxToMin(Student &a, Student &b) {
    return a.get_finalMark() > b.get_finalMark();
}

bool sortBySurname(Student &a, Student &b) {
    return a.get_surname() < b.get_surname();
}

bool is_Loser (Student &a){
    return a.get_finalMark() < 6;
}