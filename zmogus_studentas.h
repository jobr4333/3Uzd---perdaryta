//
// Created by Base on 2018-06-21.
//

#ifndef INC_3_PER_NAUJA_ZMOGUS_STUDENTAS_H
#define INC_3_PER_NAUJA_ZMOGUS_STUDENTAS_H

#include <string>
#include <string>
#include <vector>

using std::string; using std::istream; using std::vector;

class Person {
protected:
    string name;
    string surname;
public:
    Person() = default;
    Person(string n, string s) : name{n}, surname{s} {};
    inline string get_name() const {return name;};
    inline string get_surname()const {return surname;};

    void set_name(string t) {name = t;}
    void set_surname(string t) {surname = t;}

};

class Student: public Person {
protected:
    vector<int> marks;
    double examMark;
    double finalMark;
public:
    Student(): finalMark(0), examMark(0) {}
    Student(const string &name, const string &surname): Person{name, surname} {}
    void set_mark(int m){marks.push_back(m);};
    void set_examMark(int m){examMark = m;};

    double get_examMark(){return examMark;}
    double get_finalMark(){return finalMark;}
    int get_mark(int i){return marks[i];}

    double final_mark();
    double avg();

    bool operator == (Student &a);
    bool operator >  (Student& a);
    bool operator <  (Student& a);
    bool operator != (Student& a);
};
void input(int &num);
void fileRead(vector <Student>&);
void fileWrite(int t, string fileName);
void fileWriteRes(vector <Student>, string fileName);
bool sortByFinal(Student &a, Student &b);
bool sortByFinalMaxToMin( Student &a, Student &b);
bool sortBySurname(Student &a, Student &b);
bool is_Loser (Student &a);

#endif //INC_3_PER_NAUJA_ZMOGUS_STUDENTAS_H
