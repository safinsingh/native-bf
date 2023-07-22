#pragma once

#include <istream>
#include <optional>
#include <vector>

enum class Token {
	IncrementPtr,
	DecrementPtr,
	IncrementValue,
	DecrementValue,
	OutputValue,
	InputValue,
	BeginLoop,
	EndLoop
};

class Tokenizer {
	std::istream& input;
	int loop_depth = 0;

   public:
	std::vector<Token> tokens;

	Tokenizer(std::istream& stream) : input(stream){};
	static std::optional<Token> get_token(char c);
	void tokenize(void);
};
