//
// Created by tricksterDRE on 05.11.16.
//

#include "matrix.h"
#include <cassert>
#include <cstring>

using namespace std;
using namespace courseworkmath;

matrix::matrix(const size_t n, const size_t m) : N(n), M(m), elements(nullptr)
{
    this->elements = new double[N * M];
    memset(this->elements, 0, N * M * sizeof(double));
}

matrix::matrix(const matrix& right): N(right.N), M(right.M)
{
    assert(right.elements != nullptr);

    this->elements = new double[N * M];
    memcpy(elements, right.elements, N * M * sizeof(double));
}

matrix::~matrix()
{
    assert(elements != nullptr);
    delete [] this->elements;
}

size_t matrix::rows_count() const
{
    return N;
}

size_t matrix::columns_count() const
{
    return M;
}

double matrix::get(const size_t row, const size_t column) const
{
    assert(elements != nullptr && row < N && column < M);
    return elements[row * N + column];
}

double matrix::get(const std::size_t index) const
{
    assert(elements != nullptr && index < N * M);
    return elements[index];
}

void matrix::set(const size_t row, const size_t column, const double value)
{
    assert(elements != nullptr && row < N && column < M);
    elements[row * N + column] = value;
}

void matrix::set(const size_t index, const double value)
{
    assert(elements != nullptr && index < N * M);
    elements[index] = value;
}

matrix matrix::transpose() const
{
    assert(elements != nullptr);
    matrix transposedMtr(M, N);

    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < M; j++)
            transposedMtr.set(j, i, elements[i * N + j]);

    return transposedMtr;
}

matrix courseworkmath::operator * (const matrix& left, const double value)
{
    matrix result(left.rows_count(), left.columns_count());

    for (size_t i = 0; i < result.columns_count() * result.rows_count(); i++)
        result.set(i, left.get(i) * value);

    return result;
}

matrix courseworkmath::operator * (const double value, const matrix& right)
{
    matrix result(right.rows_count(), right.columns_count());

    for (size_t i = 0; i < result.columns_count() * result.rows_count(); i++)
        result.set(i, right.get(i) * value);

    return result;
}

matrix courseworkmath::operator * (const matrix& left, const matrix& right)
{
    assert(left.columns_count() == right.rows_count());
    matrix result(left.rows_count(), right.columns_count());

    for (size_t i = 0; i < left.rows_count(); i++)
    {
        for (size_t j = 0; j < right.columns_count(); j++)
        {
            result.set(i, j, 0);

            for (size_t k = 0; k < right.rows_count(); k++)
            {
                double value = result.get(i, j) + left.get(i, k) * right.get(k, j);
                result.set(i, j, value);
            }
        }
    }

    return result;
}

matrix courseworkmath::operator - (const matrix& left, const matrix& right)
{
    assert(left.rows_count() == right.rows_count() && left.columns_count() == right.columns_count());
    matrix result(left.rows_count(), left.columns_count());

    for (size_t i = 0; i < result.rows_count() * result.columns_count(); i++)
        result.set(i, left.get(i) - right.get(i));

    return result;
}

matrix courseworkmath::operator + (const matrix& left, const matrix& right)
{
    assert(left.rows_count() == right.rows_count() && left.columns_count() == right.columns_count());
    matrix result(left.rows_count(), left.columns_count());

    for (size_t i = 0; i < result.rows_count() * result.columns_count(); i++)
        result.set(i, left.get(i) + right.get(i));

    return result;
}

bool courseworkmath::operator == (const matrix& left, const matrix& right)
{
    if (left.rows_count() != right.rows_count() || left.columns_count() != right.columns_count())
        return false;

    for (size_t i = 0; i < left.rows_count(); i++)
    {
        for (size_t j = 0; j < left.columns_count(); j++)
        {
            if (left.get(i, j) != right.get(i, j))
                return false;
        }
    }

    return true;
}