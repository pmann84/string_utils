#pragma once

#include <string>
#include <vector>
#include <locale>
#include <codecvt>

namespace string_utils
{
   template<typename CharT>
   std::vector<std::basic_string<CharT>> split(const std::basic_string<CharT>& string_to_split, const std::basic_string<CharT>& delimiter)
   {
      std::vector<std::basic_string<CharT>> split_string;
      std::size_t pos = string_to_split.find(delimiter);
      std::size_t initial_pos = 0;

      // Decompose statement
      while (pos != std::basic_string<CharT>::npos)
      {
         split_string.push_back(string_to_split.substr(initial_pos, pos - initial_pos));
         initial_pos = pos + delimiter.size();
         pos = string_to_split.find(delimiter, initial_pos);
      }

      // Add the last one
      split_string.push_back(string_to_split.substr(initial_pos, std::min(pos, string_to_split.size()) - initial_pos + 1));

      return split_string;
   }

   template<typename CharT>
   std::basic_string<CharT> join(const std::vector<std::basic_string<CharT>>& split_string, const std::basic_string<CharT>& delimiter)
   {
      std::basic_string<CharT> joined_string;
      for (const auto& str : split_string)
      {
         joined_string += str;
         if (std::find(split_string.begin(), split_string.end(), str) != split_string.end() - 1)
            joined_string += delimiter;
      }
      return joined_string;
   }

   template<typename CharT>
   bool starts_with(const std::basic_string<CharT>& str, const std::basic_string<CharT>& prefix)
   {
      return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
   }

   template<typename CharT>
   bool ends_with(const std::basic_string<CharT>& str, const std::basic_string<CharT>& suffix)
   {
      return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
   }

   template<typename CharT>
   std::basic_string<CharT> trim_left(const std::basic_string<CharT>& string_to_trim)
   {
      typename std::basic_string<CharT>::const_iterator p = string_to_trim.cbegin();
      while (std::isspace(*p, std::locale())) ++p;
      return p == string_to_trim.cend() ? std::basic_string<CharT>() : std::basic_string<CharT>(p, string_to_trim.end());
   }

   template<typename CharT>
   std::basic_string<CharT> trim_right(const std::basic_string<CharT>& string_to_trim)
   {
      typename std::basic_string<CharT>::const_iterator p = string_to_trim.cend() - 1;
      while (std::isspace(*p, std::locale())) --p;
      ++p; // Increment to get correct end point
      return p == string_to_trim.cbegin() ? std::basic_string<CharT>() : std::basic_string<CharT>(string_to_trim.begin(), p);
   }

   template<typename CharT>
   std::basic_string<CharT> trim(const std::basic_string<CharT>& string_to_trim)
   {
      return trim_right(trim_left(string_to_trim));
   }

   inline std::string from_wstring(const std::wstring& wstr)
   {
      // One Liner: return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wstr);
      using convert_str_type = std::codecvt_utf8<wchar_t>;
      std::wstring_convert<convert_str_type, wchar_t> wstring_converter;
      return wstring_converter.to_bytes(wstr);
   }

   inline std::wstring to_wstring(const std::string& sstr)
   {
      // One Liner: return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(sstr);
      using convert_str_type = std::codecvt_utf8<wchar_t>;
      std::wstring_convert<convert_str_type, wchar_t> wstring_converter;
      return wstring_converter.from_bytes(sstr);
   }
}
