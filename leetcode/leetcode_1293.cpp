#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Nagato {
    int x, y;
    int rest;
    Nagato(int _x, int _y, int _r): x(_x), y(_y), rest(_r) {}
};

class Solution {
private:
    //static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int shortestPath(vector< vector<int> >& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) {
            return 0;
        }

        k = min(k, m + n - 3);
        bool visited[m][n][k + 1];
        memset(visited, false, sizeof(visited));
        queue<Nagato> q;

        Nagato temp(0,0,k);
        //q.emplace(0, 0, k);
        q.push(temp);
        visited[0][0][k] = true;

        for (int step = 1; q.size() > 0; ++step) {
            int cnt = q.size();
            for (int _ = 0; _ < cnt; ++_) {
                Nagato cur = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = cur.x + dirs[i][0];
                    int ny = cur.y + dirs[i][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        if (grid[nx][ny] == 0 && !visited[nx][ny][cur.rest]) {
                            if (nx == m - 1 && ny == n - 1) {
                                return step;
                            }
                            Nagato temp(nx,ny,cur.rest);
                            //q.emplace(nx, ny, cur.rest);
                            q.push(temp);
                            visited[nx][ny][cur.rest] = true;
                        }
                        else if (grid[nx][ny] == 1 && cur.rest > 0 && !visited[nx][ny][cur.rest - 1]) {
                            Nagato temp(nx, ny, cur.rest - 1);
                            //q.emplace(nx, ny, cur.rest - 1);
                            q.push(temp);
                            visited[nx][ny][cur.rest - 1] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    int M = 5, N = 3;
    //vector< vector<int> > grid = {
        //{0, 0, 0},{1, 1, 0},{0, 0, 0},{0, 1, 1},{0, 0, 0}, };
    vector< vector<int> > grid(M, vector<int>(N));
    //grid[0] = vector<int>{0,0,0};
    //grid[1] = vector<int>{1,1,0};
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[3][1] = 1;
    grid[3][2] = 1;
    for (unsigned int i = 0; i < grid.size(); i++){
        for (unsigned int j = 0; j < grid[i].size(); j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    Solution o;
    int result = o.shortestPath(grid, 1);
    cout << "result is " << result << endl;
    return 0;
}
