#include <iostream>

#include "AST/ASTPrinter.h"

using namespace Bunny::AST;

void ASTPrinter::PrintLine(RefStringC line)
{
    for (int i = 0; i < m_shiftWidth * m_indent; i++)
        *m_ostream << ' ';
    *m_ostream << line << std::endl;
}



