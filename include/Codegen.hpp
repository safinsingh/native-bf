#pragma once

#include <vector>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <Tokenizer.hpp>

class Codegen {
	llvm::LLVMContext ctxt;
	llvm::Module mod = llvm::Module("native-bf", ctxt);
	llvm::IRBuilder<> builder = llvm::IRBuilder<>(ctxt);

   public:
	Codegen();
	~Codegen();
	void codegen_from_tokens(std::vector<Token>& tokens);
	llvm::Value* emit_increment_ptr(void);
	llvm::Value* emit_decrement_ptr(void);
	llvm::Value* emit_increment_value(void);
	llvm::Value* emit_decrement_value(void);
	llvm::Value* emit_output_value(void);
	llvm::Value* emit_input_value(void);
	llvm::Value* emit_loop(void);
};
