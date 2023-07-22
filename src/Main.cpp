#include <fstream>
#include <iostream>
#include <vector>

#include <Codegen.hpp>
#include <Tokenizer.hpp>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: native-bf [file]" << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream stream(argv[1]);

	auto tokenizer = Tokenizer(stream);
	tokenizer.tokenize();

	auto codegen = Codegen();
	codegen.codegen_from_tokens(tokenizer.tokens);
}
