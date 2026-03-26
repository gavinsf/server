#pragma once

enum class Method {
    GET
};

namespace MethodUtils {
    const std::string toString(Method m);
    Method MethodUtils::fromString(const std::string& str);
}