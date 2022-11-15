#pragma once

#include "sead/basis/seadRawPrint.h"
#include "sead/basis/seadTypes.h"
#include <stdarg.h>

namespace sead {

template <typename T>
class SafeStringBase {

public:
    virtual ~SafeStringBase() { }
    virtual void assureTerminationImpl_() const {};

    SafeStringBase()
        : mStringTop(&cNullChar)
    {
    }
    SafeStringBase(const T* str)
        : mStringTop(str)
    {
        SEAD_ASSERT_MSG(str != nullptr, "str must not be nullptr.");
    }
    SafeStringBase(const SafeStringBase& other);

    inline const T* cstr() const
    {
        assureTerminationImpl_();
        return mStringTop;
    }

    bool isEqual(const SafeStringBase<T>& str) const;

    static const T cNullChar = 0;
    static const T cLineBreakChar;
    static const SafeStringBase cEmptyString;
    static const s32 cMaximumLength = 0x80000;

protected:
    const T& unsafeAt_(s32 idx) const { return mStringTop[idx]; }

    const T* mStringTop;
};

typedef SafeStringBase<char> SafeString;

template <typename T>
class BufferedSafeStringBase : public SafeStringBase<T> {
public:
    __attribute__((always_inline)) BufferedSafeStringBase(T* buffer, s32 size)
        : SafeStringBase<T>(buffer)
    {
        mBufferSize = size;
        if (size <= 0) {
            SEAD_ASSERT_MSG(false, "Invalied buffer size(%d).\n", this->getBufferSize());
            this->mStringTop = nullptr;
            this->mBufferSize = 0;
        } else {
            this->assureTerminationImpl_();
        }
    }

    BufferedSafeStringBase(const BufferedSafeStringBase&);

    const T& operator[](s32 idx) const;

    T* getBuffer()
    {
        return getMutableStringTop_();
    }
    s32 getBufferSize() const { return mBufferSize; }

    /// Copy up to copyLength characters to the beginning of the string, then writes NUL.
    /// @param src  Source string
    /// @param copyLength  Number of characters from src to copy (must not cause a buffer overflow)
    s32 copy(const SafeStringBase<T>& src, s32 copyLength = -1);
    /// Copy up to copyLength characters to the specified position, then writes NUL if the copy
    /// makes this string longer.
    /// @param at  Start position (-1 for end of string)
    /// @param src  Source string
    /// @param copyLength  Number of characters from src to copy (must not cause a buffer overflow)
    inline s32 copyAt(s32 at, const SafeStringBase<T>& src, s32 copyLength = -1);
    /// Copy up to copyLength characters to the beginning of the string, then writes NUL.
    /// Silently truncates the source string if the buffer is too small.
    /// @param src  Source string
    /// @param copyLength  Number of characters from src to copy
    inline s32 cutOffCopy(const SafeStringBase<T>& src, s32 copyLength = -1);
    /// Copy up to copyLength characters to the specified position, then writes NUL if the copy
    /// makes this string longer.
    /// Silently truncates the source string if the buffer is too small.
    /// @param at  Start position (-1 for end of string)
    /// @param src  Source string
    /// @param copyLength  Number of characters from src to copy
    inline s32 cutOffCopyAt(s32 at, const SafeStringBase<T>& src, s32 copyLength = -1);
    /// Copy up to copyLength characters to the specified position, then *always* writes NUL.
    /// @param at  Start position (-1 for end of string)
    /// @param src  Source string
    /// @param copyLength  Number of characters from src to copy (must not cause a buffer overflow)
    inline s32 copyAtWithTerminate(s32 at, const SafeStringBase<T>& src, s32 copyLength = -1);

    s32 format(const T* format, ...);
    s32 formatV(const T* format, va_list args);
    s32 appendWithFormat(const T* formatStr, ...);
    s32 appendWithFormatV(const T* formatStr, va_list args);

    /// Append append_length characters from str.
    s32 append(const SafeStringBase<T>& str, s32 append_length = -1);
    /// Append a character.
    s32 append(T c) { return append(c, 1); }
    /// Append a character n times.
    s32 append(T c, s32 n);

    // Implementation note: These member functions appear to be inlined in most titles.
    // However, StringBuilderBase<T> conveniently duplicates the APIs and implementations of
    // SafeStringBase<T> and BufferedSafeString<T>: some assertion messages are even identical,
    // and the good news is that most StringBuilderBase<T> functions are not inlined!

    /// Append prepend_length characters from str.
    /// @return the new length
    s32 prepend(const SafeStringBase<T>& str, s32 prepend_length = -1);

    /// Remove num characters from the end of the string.
    /// @return the number of characters that were removed
    s32 chop(s32 num);
    /// Remove the last character if it is equal to c.
    /// @return the number of characters that were removed
    s32 chopMatchedChar(T c);
    /// Remove the last character if it is equal to any of the specified characters.
    /// @param characters  List of characters to remove
    /// @return the number of characters that were removed
    s32 chopMatchedChar(const T* characters);
    /// Remove the last character if it is unprintable.
    /// @warning The behavior of this function is not standard: a character is considered
    /// unprintable if it is <= 0x20 or == 0x7F. In particular, the space character is unprintable.
    /// @return the number of characters that were removed
    s32 chopUnprintableAsciiChar();

    /// Remove trailing characters that are in the specified list.
    /// @param characters  List of characters to remove
    /// @return the number of characters that were removed
    s32 rstrip(const T* characters);
    /// Remove trailing characters that are unprintable.
    /// @warning The behavior of this function is not standard: a character is considered
    /// unprintable if it is <= 0x20 or == 0x7F. In particular, the space character is unprintable.
    /// @return the number of characters that were removed
    s32 rstripUnprintableAsciiChars();

    /// Trim a string to only keep trimLength characters.
    /// @return the new length
    inline s32 trim(s32 trim_length);
    /// Remove the specified suffix from the string if it ends with the suffix.
    /// @return the new length
    inline s32 trimMatchedString(const SafeStringBase<T>& suffix);
    /// Remove the specified suffix from the string if it ends with the suffix.
    /// Alias of trimMatchedString.
    /// @return the new length
    inline s32 removeSuffix(const SafeStringBase<T>& suffix) { return trimMatchedString(suffix); }

    /// @return the number of characters that were replaced
    inline s32 replaceChar(T old_char, T new_char);
    /// @return the number of characters that were replaced
    inline s32 replaceCharList(const SafeStringBase<T>& old_chars,
        const SafeStringBase<T>& new_chars);
    /// Set the contents of this string to target_str, after replacing occurrences of old_str in
    /// target_str with new_str.
    /// @return the number of replaced occurrences
    inline s32 setReplaceString(const SafeStringBase<T>& target_str,
        const SafeStringBase<T>& old_str, const SafeStringBase<T>& new_str);
    /// Replace occurrences of old_str in this string with new_str.
    /// @return the number of replaced occurrences
    inline s32 replaceString(const SafeStringBase<T>& old_str, const SafeStringBase<T>& new_str);

    s32 convertFromMultiByteString(const SafeStringBase<char>& str, s32 str_length);
    s32 convertFromWideCharString(const SafeStringBase<char16>& str, s32 str_length);

    inline void clear() { getMutableStringTop_()[0] = this->cNullChar; }

protected:
    T* getMutableStringTop_() { return const_cast<T*>(this->mStringTop); }

    static s32 formatImpl_(T* dst, s32 dst_size, const T* format, va_list arg);

    template <typename OtherType>
    s32 convertFromOtherType_(const SafeStringBase<OtherType>& src, s32 src_size);

    s32 mBufferSize;
};

template <typename T, s32 L>
class FixedSafeStringBase : public BufferedSafeStringBase<T> {
public:
    FixedSafeStringBase()
        : BufferedSafeStringBase<T>(mBuffer, L)
    {
        this->clear();
    }

    FixedSafeStringBase(const SafeStringBase<T>& str)
        : BufferedSafeStringBase<T>(mBuffer, L)
    {
        this->copy(str);
    }

    FixedSafeStringBase(const FixedSafeStringBase& str)
        : BufferedSafeStringBase<T>(mBuffer, L)
    {
        this->copy(str);
    }

    FixedSafeStringBase& operator=(const FixedSafeStringBase& other)
    {
        this->copy(other);
        return *this;
    }

    T mBuffer[L];
};

typedef SafeStringBase<char> SafeString;
typedef SafeStringBase<char16> WSafeString;
typedef BufferedSafeStringBase<char> BufferedSafeString;
typedef BufferedSafeStringBase<char16> WBufferedSafeString;

template <>
s32 BufferedSafeStringBase<char>::format(const char* formatStr, ...);
template <>
s32 BufferedSafeStringBase<char16>::format(const char16* formatStr, ...);
template <>
s32 BufferedSafeStringBase<char>::formatV(const char* formatStr, va_list args);
template <>
s32 BufferedSafeStringBase<char16>::formatV(const char16* formatStr, va_list args);
template <>
s32 BufferedSafeStringBase<char>::appendWithFormat(const char* formatStr, ...);
template <>
s32 BufferedSafeStringBase<char16>::appendWithFormat(const char16* formatStr, ...);
template <>
s32 BufferedSafeStringBase<char>::appendWithFormatV(const char* formatStr, va_list args);
template <>
s32 BufferedSafeStringBase<char16>::appendWithFormatV(const char16* formatStr, va_list args);

template <s32 L>
class FixedSafeString : public FixedSafeStringBase<char, L> {
public:
    FixedSafeString()
        : FixedSafeStringBase<char, L>()
    {
    }
    FixedSafeString(const SafeString& str)
        : FixedSafeStringBase<char, L>(str)
    {
    }
    FixedSafeString(const FixedSafeString& other)
        : FixedSafeString(static_cast<const SafeString&>(other))
    {
    }

    FixedSafeString& operator=(const FixedSafeString& other)
    {
        this->copy(other);
        return *this;
    }
};

} // namespace sead
