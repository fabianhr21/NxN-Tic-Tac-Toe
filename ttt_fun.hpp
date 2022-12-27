#include <vector>
#include <iostream>

void introduction(int boardSize);
int take_turn(int turn, int boardSize);
void draw(std::vector<std::string> board,int boardSize,std::string** boardMatrix);
bool is_winner(int boardSize,std::string** boardMatrix);