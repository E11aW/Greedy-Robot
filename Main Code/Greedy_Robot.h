#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_
#include <iostream>
#include <vector>
using namespace std;

class Greedy_Robot
{
public:
    //Constructors
    Greedy_Robot();
    Greedy_Robot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);
    //Getters and Setters
    int max_distance() const;
    int robot_x() const;
    int robot_y() const;
    int treasure_x() const;
    int treasue_y() const; 
    void SetValues(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);
    //Actions
    void FindPath();
    //Operator Overloads
    friend ostream& operator<<(ostream& stream, const Greedy_Robot& robot);
    friend istream& operator>>(istream& stream, Greedy_Robot& robot);
private:
    int max_distance_;
    int robot_x_, robot_y_;
    int treasure_x_, treasure_y_;
    int shortest_possible_distance_;
    string current_path_;
    vector<string> paths_;
    //Actions
    void FindPath(int current_robot_x, int current_robot_y, int current_moves, char past_direction);
    bool CheckValues();
};
#endif