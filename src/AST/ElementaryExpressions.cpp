#include <sstream>
#include "AST/ElementaryExpressions.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(BooleanExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(BooleanExpression)

#ifdef DEBUG
void BooleanExpression::Print(RefTreePrinter printer) const
{
    std::ostringstream sstm;
    sstm << "BooleanExpression(" << m_boolValue << ")";
    printer.AddLeafNode(sstm.str());
}
#endif // DEBUG


AST_NODE_DEFAULT_DESTRUCTOR(IntegerExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(IntegerExpression)

#ifdef DEBUG
void IntegerExpression::Print(RefTreePrinter printer) const
{
    std::ostringstream sstm;
    sstm << "IntegerExpression(" << m_intValue << ")";
    printer.AddLeafNode(sstm.str());
}
#endif // DEBUG


AST_NODE_DEFAULT_DESTRUCTOR(FloatExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(FloatExpression)

#ifdef DEBUG
void FloatExpression::Print(RefTreePrinter printer) const
{
    std::ostringstream sstm;
    sstm << "FloatExpression(" << m_floatValue << ")";
    printer.AddLeafNode(sstm.str());
}
#endif // DEBUG


AST_NODE_DEFAULT_DESTRUCTOR(StringExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(StringExpression)

#ifdef DEBUG
void StringExpression::Print(RefTreePrinter printer) const
{
    std::ostringstream sstm;
    sstm << "StringExpression(\"" << *m_strValue << "\")";
    printer.AddLeafNode(sstm.str());
}
#endif // DEBUG

