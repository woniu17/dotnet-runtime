// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

.assembly extern legacy library mscorlib {}
.assembly extern System.Console
{
  .publickeytoken = (B0 3F 5F 7F 11 D5 0A 3A )
  .ver 4:0:0:0
}
.assembly 'b25815' {}
.class ILGEN_0xf07bd440 {

.method static int32 main() {
.entrypoint
.maxstack	10

 .locals (int32 local_0xe, int32 ecode)
 
 ldc.i4.1
 stloc ecode
 .try {
 
 ldc.i4 0x10000001 
 stloc local_0xe

 ldloc local_0xe
 ldc.i4 0x10 
 mul.ovf

 pop
 leave xx
 } catch [mscorlib]System.OverflowException {
 pop
 ldc.i4.0
 stloc ecode
 leave xx
 }
 
xx:
 ldloc ecode
ldc.i4 100
add
 ret

}
}
