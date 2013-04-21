#include "AST/TypeList.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(TypeList)

AST_NODE_DEFINE_DUMMY_GenerateCode(TypeList)

#ifdef DEBUG

void TypeList::Print(TreePrinter &printer) const
{
    printer.StartNode(String("TypeList:"));
    if (m_firstType)
        m_firstType->Print(printer);
    if (m_otherTypes)
        m_otherTypes->Print(printer);
    printer.EndNode();
}

#endif // DEBUG


