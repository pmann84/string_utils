#pragma once

#include <string>
#include <vector>

namespace string_utils
{
   template<typename StrT>
   std::vector<StrT> split(const StrT& string_to_split, const StrT& delimiter)
   {
      std::vector<StrT> split_string;
      size_t pos = string_to_split.find(delimiter);
      size_t initial_pos = 0;

      // Decompose statement
      while (pos != std::wstring::npos)
      {
         split_string.push_back(string_to_split.substr(initial_pos, pos - initial_pos));
         initial_pos = pos + delimiter.size();
         pos = string_to_split.find(delimiter, initial_pos);
      }

      // Add the last one
      split_string.push_back(string_to_split.substr(initial_pos, std::min(pos, string_to_split.size()) - initial_pos + 1));

      return split_string;
   }

   template<typename StrT>
   StrT join(const std::vector<StrT>& split_string, const StrT& delimiter)
   {
      StrT joined_string;
      for (const auto& str : split_string)
      {
         joined_string += str;
         if (std::find(split_string.begin(), split_string.end(), str) != split_string.end() - 1)
            joined_string += delimiter;
      }
      return joined_string;
   }

   template<typename StrT>
   bool starts_with(const StrT& str, const StrT& prefix)
   {
      return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
   }

   template<typename StrT>
   bool ends_with(const StrT& str, const StrT& suffix)
   {
      return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
   }

   std::string from_wstring(const std::wstring& wstr);
   std::wstring to_wstring(const std::string& sstr);
}