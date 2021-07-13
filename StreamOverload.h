//
// Created by osnat on 1/12/19.
//

#ifndef UNTITLED4_TEST_H
#define UNTITLED4_TEST_H

#include <istream>
#include <vector>
#include "MatrixSearchable.h"

using namespace std;

template<class T>
istream& operator>> (istream& is, vector<T>& val) {
    vector<T> tempvec;
    size_t size;
    is>>size;
    tempvec.reserve(size);
    char brace;
    is>>brace;
    for(int i = 0; i < size; i++) {
        T element;
        is>>element;
        tempvec.push_back(element);
    }
    is>>brace;
    val = tempvec;
    return is;
}

/**
 * writing all size of vector, than [ T T T ...] elements in the vector.
 * @tparam T
 * @param os
 * @param val
 * @return
 */
template<class T>
ostream& operator<< (ostream& os, const vector<T>& val) {
    os<< val.size()<<" ";
    os<<"[ ";
    for(int i = 0; i < val.size(); i++){
        os<<val[i]<<" ";
    }
    os<<"]";
    return os;
}


inline istream& operator>> (istream& is, pair<int,int>& val) {
    int first, second;
    char comma, bracket;
    is>>bracket;
    is>>first;
    is>>comma;
    is>>second;
    is>>bracket;
    val = make_pair(first,second);
    return is;
}

/**
 * writing the pair to string as "<first,second>"
 * @param os
 * @param val
 * @return
 */
inline ostream& operator<< (ostream& os, const pair<int,int>& val) {
    os<<"<"<<val.first<<","<<val.second<<">";
    return os;
}



#endif //UNTITLED4_TEST_H
