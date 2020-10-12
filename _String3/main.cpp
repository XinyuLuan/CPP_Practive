#include <iostream>
#include "string.hpp"

using namespace std;

int main()
{
    cout << "test of constructor()" << endl;
    String s;
    cout << "The s is: "<< s << endl;
    s = String("hahaha");
    cout << "The s is: "<< s << endl;
    cout << "end of constructor()..." << endl << endl;

    cout << "test of constructor('char')" << endl;
    String s2('r');
    cout << "The s2 is " << s2 << endl;
    cout << "end of constructor('char')..." << endl << endl;

    cout << "test of constructor(string)" << endl;
    String s3("receive");
    cout << "The s3 is " << s3 << endl;
    cout << "end of constructor(String)..." << endl << endl;

    cout << "test of constructor(String)" << endl;
    String s4(s3);
    cout << "the s4 is " << s4 << endl;
    for(int i = 0; i < s4.length(); i++){
        cout << s4[i] << " ";
    }
    cout << endl;
    cout << "end of constructor(String)..." << endl << endl;

    cout << "test of length" << endl;
    cout << s4.length() << endl;
    cout << "end of length..." << endl << endl;

    cout << "test of operater+" << endl;
    String s5 = s3+s4;
    cout << s5 << endl;
    cout  << endl;
    String s10 = s+" " +s2;
    cout << s10 << endl;
    cout << "end of operater+ ..." << endl << endl;

    cout << "test of operater+=" << endl;
    s2 += String(" RRRR");
    cout << s2 << endl;
    cout << "end of operater+= ..." << endl << endl;



    cout << "test of operate==" << endl;
    if(s2 == "r RRRR"){
        cout << " s2 == r RRRR" << endl;
    }
    else{
        cout << "s2 != r RRRR" << endl;
    }
    if(s3 == "receivE"){
        cout << "s3 == receivE" << endl;
    }
    else{
        cout << "s3 != receivE" << endl;
    }
    cout << "end of operater+= ..." << endl << endl;



    cout << "test of operate<" << endl;
    if(s2 < "r RRRR"){
        cout << " s2 < r RRRR" << endl;
    }
    else{
        cout << "s2 >= r RRRR" << endl;
    }
    if(s3 < "receiveeee"){
        cout << "s3 < receiveeee" << endl;
    }
    else{
        cout << "s3 >= receiveeee" << endl;
    }
    cout << "end of operater< ..." << endl << endl;


    cout << "test of substr" << endl;
    cout << s3.substr(2,4) << endl;
    cout << "end of substr ..." << endl << endl;

    cout << "test of findch" << endl;
    cout << "find 'e' in s3: " << s3.findch(2, 'e') << endl;
    cout << "fine ' ' in s2: " << s2.findch(0, ' ') << endl;
    cout << "find 'f' in s3: " << s3.findch(2, 'f') << endl;
    cout << "end of findch ..." << endl << endl;

    cout << "test of findstr" << endl;
    cout << "find 'ce' in s3: " << s3.findstr(2, "ce") << endl;
    cout << "fine ' R' in s2: " << s2.findstr(0, " RRR") << endl;
    cout << "find 'ef' in s3: " << s3.findstr(2, "ef") << endl;
    cout << "end of findstr ..." << endl << endl;

    cout << "test of split" << endl;
    String s6("-a--b-");
    std::vector<String> result = s6.split('-');
    String r;
    for(String si:result){
        if(si == "") r += "\"\"";
        else r+= si;
        r+= String(" ");
    }
    assert(r == "\"\" a \"\" b \"\" ");


    String s7("abc ef gh");
    std::vector<String> result2 = s7.split('-');
    String r2;
    for(String si:result2){
        if(si == "") r2 += "\"\"";
        else r2 += si;
        r2+= String(" ");
    }
    cout << r2 << endl;
    assert(r2 == "abc ef gh ");
    cout << "end of split ..." << endl << endl;

    return 0;
}
