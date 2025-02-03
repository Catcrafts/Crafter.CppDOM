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

function setInnerHTML(id, idLenght, html, htmlLenght) {
    const decoder = new TextDecoder();
    document.getElementById(decoder.decode(new Int8Array(window.crafter_webbuild_wasi.instance.exports.memory.buffer, id, idLenght))).innerHTML = decoder.decode(new Int8Array(window.crafter_webbuild_wasi.instance.exports.memory.buffer, html, htmlLenght));
}

function strokeRect(id, x, y, width, height, color, colorLenght) {
    const decoder = new TextDecoder();
    const canvas = document.getElementById(id.toString());
    const ctx = canvas.getContext("2d");
    ctx.strokeStyle = decoder.decode(new Int8Array(window.crafter_webbuild_wasi.instance.exports.memory.buffer, color, colorLenght));
    ctx.strokeRect(x, y, width, height);
}

function putImageData(id, buffer, width, height) {
    const decoder = new TextDecoder();
    const canvas = document.getElementById(id.toString());
    const ctx = canvas.getContext("2d");
    const view = new Uint8ClampedArray(window.crafter_webbuild_wasi.instance.exports.memory.buffer, buffer, 640*360*4);
    const imageData = new ImageData(view, 640, 360);
    ctx.putImageData(imageData, 0, 0);
}

function draw(id, x, y, text, textLenght){
    const decoder = new TextDecoder();
    const canvas = document.getElementById("1");
    let ctx = canvas.getContext("2d")

    ctx.fillStyle = "red";
    ctx.font = '20px sans-serif';

    var textString = decoder.decode(new Int8Array(window.crafter_webbuild_wasi.instance.exports.memory.buffer, text, textLenght))
    let textWidth = ctx.measureText(textString).width;

    ctx.fillText(textString , x - (textWidth / 2), y);
}

function setTimeoutt(obj, time, callback) {
    setTimeout(() => {
        window.crafter_webbuild_wasi.instance.exports.__indirect_function_table.get(callback)(obj);
    }, time);
}

function addEventListener(id, eventId, listener) {

}

function fetchh(obj, url, urlLenght, buffer, callback) {
    const decoder = new TextDecoder();
    const view = new Uint8Array(window.crafter_webbuild_wasi.instance.exports.memory.buffer, buffer);
    fetch(decoder.decode(new Int8Array(window.crafter_webbuild_wasi.instance.exports.memory.buffer, url, urlLenght)), {
        // Adding Get request
        method: "GET",

        // Setting headers
        headers: {
            'Content-Type': 'application/octet-stream',
        },
        // Setting response type to arraybuffer
        responseType: "arraybuffer"
    }).then(x => x.arrayBuffer()).then(
        y => {
            const outputBytes = new Uint8Array(y);
            for(let i = 0; i < outputBytes.length; i++) {
                view[i] = outputBytes[i]
            }
            window.crafter_webbuild_wasi.instance.exports.__indirect_function_table.get(callback)(obj, outputBytes.length, buffer);
        }
    );
    return 1;
}


let env = {
    setInnerHTML:setInnerHTML,
    addEventListener:addEventListener,
    strokeRect:strokeRect,
    fetch:fetchh,
    putImageData:putImageData,
    setTimeout:setTimeoutt,
    draw:draw
}

if(window.crafter_webbuild_env){
    window.crafter_webbuild_env = {...crafter_webbuild_env, env};
} else {
    window.crafter_webbuild_env = env;
}
