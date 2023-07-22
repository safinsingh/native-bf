#include <vector>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <Codegen.hpp>
#include <Tokenizer.hpp>

#define MEM_SIZE 1024 * 1024
#define PTR_WIDTH 64

using namespace llvm;

Codegen::Codegen() : builder(IRBuilder<>(ctxt)) {
	static Type* int64_ty = Type::getInt64Ty(ctxt);
	Function* calloc_sig = Function::Create(
		FunctionType::get(Type::getInt8PtrTy(ctxt), std::vector{2, int64_ty}, false),
		Function::ExternalLinkage, "calloc", mod);

	builder.CreateCall(calloc_sig, std::vector<Value*>{ConstantInt::get(int64_ty, MEM_SIZE),
													   ConstantInt::get(int64_ty, PTR_WIDTH)});
}

Codegen::~Codegen() {}
void Codegen::codegen_from_tokens(std::vector<Token>& tokens) {
	mod.print(errs(), nullptr);
}

Value* Codegen::emit_increment_ptr(void) {}
Value* Codegen::emit_decrement_ptr(void) {}
Value* Codegen::emit_increment_value(void) {}
Value* Codegen::emit_decrement_value(void) {}
Value* Codegen::emit_output_value(void) {}
Value* Codegen::emit_input_value(void) {}
Value* Codegen::emit_loop(void) {}
