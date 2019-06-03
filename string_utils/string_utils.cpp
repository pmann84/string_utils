#include "string_utils.h"

#include <algorithm>
#include <codecvt>

namespace string_utils
{
   std::string from_wstring(const std::wstring & wstr)
   {
      // One Liner: return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wstr);
      using convert_str_type = std::codecvt_utf8<wchar_t>;
      std::wstring_convert<convert_str_type, wchar_t> wstring_converter;
      return wstring_converter.to_bytes(wstr);
   }

   std::wstring to_wstring(const std::string & sstr)
   {
      // One Liner: return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(sstr);
      using convert_str_type = std::codecvt_utf8<wchar_t>;
      std::wstring_convert<convert_str_type, wchar_t> wstring_converter;
      return wstring_converter.from_bytes(sstr);
   }
}
