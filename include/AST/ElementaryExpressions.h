#pragma once

#include <string>

#include "ShortCut.h"
#include "Expression.h"
#include "Name.h"

namespace Bunny {
    namespace AST {
        class BooleanExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(BooleanExpression)

            BooleanExpression(bool boolValue) : m_boolValue(boolValue) { }
            bool BooleanValue() { return m_boolValue; }

        private:
            bool m_boolValue;
        };

        DEFINE_PTRS(BooleanExpression)

        class IntegerExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(IntegerExpression)

            IntegerExpression(int64_t intValue) : m_intValue(intValue) { }
            int64_t IntegerValue() { return m_intValue; }

        private:
            int64_t m_intValue;
        };

        DEFINE_PTRS(IntegerExpression)

        class FloatExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(FloatExpression)

            FloatExpression(double fltValue) : m_floatValue(fltValue) { }
            double FloatValue() { return m_floatValue; }

        private:
            double m_floatValue;
        };

        DEFINE_PTRS(FloatExpression)

        class StringExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(StringExpression)

            StringExpression(SPStringC strValue) : m_strValue(strValue) { }
            StringExpression(const char *cstrValue);
            const SPStringC &StringValue() { return m_strValue; }

        private:
            SPStringC m_strValue;
        };

        DEFINE_PTRS(StringExpression)

        class NamedExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(NamedExpression)

            NamedExpression(SPNameC name) : m_name(name) { }

            const SPNameC &Name() { return m_name; }
        private:
            SPNameC m_name;
        };

        DEFINE_PTRS(NamedExpression)

    }
}

