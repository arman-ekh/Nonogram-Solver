#include <iostream>
#include <stack>
using namespace std;


void generate_row(stack<int*> row_stack,int* row , int* row_hint,int start,int hint_index, int m ,int height);

int main() {
    // int n , m;
    // cin >> n >> m;
    // const int hint_count = n+m;
    // int** hints = new int*[hint_count];
    //
    // for (int i = 0; i < hint_count; i++) {
    //     int size =0;
    //     cin >> size;
    //     hints[i] = new int[size+1];
    //     hints[i][0] = size;
    //     for (int j = 1; j <= size; j++) {
    //         cin >> hints[i][j];
    //     }
    // }
    //
    // int ** matrix = new int*[n];
    // for (int i = 0; i < n; i++) {
    //     matrix[i] = new int[m];
    // }

    int m = 8;
    int* row = new int[m];
    for (int i = 0 ; i < m ; i++) {
        row[i] = 0;
    }
    int row_hint[4] = {3 , 2 , 1,1 };
    stack<int*> row_stack ;
    generate_row(row_stack , row , row_hint , 0 , 1 , m ,0);

    // for (int i = 0; i < n; i++) {
    //     delete[] matrix[i];
    // }
    // delete[] matrix;
    // for (int i = 0; i < hint_count; i++) {
    //     delete[] hints[i];
    // }
    // delete[] hints;
    return 0;
}

void generate_row_number(int start , int hint ,int* row,int m) {
    if (start + hint > m) return;
    for (int i = start; i < start + hint; i++) {
        row[i] = 1;
    }
}

void generate_row(stack<int*> row_stack,int* row , int* row_hint,int start,int hint_index, int m ,int height) {
    if (height >= row_hint[0]) {
        row_stack.push(row);
        // for (int i = 0 ; i < m ; i++) {
        //     cout << row[i] << " " ;
        // }
        // cout << endl;
        return;
    }
    for (int i = start ; i < m; i++) {
        int* new_row = new int[m];
        for (int j = 0 ; j < m ; j++) {
            new_row[j] = row[j];
        }

        generate_row_number(i , row_hint[hint_index] , new_row ,m);
        generate_row(row_stack , new_row , row_hint , i + row_hint[hint_index]+1 , hint_index+1 , m ,height+1);
    }
}
