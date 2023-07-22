#include <algorithm>
#include <iostream>
#include <istream>
#include <optional>
#include <vector>

#include <Tokenizer.hpp>

static std::pair<char, Token> associations[] = {
	std::make_pair('>', Token::IncrementPtr),	std::make_pair('<', Token::DecrementPtr),
	std::make_pair('+', Token::IncrementValue), std::make_pair('-', Token::DecrementValue),
	std::make_pair('.', Token::OutputValue),	std::make_pair(',', Token::InputValue),
	std::make_pair('[', Token::BeginLoop),		std::make_pair(']', Token::EndLoop),
};

std::optional<Token> Tokenizer::get_token(char c) {
	const auto&& tok = std::find_if(begin(associations), end(associations),
									[c](std::pair<char, Token> tup) { return tup.first == c; });
	return tok != end(associations) ? std::optional<Token>{tok->second} : std::nullopt;
}

void Tokenizer::tokenize() {
	char c;
	while (input.get(c)) {
		auto token = get_token(c);
		if (!token) {
			continue;
		}
		if (*token == Token::BeginLoop) {
			loop_depth++;
		} else if (*token == Token::EndLoop && loop_depth-- == 0) {
			std::cerr << "Umatched closing brace" << std::endl;
			exit(EXIT_FAILURE);
		}

		tokens.push_back(*token);
	}

	if (loop_depth != 0) {
		std::cerr << "Unmatched opening brace" << std::endl;
		exit(EXIT_FAILURE);
	}
}
