Zig cc is not ready yet!
========================

I love programming languages and tools and I like spending sometime every week to test and try what I can do using them in different ways. During the past 10 years you will notice that more programming languages try to provide a better replacement for C/C++. if you are interested in this idea these are a list of some programming 
languages that you could check or read about (I assume that you already know about Rust, D, Go, etc.)

- Jai (Under development)
	* https://www.youtube.com/watch?v=TH9VCN6UkyQ&list=PLmV5I2fxaiCKfxMBrNsU1kgKJXD3PkyxO
	* https://github.com/BSVino/JaiPrimer/blob/master/JaiPrimer.md
- Odin (https://odin-lang.org/)
- Zig (https://ziglang.org/)
- V (https://vlang.io/)
- Carbon (https://github.com/carbon-language/carbon-lang/blob/trunk/README.md)

I have access to the Jai programming language and it's really a GREAT STEP FORWARD IN THE RIGHT DIRECTION.

Odin is already here, released for public usage and have similar syntax to Jai.

V seems very attractive, but I can't use it in practice, everytime I try it or check C2V, I discover a lot of
errors and problems that stop me directly. I hope this situation could be changed in the future.

Carbon still in very early stages of development.

So, This post is about (Zig) and to be more specific it's not about the Zig programming languge itself. 

It's about (Zig CC) - a Powerful Drop-In Replacement for GCC/Clang

Reference: https://andrewkelley.me/post/zig-cc-powerful-drop-in-replacement-gcc-clang.html

Using Zig cc to build Ring
==========================

Once I discovered Zig cc, I said OK, let me add a batch file that build the Ring language using it.

We already test Ring implementation through (MSVC, GCC, Clang, etc.) because we target many platforms like Windows, Linux, macOS, Android and WebAssembly.

You will find the batch file used for building Ring Compiler/VM using Zig cc here: https://github.com/ring-lang/ring/blob/master/language/build/buildzig.bat

A strange bug! 
==============

After building Ring using Zig cc, the produced Ring executable suffer from a stange/funny bug






