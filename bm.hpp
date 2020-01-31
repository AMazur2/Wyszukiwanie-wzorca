#ifndef bm_hpp
#define bm_hpp

#include <vector>
#include <string>
#include <iostream>

const int fc = 97;
const int lc = 98;
const int diff = lc-fc;

std::vector<int> findBM( std::string const & str, std::string const & text )
{
    int last[diff+1];                                   //tablica LAST
    int s1 = str.size();                                //długość wzorca
    int s2 = text.size();                               //długość tekstu
    std::vector<int> result = {};                       //vector wyników
    std::cout <<"Pattern: \t" << str << std::endl;
    std::cout <<"Text: \t\t" << text << std::endl;

    if( !s1 || !s2 || s1 > s2)                          //tekst i wzorzec muszą istnieć i długość
        return result;                                  //wzorca nie może być większa od długości tekstu
    
    if( s1 == s2 )
    {
        if( str == text )
            {
                result.push_back(0);
                return result;
            }
    }

    int i;
    for( i = 0; i < diff; ++i )
        last[i] = -1;                                   //początkowo wypełniamy wartością -1
    for( i = 0; i < s1; ++i )
        last[str[i]-fc] = i;                            //wypełniamy ostatnim indeksem pod którym jest dana litera

    int next[s1+1];                                     //tablica next
    int pi[s1+1];                                       //tablica pi

    for( i = 0; i < s1+1; ++i )
        next[i] = 0;                                    //zerujemy elementy tablicy next
    
    i = s1;
    int h = s1+1;                                       //pomocniczy iterator
    pi[i] = h;                                          //ostatni element tablicy pi ustawiamy na wartość o 1 większą od długości wzorca
    while( i > 0 )                                      //krok 1 obliczania tablicy next
    {
        while( (h <= s1) && ( str[i-1] != str[h-1] ) )
        {
            if( next[h] == 0 )
                next[h] = h-i;
            h = pi[h];
        }
        pi[--i] = --h;
    }

    h = pi[0];
    for( i = 0; i < s1+1; ++i)                          //krok 2 obliczania tablicy next
    {
        if(next[i] == 0)
            next[i] = h;
        if( i == h )
            h = pi[h];
    }

    int pos;                                            //obecna pozycja - będzie wskazywać początek wzorca w tekscie
    pos = i = 0;
    while( i < s2-s1+1 )                                //szukamy
    {
        int j = s1 -1;
        while( ( j > -1 ) && ( str[j] == text[i+j] ) )
            j--;
        if(j == -1)
        {
            while(pos < i)
                pos++;
            result.push_back(pos);
            pos++;
            i += next[0];
        }
        else
            i += std::max(next[j+1], j-last[text[i+j]-fc]);
    }
    return result;
}

#endif