#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    const int INF=1e9;
    pair<int,int> solve(vector<string>& boards,int i,int j){
        int n=boards.size();
        int w=0;

        if(boards[i][j]<='9' && boards[i][j]>='0'){
            w=boards[i][j]-'0';
        }
        //base case
        if(i==n-1 && j==n-1){
            return {0,0};
        }
        //base case 2
        if(boards[i][j] == 'X'){
            return {0,0};
        }
        pair<int ,int>diagonal={-INF,0},right={-INF,0},down={-INF,0};
        if(i+1<n && j+1<n){
            diagonal=solve(boards,i+1,j+1);
        }
        if(i+1<n){
            right=solve(boards,i+1,j);
        }
        if(j+1<n){
            down=solve(boards,i,j+1);
        }

        int max_weight=max({diagonal.first,right.first,down.first});
        int count=0;
        if(max_weight == diagonal.first)    count++;
        if(max_weight == right.first)   count++;
        if(max_weight == down.first)    count++;

        return {max_weight+w,count};
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        auto [a,b] = solve(board,0,0);
        return {a,b};
    }
};