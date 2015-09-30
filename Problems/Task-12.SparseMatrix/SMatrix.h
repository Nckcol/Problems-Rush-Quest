#pragma once
#include <iostream>
#include "List.h"
#include "List.cpp"

class SMatrix
{
    class Cell
    {
        int* _value;
        int _number;

    public:
        Cell();
        Cell(int value, int number);
        int *value() const;
        void setValue(int *value);
        int number() const;
        void setNumber(int number);
    };

    class Row
    {
        List<Cell> _cells;
        int _number;

    public:
        Row();
        Row(int number);
        List<Cell> &cells();
        void setCells(const List<Cell> &cells);
        int number() const;
        void setNumber(int number);
    };

    List<Row> _rows;
public:
    SMatrix();
    void set(int row, int column, int value);
    int get(int row, int column);
    List<Row> &rows();
    void setRows(const List<Row> &rows);
    void removeRow(int number);
    void removeColumn(int number);
    int sizeR();
    int sizeC();

    friend std::ostream& operator<<(std::ostream& os, SMatrix & matrix);
};
