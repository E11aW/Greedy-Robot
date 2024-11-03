#include <iostream>
#include <fstream>
#include "Greedy_Robot.h"
using namespace std;

void testRobot();

int main(int argc, char* argv[])
{
    ofstream outputfile;
    outputfile.open("robot_tests_results.txt", ios::app);
    if(argc < 6 || !outputfile.is_open()) return 1;
    int distance = stoi(argv[1]);
    int robotX = stoi(argv[2]);
    int robotY = stoi(argv[3]);
    int treasureX = stoi(argv[4]);
    int treasureY = stoi(argv[5]);
    Greedy_Robot robot(distance, robotX, robotY, treasureX, treasureY);
    outputfile << robot << endl;
    outputfile.close();
}