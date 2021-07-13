//
// Created by shira on 1/12/19.
//

#include <cstdio>
#include <monetary.h>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <cstring>
#include "MyMatrixClientHandler.h"

#define BUFFER_SIZE 1024


MyMatrixClientHandler::MyMatrixClientHandler(Searcher<cell>* searcher, CacheManager<MatrixSearchable, vector<cell>>* cm) {
    this->solver =  new SearchSolver<cell>(searcher);
    this->cm = cm;
}

void MyMatrixClientHandler:: handleClient(int sock_id) {

    char buffer[BUFFER_SIZE+1];
    string buff2 = "";
    while(buff2.find("end")==string::npos) {
        ssize_t n = read(sock_id, buffer, BUFFER_SIZE);
        if (n <= 0) {
            perror("ERROR read from socket");
            exit(1);
        }
        buffer[n] = 0;
        buff2 += buffer;
    }
    vector<cell> result;
    MatrixSearchable m = parseBuffer(buff2);
    if(this->cm->ifExist(m) ) {
        result = cm->getSolution(m);
    } else {
        result = this->solver->solve(&m);
        cm->saveSolution(m,result);
    }
    string resultString = fromREsultToString(result);

    ssize_t n = write(sock_id, resultString.c_str(),strlen(resultString.c_str()) );

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

}
MatrixSearchable MyMatrixClientHandler:: parseBuffer(const string& buffer) {
    stringstream ss(buffer);
    string line;
    vector<string> lines_extracted;
    while(getline(ss, line)) {
        lines_extracted.push_back(line);
    }
    if(lines_extracted.size()<4) {
        throw "invalid input from client";
    }
    vector<vector<int>> matrix;
    for(int i = 0; i < lines_extracted.size()-3; i++) {
        string current_line = lines_extracted[i];
        stringstream liness(current_line);
        int num;
        vector<int> row;
        while (liness >> num)
        {
            row.push_back(num);

            if (liness.peek() == ',')
                liness.ignore();
        }
        matrix.push_back(row);
    }
    cell init, goal;
    stringstream initss( lines_extracted[lines_extracted.size()-3]);
    int first, second;
    char comma;
    initss>>first>>comma>>second;
    init = make_pair(first,second);
    stringstream goalss(lines_extracted[lines_extracted.size()-2]);
    goalss>>first>>comma>>second;
    goal = make_pair(first,second);
    return MatrixSearchable(matrix, init, goal);
}

string MyMatrixClientHandler:: fromREsultToString(const vector<cell>& result) {
    string answer = "{ ";
    for(int i = 0; i < result.size()-1; i++) {
        cell subtruct = make_pair(result[i+1].first- result[i].first,
                result[i+1].second- result[i].second);
        if(subtruct == make_pair(1,0)) {
            answer+="Down ";
        } else if(subtruct == make_pair(-1,0)) {
            answer+="Up ";
        } else if(subtruct == make_pair(0,-1)) {
            answer+="Left ";
        } else if(subtruct == make_pair(0,1)) {
            answer+="Right ";
        }
    }
    answer+="}";
    return answer;
}

