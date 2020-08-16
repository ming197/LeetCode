#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 思路：dfs或者bfs
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int color = image[sr][sc];
        getLabels(image, visited, sr, sc, color, newColor);
        return image;

        
    }
    vector<int> findNeighbor(int sr, int sc, int color, vector<vector<int>>& image,  vector<vector<int>>& visited){
        vector<int> coordinate;
        int m = image.size(), n = image[0].size();
        if(sr-1>=0 && image[sr-1][sc] == color && visited[sr-1][sc]==0){
            coordinate.push_back(sr-1);
            coordinate.push_back(sc);
        }
        if(sr+1<m && image[sr+1][sc] == color && visited[sr+1][sc]==0){
            coordinate.push_back(sr+1);
            coordinate.push_back(sc);
        }
        if(sc-1>=0 && image[sr][sc-1] == color && visited[sr][sc-1]==0){
            coordinate.push_back(sr);
            coordinate.push_back(sc-1);
        }
        if(sc+1<n && image[sr][sc+1] == color && visited[sr][sc+1]==0){
            coordinate.push_back(sr);
            coordinate.push_back(sc+1);
        }
        return coordinate;
    }
    void getLabels(vector<vector<int>>& image, vector<vector<int>>& visited, int sr, int sc, int color, int newColor){
        vector<int> neighbors;
        image[sr][sc] = newColor;
        visited[sr][sc] = 1;
        neighbors = findNeighbor(sr, sc, color, image, visited);

        if(neighbors.size()!=0){
            for(int i=0; i<neighbors.size()/2;++i){
                getLabels(image, visited, neighbors[2*i], neighbors[2*i+1], color, newColor);
            }
        }
        
    }
    
};





int main(){
    vector<vector<int>> image = {{0,0,0}, {0,0,0}};
    int sr = 0, sc = 0;
    int newColor = 2;
    Solution solution;
    image = solution.floodFill(image, sr, sc, newColor);
    int m = image.size(), n = image[0].size();
    for(int i=0; i<m; ++i){
        if(i!=0){

            cout<< '\n';
        }
        for(int j=0; j<n; ++j){
            if(j!=0){
                cout<<' ';
            }
            cout<<image[i][j];
        }
        
    }
    return 0;
}