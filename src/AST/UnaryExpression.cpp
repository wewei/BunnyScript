#include <sstream>
#include "AST/UnaryExpression.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(UnaryExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(UnaryExpression)

#ifdef DEBUG

static const char *UnaryOperatorName(UnaryOperator oper)
{
    switch (oper) {
    case UO_NEG:
        return "- <NEG>";
    case UO_NOT:
        return "! <NOT>";
    default:
        return "";
    }
}

void UnaryExpression::Print(TreePrinter &printer) const
{
    std::ostringstream sstm;
    sstm << "UnaryExpression(" << UnaryOperatorName(m_oper) << "):";
    printer.StartNode(sstm.str());
    {
        m_exprChild->Print(printer);
    }
    printer.EndNode();
}
#endif // DEBUG


