#include "../string_utils/string_utils.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(TrimString, TestStringIsTrimmedFromRightWithSpacesOnly)
{
   const std::string str_to_test(" Hello   ");
   ASSERT_EQ(string_utils::trim_right(str_to_test), std::string(" Hello"));
}

TEST(TrimString, TestStringIsTrimmedFromRightWhenNoSpacesOnLeft)
{
   const std::string str_to_test("Hello   ");
   ASSERT_EQ(string_utils::trim_right(str_to_test), std::string("Hello"));
}

TEST(TrimString, TestStringRemainsUnchangedWhenNoSpacesOnRight)
{
   const std::string str_to_test("Hello");
   ASSERT_EQ(string_utils::trim_right(str_to_test), std::string("Hello"));
}

TEST(TrimString, TestStringIsTrimmedFromRightWithOtherWhiteSpace)
{
   const std::string str_to_test("Hello\n\t");
   ASSERT_EQ(string_utils::trim_right(str_to_test), std::string("Hello"));
}

TEST(TrimString, TestWideStringIsTrimmedFromRightWithSpacesOnly)
{
   const std::wstring str_to_test(L" Hello   ");
   ASSERT_EQ(string_utils::trim_right(str_to_test), std::wstring(L" Hello"));
}

TEST(TrimString, TestStringIsTrimmedFromLeftWithSpacesOnly)
{
   const std::string str_to_test("    Hello ");
   ASSERT_EQ(string_utils::trim_left(str_to_test), std::string("Hello "));
}

TEST(TrimString, TestStringIsTrimmedFromLeftWhenNoSpacesOnRight)
{
   const std::string str_to_test("    Hello");
   ASSERT_EQ(string_utils::trim_left(str_to_test), std::string("Hello"));
}

TEST(TrimString, TestStringRemainsUnchangedWhenNoSpacesOnLeft)
{
   const std::string str_to_test("Hello");
   ASSERT_EQ(string_utils::trim_left(str_to_test), std::string("Hello"));
}

TEST(TrimString, TestStringIsTrimmedFromLeftWithOtherWhiteSpace)
{
   const std::string str_to_test("\n\tHello");
   ASSERT_EQ(string_utils::trim_left(str_to_test), std::string("Hello"));
}

TEST(TrimString, TestWideStringIsTrimmedFromLeftWithSpacesOnly)
{
   const std::wstring str_to_test(L"    Hello ");
   ASSERT_EQ(string_utils::trim_left(str_to_test), std::wstring(L"Hello "));
}

TEST(TrimString, TestStringIsTrimmedFromBothSides)
{
   const std::string str_to_test("    Hello  ");
   ASSERT_EQ(string_utils::trim(str_to_test), std::string("Hello"));
}

TEST(TrimString, TestEmptyStringIsUnChanged)
{
   const std::string str_to_test("");
   ASSERT_EQ(string_utils::trim(str_to_test), std::string(""));
}

