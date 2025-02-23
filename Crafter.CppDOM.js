/*
Crafter.CppDOM
Copyright (C) 2025 Catcrafts
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

const decoder = new TextDecoder();

let memorycounter = -1;
const jsmemory = new Map();

function freeJs(ptr) {
    jsmemory.delete(ptr);
}

function getElementById(id, idLenght) {
    const obj = document.getElementById(decoder.decode(new Int8Array(window.crafter_webbuild_wasi.instance.exports.memory.buffer, id, idLenght)));
    jsmemory.set(++memorycounter, obj);
    return memorycounter;
}

function setInnerHTML(ptr, html, htmlLenght) {
    jsmemory.get(ptr).innerHTML = decoder.decode(new Int8Array(window.crafter_webbuild_wasi.instance.exports.memory.buffer, html, htmlLenght));
}

let env = {
    freeJs:freeJs,
    getElementById:getElementById,
    setInnerHTML:setInnerHTML,
}

if(window.crafter_webbuild_env){
    window.crafter_webbuild_env = {...crafter_webbuild_env, env};
} else {
    window.crafter_webbuild_env = env;
}
