#include <iostream>
#include <cstdio>

using namespace std;

int **map;
int max_i, max_j;
int current_i;
int current_j;

int end_i;
int end_j;

int dfs(int i, int j) {

    // if dfs() return 1;
    int result;

    if(i == max_i) return 0; // 현재 위치가 가장 하단인 부분
    if(j == max_j) return 0; // 현재 위치가 가장 오른쪽인 부분
    if(i < 0) return 0; // 현재 위치가 가장 상단인 부분
    if(j < 0) return 0; // 현재 위치가 가장 왼쪽인 부분
    if(map[i][j] == 3) return 1; // 동굴의 끝을 만나는 부분
    
    result = dfs(i+1, j);
    if(result == 0)
        cout << "(" << i << ", " << j << ")" << endl;
    
    result = dfs(i, j+1);
    if(result == 0)
        cout << "(" << i << ", " << j << ")" << endl;

    if(map[i][j] == 0) return 0;
}

int main() {

    int i, j;

    freopen("input.txt", "r", stdin);

    cin >> max_i;
    cin >> max_j;

    map = (int **)malloc(sizeof(int *) * max_i); // memory dynamic allocation
    for(i = 0; i < max_i; i++) {
        map[i] = (int *)malloc(sizeof(int) * max_j);
    }
    
    for(i = 0; i < max_i; i++) { // input map data
        for(j = 0; j < max_j; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                current_i = i;
                current_j = j;
            }
            //cout << map[i][j] << " ";
        }
        //cout << endl;
    }

    dfs(current_i, current_j);

    return 0;
}
