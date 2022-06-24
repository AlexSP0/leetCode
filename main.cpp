#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {

public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        //Проверка квадрата 3х3
        for(int y = 0; y < 3; y++) {
            for(int x = 0; x < 3; x++) {
                if(!isValidRegion(board, x, y)) {
                    return false;
                }
            }
        }
        //проверка строк
        std::unordered_map<char,int> map1;
        for(int y = 0; y < board.size(); y++) {
            map1.clear();
            for(int x = 0; x < board[y].size(); x++) {
                if(board[y][x] != '.') {
                    if(map1.find(board[y][x]) == map1.end()) {
                        map1.insert({board[y][x],1});
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        //проверка колонок
        std::unordered_map<char,int> map2;
        for(int x = 0; x < board[0].size(); x++) {
            map2.clear();
            for(int y = 0; y < board.size(); y++) {
                if(board[y][x] != '.') {
                    if(map2.find(board[y][x]) == map1.end()) {
                        map2.insert({board[y][x],1});
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isValidRegion(std::vector<std::vector<char>>& board, int x, int y) {
        int leftX = x*3;
        int leftY = y*3;
        std::unordered_map<char,int> map;
        for(int currentY = leftY; currentY < leftY + 3; currentY++) {
            for(int currentX = leftX; currentX < leftX + 3; currentX++) {
                if(board[currentY][currentX] != '.') {
                    if(map.find(board[currentY][currentX]) == map.end()) {
                        //Элемент не найден
                        map.insert({board[currentY][currentX],1});
                    } else {
                        //Элемент найден
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    std::vector<std::vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                            {'6','.','.','1','9','5','.','.','.'},
                                            {'.','9','8','.','.','.','.','6','.'},
                                            {'8','.','.','.','6','.','.','.','3'},
                                            {'4','.','.','8','.','3','.','.','1'},
                                            {'7','.','.','.','2','.','.','.','6'},
                                            {'.','6','.','.','.','.','2','8','.'},
                                            {'.','.','.','4','1','9','.','.','5'},
                                            {'.','.','.','.','8','.','.','7','9'}};

    Solution sol;
    sol.isValidSudoku(board);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
