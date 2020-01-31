#include "bm.hpp"
#include "naive.hpp"
#include <iostream>
#include <vector>

using namespace std;

void test1()
{    
    cout << "TEST 1: pattern longet than text" << endl;
    string pat, text;
    pat = "abbaaabba";
    text = "abba";
    cout << "Pattern length: " << pat.size() << endl;
    cout << "Text length: \t" << text.size() << endl;
    vector<int> bm = {};
    vector<int> n = {};
    bm = findBM( pat, text );
    n = findN( pat, text );
    cout << "BM results: \t";
    for(int i = 0; i < bm.size(); ++i )
        cout<< bm[i] << " ";
    cout << endl;
    cout << "N Results: \t";
    for(int i = 0; i < n.size(); ++i )
        cout<< n[i] << " ";
    cout << endl << endl;   
}

void test2()
{
    cout << "TEST 2: pattern don't exist" << endl;
    string pat, text;
    pat = "";
    text = "abba";
    cout << "Pattern length: " << pat.size() << endl;
    cout << "Text length: \t" << text.size() << endl;
    vector<int> bm = {};
    vector<int> n = {};
    bm = findBM( pat, text );
    n = findN( pat, text );
    cout << "BM results: \t";
    for(int i = 0; i < bm.size(); ++i )
        cout<< bm[i] << " ";
    cout << endl;
    cout << "N Results: \t";
    for(int i = 0; i < n.size(); ++i )
        cout<< n[i] << " ";
    cout << endl << endl;   
}

void test3()
{
    cout << "TEST 3: pattern is the same as text" << endl;
    string pat, text;
    pat = "abba";
    text = "abba";
    cout << "Pattern length: " << pat.size() << endl;
    cout << "Text length: \t" << text.size() << endl;
    vector<int> bm = {};
    vector<int> n = {};
    bm = findBM( pat, text );
    n = findN( pat, text );
    cout << "BM results: \t";
    for(int i = 0; i < bm.size(); ++i )
        cout<< bm[i] << " ";
    cout << endl;
    cout << "N Results: \t";
    for(int i = 0; i < n.size(); ++i )
        cout<< n[i] << " ";
    cout << endl << endl;   
}

void test4()
{
    cout << "TEST 4: pattern don't exist in text" << endl;
    string pat, text;
    pat = "aba";
    text = "abbaabbabbbabba";
    cout << "Pattern length: " << pat.size() << endl;
    cout << "Text length: \t" << text.size() << endl;
    vector<int> bm = {};
    vector<int> n = {};
    bm = findBM( pat, text );
    n = findN( pat, text );
    cout << "BM results: \t";
    for(int i = 0; i < bm.size(); ++i )
        cout<< bm[i] << " ";
    cout << endl;
    cout << "N Results: \t";
    for(int i = 0; i < n.size(); ++i )
        cout<< n[i] << " ";
    cout << endl << endl;  
}

void test5()
{
    cout<< "TEST 5: patter is in text" << endl;
    string pat, text;
    pat = "abba";
    text = "abbaabbabbbabba";
    cout << "Pattern length: " << pat.size() << endl;
    cout << "Text length: \t" << text.size() << endl;
    vector<int> bm = {};
    vector<int> n = {};
    bm = findBM( pat, text );
    n = findN( pat, text );
    cout << "BM results: \t";
    for(int i = 0; i < bm.size(); ++i )
        cout<< bm[i] << " ";
    cout << endl;
    cout << "N Results: \t";
    for(int i = 0; i < n.size(); ++i )
        cout<< n[i] << " ";
    cout << endl << endl;   
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}