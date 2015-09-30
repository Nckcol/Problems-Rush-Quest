#include "stdafx.h"
#include "SMatrix.h"



SMatrix::Cell::Cell() :
    _number(0), _value(nullptr)
{

}

SMatrix::Cell::Cell(int value, int number) :
    _number(number), _value(new int(value))
{

}

int *SMatrix::Cell::value() const
{
    return _value;
}

void SMatrix::Cell::setValue(int *value)
{
    _value = value;
}

int SMatrix::Cell::number() const
{
    return _number;
}

void SMatrix::Cell::setNumber(int number)
{
    _number = number;
}

SMatrix::Row::Row() :
    _number(0)
{

}

SMatrix::Row::Row(int number) :
    _number(number)
{

}

List<SMatrix::Cell> &SMatrix::Row::cells()
{
    return _cells;
}

void SMatrix::Row::setCells(const List<Cell> &cells)
{
    _cells = cells;
}

int SMatrix::Row::number() const
{
    return _number;
}

void SMatrix::Row::setNumber(int number)
{
    _number = number;
}


List<SMatrix::Row> &SMatrix::rows()
{
    return _rows;
}

void SMatrix::setRows(const List<Row> &rows)
{
    _rows = rows;
}

void SMatrix::removeRow(int number)
{
    auto currentRow = rows().head();

    if (!currentRow) return;

    if (currentRow->next())
    {
        while (currentRow->data()->number() < number && currentRow->next())
        {
            currentRow = currentRow->next();
        }
    }

    auto tmp = currentRow->next();

    if (currentRow->data()->number() == number)
    {
        rows().remove(currentRow);
    }
    else
    {
        currentRow->data()->setNumber(currentRow->data()->number() + 1);
    }

    if (!tmp) return;
    while (tmp)
    {
        tmp->data()->setNumber(tmp->data()->number() - 1);
        tmp = tmp->next();
    }

}

void SMatrix::removeColumn(int number)
{
    auto currentRow = rows().head();

    while (currentRow)
    {
        List<Cell>& cells = currentRow->data()->cells();
        auto currentColumn = cells.head();

        currentRow = currentRow->next();

        if (!currentColumn) continue;

        while (currentColumn->data()->number() < number)
        {
            currentColumn = currentColumn->next();
            if (!currentColumn) break;
        }

        auto tmp = currentColumn;

        if (currentColumn)
        {
            if (currentColumn->data()->number() == number)
            {
                tmp = currentColumn->next();
                cells.remove(currentColumn);
            }
        }
        
        while (tmp)
        {
            tmp->data()->setNumber(tmp->data()->number() - 1);
            tmp = tmp->next();
        }
    }
}

int SMatrix::sizeR()
{
    if (!rows().head()) return 0;
    auto current = rows().head();
    int number = 0;
    while (current && current->data()->cells().head())
    {
        number = current->data()->number() + 1;
        current = current->next();
    }
    return  number;
}

int SMatrix::sizeC()
{
    int sizeC = 0;
    auto currentRow = rows().head();

    if (!currentRow) return sizeC;

    while (currentRow)
    {
        if (currentRow->data()->cells().head())
        {
            if (currentRow->data()->cells().tail()->data()->number() + 1 > sizeC)
            {
                sizeC = currentRow->data()->cells().tail()->data()->number() + 1;
            }
        }
        currentRow = currentRow->next();
    }

    return sizeC;
}

std::ostream &operator<<(std::ostream &os, SMatrix &matrix)
{
    for (int i = 0; i < matrix.sizeR(); i++)
    {
        for (int j = 0; j < matrix.sizeC(); j++)
        {
            /*
            if(matrix.get(i, j) < 10)
            {
            os << "0";
            }
            */
            os << matrix.get(i, j) << " ";
        }
        os << std::endl;
    }

    return os;
}

SMatrix::SMatrix()
{

}

void SMatrix::set(int row, int column, int value)
{
    if (!value) return;

    auto currentRow = rows().head();

    if (!currentRow)
    {
        rows().pushFront(new Row(row));
        currentRow = rows().head();
    }
    else
    {
        if (currentRow->data()->number() > row)
        {
            rows().pushFront(new Row(row));
            currentRow = rows().head();
        }
        else
        {
            if (currentRow->next())
            {
                while (currentRow->next()->data()->number() <= row)
                {
                    currentRow = currentRow->next();
                    if (!currentRow->next()) break;
                }
            }

            if (currentRow->data()->number() != row)
            {
                rows().pushAfter(currentRow, new Row(row));
                currentRow = currentRow->next();
            }
        }
    }

    auto currentColumn = currentRow->data()->cells().head();

    if (!currentColumn)
    {
        currentRow->data()->cells().pushFront(new Cell(value, column));
        return;
    }

    if (currentColumn->data()->number() > column)
    {
        currentRow->data()->cells().pushFront(new Cell(value, column));
        return;
    }

    if (currentColumn->next())
    {
        while (currentColumn->next()->data()->number() <= column)
        {
            currentColumn = currentColumn->next();
            if (!currentColumn->next()) break;
        }
    }

    if (currentColumn->data()->number() == column)
    {
        currentColumn->data()->setValue(new int(value));
    }
    else
    {
        currentRow->data()->cells().pushAfter(currentColumn, new Cell(value, column));
    }
}

int SMatrix::get(int row, int column)
{
    auto currentRow = rows().head();

    if (!currentRow) return 0;

    while (currentRow->data()->number() != row)
    {
        currentRow = currentRow->next();
        if (!currentRow) return 0;
    }

    auto currentColumn = currentRow->data()->cells().head();
    if (!currentColumn) return 0;
    while (currentColumn->data()->number() != column)
    {
        currentColumn = currentColumn->next();
        if (!currentColumn) return 0;
    }

    return *currentColumn->data()->value();
}
