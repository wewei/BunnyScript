#include <sstream>
#include "AST/BinaryExpression.h"

using namespace Bunny::AST;

AST_NODE_DEFAULT_DESTRUCTOR(BinaryExpression)

AST_NODE_DEFINE_DUMMY_GenerateCode(BinaryExpression)

#ifdef DEBUG

static const char *BinaryOperatorName(BinaryOperator oper)
{
    switch (oper) {
    case BO_ADD:
        return "+ <ADD>";
    case BO_MINUS:
        return "- <MINUS>";
    case BO_MULTIPLY:
        return "* <MULTIPLY>";
    case BO_DIVIDE:
        return "/ <DIVIDE>";
    case BO_POWER:
        return "^ <POWER>";
    case BO_LT:
        return "< <LT>";
    case BO_GT:
        return "> <GT>";
    case BO_LE:
        return "<= <LE>";
    case BO_GE:
        return ">= <GE>";
    case BO_EQ:
        return "== <EQ>";
    case BO_NE:
        return "!= <NE>";
    case BO_AND:
        return "and <AND>";
    case BO_OR:
        return "or <OR>";
    case BO_XOR:
        return "xor <XOR>";
    case BO_SUBS:
        return "[] <SUBS>";
    default:
        return "";
    }
}

void BinaryExpression::Print(RefTreePrinter printer) const
{
    std::ostringstream sstm;
    sstm << "BinaryExpression(" << BinaryOperatorName(m_oper) << "):";
    printer.StartNode(sstm.str());
    {
        m_exprLeft->Print(printer);
        m_exprRight->Print(printer);
    }
    printer.EndNode();
}
#endif // DEBUG

