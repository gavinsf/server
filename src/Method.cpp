#include "../include/Method.h"


const std::string MethodUtils::toString(Method m)
{
    switch (m)
    {
        case Method::GET:   return "GET";
        default:            return "";
    }
}

Method MethodUtils::fromString(const std::string& str)
{
    if (str == MethodUtils::toString(Method::GET))
    {
        return Method::Get
    }
}