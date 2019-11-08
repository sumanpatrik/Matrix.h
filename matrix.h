//
// Matrix class Created by Suman and Arijit on 07-11-2019.
//
#include <iostream>
using namespace std;

class matrix{
    int row;
    int col;
    int * mat;

public:
    matrix(int row, int col){
        this -> row = row;
        this -> col = col;
        mat = new int[row * col];
    }

    // member function section ...
    void setmatrix();
    void getmatrix();
    int count(int key);
    void setall(int );
    matrix tranpose();
    // bool friend compare(matrix, matrix);       // usage - compare(mat1, mat2) => return 1(true) if same else 0(false)
    bool  compare(matrix );                      // usage - mat1.compare(mat2) => return 1(true) if same, else 0(false)
    int sum(char type );    // all, major diagonal, upper and lower ...
    int onindex(int index);
    void set(int index, int element);


    // operator overloading section  ...
    friend istream & operator>>(istream &, matrix);
    friend ostream & operator<<(ostream&, matrix);

    matrix operator+(matrix );
    matrix operator-(matrix );
    matrix operator*(matrix );
};

void matrix ::setmatrix() {
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            int location = i * col + j;
            cin>>mat[location];
        }
    }
}

void matrix ::getmatrix() {
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            int location = i * col + j;
            cout<<mat[location]<<" ";
        }
        cout<<"\n";
    }
}

int matrix ::count(int key) {
    int result = 0;
    for(int i=0 ; i<row * col; i++){
        if(mat[i] == key)
            result ++;
    }
    return result;
}

void matrix ::setall(int value) {
    for(int i=0 ; i<row * col ; i++){
        mat[i] = value;
    }
}

matrix matrix :: tranpose() {
    matrix result(col ,row);
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            int loc_source = i * col + j;
            int loc_dest  = j * row + i;
            result.mat[loc_dest] = mat[loc_source];
        }
    }
    return result;
}
/*bool compare(matrix mat1, matrix mat2){
    matrix result = mat1 - mat2;
    if(result.count(0) == (mat1.row * mat1.col))
        return true;
    else
        return false;
}  */

bool matrix :: compare(matrix mat2){
    matrix result = *this - mat2;
    if(result.count(0) == (row * col))
        return true;
    else
        return false;
}

int matrix :: sum(char type = 'a'){     // a => all, d=> diagonal, u=> upper triangle, l=> lower triangle ...
    int result = 0;
    switch(type){
        case 'a':
            for(int i=0 ; i<row*col ; i++){
                result += mat[i];
            }
            return result;

        case 'd':
            for(int i=0 ; i<row ; i++){
                for(int j=0 ; j<col ; j++){
                    if(i == j){
                        int location = i * col + j;
                        result += mat[location];
                    }
                }
            }
            return result;

        case 'u':
            for(int i=0 ; i<row ; i++){
                for(int j=0 ; j<col ; j++ ){
                    if(i>j){
                        int location = i * col + j;
                        result += mat[location];
                    }
                }
            }
            return result;

        case 'l':
            for(int i=0 ; i<row ; i++){
                for(int j=0 ; j<col ; j++ ){
                    if(i<j){
                        int location = i * col + j;
                        result += mat[location];
                    }
                }
            }
            return result;

    }

}

int matrix ::onindex(int index) {
    return mat[index];
}

void matrix :: set(int index, int element){
    mat[index] = element;
}

istream & operator>>(istream & in, matrix obj) {
    for(int i=0 ; i<obj.row ; i++){
        for(int j=0 ; j<obj.col ; j++){
            int location = i * obj.col + j;
            in>>obj.mat[location];
        }
    }
    return in;
}

ostream & operator<<(ostream & out, matrix obj) {
    for(int i=0 ; i<obj.row ; i++){
        for(int j=0 ; j<obj.col ; j++){
            int location = i * obj.col + j;
            out<<obj.mat[location]<<" ";
        }
        out<<"\n";
    }
    return out;
}

matrix  matrix ::operator+(matrix mat2) {
    matrix result(row, col); // row = obj.row and col = obj.col;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            int location = i * col + j;
            result.mat[location] = mat[location] + mat2.mat[location];
        }
    }
    return result;
}

matrix  matrix ::operator-(matrix mat2) {
    matrix result(row, col); // row = obj.row and col = obj.col;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            int location = i * col + j;
            result.mat[location] = mat[location] - mat2.mat[location];
        }
    }
    return result;
}

matrix matrix ::operator*(matrix mat2) {
    matrix result(col, mat2.row);

    for(int i=0 ; i<result.row ; i++){
        for(int j=0 ; j<result.col ; j++){
            int loc_result = i * result.col + j;
            result.mat[loc_result] = 0;
            for(int k=0 ; k<row ; k++){
                int loc_first = i * col + k;
                int loc_second = k * mat2.col + j;
                result.mat[loc_result] += mat[loc_first] * mat2.mat[loc_second];
            }
        }
    }
    return result;
}