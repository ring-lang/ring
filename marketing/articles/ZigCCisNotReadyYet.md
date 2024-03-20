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

To discover it, At first run ring/language/tests/test.exe 

All of the tests PASS except one test!

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/articles/image/testringusingzigcc.png)

Assume that we have the next Ring program (test.ring)

	? 5--

Output

	4

If we have a valid Ring executable then using Ring test.ring -ic will generate the next byte code

	===========================================================================
 	Byte Code - Before Execution by the VM
	===========================================================================

     	PC              OPCode                 Data

      	1            LoadFunc           ringvm_see                   0
      	2               PushN             5.000000
      	3                  --
      	4               PushV
      	5                Call                    0
      	6         NoOperation
      	7           FreeStack

Now what we care about is that we have the (PushN) instruction that push the number five to the Stack then we have the decrement instruction (--) that decrese five to four then we print this result.

Using the wrong Ring executable produced by (Zig cc) will generate the next byte code!


	===========================================================================
 	Byte Code - Before Execution by the VM
	===========================================================================

	     PC              OPCode                 Data
	
	      1            LoadFunc           ringvm_see                   0
	      2               PushN             5.000000
	      3   AssignmentPointer
	      4                 Dup
	      5                 Dup
	      6               PushV
	      7               PushN            -1.000000
 	      8                 SUM                    0
 	      9         BeforeEqual                    9
 	     10         SetProperty                    0                   0
 	     11               PushV
 	     12                Call                    0
 	     13         NoOperation
 	     14           FreeStack

Executing such a wrong program will produce a runtime error instead of printing (4)

We will get the next message

	Line 1 Error (R34) : Variable is required for the assignment operation

So, why I am saying it's a funny bug?

Let's see what Zig cc did in a wrong way to have this result

In Ring implementation we have the next C code to generate the bytecode for increment/decrement operations (i.e. ++ and --)

	int nLastOperation,nMark,nMode,nValue  ;
	List *pMark  ;
	nLastOperation = ring_parser_icg_getlastoperation(pParser) ;
	pMark = ring_parser_icg_getactiveoperation(pParser);
	/* ++ & -- */
	if ( ring_parser_isoperator2(pParser,OP_INC) ) {
		// ... SOME CODE FOR THE INCREMENT OPERATION
	}
	else if ( ring_parser_isoperator2(pParser,OP_DEC) ) {
		// ... HERE WE HAVE OUR CODE FOR THE DECREMENT OPERATION
		ring_parser_nexttoken(pParser);
		switch ( nLastOperation ) {
			case ICO_LOADADDRESS :
				nMode = RING_PARSER_ICG_NORMALMM ;
				if ( pParser->nBracesCounter ) {
					nMode = RING_PARSER_ICG_USEASSIGNMENT ;
					nValue = -1.0 ;
				}
				break ;
			case ICO_LOADSUBADDRESS :
				nMode = RING_PARSER_ICG_USESETPROPERTY ;
				nValue = -1.0 ;
				break ;
			default :
				nMode = RING_PARSER_ICG_NORMALMM ;
		}
	}
	else {
		return RING_PARSER_FAIL ;
	}

So we have a simple SWITCH STATEMENT that check the value of (nLastOperation) and based on this value determine which byte code to generate.

Now, Look at this (nLastOperation = 29) while the value of (ICO_LOADSUBADDRESS = 19)
And Zig cc decided for some reason that this (29) IS EQUAL TO (19) and executed the code after 
(case ICO_LOADSUBADDRESS) which generated the SetProperty instruction
That's why we get a runtime error says (Variable is required for the assignment operation
) while we don't have an assignment operation at all!

For debugging you can add the next printf() statements before the switch statement

	printf("last op: %d before switch \n", nLastOperation);
	printf("ICO_LOADSUBADDRESS value %d before switch \n",ICO_LOADSUBADDRESS);

Output

	last op: 29 before switch
	ICO_LOADSUBADDRESS value 19 before switch

So this let us be sure about the bug in Zig cc that generated wrong code for switch statement.


Workaround!
===========

This is the funny part!

Just add a printf() after the switch statement like this

	printf("last op: %d after switch \n", nLastOperation);
	printf("ICO_LOADSUBADDRESS value %d after switch \n",ICO_LOADSUBADDRESS);

And for some reason, Zig cc will do the right thing because (nLastOperation) is used after the switch.

Another workaround is to avoid (-Ofast) flag when using (zig cc) which is unacceptable solution
because this will produce 10x slower Ring executable.

Final Comments
==============

All other compilers including Clang doesn't have this bug and produce valid Ring executable

This is important to know, because many people think that Zig cc is just a Clang wrapper

So this is the summary: IMHO, DON'T USE ZIG CC IN PRODUCTION, IT'S NOT THE SAME AS CLANG




