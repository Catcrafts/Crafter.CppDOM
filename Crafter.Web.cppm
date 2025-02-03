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
#include <cstddef>
#include <cstdint>
#include <cstdlib>
export module Crafter.Web;
export import :HtmlElement;
export import :Canvas;

extern "C" {
    void __cxa_allocate_exception() {

    }

    void __cxa_throw(int, int, int) {

    }
}



export namespace Crafter::Web::Bindings {
    __attribute__((import_module("env"), import_name("setInnerHTML"))) void SetInnerHTML(const char* id, std::size_t idLenght, const char* html, std::size_t htmlLenght);
    __attribute__((import_module("env"), import_name("strokeRect"))) void StrokeRect(std::uint64_t id, std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height, const char* color, std::size_t colorLenght);
    __attribute__((import_module("env"), import_name("putImageData"))) void PutImageData(std::uint64_t id, Crafter::Web::Pixel* buffer, std::uint32_t width, std::uint32_t height);
    __attribute__((import_module("env"), import_name("fetch"))) void Fetch(void* obj, const char* url, std::size_t urlCallback, char* buffer, void (*listener)(void* obj, std::uint32_t, char*));
    __attribute__((import_module("env"), import_name("setTimeout"))) void SetTimeout(void* obj, std::uint32_t time, void (*listener)(void* obj));
    __attribute__((import_module("env"), import_name("draw"))) void Draw(std::uint64_t id, std::uint32_t x, std::uint32_t y, const char* text, std::uint32_t textLenght);
    //__attribute__((import_module("env"), import_name("addEventListener"))) void AddEventListener(std::string id, std::string eventId, void (*listener)(void));
}

