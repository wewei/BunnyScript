#include "AST/FunctionExpression.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(ParameterList)

AST_NODE_DEFINE_DUMMY_GenerateCode(ParameterList)

#ifdef DEBUG

void ParameterList::Print(TreePrinter &printer) const
{
    printer.StartNode(String("ParameterList:"));
    if (m_firstParamType)
        m_firstParamType->Print(printer);
    if (m_firstParamName)
        m_firstParamName->Print(printer);
    if (m_otherParameters)
        m_otherParameters->Print(printer);
    printer.EndNode();
}

#endif // DEBUG


AST_NODE_DEFAULT_DESTRUCTOR(FunctionExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(FunctionExpression)

#ifdef DEBUG

void FunctionExpression::Print(TreePrinter &printer) const
{
    printer.StartNode(String("FunctionExpression:"));
    if (m_returnType)
        m_returnType->Print(printer);
    if (m_paramList)
        m_paramList->Print(printer);
    if (m_statement)
        m_statement->Print(printer);
    printer.EndNode();
}

#endif // DEBUG

