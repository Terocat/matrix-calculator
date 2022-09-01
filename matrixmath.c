#include <stdio.h>

void switchRows(int m, int n, float matrix[m][n], int rowA, int rowB)
{
    for(int i = 0; i < n; i++)
    {
        int copyVal = matrix[rowA][i];
        matrix[rowA][i] = matrix[rowB][i];
        matrix[rowB][i] = copyVal;
    }
}

void logMatrix(int m, int n, float matrix[m][n])
{
    printf("\n");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%.1f ", matrix[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void addRows(int m, int n, float matrix[m][n], int rowA, int rowB, float factor)
{
    for(int i = 0; i < n; i++)
    {
        matrix[rowB][i] = matrix[rowB][i] + factor * matrix[rowA][i];
    }
}

void multiplyRow(int m, int n, float matrix[m][n], int row, float factor)
{
    for(int i = 0; i < n; i++)
    {
        matrix[row][i] *= factor;
    }
}

void reduce(int m, int n, float matrix[m][n])
{
    int prevStepRow = -1; // "-1" because we assume there are no steps yet
    int pivotRow;
    float pivotVal; 

    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < m; i++)
        {
            // choose pivot row
            if(matrix[i][j] == 0 || i <= prevStepRow) continue;

            pivotRow = i;
            pivotVal = matrix[i][j];

            if(i > prevStepRow + 1) // make new step be exactly 1 row higher than previous
            {
                switchRows(m, n, matrix, i, prevStepRow + 1);
                pivotRow = prevStepRow + 1;
            }

            // clear column
            for(int targetRow = 0; targetRow < m; targetRow++)
            {
                if(targetRow == pivotRow) continue;

                float factor = -matrix[targetRow][j] / pivotVal;
                addRows(m, n, matrix, pivotRow, targetRow, factor);
            }

            // new step is done

            multiplyRow(m, n, matrix, pivotRow, 1.0 / pivotVal);
            prevStepRow++;
            break; // break out of row loop, since column is already clear
        }
    }
}










