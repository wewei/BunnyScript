#include <iostream>

#include "AST/TreePrinter.h"

using namespace Bunny::AST;

void SimpleTreePrinter::StartNode(RefStringC nodeInfo)
{
    for (int i = 0; i < m_shiftWidth * m_indent; i++)
        *m_ostream << ' ';
    *m_ostream << nodeInfo << std::endl;
    m_indent ++;
}

void SimpleTreePrinter::EndNode()
{
    m_indent --;
}


