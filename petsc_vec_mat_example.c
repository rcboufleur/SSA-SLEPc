//Based on https://www.youtube.com/watch?v=kP7DAOrqECo
# include <petsc.h>
#include <slepcsvd.h>

int main(int argc, char **argv)
{
    // Create PETSc Vector Example
    // Vec b;
    // int j[4] = {0, 1, 2, 3};
    // double ab[4] = {7.0, 1.0, 2.0, 4.0};

    PetscInitialize(&argc, &argv, NULL, "Create vector AND matrix");

    // VecCreate(PETSC_COMM_WORLD, &b);
    // VecSetSizes(b, PETSC_DECIDE, 4);
    // VecSetFromOptions(b);
    // VecSetValues(b, 4, j, ab, INSERT_VALUES);
    // VecAssemblyBegin(b); VecAssemblyEnd(b);

    // VecView(b, PETSC_VIEWER_STDOUT_WORLD);

    // VecDestroy(&b);

    // Create PETSc Matrix example
    Mat A;
    int i;
    int jA[4] = {0, 1, 2, 3};
    double aA[4][4] = { {7.0, 1.0, 1.0, 4.0},
                        {5.0, 2.0, 9.0, 8.0},
                        {8.0, 4.0, 4.0, 3.0},
                        {9.0, 0.0, 6.0, 4.0} };

    MatCreate(PETSC_COMM_WORLD, &A);
    MatSetSizes(A, PETSC_DECIDE, PETSC_DECIDE, 4, 4);
    MatSetFromOptions(A);
    MatSetUp(A);
    for (i = 0; i<4; i++){
        MatSetValues(A, 1, &i, 4, jA, aA[i], INSERT_VALUES);
    }

    MatAssemblyBegin(A, MAT_FINAL_ASSEMBLY); MatAssemblyEnd(A, MAT_FINAL_ASSEMBLY);

    MatView(A, PETSC_VIEWER_STDOUT_WORLD);

    MatDestroy(&A);


}