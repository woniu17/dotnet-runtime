// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

using System.Runtime.CompilerServices;

unsafe class Runtime_74117
{
    public unsafe static int Main()
    {
        byte a = 5;
        Problem(ref a, 0);
        return 100;
    }

    [MethodImpl(MethodImplOptions.NoInlining)]
    static byte GetByte() => 1;

    [MethodImpl(MethodImplOptions.NoInlining)]
    private static void Problem(ref byte x, int a)
    {
        JitUse(&a);
        Unsafe.Add(ref x, a) = GetByte();
    }

    [MethodImpl(MethodImplOptions.NoInlining)]
    public static void JitUse<T>(T* arg) where T : unmanaged { }
}