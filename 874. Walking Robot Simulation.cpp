class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        if(commands.empty()) return 0;

        int n = commands.size();

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;

        set<pair<int, int>> obsti;
        for(auto i : obstacles){
            obsti.insert({i[0], i[1]});
        }

        int x_cod = 0, y_cod = 0, maxDistance = 0;
        for(int cmd : commands){
            if(cmd == -2){
                dir = (dir - 1 + 4) % 4;
            }
            else if(cmd == -1){
                dir = (dir + 1) % 4;
            }
            else{
                for(int steps = 0; steps < cmd; steps++){
                    int new_x = x_cod + directions[dir].first;
                    int new_y = y_cod + directions[dir].second;

                    if(obsti.count({new_x, new_y})){
                        break;
                    }
                    x_cod = new_x;
                    y_cod = new_y;
                    maxDistance = max(maxDistance, x_cod*x_cod + y_cod*y_cod);
                }
            }
        }
        return maxDistance;
    }
};