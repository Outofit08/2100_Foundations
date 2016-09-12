//
//  prgrm3.h
//  CSCE2100
//
//  Created by brashad hasley on 10/21/15.
//  Copyright (c) 2015 Brashad Hasley. All rights reserved.
//



#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <ctype.h>


using namespace std;


struct Patron{
    string fname;
    string lname;
    string address;
    string city;
    string state;
    string zip;
    string date_birth;
    string date_death;
    string date_wed;
    int pid;
    int child_count;
    struct Patron *pnext;
    struct Patron *spouse;
    struct Patron *child[5];
    struct Patron *parent;
};

struct Patron *patronHead = NULL;
struct Patron *patronTail = NULL;
struct Patron *patronWalk = NULL;
struct Patron *patronTemp = NULL;



void menu();
void choice(string a,string b);
void add(string n,string n2);
void add_spouse(int sp,string spn,string spl);
void add_child(int pcid,string cn,string cn2);
void add_address(int ad,string ad1);
void add_city(int ct,string ct1);
void add_state(int st,string st1);
void add_zip(int zi,string zi1);
void add_db(int db, string db1);
void add_dd(int dd, string dd1);
void add_wed(int wd, string wd1);
void search(string s,string s1);
void print(int pr);
void print_all();
void commands();
//void remove(string r,string r1);
void quit(string q);
void fromfile(string f);
void ftree(int id);

string finish;
string total;
string filename;
string input;
string input2;
string input3;
int ipatr;
int IDNUM = 1;
int filuse = 0;

