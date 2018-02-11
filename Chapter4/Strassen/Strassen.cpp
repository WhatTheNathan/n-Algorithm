#include <iostream>
#include <vector>

using namespace::std;

vector<vector<int>> matrix_minus(vector<vector<int>> A,vector<vector<int>> B) {
    if(A.size() != B.size() || A[0].size() != B[0].size()) {
        cout << "error occur in matrix_minus: Fails to minus a matrix with different row or column"<<endl;
    }
    vector<vector<int>> C(A.size(),vector<int>(A.size()));
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int>> matrix_plus(vector<vector<int>> A,vector<vector<int>> B) {
    if(A.size() != B.size() || A[0].size() != B[0].size()) {
        cout << "error occur in matrix_plus: Fails to plus a matrix with different row or column"<<endl;
    }
    vector<vector<int>> C(A.size(),vector<int>(A.size()));
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> matrix_multiply(vector<vector<int>> A,vector<vector<int>> B) {
    if(A[0].size() != B.size()) {
        cout << "error occur in matrix_multiply"<<endl;
    }
    vector<vector<int>> C(A.size(),vector<int>(B[0].size()));
    for(int i = 0; i < C.size(); i++)
        for(int j = 0; j < C[0].size(); j++) {
            C[i][j] = 0;
            for(int k = 0; k < A[0].size(); k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

vector<vector<int>> Strassen(vector<vector<int>> A,vector<vector<int>> B) {
    /* initial C */
    int n = A.size();
    vector<vector<int>> C(n,vector<int>(n));

    /* base case */
    if(n == 1)
        C[0][0] = A[0][0] * B[0][0];
    else {
        /* A partion */
        vector<vector<int>> A_11(n/2,vector<int>(n/2));
        vector<vector<int>> A_12(n/2,vector<int>(n/2));
        vector<vector<int>> A_21(n/2,vector<int>(n/2));
        vector<vector<int>> A_22(n/2,vector<int>(n/2));

        vector<vector<int>> B_11(n/2,vector<int>(n/2));
        vector<vector<int>> B_12(n/2,vector<int>(n/2));
        vector<vector<int>> B_21(n/2,vector<int>(n/2));
        vector<vector<int>> B_22(n/2,vector<int>(n/2));

        vector<vector<int>> C_11(n/2,vector<int>(n/2));
        vector<vector<int>> C_12(n/2,vector<int>(n/2));
        vector<vector<int>> C_21(n/2,vector<int>(n/2));
        vector<vector<int>> C_22(n/2,vector<int>(n/2));

        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n / 2; j++) {
                A_11[i][j] = A[i][j];
                A_12[i][j] = A[i][j + n / 2];
                A_21[i][j] = A[i + n / 2][j];
                A_22[i][j] = A[i + n / 2][j + n / 2];

                B_11[i][j] = B[i][j];
                B_12[i][j] = B[i][j + n / 2];
                B_21[i][j] = B[i + n / 2][j];
                B_22[i][j] = B[i + n / 2][j + n / 2];
            }
        }

        /* S */
        vector<vector<int>> S_1 = matrix_minus(B_12,B_22);
        vector<vector<int>> S_2 = matrix_plus(A_11,A_12);
        vector<vector<int>> S_3 = matrix_plus(A_21,A_22);
        vector<vector<int>> S_4 = matrix_minus(B_21,B_11);
        vector<vector<int>> S_5 = matrix_plus(A_11,A_22);
        vector<vector<int>> S_6 = matrix_plus(B_11,B_22);
        vector<vector<int>> S_7 = matrix_minus(A_12,A_22);
        vector<vector<int>> S_8 = matrix_plus(B_21,B_22);
        vector<vector<int>> S_9 = matrix_minus(A_11,A_21);
        vector<vector<int>> S_10 = matrix_plus(B_11,B_12);

        /* P */
        vector<vector<int>> P_1 = matrix_multiply(A_11,S_1);
        vector<vector<int>> P_2 = matrix_multiply(S_2,B_22);
        vector<vector<int>> P_3 = matrix_multiply(S_3,B_11);
        vector<vector<int>> P_4 = matrix_multiply(A_22,S_4);
        vector<vector<int>> P_5 = matrix_multiply(S_5,S_6);
        vector<vector<int>> P_6 = matrix_multiply(S_7,S_8);
        vector<vector<int>> P_7 = matrix_multiply(S_9,S_10);

        /* C */
        C_11 = matrix_plus(matrix_minus(matrix_plus(P_5,P_4),P_2),P_6);
        C_12 = matrix_plus(P_1,P_2);
        C_21 = matrix_plus(P_3,P_4);
        C_22 = matrix_minus(matrix_minus(matrix_plus(P_5,P_1),P_3),P_7);

        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n / 2; j++) {
                C[i][j] = C_11[i][j];
                C[i][j + n / 2] = C_12[i][j];
                C[i + n / 2][j] = C_21[i][j];
                C[i + n / 2][j + n / 2] = C_22[i][j];
            }
        }
    }
    return C;
}

int main() {
    vector<vector<int>> A = {{1,2,3,4},{2,1,3,4},{1,2,3,4},{1,2,3,4}};
    vector<vector<int>> B = {{1,2,3,4},{2,1,3,4},{1,2,3,4},{1,2,3,4}};
    vector<vector<int>> C;
    C = Strassen(A, B);

//    C= matrix_multiply(A,B);
    for(int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout<<endl;
    }
}