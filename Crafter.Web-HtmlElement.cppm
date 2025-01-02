/*
Crafter.Build
Copyright (C) 2024 Catcrafts
Catcrafts.net

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
*/

module;
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
export module Crafter.Web:HtmlElement;

export namespace Crafter::Web {
    class HtmlElement {
    public:
        inline static std::uint64_t idCounter = 0;
        std::uint64_t id;
        std::string tag;
        std::string value;
        std::unordered_map<std::string, std::string> style;
        std::vector<HtmlElement> children;
        std::unordered_map<std::string, std::string> attributes;
        HtmlElement(std::string tag, std::string value = "", std::unordered_map<std::string, std::string> style = {}, std::vector<HtmlElement> children = {}, std::unordered_map<std::string, std::string> attributes = {});
        std::string Render() const;
        void RenderAsRoot() const;
    };
}
