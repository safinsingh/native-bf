default:
	clang++ -g src/Main.cpp src/Codegen.cpp src/Tokenizer.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -Iinclude -o native-bf -std=c++17