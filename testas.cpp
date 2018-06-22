//
// Created by Base on 2018-06-22.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "zmogus_studentas.h"

TEST_CASE("Student::final_mark()"){
    Student stud;
    for(size_t i = 6; i < 11; i++) stud.set_mark(i), std::cout << i << " ";
    SECTION("avg() test1") {
        REQUIRE(stud.avg() == 8.0);
    }
    stud.set_examMark(10);
    SECTION("final_mark() test1") {
        REQUIRE(stud.final_mark() == 9.2);
    }


}
