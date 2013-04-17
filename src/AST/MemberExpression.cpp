#include "AST/MemberExpression.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(MemberExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(MemberExpression)

#ifdef DEBUG
void MemberExpression::Print(RefTreePrinter printer) const
{
    printer.StartNode(String("MemberExpression:"));
    if (m_exprMaster)
        m_exprMaster->Print(printer);
    m_memberName->Print(printer);
    printer.EndNode();
}
#endif // DEBUG

