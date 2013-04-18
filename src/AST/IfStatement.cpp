#include "AST/IfStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(IfStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(IfStatement)

void IfStatement::Print(TreePrinter &printer) const
{
    printer.StartNode(String("IfStatement"));
    m_exprCondition->Print(printer);
    m_thenClause->Print(printer);
    if (m_elseClause)
        m_elseClause->Print(printer);
    printer.EndNode();
}

