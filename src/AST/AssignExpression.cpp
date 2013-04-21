#include <sstream>
#include "AST/AssignExpression.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(LValue)

AST_NODE_DEFINE_DUMMY_GenerateCode(LValue)

#ifdef DEBUG

void LValue::Print(TreePrinter &printer) const
{
    printer.StartNode(String("LValue:"));
    {
        m_exprChild->Print(printer);
    }
    printer.EndNode();
}
#endif // DEBUG



AST_NODE_DEFAULT_DESTRUCTOR(AssignExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(AssignExpression)

#ifdef DEBUG

void AssignExpression::Print(TreePrinter &printer) const
{
    printer.StartNode(String("AssignExpression:"));
    {
        m_lvalue->Print(printer);
        m_exprValue->Print(printer);
    }
    printer.EndNode();
}
#endif // DEBUG


