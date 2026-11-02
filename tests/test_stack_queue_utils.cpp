#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "stackqueue/stack_queue_utils.hpp"

TEST_CASE("Problem 1"){
    std::string case_one = "abbaca";
    std::string case_two = "abccba";
    std::string case_three = "abcde";
    std::string case_four = "aaaaa";
    std::string case_five ="aaaa";
    std::string case_six = "1122334455";
    std::string case_seven = "abbaa";
    REQUIRE(remove_duplicates(case_one) == "ca");
    REQUIRE(remove_duplicates(case_two) == "");
    REQUIRE(remove_duplicates(case_three) == "abcde");
    REQUIRE(remove_duplicates(case_four) == "a");
    REQUIRE(remove_duplicates(case_five) == "");
    REQUIRE(remove_duplicates(case_six) == "");
    REQUIRE(remove_duplicates(case_seven) == "a");

}

TEST_CASE("Problem 2"){
    std::string case_one = "ab<c";
    std::string case_two = "ab<<";
    std::string case_three = "a<b<<";
    std::string case_four = "<";
    std::string case_five = "<<a";
    std::string case_six = "a<bc<d";
    REQUIRE(clean_backspace_string(case_one) == "ac");
    REQUIRE(clean_backspace_string(case_two) == "");
    REQUIRE(clean_backspace_string(case_three) == "");
    REQUIRE(clean_backspace_string(case_four) == "");
    REQUIRE(clean_backspace_string(case_five) == "a");
    REQUIRE(clean_backspace_string(case_six) == "bd");
    
}

TEST_CASE("Problem 3"){

dsac::stackqueue::stack<int> st;
st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.push(5);
dsac::stackqueue::queue<int> qu;
int elem = 5;
int num = 5;
REQUIRE(stack_contains(st, qu, elem) == true);
REQUIRE(st.size() == 5);
REQUIRE(qu.empty() == true);

elem = 1;
REQUIRE(stack_contains(st, qu, elem) == true);
REQUIRE(st.size() == 5);
REQUIRE(qu.empty() == true);

elem = 3;
REQUIRE(stack_contains(st, qu, elem) == true);
REQUIRE(st.size() == 5);
REQUIRE(qu.empty() == true);

elem = 10;
REQUIRE(stack_contains(st, qu, elem) == false);
REQUIRE(st.size() == 5);
REQUIRE(qu.empty() == true);

qu.push(1);
REQUIRE_THROWS_AS(stack_contains(st, qu, elem), std::invalid_argument);
qu.pop();

elem = 5;
while(!st.empty()){st.pop();}
REQUIRE(stack_contains(st, qu, elem) == false);
REQUIRE(st.size() == 0);
REQUIRE(qu.empty() == true);

st.push(5);
REQUIRE(stack_contains(st, qu, elem) == true);
REQUIRE(st.size() == 1);
REQUIRE(qu.empty() == true);

elem = 10;
REQUIRE(stack_contains(st, qu, elem) == false);
REQUIRE(st.size() == 1);
REQUIRE(qu.empty() == true);
}