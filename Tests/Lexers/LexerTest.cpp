#include "gtest/gtest.h"

#include "../../src/Lexers/lexer.h"

TEST(LexerTest, Tokenize_EOF) {
    Lexer lexer("");
    const tokens_vector& tokens = lexer.tokenize();

    ASSERT_EQ(1, tokens.size());

    EXPECT_EQ(TokenType::EndOfFile, tokens[0].type);
    EXPECT_EQ("", tokens[0].value);
}


TEST(LexerTest, Tokenize_keyword_int) {
    Lexer lexer("int");
    const tokens_vector& tokens = lexer.tokenize();

    ASSERT_EQ(2, tokens.size());

    EXPECT_EQ(TokenType::Int, tokens[0].type);
    EXPECT_EQ("int", tokens[0].value);

    const size_t last_token = tokens.size() - 1;
    EXPECT_EQ(TokenType::EndOfFile, tokens[last_token].type);
    EXPECT_EQ("", tokens[last_token].value);
}

TEST(LexerTest, Tokenize_identifier_multi) {
    const std::vector<std::string_view> test_cases = {
        "a",
        "abc",
        "abc1",
        "aBc123",
        "A1b3C2",
        "_a_b_c_123",
        "_a_2Bc_1Nd5",
        "_",
    };

    for (const auto& test_identifier : test_cases) {
        Lexer lexer(test_identifier);
        const tokens_vector& tokens = lexer.tokenize();

        ASSERT_EQ(2, tokens.size()) << "Failed on input: " << test_identifier;

        EXPECT_EQ(TokenType::Identifier, tokens[0].type);
        EXPECT_EQ(test_identifier, tokens[0].value);

        const size_t last_token = tokens.size() - 1;
        EXPECT_EQ(TokenType::EndOfFile, tokens[last_token].type);
        EXPECT_EQ("", tokens[last_token].value);
    }
}

TEST(LexerTest, Tokenize_int_number) {
    const std::vector<std::string_view> test_cases = {
        "1",
        "10",
        "1234",
        "5555555555555555555555"
    };

    for (const auto& test_num : test_cases) {
        Lexer lexer(test_num);
        const tokens_vector& tokens = lexer.tokenize();

        ASSERT_EQ(2, tokens.size()) << "Failed on input: " << test_num;

        EXPECT_EQ(TokenType::IntLiteral, tokens[0].type);
        EXPECT_EQ(test_num, tokens[0].value);

        const size_t last_token = tokens.size() - 1;
        EXPECT_EQ(TokenType::EndOfFile, tokens[last_token].type);
        EXPECT_EQ("", tokens[last_token].value);
    }
}

TEST(LexerTest, Tokenize_int_definition) {
    const std::vector<std::string_view> test_cases = {
        "int abc = 10;",
        "int _a_bc123 = 55;",
        "int a_12_bng_4=10000;"
    };

    // We need expected values to match against!
    const std::vector<std::string_view> expected_identifiers = {
        "abc",
        "_a_bc123",
        "a_12_bng_4"
    };

    const std::vector<std::string_view> expected_numbers = {
        "10",
        "55",
        "10000"
    };

    for (size_t i = 0; i < test_cases.size(); ++i) {
        Lexer lexer(test_cases[i]);
        const tokens_vector& tokens = lexer.tokenize();

        ASSERT_EQ(6, tokens.size()) << "Failed on input: " << test_cases[i];

        EXPECT_EQ(TokenType::Int, tokens[0].type);
        EXPECT_EQ("int", tokens[0].value);

        EXPECT_EQ(TokenType::Identifier, tokens[1].type);
        EXPECT_EQ(expected_identifiers[i], tokens[1].value);

        EXPECT_EQ(TokenType::Assign, tokens[2].type);
        EXPECT_EQ("=", tokens[2].value);

        EXPECT_EQ(TokenType::IntLiteral, tokens[3].type);
        EXPECT_EQ(expected_numbers[i], tokens[3].value);

        EXPECT_EQ(TokenType::SemiColon, tokens[4].type);
        EXPECT_EQ(";", tokens[4].value);

        EXPECT_EQ(TokenType::EndOfFile, tokens[5].type);
    }
}

TEST(LexerTest, Tracking_line_col) {
    Lexer lexer("int \n  x");
    const tokens_vector& tokens = lexer.tokenize();

    ASSERT_EQ(3, tokens.size());

    EXPECT_EQ(1, tokens[0].line);
    EXPECT_EQ(1, tokens[0].col);

    EXPECT_EQ(2, tokens[1].line);
    EXPECT_EQ(3, tokens[1].col);

    EXPECT_EQ(2, tokens[2].line);
    EXPECT_EQ(4, tokens[2].col);
}