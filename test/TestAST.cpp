#include <iostream>
#include <string>

#include "AST/AST.h"

using namespace Bunny::AST;

int main()
{
    SPIntegerExpression intExpA(new IntegerExpression(1));
    SPIntegerExpression intExpB(new IntegerExpression(2));
    SPBinaryExpression addExp(new BinaryExpression(intExpA, intExpB, BO_ADD));
    return 0;
}


