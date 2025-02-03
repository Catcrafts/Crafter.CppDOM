/*
Crafter.Web
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
export module Crafter.Web:Canvas;
import :HtmlElement;

export namespace Crafter::Web {

    struct Pixel {
        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
        std::uint8_t a;
    };

    class Canvas : public Crafter::Web::HtmlElement {
    public:
        std::uint32_t width;
        std::uint32_t height;
        Canvas(std::uint32_t width, std::uint32_t height, std::string value = "", std::unordered_map<std::string, std::string> style = {}, std::vector<HtmlElement*> children = {}, std::unordered_map<std::string, std::string> attributes = {});
        void DrawRect(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height, std::string color);
        void SetBuffer(Pixel* buffer);
    };
}

