#include "AST/FunctionType.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(FunctionType)

AST_NODE_DEFINE_DUMMY_GenerateCode(FunctionType)

#ifdef DEBUG

void FunctionType::Print(TreePrinter &printer) const
{
    printer.StartNode(String("FunctionType:"));
    if (m_returnType)
        m_returnType->Print(printer);
    if (m_paramTypeList)
        m_paramTypeList->Print(printer);
    printer.EndNode();
}

#endif // DEBUG

