//
//  HasB_00_P3_main.cpp
//  CSCE2100
//
//  Created by brashad hasley on 10/21/15.
//  Copyright (c) 2015 Brashad Hasley. All rights reserved.
//



// this is the only include needed as all other includes are in the
// header file.
#include "F_00_P4_main.h"
#include <algorithm>
// my main funtion will run the porgram until the user types
// the string quit on the command line.
int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"    Brashad's ADDRESS BOOK"<<endl;
    cout<<"    AVAILABLE COMMANDS:"<<endl;
    cout<<"    add name <first last>"<<endl;
    cout<<"    add spouse <uid> <first last>"<<endl;
    cout<<"    add child <uid> <first last>"<<endl;
    cout<<"    add address1 <uid> <address>"<<endl;
    cout<<"    add city <uid> <city>"<<endl;
    cout<<"    add state <uid> <state>"<<endl;
    cout<<"    add zip <uid> <zip>"<<endl;
    cout<<"    add date_birth <uid> <ddmmyyyy>"<<endl;
    cout<<"    add date_wedding <uid> <ddmmyyy>"<<endl;
    cout<<"    add date_death <uid> <ddmmyyyy>"<<endl;
    cout<<"    search <name>"<<endl;
    //cout<< "    remove <name>"<<endl;
    cout<<"    print all"<<endl;
    cout<<"    print<uid>"<<endl;
    cout<<"    file <filename>"<<endl;
    cout<<"    quit"<<endl;
    cout<<"Type commands to see this list again."<<endl;
    //cout<< "cmd> ";
    while (finish != "quit") {
        menu();
        choice(total,input);
        filuse = 0;
        //finish.clear();
        total.clear();
        input.clear();
        input2.clear();
        input3.clear();
    }
}
// this is the menu function it will present the cmd line
//
void menu(){
    cout<< "cmd> ";
    string line1;
    getline(cin,line1);
    string intcon;
// this will convert all input in to lowercase.
    //transform(line1.begin(), line1.end(), line1.begin(),::tolower);
    // print to test lowercase.
    // cout <<line<<endl;
    // sets the string finish to entire line. will be checked at end of while loop.
    
    
// this does not have to be in a if statemnt but had wierd errors with commas
// when i didnt include it.
    size_t found = line1.find_first_of(' ');
        //string::iterator end_pos = remove(line1.begin(),line1.end(),' ');
        //line1.erase(end_pos,line1.end());
    transform(finish.begin(), finish.end(),finish.begin(),::tolower);
    finish = line1;
    total = line1.substr(0,found);
    line1.erase(0,total.length()+1);
    //cout << total<<endl;
    transform(total.begin(), total.end(),total.begin(),::tolower);
    
    size_t found2 = line1.find_first_of(' ');
    
    input = line1.substr(0,found2);
    line1.erase(0,input.length()+1);
    size_t found3 = line1.find_first_of(' ');
    //cout << input<<endl;
    for(int i=0; i<line1.length();i++){
    if (isdigit(line1[i])){
        intcon = line1.substr(0,found3);
        int position = intcon.find_first_of('0');
        string id = intcon.substr(position+1);
        //cout<< "num read"<<endl;
        // starts with integer
        ipatr = atoi(id.c_str());
        line1.erase(0,intcon.length()+1);
        size_t found4 = line1.find_first_of(' ');
        input2 = line1.substr(0,found4);
        line1.erase(0,input2.length()+1);
    }
    else if(i > 1){
        // does not start with integer
        input2 = line1.substr(0,found3);
        //cout<< " no num"<<endl;
        line1.erase(0,input2.length()+1);
     }
    }
    //string::iterator end_pos1 = remove(input.begin(),input.end(),' ');
    //input.erase(end_pos1,input.end());
    input3 = line1;
    //input[0] = toupper(input[0]);
    input2[0] = toupper(input2[0]);
    input3[0] = toupper(input3[0]);
    //string::iterator end_pos2 = remove(input3.begin(),input3.end(),' ');
    //input3.erase(end_pos2,input3.end());
    //string::iterator end_pos3 = remove(total.begin(),total.end(),' ');
    //total.erase(end_pos3,total.end());
        //cout<< input <<" "<< input2 <<" "<< input3 << endl;
        //cout<<line1<<endl;

// this will clear the line1 string just to be sure
// there are no chars left on the line.
    line1.clear();
}

// this is my choice function that will take in the command and feed the input into
// the corresponding function.
void choice(string a,string b){
    
    if (a == "add"){
        if (b == "name") {
            add(input2,input3);
        }
        if(b == "spouse"){
            add_spouse(ipatr, input2, input3);
        }
        if (b == "child") {
            add_child(ipatr, input2, input3);
        }
        if (b == "address1"){
            add_address(ipatr,input2);
        }
        if (b == "city"){
            add_city(ipatr,input2);
        }
        if (b == "state"){
            add_state(ipatr,input2);
        }
        if (b == "zip"){
            add_zip(ipatr, input2);
        }
        if (b == "date_birth"){
            add_db(ipatr, input2);
        }
        if (b == "date_wedding"){
            add_wed(ipatr, input2);
        }
        if (b == "date_death"){
            add_dd(ipatr, input2);
        }
    }
    else if (a == "commands"){
        commands();
    }
    else if (a == "search"){
        if (patronHead !=NULL) {
        search(input,input2);
        }
        //else
          //  cout<< "There are no patrons in the list"<<endl;
    }
    else if (a == "print"){
        if (patronHead !=NULL) {
            if ( b == "all"){
                print_all();
            }
            else if( b == "ftree"){
                ftree(ipatr);
            }
            else{
            print(ipatr);
            }
            
        }
        else
            cout<< "NO NAMES IN LIST"<<endl;
    }
    //else if ( a == "remove"){
      //  if (patronHead !=NULL) {
        //remove(input2,input3);
        //}
        //else
      //      cout<< "There are no patrons in the list"<<endl;
    //}
    else if (finish == "quit"){
        //finish = a;
        cout<< "Have a good day and pleasant tomorrow! Good-bye.";
        
    }
    else if (a == "file"){
        fromfile(b);
    }
    else{
        cout<<"invalid entry"<<endl;
    }
    //finish.clear();
    //input.clear();
    //input2.clear();
    //total.clear();

}
// this function performs the adding of names and assiging of id numbers.
void add(string n,string n2){
    n[0] = toupper(n[0]);
    n2[0] = toupper(n2[0]);
    int found=0;
    patronWalk = patronHead;
    while (patronWalk!=NULL) {
        // this checks if the patron being added is in the list already.
        if (patronWalk->fname == n && patronWalk->lname == n2){
            // this will check if a spouse is being added or a name.
            if (input == "name"){
                cout<<"DUPLICATE: " << n <<" "<< n2 <<"  UID: ID"<<setfill('0')<<setw(3)<<patronTail->pid<<endl;
                found = 1;
                patronWalk = NULL;
            }
            else{
                cout<<"ALREADY IN LIST: "<< n <<" "<< n2 <<"  UID: ID"<<setfill('0')<<setw(3)<<patronTail->pid<<endl;
                found = 1;
                patronWalk = NULL;
            }
        }
        else{
            patronWalk = patronWalk ->pnext;
        }
        
    }
    //this will add the patron to the list if not already in the list
    if(found!=1){
     if (n2.length() > 1){
        if (patronHead==NULL){
            patronHead = new struct Patron;
            patronHead -> pnext = NULL;
            patronTail = patronHead;
        }
        else{
            patronTail -> pnext = new struct Patron;
            patronTail = patronTail->pnext;
            patronTail->pnext = NULL;
        }
         // this adds a first and last name to the linked list
         // and assignes a id number as IDNUM;
        patronTail-> lname = n2;
        patronTail-> fname = n;
        patronTail-> pid = IDNUM;
        cout<< "ADDED: "<< n <<" "<< n2 <<"  UID: ID"<<setfill('0')<<setw(3)<<patronTail->pid<<endl;
        IDNUM++;
        patronTail->child_count = 0;
        }
        else{
            cout<< "No last name was input, please give the last name"<<endl;
        }
    }
    //input.clear();
}
// this function will simply reprint the list of commands.
void commands(){
    cout<<"AVAILABLE COMMANDS:"<<endl;
    cout<<"    add name <first last>"<<endl;
    cout<<"    add spouse <uid> <first last>"<<endl;
    cout<<"    add child <uid> <first last>"<<endl;
    cout<<"    add address1 <uid> <address>"<<endl;
    cout<<"    add city <uid> <city>"<<endl;
    cout<<"    add state <uid> <state>"<<endl;
    cout<<"    add zip <uid> <zip>"<<endl;
    cout<<"    add date_birth <uid> <ddmmyyyy>"<<endl;
    cout<<"    add date_wedding <uid> <ddmmyyy>"<<endl;
    cout<<"    add date_death <uid> <ddmmyyyy>"<<endl;
    cout<<"    search <name>"<<endl;
    //cout<< "    remove <name>"<<endl;
    cout<<"    print all"<<endl;
    cout<<"     print<uid>"<<endl;
    cout<<"    file <filename>"<<endl;
    cout<<"    quit"<<endl;
}
// this adds a spouse and links them to another patron on the list.
void add_spouse(int sp,string spn,string spl){
    //this runs the add function to add the spouse to the list if they are not already in it.
    add(spn, spl);
    int found = 0;
    patronWalk = patronHead;
    //this will search for the spouse in the list and assign them to Temp.
    while (patronWalk!=NULL) {
        if (patronWalk->lname == spl && patronWalk->fname == spn){
            //patronWalk = NULL;
                //cout<<"TRUE:" << patronWalk->fname<<" "<< patronWalk->lname <<" "<<setfill('0')<<setw(3)<<patronWalk->pid<<endl;
                //cout<<"TRUE:" <<setfill('0')<<setw(3)<<patronWalk->pid<<endl;
                found = 1;
            //Temp is set as the spouse struct in the list
                patronTemp = patronWalk;
                patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk ->pnext;
        }
    }
    //this will search for the assigned patron and add spouse to both patrons.
    patronWalk = patronHead;
    while (patronWalk!=NULL) {
        if (patronWalk->pid == sp){
            // used both list and pointer to spouse to link the two list. 
            patronWalk->spouse = patronTemp;
            patronTemp->spouse = patronWalk;
            //cout<< patronWalk ->spouse->fname<<endl;
            //cout<< patronTemp->spouse->fname<<endl;
            patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk->pnext;
        }
        
    }
    if (found != 1) {
        cout << "FALSE: "<< spn << " "<< spl <<endl;
    }
    //input.clear();
        //cout <<"worked"<<endl;
}
//this function adds child and links to parent
void add_child(int pcid,string cn,string cn2){
    add(cn, cn2);
    int found = 0;
    patronWalk = patronHead;
    //this will search for the child in the list and assign them to Temp.
    while (patronWalk!=NULL) {
        if (patronWalk->lname == cn2 && patronWalk->fname == cn){
            //patronWalk = NULL;
            found = 1;
            //Temp is set as the child struct in the list
            patronTemp = patronWalk;
            patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk ->pnext;
        }
    }
    //this will search for the assigned patron and add child to both patrons.
    patronWalk = patronHead;
    while (patronWalk!=NULL) {
        if (patronWalk->pid == pcid){
            //will make the array pointer in the specified patron list
            //point to and label the patron as child to the specidied patron
            patronWalk->child[patronWalk->child_count] = patronTemp;
            //cout<< patronWalk ->child[patronWalk->child_count]->fname<<endl;
            //cout<< patronTail->parent->fname<<endl;
			patronTemp->parent = patronWalk;
            patronWalk->child_count++;
            //patronWalk->child->pnext = ;
            patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk->pnext;
        }
        
    }
    /*patronWalk = patronHead;
    //int ccount=0;
    while (patronWalk!=NULL) {
        if (patronWalk->pid == pcid){
            for( int i = 0; i< patronWalk->child_count;i++){
                cout<<patronWalk->child[i]->fname<<endl;
            }
        }
    
        else{
            patronWalk = patronWalk->pnext;
        }
        patronWalk = NULL;
    }*/
    if (found != 1) {
        cout << "FALSE: "<< cn << " "<< cn2 <<endl;
    }
}

void add_address(int ad,string ad1){
    patronWalk = patronHead;
    while (patronWalk != NULL){
        if (patronWalk->pid == ad){
            patronWalk->address = ad1 + " " + input3;
            cout<< "ADDED Address1: "<< patronWalk->address << endl;
            patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk->pnext;
        }
    }
}

void add_city(int ct,string ct1){
    patronWalk = patronHead;
    while (patronWalk != NULL){
        if (patronWalk->pid == ct){
            patronWalk->city = ct1;
            cout<< "ADDED CITY: "<< patronWalk->city << endl;
            patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk->pnext;
        }
    }
}
void add_state(int st,string st1){
    patronWalk = patronHead;
    while (patronWalk != NULL){
        if (patronWalk->pid == st){
            patronWalk->state = st1;
            cout<< "ADDED STATE: "<< patronWalk->state << endl;
            patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk->pnext;
        }
    }

}
void add_zip(int zi,string zi1){
    patronWalk = patronHead;
    while (patronWalk != NULL){
        if (patronWalk->pid == zi){
            patronWalk->zip = zi1;
            cout<< "ADDED ZIP: "<< patronWalk->zip << endl;
            patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk->pnext;
        }
    }

}
void add_db(int db,string db1){
    patronWalk = patronHead;
    while (patronWalk != NULL){
        if (patronWalk->pid == db){
            patronWalk->date_birth = db1;
            cout<< "ADDED DATE_BIRTH: "<< patronWalk->date_birth << endl;
            patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk->pnext;
        }
    }
}
void add_dd(int dd,string dd1){
    patronWalk = patronHead;
    while (patronWalk != NULL){
        if (patronWalk->pid == dd){
            patronWalk->date_death = dd1;
            cout<< "ADDED DATE_DEATH: "<< patronWalk->date_death << endl;
            patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk->pnext;
        }
    }
}
void add_wed(int wd,string wd1){
    patronWalk = patronHead;
    while (patronWalk != NULL){
        if (patronWalk->pid == wd){
            patronWalk->date_wed = wd1;
            cout<< "ADDED DATE_WEDDING: "<< patronWalk->date_wed << endl;
            patronWalk = NULL;
        }
        else{
            patronWalk = patronWalk->pnext;
        }
    }
}
// this function will search for a specific name and show there id number.
// can also be used to see if a person is in the data base.
void search(string s,string s1){
    int found=0;
    s[0] = toupper(s[0]);
    s1[0] = toupper(s1[0]);
    //cout<< s << " | "<< s1<<endl;
    patronWalk = patronHead;
    while (patronWalk!=NULL) {
        if (patronWalk->lname == s1){
            //cout<<"TRUE:" << patronWalk->lname<<" "<<setfill('0')<<setw(3)<<patronWalk->pid<<endl;
            //found = 1;
            //patronWalk = NULL;
            if (patronWalk->fname == s){
                //cout<<"TRUE:" << patronWalk->fname<<" "<< patronWalk->lname <<" "<<setfill('0')<<setw(3)<<patronWalk->pid<<endl;
                cout<<"TRUE:" <<setfill('0')<<setw(3)<<patronWalk->pid<<endl;
                found = 1;
                patronWalk = NULL;
            }
        }
        else{
        patronWalk = patronWalk ->pnext;
        }
    }
    if (found != 1) {
        cout << "FALSE: "<< s << " "<< s1 <<endl;
    }
    //input.clear();
}
// this function will print a list of all patrons in the data base and there id numbers.
void print_all(){
    /*patronWalk = patronHead;
    cout << "Current list of patrons: " <<endl;
    while (patronWalk!=NULL) {
        cout<<"id"<<setfill('0')<<setw(3)<<patronWalk->pid<<" "<<patronWalk->name<< endl;
        patronWalk = patronWalk ->pnext;
    }*/
    int counter=0;
    //int tempint;
    struct Patron *tempstring;
    patronWalk = patronHead;
    while (patronWalk!=NULL) {
        counter++;
        patronWalk = patronWalk ->pnext;
    }
            //go through every node
            for(int i = 0; i < counter; i++){
                patronWalk = patronHead;
                //skip sorted nodes
                for(int j = 0; j < i; j++){
                    patronWalk = patronWalk->pnext;
                }
                patronTemp = patronWalk;
                while(patronWalk != NULL){
                    if(patronWalk->lname < patronTemp->lname){
                        tempstring = patronWalk;
                        //tempint= patronWalk->pid;
                        patronWalk = patronTemp;
                        //patronWalk->pid=patronTemp->pid;
                        patronTemp = tempstring;
                        //patronTemp->pid = tempint;
                    }
                    patronWalk = patronWalk->pnext;
                }
                
                patronWalk = patronHead;
                for(int j = 0; j < i; j++){
                    patronWalk = patronWalk->pnext;
                }
                
            }
            patronWalk = patronHead;
            while(patronWalk != NULL){
                cout<<patronWalk->fname<<" "<<patronWalk->lname<< " UID: "<<setfill('0')<<setw(3)<<patronWalk->pid<<endl;
                patronWalk = patronWalk->pnext;
            }
    
}
// this function will print out all known information for a given patron.
void print(int pr){
    cout<< pr <<endl;
    patronWalk = patronHead;
    while(patronWalk != NULL){
        if (patronWalk->pid == pr){
            cout<<"         UID: ID"<<setfill('0')<<setw(3)<<patronWalk->pid<<endl;
            cout<<"        NAME: "<< patronWalk->fname<<" "<<patronWalk->lname<< endl;
            cout<<"    ADDRESS1: "<<patronWalk->address<<endl;
            cout<<"        CITY: "<<patronWalk->city<<endl;
            cout<<"       STATE: "<<patronWalk->state<<endl;
            cout<<"         ZIP: "<<patronWalk->zip<<endl;
            cout<<"  DATE_BIRTH: "<<patronWalk->date_birth<<endl;
            cout<<"  DATE_DEATH: "<<patronWalk->date_death<<endl;
            cout<<"DATE_WEDDING: "<<patronWalk->date_wed<<endl;
            if (patronWalk->spouse!=NULL){
                cout<<"      SPOUSE: "<<patronWalk->spouse->fname<<" "<<patronWalk->spouse->lname<<endl;
            }
            
            for(int i = 0; i <patronWalk->child_count;i++){
                if(patronWalk->child[i]!=NULL){
                cout<<"      CHILD"<< i <<": "<<patronWalk->child[i]->fname;
                cout<<" "<<patronWalk->child[i]->lname<<endl;
                }
            }
            patronWalk = NULL;
        }
        else{
        patronWalk = patronWalk->pnext;
        }
    }
}
// this was taken and modified to my code from runnable code masong
// it was originally designed to work with classes. But I made slight changes
// for it to work with my structures.
/*void remove(string r,string r1){
    Patron *pPre = NULL, *pDel = NULL;
    int rem1=0;
    // Check whether it is the head node?
     if it is, delete and update the head node
    if (patronHead->lname == r) {
        // point to the node to be deleted
        pDel = patronHead;
        // update /
        patronHead = pDel->pnext;
        delete pDel;
        cout<<"Removal successful: "<< r <<endl;
        rem1 =1;
        return;
    }
    
    pPre = patronHead;
    pDel = patronHead->pnext;
    
    //traverse the list and check the value of each node
    while (pDel != NULL) {
        if (pDel->lname == r) {
            // Update the list
            pPre->pnext = pDel->pnext;
            //If it is the last node, update the tail
            if (pDel == patronTail) {
                patronTail = pPre;
            }
            delete pDel;  Here only remove the first node with the given value
            cout<<"Removal successful: "<< r <<endl;
            rem1=1;
            break; //break and return
        }
        pPre = pDel;
        pDel = pDel->pnext;
    }
    if (rem1!=1){
        cout<< "ERROR Not found for Removal: "<< r <<endl;
    }

    //input.clear();
}*/

// this function will read from file and run the choice
// program. This function can read commas or spaces from
// xls of csv files. .txt files work but the use of commas
// in .txt files seems to add unknown chars to the end of
// the input name.
void fromfile(string f){
    
    //ofstream filese("example.txt");
    string intcon;
    string line;
    ifstream myfile (f);
    //total.clear();
    //input.clear();
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            //transform(line.begin(), line.end(), line.begin(),::tolower);
            
            size_t found = line.find_first_of(',');
                //line[found] = ',';
                //string::iterator end_pos = remove(line.begin(),line.end(),' ');
                //line.erase(end_pos,line.end());
            //string::iterator end_pos = remove(line1.begin(),line1.end(),' ');
            //line1.erase(end_pos,line1.end());
            //transform(finish.begin(), finish.end(),finish.begin(),::tolower);
            finish = line;
            total = line.substr(0,found);
            line.erase(0,total.length()+1);
            //cout << total<<endl;
            transform(total.begin(), total.end(),total.begin(),::tolower);
            
            size_t found2 = line.find_first_of(',');
            
            input = line.substr(0,found2);
            line.erase(0,input.length()+1);
            size_t found3 = line.find_first_of(',');
            
            if (isdigit(line[0])){
                intcon = line.substr(0,found3);
                //cout<< "num read"<<endl;
                // starts with integer
                ipatr = atoi(intcon.c_str());
                line.erase(0,intcon.length()+1);
                size_t found4 = line.find_first_of(',');
                input2 = line.substr(0,found4);
                line.erase(0,input2.length()+1);
            }
            else{
                // does not start with integer
                input2 = line.substr(0,found3);
                //cout<< " no num"<<endl;
                line.erase(0,input2.length()+1);
            }
            //string::iterator end_pos1 = remove(input.begin(),input.end(),' ');
            //input.erase(end_pos1,input.end());
            input3 = line;
            //input[0] = toupper(input[0]);
            input2[0] = toupper(input2[0]);
            input3[0] = toupper(input3[0]);
            //string::iterator end_pos2 = remove(input3.begin(),input3.end(),' ');
            //input3.erase(end_pos2,input3.end());
            //string::iterator end_pos3 = remove(total.begin(),total.end(),' ');
            //total.erase(end_pos3,total.end());
            //cout<< input <<" "<< input2 <<" "<< input3 << endl;
            //cout<<line1<<endl;
            
            // this will clear the line1 string just to be sure
            // there are no chars left on the line.
            
            choice(total,input);
            line.clear();
            total.clear();
            input.clear();
            input2.clear();
            input3.clear();
        }
        myfile.close();
    }
    else{
        cout << "CANNOT OPEN INPUT FILE"<<endl;
    }
    //filuse = 1;
}

void ftree(int pr){
 patronWalk = patronHead;
    while(patronWalk != NULL){
        if (patronWalk->pid == pr){
            cout<<"NAME: "<< patronWalk->fname<<" "<<patronWalk->lname<<" -- ";
		
            cout<<"SPOUSE: "<<patronWalk->spouse->fname<<" "<<patronWalk->spouse->lname<<endl;
            for(int i = 0; i <patronWalk->child_count;i++){
                cout<<"\tCHILD "<< i+1 <<": "<<patronWalk->child[i]->fname;
                cout<<" "<<patronWalk->child[i]->lname;
				if(patronWalk->child[i]->spouse!=NULL){
				cout<<" -- SPOUSE: "<<patronWalk->child[i]->spouse->fname<<" "<<patronWalk->child[i]->spouse->lname<<endl;
				}
				else{
					cout<<endl;
				}
				for(int j = 0; j < patronWalk->child[i]->child_count;j++){
                    if (patronWalk->child[i]->child[j]!=NULL){
                        cout<<"\t\tGRANDCHILD "<< j+1 <<": "<<patronWalk->child[i]->child[j]->fname;
                        cout<<" "<<patronWalk->child[i]->child[j]->lname;
                        if(patronWalk->child[i]->child[j]->spouse!=NULL){
                            cout<< " -- SPOUSE: "<< patronWalk->child[i]->child[j]->spouse->fname<<" "<<patronWalk->child[i]->child[j]->spouse->lname<<endl;
                        }
                        else{
                         cout<<endl;
                        }
                    }
                    
            //patronWalk = NULL;
        }
        }
        }
        else{
        patronWalk = patronWalk->pnext;
        }
        patronWalk = NULL;
  }
}

/*
 List of sources used in my code
 void remove(); source : http://code.runnable.com/Us53QO5op1hWAACi/how-to-remove-a-node-from-a-linked-list-for-c%2B%2B

 
 */