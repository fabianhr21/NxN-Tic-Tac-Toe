#include <vector>
#include <iostream>
#include "ttt_fun.hpp"
#include <stdlib.h>

int main(int argc, char* argv[]){
  const int boardSize = strtol(argv[1],nullptr,0);
  std::vector<std::string> board(boardSize*boardSize);
  std::string** boardMatrix = new std::string*[boardSize];
  int mark;
  int turno;
  introduction(boardSize);
  for (int i =1; i < (boardSize*boardSize)+1;i++){
    turno = take_turn(i,boardSize);
    std::cin >> mark;
    mark -= 1;
    while (board[mark].empty() == false || mark > boardSize*boardSize ){
      std::cout << "\n Casilla ocupada. Intente otro número: ";
      std::cin >> mark;
      mark -= 1;
    }
    if (i % 2 == 0){
        board[mark] = "O";
     } else {
    board[mark] = "X";
     }
    /*Create board mATRIX*/
    int cont = 0;
    for (int i =0;i<boardSize;i++){
        boardMatrix[i] = new std::string[boardSize];
      for (int j=0;j<boardSize;j++){
        /*char a = board[cont];*/
        boardMatrix[i][j] = board[cont];
        cont++; 
      }
    }
    /*Draw board*/
    draw(board,boardSize,boardMatrix); 
    is_winner(boardSize,boardMatrix);
}
return 0;
}