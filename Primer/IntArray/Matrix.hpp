
class Matrix {
    public:
        Matrix(int rows, int columns);
        Matrix(Matrix& copy);

        Matrix& transpose();
        
        Matrix& operator*(Matrix& lhs, Matrix& rhs);
        Matrix& operator+(Matrix& lhs, Matrix& rhs);

        ~Matrix() {
            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

    private:
        int** matrix;
        int   rows;
        int   columns;
}
