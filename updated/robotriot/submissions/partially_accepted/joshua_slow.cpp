#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <numeric>

using namespace std;

#define ll long long
#define read(a) cin >> a
#define write(a) cout << (a) << endl
#define readpush(type,a) type temp; read(temp); a.push_back(temp)
#define readinsert(type,a) type temp; read(temp); a.insert(temp)
#define setcontains(set, x) (set.find(x) != set.end())

#define rep(i, high) for (ll i = 0; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define repp(i, high) for (ll i = high; i >= 0; i--)
#define inf 1e9

void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

bool can(vector<string>& map, int x, int y, set<pair<int,int>>& visited)
{
    if (x == 0 || x == map.size()-1 || y == 0 || y == map[0].size())
    {
        return true;
    }
    pair<int, int> coord = { x,y };
    if (setcontains(visited, coord))
    {
        return false;
    }
    else
    {
        visited.insert(coord);
    }
    
    vector<pair<int, int>> moves = { {0,1},{0,-1},{1,0},{-1,0} };
    repe(move, moves)
    {
        if (map[x+move.first][y+move.second] == '#')
        {
            continue;
        }

        if (can(map,x+move.first,y+move.second,visited))
        {
            return true;
        }

    }

    return false;
}

int main()
{
    fast();

    int rows;
    int columns;
    read(rows);
    read(columns);
    vector<string> map;
    rep(i, rows)
    {
        readpush(string, map);
    }

    vector<pair<int, int>> robots;
    bool found = true;
    while (found)
    {
        found = false;
        rep(i, rows)
        {
            rep(j, columns)
            {
                if (map[i][j] == 'X')
                {
                    robots.push_back({ i,j });
                    map[i][j] = '.';
                    found = true;
                }
            }
        }
    }
    
    repe(robot, robots)
    {
        set<pair<int,int>> visited;
        if (can(map, robot.first, robot.second, visited))
        {
            
            write("Death to humans");
            return 0;
        }
    }

    write("We are safe");

    return 0;
}