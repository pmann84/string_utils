#include "../string_utils/string_utils.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(TrimString, TestStringConvertedToUpperCase)
{
   const std::string str_to_test("hello");
   ASSERT_EQ(string_utils::to_upper(str_to_test), std::string("HELLO"));
}

TEST(TrimString, TestMixedStringConvertedToUpperCase)
{
    const std::string str_to_test("hElLo");
    ASSERT_EQ(string_utils::to_upper(str_to_test), std::string("HELLO"));
}

TEST(TrimString, TestStringConvertedToLowerCase)
{
    const std::string str_to_test("HELLO");
    ASSERT_EQ(string_utils::to_lower(str_to_test), std::string("hello"));
}

TEST(TrimString, TestMixedStringConvertedToLowerCase)
{
    const std::string str_to_test("hElLo");
    ASSERT_EQ(string_utils::to_lower(str_to_test), std::string("hello"));
}

TEST(TrimString, TestMixedStringWithNonLetterCharsConvertedToLowerCase)
{
    const std::string str_to_test("hElLo!");
    ASSERT_EQ(string_utils::to_lower(str_to_test), std::string("hello!"));
}