#include <iostream> //std
#include <vector>
#include "TicTacToeBoard.hpp"

TicTacToeBoard::TicTacToeBoard(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}
TicTacToeBoard::TicTacToeBoard(int givenSize){
    for (int i = 0; i < givenSize; i++){
        for (int j = 0; j < givenSize; j++){
            board[i][j] = ' ';
        }
    }
}
int TicTacToeBoard::size() const{
    return board.size();
}
char TicTacToeBoard::getValue(int row, int col) const{
    return board[row][col];
}
void TicTacToeBoard::mark(int row, int col, char playerId){
    board[row][col] = playerId;
}
void TicTacToeBoard::clear(){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            board[i][j] = ' ';
        }
    }
}
std::string TicTacToeBoard::to_string() const{
    std::string result= "";
    for (int i = 0; i < board.size(); i++){
        result += "| ";
        for (int j = 0; j < board.size(); j++){
            result += board[i][j];
            result += " |"; 
        }
        result += "\n";
        for (int j = 0; j < board.size(); j++){
            result += "---";
        }
        result += "\n";
    }
    return result;
}

bool TicTacToeBoard::winByRow(int row, int col) const{
    for(int i = 1; i < board.size(); i++){
        if(board[row][i-1] != board[row][i]){
            return false;
        }
    }
    return true;
}

bool TicTacToeBoard::winByCol(int row, int col) const{
    for(int i = 1; i < board.size(); i++){
        if(board[i-1][col] != board[i][col]){
            return false;
        }
    }
    return true;
}

bool TicTacToeBoard::winByDiagonal(int row, int col) const{
    if(board[row][col]==' '){
        return false;
    }
    if(row!=col && row+col!=board.size()-1){
        return false;
    }
    if(row==col && row+col==board.size()-1){
        return winByDiagonal(row-1,col-1) || winByDiagonal(row-1,col+1);
    }
    for(int i = 0; i < board.size(); i++){
        if(row==col){
            if(board[i][i]!=board[row][col]){
                return false;
            }
        }
        else if(board[i][board.size()-1-i]!=board[row][col]){
            return false;
        }
    }
    return true;
}