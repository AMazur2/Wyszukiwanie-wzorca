#ifndef naive_hpp
#define naive_hpp

#include <vector>
#include <string>
#include <iostream>

std::vector<int> findN( std::string const & str, std::string const & text )
{
    std::vector<int> res = {};
    int s1 = str.size();
    int s2 = text.size();

    if( !s1 || !s2 || s1 > s2 )
        return res;

    if( s1 == s2 )
    {
        if( str == text )
            {
                res.push_back(0);
                return res;
            }
    }

    for( int i = 0; i < s2; ++i )
    {
        std::string wind = text.substr(i, s1);
        if( wind == str )
        {
            res.push_back(i);
        }
    }

    return res;
}

#endif