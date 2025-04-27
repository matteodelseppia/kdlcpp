#pragma once

namespace kdlcpp::detail::tokens {

// clang format off

constexpr const char* $true  = "#true";
constexpr const char* $false = "#false";
constexpr const char* $null  = "#null";
constexpr const char $quote  = '\"';
constexpr const char $equal  = '=';
constexpr const char $space  = ' ';
constexpr const char $lbrace = '{';
constexpr const char $rbrace = '}';
constexpr const char $newln  = '\n';
constexpr const char $slash  = '/';

// clang format on

} // namespace kdlcpp::detail::tokens