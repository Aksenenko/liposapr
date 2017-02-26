#include <iostream>
#include "matrix.h"

using namespace courseworkmath;
using namespace std;

int main()
{
    matrix m1(2, 2);
    matrix m2(2, 2);

    cout<<"Enter m1 matrix: "<<endl;
    cin>>m1;

    cout<<"Enter m2 matrix: "<<endl;
    cin>>m2;

    cout<<"matrix m1 = "<<endl<<m1<<endl;
    cout<<"matrix m2 = "<<endl<<m2<<endl;

    cout<<"Mul result = "<<endl<<m1 * m2<<endl;
    cout<<"Sum result = "<<endl<<m1 + m2<<endl;
    cout<<"Sub result = "<<endl<<m1 - m2<<endl;

    cout<<"Transpose result m1 = "<<endl<<m1.transpose()<<endl;
    cout<<"Transpose result m2 = "<<endl<<m2.transpose()<<endl;

    return 0;
}