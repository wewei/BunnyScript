#pragma once

#include <stack>
#include <vector>
#include <iostream>

#include "ShortCut.h"

namespace Bunny {
    namespace AST {
        class ASTPrinter
        {
        public:
            ASTPrinter(const SPOStream &ostream, int shiftWidth)
                : m_ostream(ostream)
                , m_shiftWidth(shiftWidth)
                , m_indent(0)
            { }
            ASTPrinter(const SPOStream &ostream)
                : m_ostream(ostream)
                , m_shiftWidth(2)
                , m_indent(0)
            { }
            ASTPrinter(int shiftWidth)
                : m_ostream(new OStream(std::cout.rdbuf()))
                , m_shiftWidth(shiftWidth)
                , m_indent(0)
            { }
            ASTPrinter()
                : m_ostream(new OStream(std::cout.rdbuf()))
                , m_shiftWidth(2)
                , m_indent(0)
            { }

            virtual void PrintLine(RefStringC line);
            virtual void BeginScope() { m_indent ++; }
            virtual void EndScope() { m_indent --; }
        private:
            SPOStream m_ostream;
            int m_shiftWidth;
            int m_indent;
        };

        DEFINE_PTRS(ASTPrinter)
    }
}

