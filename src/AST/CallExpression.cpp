#include <sstream>
#include "AST/CallExpression.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(ArgumentList)

AST_NODE_DEFINE_DUMMY_GenerateCode(ArgumentList)

#ifdef DEBUG

void ArgumentList::Print(TreePrinter &printer) const
{
    printer.StartNode(String("ArgumentList:"));
    if (m_firstArgument)
        m_firstArgument->Print(printer);
    if (m_otherArguments)
        m_otherArguments->Print(printer);
    printer.EndNode();
}

#endif // DEBUG


AST_NODE_DEFAULT_DESTRUCTOR(CallExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(CallExpression)

#ifdef DEBUG

void CallExpression::Print(TreePrinter &printer) const
{
    printer.StartNode(String("CallExpression:"));
    {
        m_procedure->Print(printer);
        m_argumentList->Print(printer);
    }
    printer.EndNode();
}

#endif // DEBUG

