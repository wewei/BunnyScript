#include "AST/BlockStatement.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(BlockStatement)

AST_NODE_DEFINE_DUMMY_GenerateCode(BlockStatement)

void BlockStatement::Print(TreePrinter &printer) const
{
    printer.StartNode(String("BlockStatement"));
    if (m_statements)
        m_statements->Print(printer);
    printer.EndNode();
}


AST_NODE_DEFAULT_DESTRUCTOR(StatementList)

AST_NODE_DEFINE_DUMMY_GenerateCode(StatementList)

void StatementList::Print(TreePrinter &printer) const
{
    printer.StartNode(String("StatementList"));
    if (m_firstStatement)
        m_firstStatement->Print(printer);
    if (m_otherStatements)
        m_otherStatements->Print(printer);
    printer.EndNode();
}

