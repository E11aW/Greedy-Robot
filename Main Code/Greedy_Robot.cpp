#include "Greedy_Robot.h"

Greedy_Robot::Greedy_Robot()
{
    SetValues(0, 0, 0, 0, 0);
}
Greedy_Robot::Greedy_Robot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y)
{
    SetValues(max_distance, robot_x, robot_y, treasure_x, treasure_y);
}
int Greedy_Robot::max_distance() const 
{
    return max_distance_;
}
int Greedy_Robot::robot_x() const
{
    return robot_x_;
}
int Greedy_Robot::robot_y() const
{
    return robot_y_;
}
int Greedy_Robot::treasure_x() const
{
    return treasure_x_;
}
int Greedy_Robot::treasue_y() const
{
    return treasure_y_;
}
void Greedy_Robot::SetValues(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y)
{
    max_distance_ = max_distance;
    robot_x_ = robot_x;
    robot_y_ = robot_y;
    treasure_x_ = treasure_x;
    treasure_y_ = treasure_y;
    CheckValues();
}
void Greedy_Robot::FindPath()
{
    FindPath(robot_x_, robot_y_, 0, '0');
}
ostream& operator<< (ostream& stream, const Greedy_Robot& robot)
{
    int size = robot.paths_.size();
    if(size > 0)
    {
        for(string path : robot.paths_)
        {
            stream << path << endl;
        }
        if(robot.paths_[0] == "Already on treasure!") size = 0;
    }
    stream << "Number of paths: " << size << endl;
    return stream;
}
istream& operator>> (istream& stream, Greedy_Robot& robot)
{
    stream >> robot.max_distance_;
    stream >> robot.robot_x_;
    stream >> robot.robot_y_;
    stream >> robot.treasure_x_;
    stream >> robot.treasure_y_;
    robot.CheckValues();
    return stream;
}
bool Greedy_Robot::CheckValues()
{
    if(max_distance_ <= 0) return false;
    shortest_possible_distance_ = abs(robot_x_ - treasure_x_) + abs(robot_y_ - treasure_y_);
    if(shortest_possible_distance_ == 0) paths_.push_back("Already on treasure!");
    else FindPath();
    return true;
}
void Greedy_Robot::FindPath(int current_robot_x, int current_robot_y, int current_moves, char past_direction)
{
    //Base case for each path
    if(current_robot_x == treasure_x_ && current_robot_y == treasure_y_)
    {
        paths_.push_back(current_path_);
        return;
    }
    if(current_robot_y < treasure_y_ && (current_moves < max_distance_ || past_direction != 'n'))
    {
        current_path_ += "N";
        if(past_direction != 'n') FindPath(current_robot_x, current_robot_y + 1, 1, 'n');
        else FindPath(current_robot_x, current_robot_y + 1, current_moves + 1, 'n');
        current_path_.pop_back();
    }
    if(current_robot_y > treasure_y_ && (current_moves < max_distance_ || past_direction != 's'))
    {
        current_path_ += "S";
        if(past_direction != 's') FindPath(current_robot_x, current_robot_y - 1, 1, 's');
        else FindPath(current_robot_x, current_robot_y - 1, current_moves + 1, 's');           
        current_path_.pop_back();
    }   
    if(current_robot_x < treasure_x_ && (current_moves < max_distance_ || past_direction != 'e'))
    {
        current_path_ += "E";
        if(past_direction != 'e') FindPath(current_robot_x + 1, current_robot_y, 1, 'e');
        else FindPath(current_robot_x + 1, current_robot_y, current_moves + 1, 'e');         
        current_path_.pop_back();
    }
    if(current_robot_x > treasure_x_ && (current_moves < max_distance_ || past_direction != 'w'))
    {
        current_path_ += "W";
        if(past_direction != 'w') FindPath(current_robot_x - 1, current_robot_y, 1, 'w');
        else FindPath(current_robot_x - 1, current_robot_y, current_moves + 1, 'w');
        current_path_.pop_back();
    }
}