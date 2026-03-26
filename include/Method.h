#pragma once

#include <string_view>
#include <optional>

enum class Method 
{
    GET
};

namespace MethodUtils 
{
    constexpr std::string_view MethodUtils::toString(Method m) noexcept
    std::optional<Method> MethodUtils::fromString(std::string_view str) noexcept;
}