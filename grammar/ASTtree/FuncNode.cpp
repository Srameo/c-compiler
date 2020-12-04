#include "./FuncNode.h"

AST::DefineFuncNode::DefineFuncNode() : BaseNode(AST::def_func) {}

AST::DefineFuncNode::DefineFuncNode(std::string content) : BaseNode(content, AST::def_func) {}

void AST::DefineFuncNode::setReturnSymbolType(std::string symbol_type) {
    if (symbol_type == "int") {
        this->return_symbol_type = STE::SymbolType::integer;
    } else if (symbol_type == "void") {
        this->return_symbol_type = STE::SymbolType::void_type;
    }
}

void AST::DefineFuncNode::printInfo(int) {
    std::cout << "function defination: " << this->content;
}

AST::CallFuncNode::CallFuncNode() : BaseNode(AST::call_func) {}

AST::CallFuncNode::CallFuncNode(std::string content) : BaseNode(content, AST::call_func) {}

void AST::CallFuncNode::printInfo(int) {
    std::cout << "call function: " << this->content;
}

