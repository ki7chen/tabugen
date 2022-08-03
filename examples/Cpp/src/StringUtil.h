// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// from google3/strings/strutil.h

#pragma once

#include <stdlib.h>
#include <cstring>
#include <vector>
#include "StringPiece.h"


std::string StringPrintf(const char* format, ...);

// ----------------------------------------------------------------------
// HasPrefixString()
//    Check if a string begins with a given prefix.
// StripPrefixString()
//    Given a string and a putative prefix, returns the string minus the
//    prefix string if the prefix matches, otherwise the original
//    string.
// ----------------------------------------------------------------------
inline bool HasPrefixString(StringPiece str, StringPiece prefix) {
  return str.size() >= prefix.size() &&
         memcmp(str.data(), prefix.data(), prefix.size()) == 0;
}

inline std::string StripPrefixString(const std::string& str,
                                     const std::string& prefix) {
  if (HasPrefixString(str, prefix)) {
    return str.substr(prefix.size());
  } else {
    return str;
  }
}

// ----------------------------------------------------------------------
// HasSuffixString()
//    Return true if str ends in suffix.
// StripSuffixString()
//    Given a string and a putative suffix, returns the string minus the
//    suffix string if the suffix matches, otherwise the original
//    string.
// ----------------------------------------------------------------------
inline bool HasSuffixString(StringPiece str, StringPiece suffix) {
  return str.size() >= suffix.size() &&
         memcmp(str.data() + str.size() - suffix.size(), suffix.data(),
                suffix.size()) == 0;
}

inline std::string StripSuffixString(const std::string& str,
                                     const std::string& suffix) {
  if (HasSuffixString(str, suffix)) {
    return str.substr(0, str.size() - suffix.size());
  } else {
    return str;
  }
}

// ----------------------------------------------------------------------
// ReplaceCharacters
//    Replaces any occurrence of the character 'remove' (or the characters
//    in 'remove') with the character 'replacewith'.
//    Good for keeping html characters or protocol characters (\t) out
//    of places where they might cause a problem.
// StripWhitespace
//    Removes whitespaces from both ends of the given string.
// ----------------------------------------------------------------------
void ReplaceCharacters(std::string* s, const char* remove, char replacewith);
                                       

std::string& StripWhitespace(std::string& s);
StringPiece StripWhitespace(StringPiece s);

// ----------------------------------------------------------------------
// LowerString()
// UpperString()
// ToUpper()
//    Convert the characters in "s" to lowercase or uppercase.  ASCII-only:
//    these functions intentionally ignore locale because they are applied to
//    identifiers used in the Protocol Buffer language, not to natural-language
//    strings.
// ----------------------------------------------------------------------

inline void LowerString(std::string* s) {
  std::string::iterator end = s->end();
  for (std::string::iterator i = s->begin(); i != end; ++i) {
    // tolower() changes based on locale.  We don't want this!
    if ('A' <= *i && *i <= 'Z') *i += 'a' - 'A';
  }
}

inline void UpperString(std::string* s) {
  std::string::iterator end = s->end();
  for (std::string::iterator i = s->begin(); i != end; ++i) {
    // toupper() changes based on locale.  We don't want this!
    if ('a' <= *i && *i <= 'z') *i += 'A' - 'a';
  }
}

inline void ToUpper(std::string* s) { UpperString(s); }

inline std::string ToUpper(const std::string& s) {
  std::string out = s;
  UpperString(&out);
  return out;
}

// ----------------------------------------------------------------------
// StringReplace()
//    Give me a string and two patterns "old" and "new", and I replace
//    the first instance of "old" in the string with "new", if it
//    exists.  RETURN a new string, regardless of whether the replacement
//    happened or not.
// ----------------------------------------------------------------------

std::string StringReplace(const std::string& s,
                                          const std::string& oldsub,
                                          const std::string& newsub,
                                          bool replace_all);

// ----------------------------------------------------------------------
// SplitStringUsing()
//    Split a string using a character delimiter. Append the components
//    to 'result'.  If there are consecutive delimiters, this function skips
//    over all of them.
// ----------------------------------------------------------------------
void SplitStringUsing(StringPiece full, const char* delim,
                                      std::vector<std::string>* res);

// Split a string using one or more byte delimiters, presented
// as a nul-terminated c string. Append the components to 'result'.
// If there are consecutive delimiters, this function will return
// corresponding empty strings.  If you want to drop the empty
// strings, try SplitStringUsing().
//
// If "full" is the empty string, yields an empty string as the only value.
// ----------------------------------------------------------------------
void SplitStringAllowEmpty(StringPiece full, const char* delim,
                                           std::vector<std::string>* result);

// ----------------------------------------------------------------------
// Split()
//    Split a string using a character delimiter.
// ----------------------------------------------------------------------
inline std::vector<std::string> SplitString(StringPiece full, const char* delim,
                                      bool skip_empty = true) {
  std::vector<std::string> result;
  if (skip_empty) {
    SplitStringUsing(full, delim, &result);
  } else {
    SplitStringAllowEmpty(full, delim, &result);
  }
  return result;
}

// ----------------------------------------------------------------------
// JoinStrings()
//    These methods concatenate a vector of strings into a C++ string, using
//    the C-string "delim" as a separator between components. There are two
//    flavors of the function, one flavor returns the concatenated string,
//    another takes a pointer to the target string. In the latter case the
//    target string is cleared and overwritten.
// ----------------------------------------------------------------------
void JoinStrings(const std::vector<std::string>& components,
                                 const char* delim, std::string* result);

inline std::string JoinStrings(const std::vector<std::string>& components,
                               const char* delim) {
  std::string result;
  JoinStrings(components, delim, &result);
  return result;
}


// ----------------------------------------------------------------------
// FastIntToBuffer()
// FastHexToBuffer()
// FastHex64ToBuffer()
// FastHex32ToBuffer()
// FastTimeToBuffer()
//    These are intended for speed.  FastIntToBuffer() assumes the
//    integer is non-negative.  FastHexToBuffer() puts output in
//    hex rather than decimal.  FastTimeToBuffer() puts the output
//    into RFC822 format.
//
//    FastHex64ToBuffer() puts a 64-bit unsigned value in hex-format,
//    padded to exactly 16 bytes (plus one byte for '\0')
//
//    FastHex32ToBuffer() puts a 32-bit unsigned value in hex-format,
//    padded to exactly 8 bytes (plus one byte for '\0')
//
//       All functions take the output buffer as an arg.
//    They all return a pointer to the beginning of the output,
//    which may not be the beginning of the input buffer.
// ----------------------------------------------------------------------

// Suggested buffer size for FastToBuffer functions.  Also works with
// DoubleToBuffer() and FloatToBuffer().
static const int kFastToBufferSize = 32;

char* FastInt32ToBuffer(int32_t i, char* buffer);
char* FastInt64ToBuffer(int64_t i, char* buffer);
char* FastUInt32ToBuffer(uint32_t i, char* buffer);  // inline below
char* FastUInt64ToBuffer(uint64_t i, char* buffer);  // inline below
char* FastHexToBuffer(int i, char* buffer);
char* FastHex64ToBuffer(uint64_t i, char* buffer);
char* FastHex32ToBuffer(uint32_t i, char* buffer);

// at least 22 bytes long
inline char* FastIntToBuffer(int i, char* buffer) {
  return (sizeof(i) == 4 ?
          FastInt32ToBuffer(i, buffer) : FastInt64ToBuffer(i, buffer));
}
inline char* FastUIntToBuffer(unsigned int i, char* buffer) {
  return (sizeof(i) == 4 ?
          FastUInt32ToBuffer(i, buffer) : FastUInt64ToBuffer(i, buffer));
}
inline char* FastLongToBuffer(long i, char* buffer) {
  return (sizeof(i) == 4 ?
          FastInt32ToBuffer(i, buffer) : FastInt64ToBuffer(i, buffer));
}
inline char* FastULongToBuffer(unsigned long i, char* buffer) {
  return (sizeof(i) == 4 ?
          FastUInt32ToBuffer(i, buffer) : FastUInt64ToBuffer(i, buffer));
}

// ----------------------------------------------------------------------
// FastInt32ToBufferLeft()
// FastUInt32ToBufferLeft()
// FastInt64ToBufferLeft()
// FastUInt64ToBufferLeft()
//
// Like the Fast*ToBuffer() functions above, these are intended for speed.
// Unlike the Fast*ToBuffer() functions, however, these functions write
// their output to the beginning of the buffer (hence the name, as the
// output is left-aligned).  The caller is responsible for ensuring that
// the buffer has enough space to hold the output.
//
// Returns a pointer to the end of the string (i.e. the null character
// terminating the string).
// ----------------------------------------------------------------------

char* FastInt32ToBufferLeft(int32_t i, char* buffer);
char* FastUInt32ToBufferLeft(uint32_t i, char* buffer);
char* FastInt64ToBufferLeft(int64_t i, char* buffer);
char* FastUInt64ToBufferLeft(uint64_t i, char* buffer);

// Just define these in terms of the above.
inline char* FastUInt32ToBuffer(uint32_t i, char* buffer) {
  FastUInt32ToBufferLeft(i, buffer);
  return buffer;
}
inline char* FastUInt64ToBuffer(uint64_t i, char* buffer) {
  FastUInt64ToBufferLeft(i, buffer);
  return buffer;
}

inline std::string SimpleBtoa(bool value) { return value ? "true" : "false"; }

// ----------------------------------------------------------------------
// SimpleItoa()
//    Description: converts an integer to a string.
//
//    Return value: string
// ----------------------------------------------------------------------
std::string SimpleItoa(int i);
std::string SimpleItoa(unsigned int i);
std::string SimpleItoa(long i);
std::string SimpleItoa(unsigned long i);
std::string SimpleItoa(long long i);
std::string SimpleItoa(unsigned long long i);

// ----------------------------------------------------------------------
// SimpleDtoa()
// SimpleFtoa()
// DoubleToBuffer()
// FloatToBuffer()
//    Description: converts a double or float to a string which, if
//    passed to NoLocaleStrtod(), will produce the exact same original double
//    (except in case of NaN; all NaNs are considered the same value).
//    We try to keep the string short but it's not guaranteed to be as
//    short as possible.
//
//    DoubleToBuffer() and FloatToBuffer() write the text to the given
//    buffer and return it.  The buffer must be at least
//    kDoubleToBufferSize bytes for doubles and kFloatToBufferSize
//    bytes for floats.  kFastToBufferSize is also guaranteed to be large
//    enough to hold either.
//
//    Return value: string
// ----------------------------------------------------------------------
std::string SimpleDtoa(double value);
std::string SimpleFtoa(float value);

char* DoubleToBuffer(double i, char* buffer);
char* FloatToBuffer(float i, char* buffer);

// In practice, doubles should never need more than 24 bytes and floats
// should never need more than 14 (including null terminators), but we
// overestimate to be safe.
static const int kDoubleToBufferSize = 32;
static const int kFloatToBufferSize = 24;

namespace strings {

enum PadSpec {
  NO_PAD = 1,
  ZERO_PAD_2,
  ZERO_PAD_3,
  ZERO_PAD_4,
  ZERO_PAD_5,
  ZERO_PAD_6,
  ZERO_PAD_7,
  ZERO_PAD_8,
  ZERO_PAD_9,
  ZERO_PAD_10,
  ZERO_PAD_11,
  ZERO_PAD_12,
  ZERO_PAD_13,
  ZERO_PAD_14,
  ZERO_PAD_15,
  ZERO_PAD_16,
};

struct Hex {
  uint64_t value;
  enum PadSpec spec;
  template <class Int>
  explicit Hex(Int v, PadSpec s = NO_PAD)
      : spec(s) {
    // Prevent sign-extension by casting integers to
    // their unsigned counterparts.
#ifdef LANG_CXX11
    static_assert(
        sizeof(v) == 1 || sizeof(v) == 2 || sizeof(v) == 4 || sizeof(v) == 8,
        "Unknown integer type");
#endif
    value = sizeof(v) == 1 ? static_cast<uint8_t>(v)
          : sizeof(v) == 2 ? static_cast<uint16_t>(v)
          : sizeof(v) == 4 ? static_cast<uint32_t>(v)
          : static_cast<uint64_t>(v);
  }
};

struct AlphaNum {
  const char *piece_data_;  // move these to string_ref eventually
  size_t piece_size_;       // move these to string_ref eventually

  char digits[kFastToBufferSize];

  // No bool ctor -- bools convert to an integral type.
  // A bool ctor would also convert incoming pointers (bletch).

  AlphaNum(int i32)
      : piece_data_(digits),
        piece_size_(FastInt32ToBufferLeft(i32, digits) - &digits[0]) {}
  AlphaNum(unsigned int u32)
      : piece_data_(digits),
        piece_size_(FastUInt32ToBufferLeft(u32, digits) - &digits[0]) {}
  AlphaNum(long long i64)
      : piece_data_(digits),
        piece_size_(FastInt64ToBufferLeft(i64, digits) - &digits[0]) {}
  AlphaNum(unsigned long long u64)
      : piece_data_(digits),
        piece_size_(FastUInt64ToBufferLeft(u64, digits) - &digits[0]) {}

  // Note: on some architectures, "long" is only 32 bits, not 64, but the
  // performance hit of using FastInt64ToBufferLeft to handle 32-bit values
  // is quite minor.
  AlphaNum(long i64)
      : piece_data_(digits),
        piece_size_(FastInt64ToBufferLeft(i64, digits) - &digits[0]) {}
  AlphaNum(unsigned long u64)
      : piece_data_(digits),
        piece_size_(FastUInt64ToBufferLeft(u64, digits) - &digits[0]) {}

  AlphaNum(float f)
    : piece_data_(digits), piece_size_(strlen(FloatToBuffer(f, digits))) {}
  AlphaNum(double f)
    : piece_data_(digits), piece_size_(strlen(DoubleToBuffer(f, digits))) {}

  AlphaNum(Hex hex);

  AlphaNum(const char* c_str)
      : piece_data_(c_str), piece_size_(strlen(c_str)) {}
  // TODO: Add a string_ref constructor, eventually
  // AlphaNum(const StringPiece &pc) : piece(pc) {}

  AlphaNum(const std::string& str)
      : piece_data_(str.data()), piece_size_(str.size()) {}

  AlphaNum(StringPiece str)
      : piece_data_(str.data()), piece_size_(str.size()) {}

  size_t size() const { return piece_size_; }
  const char *data() const { return piece_data_; }

 private:
  // Use ":" not ':'
  AlphaNum(char c);  // NOLINT(runtime/explicit)

  // Disallow copy and assign.
  AlphaNum(const AlphaNum&);
  void operator=(const AlphaNum&);
};

}  // namespace strings

using strings::AlphaNum;

// ----------------------------------------------------------------------
// StrCat()
//    This merges the given strings or numbers, with no delimiter.  This
//    is designed to be the fastest possible way to construct a string out
//    of a mix of raw C strings, strings, bool values,
//    and numeric values.
//
//    Don't use this for user-visible strings.  The localization process
//    works poorly on strings built up out of fragments.
//
//    For clarity and performance, don't use StrCat when appending to a
//    string.  In particular, avoid using any of these (anti-)patterns:
//      str.append(StrCat(...)
//      str += StrCat(...)
//      str = StrCat(str, ...)
//    where the last is the worse, with the potential to change a loop
//    from a linear time operation with O(1) dynamic allocations into a
//    quadratic time operation with O(n) dynamic allocations.  StrAppend
//    is a better choice than any of the above, subject to the restriction
//    of StrAppend(&str, a, b, c, ...) that none of the a, b, c, ... may
//    be a reference into str.
// ----------------------------------------------------------------------

std::string StrCat(const AlphaNum& a, const AlphaNum& b);
std::string StrCat(const AlphaNum& a, const AlphaNum& b,
                                   const AlphaNum& c);
std::string StrCat(const AlphaNum& a, const AlphaNum& b,
                                   const AlphaNum& c, const AlphaNum& d);
std::string StrCat(const AlphaNum& a, const AlphaNum& b,
                                   const AlphaNum& c, const AlphaNum& d,
                                   const AlphaNum& e);
std::string StrCat(const AlphaNum& a, const AlphaNum& b,
                                   const AlphaNum& c, const AlphaNum& d,
                                   const AlphaNum& e, const AlphaNum& f);
std::string StrCat(const AlphaNum& a, const AlphaNum& b,
                                   const AlphaNum& c, const AlphaNum& d,
                                   const AlphaNum& e, const AlphaNum& f,
                                   const AlphaNum& g);
std::string StrCat(const AlphaNum& a, const AlphaNum& b,
                                   const AlphaNum& c, const AlphaNum& d,
                                   const AlphaNum& e, const AlphaNum& f,
                                   const AlphaNum& g, const AlphaNum& h);
std::string StrCat(const AlphaNum& a, const AlphaNum& b,
                                   const AlphaNum& c, const AlphaNum& d,
                                   const AlphaNum& e, const AlphaNum& f,
                                   const AlphaNum& g, const AlphaNum& h,
                                   const AlphaNum& i);

inline std::string StrCat(const AlphaNum& a) {
  return std::string(a.data(), a.size());
}

// ----------------------------------------------------------------------
// StrAppend()
//    Same as above, but adds the output to the given string.
//    WARNING: For speed, StrAppend does not try to check each of its input
//    arguments to be sure that they are not a subset of the string being
//    appended to.  That is, while this will work:
//
//    string s = "foo";
//    s += s;
//
//    This will not (necessarily) work:
//
//    string s = "foo";
//    StrAppend(&s, s);
//
//    Note: while StrCat supports appending up to 9 arguments, StrAppend
//    is currently limited to 4.  That's rarely an issue except when
//    automatically transforming StrCat to StrAppend, and can easily be
//    worked around as consecutive calls to StrAppend are quite efficient.
// ----------------------------------------------------------------------

void StrAppend(std::string* dest, const AlphaNum& a);
void StrAppend(std::string* dest, const AlphaNum& a,
                               const AlphaNum& b);
void StrAppend(std::string* dest, const AlphaNum& a,
                               const AlphaNum& b, const AlphaNum& c);
void StrAppend(std::string* dest, const AlphaNum& a,
                               const AlphaNum& b, const AlphaNum& c,
                               const AlphaNum& d);

// ----------------------------------------------------------------------
// Join()
//    These methods concatenate a range of components into a C++ string, using
//    the C-string "delim" as a separator between components.
// ----------------------------------------------------------------------
template <typename Iterator>
void Join(Iterator start, Iterator end, const char* delim,
          std::string* result) {
  for (Iterator it = start; it != end; ++it) {
    if (it != start) {
      result->append(delim);
    }
    StrAppend(result, *it);
  }
}

template <typename Range>
std::string Join(const Range& components, const char* delim) {
  std::string result;
  Join(components.begin(), components.end(), delim, &result);
  return result;
}

// ----------------------------------------------------------------------
// ToHex()
//    Return a lower-case hex string representation of the given integer.
// ----------------------------------------------------------------------
std::string ToHex(uint64_t num);

// ----------------------------------------------------------------------
// GlobalReplaceSubstring()
//    Replaces all instances of a substring in a string.  Does nothing
//    if 'substring' is empty.  Returns the number of replacements.
//
//    NOTE: The string pieces must not overlap s.
// ----------------------------------------------------------------------
int GlobalReplaceSubstring(const std::string& substring,
                                           const std::string& replacement,
                                           std::string* s);


inline bool IsValidCodePoint(uint32_t code_point) {
  return code_point < 0xD800 ||
         (code_point >= 0xE000 && code_point <= 0x10FFFF);
}

static const int UTFmax = 4;
// ----------------------------------------------------------------------
// EncodeAsUTF8Char()
//  Helper to append a Unicode code point to a string as UTF8, without bringing
//  in any external dependencies. The output buffer must be as least 4 bytes
//  large.
// ----------------------------------------------------------------------
int EncodeAsUTF8Char(uint32_t code_point, char* output);

// ----------------------------------------------------------------------
// UTF8FirstLetterNumBytes()
//   Length of the first UTF-8 character.
// ----------------------------------------------------------------------
int UTF8FirstLetterNumBytes(const char* src, int len);

// From google3/third_party/absl/strings/escaping.h

// ----------------------------------------------------------------------
// CleanStringLineEndings()
//   Clean up a multi-line string to conform to Unix line endings.
//   Reads from src and appends to dst, so usually dst should be empty.
//
//   If there is no line ending at the end of a non-empty string, it can
//   be added automatically.
//
//   Four different types of input are correctly handled:
//
//     - Unix/Linux files: line ending is LF: pass through unchanged
//
//     - DOS/Windows files: line ending is CRLF: convert to LF
//
//     - Legacy Mac files: line ending is CR: convert to LF
//
//     - Garbled files: random line endings: convert gracefully
//                      lonely CR, lonely LF, CRLF: convert to LF
//
//   @param src The multi-line string to convert
//   @param dst The converted string is appended to this string
//   @param auto_end_last_line Automatically terminate the last line
//
//   Limitations:
//
//     This does not do the right thing for CRCRLF files created by
//     broken programs that do another Unix->DOS conversion on files
//     that are already in CRLF format.  For this, a two-pass approach
//     brute-force would be needed that
//
//       (1) determines the presence of LF (first one is ok)
//       (2) if yes, removes any CR, else convert every CR to LF
void CleanStringLineEndings(const std::string& src,
                                            std::string* dst,
                                            bool auto_end_last_line);

// Same as above, but transforms the argument in place.
void CleanStringLineEndings(std::string* str,
                                            bool auto_end_last_line);

namespace strings {
inline bool EndsWith(StringPiece text, StringPiece suffix) {
  return suffix.empty() ||
      (text.size() >= suffix.size() &&
       memcmp(text.data() + (text.size() - suffix.size()), suffix.data(),
              suffix.size()) == 0);
}
}  // namespace strings

namespace internal {

    // A locale-independent version of the standard strtod(), which always
    // uses a dot as the decimal separator.
    double NoLocaleStrtod(const char* str, char** endptr);

}  // namespace internal