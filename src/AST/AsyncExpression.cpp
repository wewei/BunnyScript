#include "AST/AsyncExpression.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(AsyncExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(AsyncExpression)

#ifdef DEBUG

void AsyncExpression::Print(TreePrinter &printer) const
{
    printer.StartNode(String("AsyncExpression:"));
    {
        m_exprChild->Print(printer);
    }
    printer.EndNode();
}

#endif // DEBUG

