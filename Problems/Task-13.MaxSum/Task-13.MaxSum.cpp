// Task-13.MaxSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int ** newMatrix(int width, int height);
void read(int **matrix, int width, int height);
void write(int **matrix, int width, int height);
void fill(int **matrix, int width, int height);

int main()
{
    int height, width;
    int maxSum = 0;

    struct Point
    {
        int x;
        int y;
        Point() : x(0), y(0) {}
        Point(int x, int y) : x(x), y(y) {}

    };

    struct Rectangle
    {
        Point first;
        Point second;
        Rectangle() : first(Point(0, 0)), second(Point(0, 0)) {}
        Rectangle(Point first, Point second) : first(first), second(second) {}
        Rectangle(int x1, int y1, int x2, int y2) : first(Point(x1, y1)), second(Point(x2, y2)) {}
    } maxRect;


    //cin >> width >> height;
    width = 10;
    height = 10;

    int **matrix = newMatrix(width,height);

    //read(matrix, width, height);
    fill(matrix, width, height);
    write(matrix, width, height);

    for (int x1 = 0; x1 < width; x1++)
    {
        for (int y1 = 0; y1 < height; y1++)
        {
            for (int x2 = x1 + 1; x2 < width; x2++)
            {
                for (int y2 = y1 + 1; y2 < height; y2++)
                {
                    if (matrix[y1][x1] + matrix[y1][x2] + matrix[y2][x1] + matrix[y2][x2] > maxSum)
                    {
                        maxSum = matrix[y1][x1] + matrix[y1][x2] + matrix[y2][x1] + matrix[y2][x2];
                        maxRect = Rectangle(x1, y1, x2, y2);
                    }
                }
            }
        }
    }

    cout << "Sum: " << maxSum << endl;
    cout << "Coordinates: " << endl;
    cout << maxRect.first.x << " " << maxRect.first.y << endl 
         << maxRect.second.x << " " << maxRect.second.y << endl;
    cout << "Corners: " << endl;
    cout << matrix[maxRect.first.y][maxRect.first.x] << " " << matrix[maxRect.first.y][maxRect.second.x] << endl 
         << matrix[maxRect.second.y][maxRect.first.x] << " " << matrix[maxRect.second.y][maxRect.second.x] << endl;


    return 0;
}

int ** newMatrix(int width, int height)
{
    int **matrix = new int *[height];
    for (int i = 0; i < height; i++)
    {
        matrix[i] = new int[width];
    }
    return matrix;
}

void read(int **matrix, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void write(int **matrix, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void fill(int **matrix, int width, int height)
{
    srand(time(NULL));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            matrix[i][j] = rand()%100;
        }
    }
}

