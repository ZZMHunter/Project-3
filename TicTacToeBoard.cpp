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

bool TicTacToeBoard::isAvailable(int row, int col) const{
    if(isValidRow(row) && isValidCol(col)){
        return board[row][col]==' ';
    }
    else{
        return false;
    }
}

bool TicTacToeBoard::isValidRow(int row) const{
    return row >= 0 && row < board.size();
}

bool TicTacToeBoard::isValidCol(int col) const{
    return col >= 0 && col < board.size();
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

bool TicTacToeBoard::tie() const{
    for(int r = 0; r < board.size(); r++){
        if(std::count(board[r].begin(),board[r].end(),'X')==0 || std::count(board[r].begin(),board[r].end(),'O'==0)){
            return false;
        }
    }
    //check column
    for(int c = 0; c < board.size(); c++){
        char firstChar = board[0][c];
        bool chance = true;
        for(int r = 0; r < board.size(); r++){
            if(board[r][c]!=firstChar && board[r][c]!=' '){
                if(firstChar!=' ' && board[r][c]!=' '){
                    chance = false;
                }
                firstChar = board[r][c];
            }
        }
        if(chance){
            return false;
        }
    }
    char firstChar = board[0][0];
    bool chance = true;
    for(int i = 1; i < board.size(); i++){
        if(board[i][i]!=firstChar && board[i][i]!=' '){
            if(firstChar!=' ' && board[i][i]!=' '){
                chance = false;
            }
            firstChar = board[i][i];
        }
    }
    if(chance){
        return false;
    }
    chance = true;
    firstChar = board[0][board.size()-1];
    for(int i = 1; i < board.size(); i++){
        if(board[i][board.size()-1-i]!=firstChar && board[i][board.size()-1-i]!=' '){
            if(firstChar!=' ' && board[i][board.size()-1-i]!=' '){
                chance = false;
            }
            firstChar = board[i][board.size()-1-i];
        }
    }
    if(chance){
        return false;
    }
    return true;
}

bool TicTacToeBoard::win(int row, int col) const{
    return winByRow(row,col) || winByCol(row,col) || winByDiagonal(row,col);
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