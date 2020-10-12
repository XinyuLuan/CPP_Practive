#include <iostream>
#include "string.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    String s("-a--b-bbbb--");
    cout << s << endl;
    vector<String> s_set = s.split('-');
    String res;
    for(String si : s_set){
        if(si == "") res += String("\"\"");
        else{
            res += si;
        }
    }
//    for(String si : s_set){
//        if(si == "") cout << "\"\" ";
//        else cout << si << " ";
//    }
//    cout << endl;
    cout << res << endl;
    assert( res == String("\"\"a\"\"bbbbb\"\"\"\""));

    String s2("abc ef gh");
     cout << s2 << endl;
    vector<String> s_set2 = s2.split(' ');
    cout << "hahaha" << endl;
    String res2;
    for(String si : s_set2){
        if(si == "") res2 += String("\"\"");
        else{
            res2 += si;
        }
    }

    cout << "hahaha!!!!" << endl;
//    for(String si : s_set){
//        if(si == "") cout << "\"\" ";
//        else cout << si << " ";
//    }
//    cout << endl;
//    cout << "" << res << endl;
    assert( res2 == String("abcefgh"));
    return 0;
}
