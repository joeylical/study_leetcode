#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int i=0;
        int j=0;
        vector<vector<int>> step = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int step_i = 0;
        int counter = 1;
        int not_end = 1;

        result[i][j] = counter++;
        while(not_end) {
            not_end = 0;
            int step_x = step[step_i][0];
            int step_y = step[step_i][1];
            do{
                int new_i = i + step_x;
                int new_j = j + step_y;

                if(new_i >= n)
                    break;
                if(new_j >= n)
                    break;
                if(new_i < 0)
                    break;
                if(new_j < 0)
                    break;
                if(result[new_i][new_j])
                    break;
                not_end = 1;
                i = new_i;
                j = new_j;
                result[i][j] = counter++;
            }while(1);
            step_i++;
            step_i &= 3;
        }

        return result;
    }
};

int main() {
    int N = 5;
    Solution s;
    auto r = s.generateMatrix(N);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<r[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

