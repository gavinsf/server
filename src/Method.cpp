#include "../include/Method.h"
#include <string_view>
#include <optional>

std::string_view MethodUtils::toString(Method m) noexcept
{
    switch (m)
    {
        case Method::GET:   return "GET";
        default:            return "";
    }
}

std::optional<Method> MethodUtils::fromString(std::string_view str) noexcept
{
    if (str == "GET")       return Method::GET;
    return std::nullopt
}