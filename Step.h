//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_STATE_H
#define UNTITLED4_STATE_H

#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

template<class State>
class Step {
    State state;
    double cost = 0;
    const Step<State>* comeFrom = nullptr;
    double Heuristic = 0;
public:

    explicit Step<State>(const State& state) {
        this->state = state;
    }
    Step<State>(){

    }
    Step(const Step<State>& oldStep) {
        this->state = oldStep.state;
        this->comeFrom = oldStep.comeFrom;
        this->cost = oldStep.cost;
    }

    void setParent(const Step<State>& p){
        this->comeFrom = &p;
    }


    void setCost(double cost) {
        this->cost = cost;
    }

    State getState() const{
        return this->state;
    }

    double getCost() const{
        return this->cost;
    }

    const Step<State>* getParent() const{
        return this->comeFrom;
    }

    bool operator<(Step<State> const& s) const{
        return (this->cost < s.cost);
    }
    bool operator>(Step<State> const& s) const{
        return (this->cost > s.cost);
    }
    bool operator<=(Step<State> const& s) const{
        return (this->cost <= s.cost);
    }
    bool operator>=(Step<State> const& s) const{
        return (this->cost >= s.cost);
    }

    //compare only the states.
    bool operator==(Step<State> const& s) const{
        return ( this->state == s.state);
    }

    Step<State>& operator=(const Step<State>& oldStep) {
        this->state = oldStep.state;
        this->cost = oldStep.cost;
        this->comeFrom = oldStep.comeFrom;
        return *this;
    }
    double getHeuristic() const{
        return this->Heuristic;
    }
    void setHeuristic(double h){
        this->Heuristic = h;
    }

};






#endif //UNTITLED4_STATE_H
