#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>

int main() {
    llvm::LLVMContext context;
    llvm::Module myModule("MyFirstLanguage", context);

    llvm::outs() << "LLVM is officially linked and running on Windows!\n";
    myModule.print(llvm::outs(), nullptr);

    return 0;
}