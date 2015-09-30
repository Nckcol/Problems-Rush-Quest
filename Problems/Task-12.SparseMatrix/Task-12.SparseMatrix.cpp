// Task-12.SparseMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{
    SMatrix matrix;


    srand(time(0));
    
    for(int i = 0; i < 20; i++)
    {
        int r = rand()%10,
        c = rand()%10,
        v = rand()%10;
        matrix.set(r, c, v);
    }

    int maxC = -1,
        maxR = -1,
        max = 0;

    for (int i = 0; i < matrix.sizeR(); i++)
        for (int j = 0; j < matrix.sizeC(); j++)
            if (matrix.get(i, j) > max)
            {
                maxR = i;
                maxC = j;
                max = matrix.get(i, j);
            }

    cout << matrix << endl;

    cout << max << " " << maxR << " " << maxC << endl << endl;

    matrix.removeRow(maxR);
    matrix.removeColumn(maxC);
    cout << matrix << endl;

    return 0;
}

