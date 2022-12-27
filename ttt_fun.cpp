#include <vector>
#include <iostream>

void introduction(int boardSize){
  std::cout << "Bienvenidos, el primer jugador es X y el segundo es O, para marcar una casilla introduzca un número del 1 al 9.";
  for (int j=1;j<=boardSize;j++){
    std::cout << "\n"; 
    for (int i=1;i <boardSize; i++){
      std::cout << "_|"; 
    }
    std::cout << "_\n"; 
  }
}

int take_turn(int turn,int boardSize){
  if (turn%2 == 0){
    std::cout << "Jugador O. Ingresa un número del 1 al " << (boardSize*boardSize) << ":";
    return 2;
  } else{
    std::cout << "Jugador X. Ingresa un número del 1 al " << (boardSize*boardSize) << ":";
    return 1;
  }
}


void draw(std::vector<std::string> board, int boardSize,std::string** boardMatrix) { 
  for (int i=0;i<boardSize;i++){
    std::cout << "\n";
    for (int j=0;j<boardSize-1; j++){
      if (boardMatrix[i][j] == ""){
        std::cout << "_|"; 
      }
      else std::cout << boardMatrix[i][j] << "|";
    } 
    if (boardMatrix[i][boardSize-1] == ""){
      std::cout << "_ \n"; 
    }
    else  std::cout << boardMatrix[i][boardSize-1] << "\n"; 
  }
 
}

bool is_winner(int boardSize,std::string** boardMatrix){
    for (int i=0;i<boardSize;i++){
      int a = 0;
      int b = 0;
      for (int j=1;j<boardSize;j++){
        if (boardMatrix[i][j] == "X" && boardMatrix[i][j-1] == "X"){
          a = a+1;
        }
        else if (boardMatrix[i][j] == "O" && boardMatrix[i][j-1] == "O"){ 
          b = b+1;
      }
      if (a == boardSize-1){
        std::cout << "El jugador X gana";
        exit(0);
        return 0;
      }
      else if (b == boardSize-1){
        std::cout << "El jugador O gana";
        exit(0);
        return 0;
        
      }
      }
    }
    /*Check verticals*/
    for (int i=0;i<boardSize;i++){
      int a = 0;
      int b = 0;
      for (int j=1;j<boardSize;j++){
        if (boardMatrix[j][i] == "X" && boardMatrix[j-1][i] == "X"){
          a = a+1;
        }
        else if (boardMatrix[j][i] == "O" && boardMatrix[j-1][i] == "O"){ 
          b = b+1;
        }
      if (a == boardSize-1){
        std::cout << "El jugador X gana";
        exit(0);
        return 0;
      }
      else if (b == boardSize-1){
        std::cout << "El jugador O gana";
        exit(0);
        return 0;
      }
      }
    }    
    /*Check diags*/
    std::vector<std::string> boardcount(boardSize);
    for (int i=0;i<boardSize;i++){
      for (int j=0;j<boardSize;j++){
        if (j == i){
          boardcount.push_back(boardMatrix[i][j]);
        }
      }
    }


    int a = 0;
    int b = 0;
    for (int i = 1;i<boardcount.size();i++){
      if (boardcount[i] == "X" && boardcount[i-1]=="X"){
        a = a+1;
      }
      else if (boardcount[i] == "O" && boardcount[i-1]=="O"){
        b = b+1;
      }
    if (a == boardSize-1){ 
      std::cout << "El jugador X gana";
      exit(0);
      return 0;
    }
    else if (b == boardSize-1){
      std::cout << "El jugador O gana";
      exit(0);
      return 0;
    }   
    }
    std::vector<std::string> boardcountI(boardSize);
    for (int i=0;i<boardSize;i++){
      for (int j=0;j<boardSize;j++){
        if (j == (boardSize-1) - i){
          boardcountI.push_back(boardMatrix[i][j]);
        }
      }
    }
    a = 0;
    b = 0;
    for (int i = 1;i<boardcountI.size();i++){
      
      if (boardcountI[i] == "X" && boardcountI[i-1]=="X"){
        a = a+1;
      }
      else if (boardcountI[i] == "O" && boardcountI[i-1]=="O"){
        b = b+1;
      }
    if (a == boardSize-1){ 
      std::cout << "El jugador X gana";
      exit(0);
      return 0;
    }
    else if (b == boardSize-1){
      std::cout << "El jugador O gana";
      exit(0);
      return 0;
    }   
    }     

}

