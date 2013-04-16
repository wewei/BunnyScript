#pragma once

#include <stack>
#include <vector>
#include <iostream>

#include "ShortCut.h"

namespace Bunny {
    namespace AST {
        class TreePrinter
        {
        public:
            TreePrinter(const SPOStream &ostream)
                : m_ostream(ostream)
            { }

            virtual ~TreePrinter() { }

            virtual void StartNode(RefStringC nodeInfo) = 0;

            virtual void EndNode() = 0;

            void AddLeafNode(RefStringC nodeInfo) {
                StartNode(nodeInfo);
                EndNode();
            }

        protected:
            SPOStream m_ostream;
        };

        DEFINE_PTRS(TreePrinter)

        class SimpleTreePrinter : public TreePrinter
        {
        public:
            SimpleTreePrinter(const SPOStream &ostream, int shiftWidth)
                : TreePrinter(ostream)
                , m_shiftWidth(shiftWidth)
                , m_indent(0)
            { }

            SimpleTreePrinter(const SPOStream &ostream)
                : TreePrinter(ostream)
                , m_shiftWidth(2)
                , m_indent(0)
            { }

            SimpleTreePrinter(int shiftWidth)
                : TreePrinter(SPOStream(new OStream(std::cout.rdbuf())))
                , m_shiftWidth(shiftWidth)
                , m_indent(0)
            { }

            SimpleTreePrinter()
                : TreePrinter(SPOStream(new OStream(std::cout.rdbuf())))
                , m_shiftWidth(2)
                , m_indent(0)
            { }

            virtual ~SimpleTreePrinter() { }

            virtual void StartNode(RefStringC nodeInfo);
            virtual void EndNode();
                
        protected:
            int m_shiftWidth;
            int m_indent;
        };
    }
}

