#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <iostream>
#include <string>
#include "tlista.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void kiiras(Ember &emberek);

void test_1(Ember e1, Ember e2, Tlista& l);

void test_2(Ember e1, Ember e2, Ember e3, Tlista& l);

void test_3(Ember e1, Ember e2, Tlista& l);

void test_4(Ember e1, Ember e2, Tlista& l);

void test_5(Ember e1, Ember e2, Tlista& l);

void test_6(Ember e1, Ember e2, Ember e3, Tlista& l, char* testfile);

int teszt();

#endif // TEST_H_INCLUDED
