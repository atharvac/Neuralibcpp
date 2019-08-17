#include <cstdlib>
#include <iostream>
#include <ctime>


float get_rand(void) {
    float r = (rand()%1000);
    return r/1000;
}


class Matrix {
private:
    int r, c;
public:
    float **mat;
    Matrix(int row, int col) {

        r = row;
        c = col;
        mat = new float*[row];
        for(int i=0;i<row;i++){
            mat[i] = new float[col];
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[i][j] = get_rand();
            }
        }
    }

    Matrix* clone(void) {
        Matrix *nmat = new Matrix(r, c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                nmat->mat[i][j] = mat[i][j];
            }
        }
        return nmat;
    }

    //Multiply fixed number with all eements
    void operator*(float n) {
        Matrix* nmat = this;
        for(int i=0;i<nmat->r;i++){
            for(int j=0;j<nmat->c;j++){
                nmat->mat[i][j] = nmat->mat[i][j] * n;
            }
        }
    }

    //Direct product
    void operator*(Matrix* nmat2) {
        Matrix* nmat = this;
        for(int i=0;i<nmat->r;i++){
            for(int j=0;j<nmat->c;j++){
                nmat->mat[i][j] = nmat->mat[i][j] * nmat2->mat[i][j];
            }
        }
    }

    //Dot product
    static Matrix* dot(Matrix* nmat, Matrix* nmat2){
        float sum = 0;
        if (nmat->c == nmat2->r) {
            Matrix* res = new Matrix(nmat->r, nmat2->c);
            for(int i=0;i<res->r;i++){
                for(int j=0;j<res->c;j++){
                    sum = 0;
                    for(int k=0;k<nmat->c;k++){
                        sum += nmat->mat[i][k] * nmat2->mat[k][j];
                    }
                    res->mat[i][j] = sum;
                }
            }
            delete(nmat);
            return res;
        }

        else{
            return nmat;
        }
    }

    //Add fixed number to all elements
    void operator+(float n) {
        Matrix* nmat = this;
        for(int i=0;i<nmat->r;i++){
            for(int j=0;j<nmat->c;j++){
                nmat->mat[i][j] = nmat->mat[i][j] + n;
            }
        }
    }
    //Direct addition
    void operator+(Matrix* nmat2) {
        Matrix* nmat = this;
        for(int i=0;i<nmat->r;i++){
            for(int j=0;j<nmat->c;j++){
                nmat->mat[i][j] = nmat->mat[i][j] + nmat2->mat[i][j];
            }
        }
    }


    void set(float n) {
        Matrix* nmat = this;
        for(int i=0;i<nmat->r;i++){
            for(int j=0;j<nmat->c;j++){
                nmat->mat[i][j] = n;
            }
        }
    }

    void show(void) {
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                std::cout << mat[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }


};

int main(void) {
    srand(time(0));
    Matrix* m = new Matrix(2, 3);
    Matrix* n = new Matrix(3, 2);
    m->show();
    std::cout << std::endl << '\n';
    n->show();
    m = Matrix::dot(m, n);
    std::cout << std::endl << '\n';
    m->show();
    return 0;
}
