//
// Created by osnat on 1/12/19.
//

#ifndef UNTITLED4_FILECACHMANAGER_H
#define UNTITLED4_FILECACHMANAGER_H

#include <fstream>
#include <sstream>
#include "CacheManager.h"
#include "To_String.h"

template <class Problem, class Solution>
class FileCacheManager: public CacheManager< Problem, Solution> {
    //file format:
    //each line- string of problem:string of solution

    unordered_map<Problem, Solution> map;
    string fileName;
    bool isLoaded = false;
    pthread_mutex_t tex;



    void loadMap(){
        if(isLoaded) {
            return;
        }
        ifstream readFile;
        readFile.open(this->fileName);
        if(readFile.is_open()) {
            string line;
            while (getline(readFile, line)) {
                string problem, solution;
                problem = line.substr(0, line.find(':'));
                line.erase(0, line.find(':')+1);
                solution = line;

                stringstream ssp(problem);
                stringstream sss(solution);
                Problem prob;
                Solution sol;
                ssp>>prob;
                sss>>sol;

                map[prob] = sol;
            }
        }
        isLoaded = true;
    }
    void saveMap(){
        pthread_mutex_lock(&this->tex);
        if(!isLoaded) {
            loadMap();
        }
        ofstream writeToFile;
        writeToFile.open(this->fileName, ios::trunc);
        if(!writeToFile.is_open()) {
            throw "can't open FileCacheManager file";
        }
        for(const auto& keyVal: this->map) {
            writeToFile << keyVal.first << ":" << keyVal.second << endl;
        }
        pthread_mutex_unlock(&this->tex);

    }


public:
    explicit FileCacheManager<Problem,Solution>(const string& file_name) {
        this->fileName = file_name;
        pthread_mutex_init(&this->tex, nullptr);
    }


    ~FileCacheManager(){
        saveMap();
        pthread_mutex_destroy(&this->tex);
    }


    bool ifExist(const Problem& p) override {
        pthread_mutex_lock(&this->tex);
        if(!isLoaded) {
            loadMap();
        }
        bool res;
        res =(map.find(p) != map.end())? true:false;
        pthread_mutex_unlock(&this->tex);
        return res;

    }


    void saveSolution(const Problem& p,const Solution& s) override {
        pthread_mutex_lock(&this->tex);
        map[p] = s;
        pthread_mutex_unlock(&this->tex);

    }

    Solution getSolution(const Problem& p) override {
        pthread_mutex_lock(&this->tex);
        if(!isLoaded) {
            loadMap();
        }
        Solution s = map[p];
        pthread_mutex_unlock(&this->tex);
        return s;
    }

};


#endif //UNTITLED4_FILECACHMANAGER_H
