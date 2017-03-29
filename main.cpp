#include <iostream>

using namespace std;

int vl[200000];
int vr[200000];


void DFS_bracket(char *str, int n, int left_used, int right_used, int &res) {
    if (left_used == right_used && left_used + right_used == 2 * n) {
        int temp = 0;
        for (int i = 0; i < left_used * 2; ++i) {
//            cout << str[i];
            if (str[i] == '(')
                temp += vl[i];
            else
                temp += vr[i];
        }
        res = res > temp ? res : temp;
        return;
    }
    if (left_used < right_used || left_used + right_used >= 2 * n) {
        return;
    }
    int index = left_used + right_used;
    str[index] = '(';
    DFS_bracket(str, n, left_used + 1, right_used, res);

    str[index] = ')';
    DFS_bracket(str, n, left_used, right_used + 1, res);

}


int main() {
    int N;
    cin >> N;

    for (int i = 0; i < 2 * N; ++i) {
        cin >> vl[i];
    }
    for (int i = 0; i < 2 * N; ++i) {
        cin >> vr[i];
    }

    int res = 0;
    char *str = new char[N * 2 + 1];
    DFS_bracket(str, N, 0, 0, res);
    cout << res << endl;

    return 0;
}