// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.


.assembly extern legacy library mscorlib {}
.assembly extern System.Console
{
  .publickeytoken = (B0 3F 5F 7F 11 D5 0A 3A )
  .ver 4:0:0:0
}
.assembly 'b71318' {}
.method public static int32 f1() cil managed
{
	.entrypoint
	.maxstack 1

	start_try3:
		leave.s OUT
	end_try3: //

	start_try:
		leave.s OUT
	end_try: //

	exception_filter:
    		pop
    		ldc.i4.1
    		endfilter
	start_filter:
		leave.s OUT
	end_filter: //

	start_handler:
		leave.s OUT
	end_handler:  //

	start_handler2:
		leave.s OUT
	end_handler2:  //

	start_fault3:
		endfault
	end_fault3: //
	OUT:
	    ldc.i4 100
		ret

	.try start_try to end_try
	filter exception_filter handler start_filter to end_filter
	catch [mscorlib]System.Exception handler start_handler to end_handler
	catch [mscorlib]System.Exception handler start_handler2 to end_handler2
	.try start_try3 to end_try3 fault handler start_fault3 to end_fault3
	
}
