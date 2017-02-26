//
// Created by tricksterDRE on 05.11.16.
//

#pragma once
#include <memory>
#include <cstddef>
#include <ostream>
#include <istream>

namespace courseworkmath
{
    /**
    *  @brief  Simple matrix class
    */
    class matrix
    {
    public:
        /**
        *  @brief  Constructor with params
        *  @param n Rows count
        *  @param m Columns count
        */
        matrix(const std::size_t n, const std::size_t m);

        /**
        *  @brief  Copy constructor
        *  @param right Object to copy from
        */
        matrix(const matrix& right);

        /**
        *  @brief  Destructor
        */
        virtual ~matrix();

        /**
        *  @brief  Gets matrix value at specified position
        *  @param  row Row index
        *  @param column Column index
        */
        double get(const std::size_t row, const std::size_t column) const;

        /**
        *  @brief  Gets matrix value at index (in flat array style)
        *  @param  index Index
        */
        double get(const std::size_t index) const;

        /**
        *  @brief  Sets matrix value at specified position
        *  @param  row Row index
        *  @param  column Column index
        *  @param  value Value to write
        */
        void set(const std::size_t row, const std::size_t column, const double value);

        /**
        *  @brief  Sets matrix value at index
        *  @param  index Index
        *  @param  value Value to write
        */
        void set(const std::size_t index, const double value);

        /**
        *  @brief  Returns matrix's row count
        */
        size_t rows_count() const;

        /**
        *  @brief  Returns matrix's column count
        */
        size_t columns_count() const;

        /**
        *  @brief  Returns transposed matrix
        */
        matrix transpose() const;

        /**
         * Input operator
         * @param is input stream
         * @param t Matrix to input
         * @return input stream
         */
        friend std::istream& operator >> (std::istream& is, matrix& t)
        {
            for (size_t i = 0; i < t.rows_count(); i++)
            {
                for (size_t j = 0; j < t.columns_count(); j++)
                {
                    double value = 0.0;
                    is >> value;
                    t.set(i, j, value);
                }
            }
            return is;
        }

        /**
         * Output operator
         * @param os output stream
         * @param t matrix to output
         * @return output stream
         */
        friend std::ostream &operator<<(std::ostream &os, const matrix &t)
        {
            for (size_t i = 0; i < t.rows_count(); i++)
            {
                for (size_t j = 0; j < t.columns_count(); j++)
                    os << t.get(i, j) << "\t";

                os << std::endl;
            }

            return os;
        }
    private:
        double *elements;
        std::size_t N, M;
    };

    bool operator == (const matrix& left, const matrix& right);

    matrix operator * (const double value, const matrix& right);
    matrix operator * (const matrix& left, const double value);

    matrix operator * (const matrix& left, const matrix& right);

    matrix operator - (const matrix& left, const matrix& right);
    matrix operator + (const matrix& left, const matrix& right);
}

