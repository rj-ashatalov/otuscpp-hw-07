#pragma once
#include <sstream>
#include <list>
#include <vector>
#include <iterator>
#include <tuple>

template<class ...T>
struct is_same_all
{
};

template<class T>
struct is_same_all<T> : std::true_type
{
};

template<class T, class ...TArgs>
struct is_same_all<T, T, TArgs...> : is_same_all<T, TArgs...>
{
};

template<class T, class U, class ...TArgs>
struct is_same_all<T, U, TArgs...> : std::false_type
{
};

struct _char_print_tag {};
struct _short_print_tag {};
struct _int_print_tag{};
struct _long_long_print_tag{};
struct _string_print_tag{};
struct _iterable_print_tag{};
struct _tuple_print_tag{};

template<class T>
std::string toString(T&& src);

template <class T>
struct _print_traits {
};

template <>
struct _print_traits<char> {
    using category = _char_print_tag;
};

template <>
struct _print_traits<short> {
    using category = _short_print_tag;
};

template <>
struct _print_traits<int> {
    using category = _int_print_tag;
};

template <>
struct _print_traits<long long int> {
    using category = _long_long_print_tag;
};

template <>
struct _print_traits<std::string> {
    using category = _string_print_tag;
};

template <class T, class U>
struct _print_traits<std::vector<T, U>> {
    using category = _iterable_print_tag;
};

template <class T, class U>
struct _print_traits<std::list<T, U>> {
    using category = _iterable_print_tag;
};

template <class ...Args>
struct _print_traits<std::tuple<Args...>> {
    using category = std::enable_if_t<is_same_all<Args...>::value, _tuple_print_tag>;
};


template<class T>
std::string toStringInternal(T&& src, _char_print_tag)
{
    return std::to_string(static_cast<unsigned char>(src));
}

template<class T>
std::string toStringInternal(T&& src, _short_print_tag)
{
    return toString(static_cast<char>(src>>8)) + "." + toString(static_cast<char>((src<<8)>>8));
}

template<class T>
std::string toStringInternal(T&& src, _int_print_tag)
{
    return toString(static_cast<short>(src>>16)) + "." + toString(static_cast<short>((src<<16)>>16));
}

template<class T>
std::string toStringInternal(T&& src, _long_long_print_tag)
{
    return toString(static_cast<int>(src>>32)) + "." + toString(static_cast<int>((src<<32)>>32));
}

template<size_t TIndex = 0, class ...Args>
std::string toStringInternal(std::tuple<Args...>&& src, _tuple_print_tag tag)
{
    if constexpr ((TIndex + 1) >= sizeof...(Args))
    {
        return toString(std::get<TIndex>(src));
    }
    else
    {
        return toString(std::get<TIndex>(src)) + "." + toStringInternal<TIndex + 1u>(std::forward<std::tuple<Args...>>(src), tag);
    }
}

template<class T>
std::string toStringInternal(T&& src, _string_print_tag)
{
    return std::forward<T>(src);
}

//! Join containers
template<class T>
std::string toStringInternal(T&& src, _iterable_print_tag)
{
    if (src.size() <= 0) {
        return "";
    }

    std::stringstream output;
    std::copy(src.begin(), std::prev(src.end()), std::ostream_iterator<typename std::remove_reference_t<T>::value_type>(output, "."));
    output << src.back();
    return output.str();
}

//! Entry point
template<class T>
std::string toString(T&& src)
{
    return toStringInternal(std::forward<T>(src), typename _print_traits<typename std::remove_reference_t<T>>::category());
}
