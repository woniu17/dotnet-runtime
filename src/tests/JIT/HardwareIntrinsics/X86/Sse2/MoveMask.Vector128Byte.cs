// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

/******************************************************************************
 * This file is auto-generated from a template file by the GenerateTests.csx  *
 * script in tests\src\JIT\HardwareIntrinsics\X86\Shared. In order to make    *
 * changes, please update the corresponding template and run according to the *
 * directions listed in the file.                                             *
 ******************************************************************************/

using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Intrinsics;
using System.Runtime.Intrinsics.X86;
using JIT.HardwareIntrinsics.X86;
using Xunit;

namespace JIT.HardwareIntrinsics.X86._Sse2
{
    public static partial class Program
    {
        [Fact]
        public static void MoveMaskVector128Byte()
        {
            var test = new SimdScalarUnaryOpConvertTest__MoveMaskVector128Byte();

            if (test.IsSupported)
            {
                // Validates basic functionality works, using Unsafe.Read
                test.RunBasicScenario_UnsafeRead();

                if (Sse2.IsSupported)
                {
                    // Validates basic functionality works, using Load
                    test.RunBasicScenario_Load();

                    // Validates basic functionality works, using LoadAligned
                    test.RunBasicScenario_LoadAligned();
                }

                // Validates calling via reflection works, using Unsafe.Read
                test.RunReflectionScenario_UnsafeRead();

                if (Sse2.IsSupported)
                {
                    // Validates calling via reflection works, using Load
                    test.RunReflectionScenario_Load();

                    // Validates calling via reflection works, using LoadAligned
                    test.RunReflectionScenario_LoadAligned();
                }

                // Validates passing a static member works
                test.RunClsVarScenario();

                // Validates passing a local works, using Unsafe.Read
                test.RunLclVarScenario_UnsafeRead();

                if (Sse2.IsSupported)
                {
                    // Validates passing a local works, using Load
                    test.RunLclVarScenario_Load();

                    // Validates passing a local works, using LoadAligned
                    test.RunLclVarScenario_LoadAligned();
                }

                // Validates passing the field of a local class works
                test.RunClassLclFldScenario();

                // Validates passing an instance member of a class works
                test.RunClassFldScenario();

                // Validates passing the field of a local struct works
                test.RunStructLclFldScenario();

                // Validates passing an instance member of a struct works
                test.RunStructFldScenario();
            }
            else
            {
                // Validates we throw on unsupported hardware
                test.RunUnsupportedScenario();
            }

            if (!test.Succeeded)
            {
                throw new Exception("One or more scenarios did not complete as expected.");
            }
        }
    }

    public sealed unsafe class SimdScalarUnaryOpConvertTest__MoveMaskVector128Byte
    {
        private struct TestStruct
        {
            public Vector128<Byte> _fld;

            public static TestStruct Create()
            {
                var testStruct = new TestStruct();

                for (var i = 0; i < Op1ElementCount; i++) { _data[i] = TestLibrary.Generator.GetByte(); }
                Unsafe.CopyBlockUnaligned(ref Unsafe.As<Vector128<Byte>, byte>(ref testStruct._fld), ref Unsafe.As<Byte, byte>(ref _data[0]), (uint)Unsafe.SizeOf<Vector128<Byte>>());

                return testStruct;
            }

            public void RunStructFldScenario(SimdScalarUnaryOpConvertTest__MoveMaskVector128Byte testClass)
            {
                var result = Sse2.MoveMask(_fld);
                testClass.ValidateResult(_fld, result);
            }
        }

        private static readonly int LargestVectorSize = 16;

        private static readonly int Op1ElementCount = Unsafe.SizeOf<Vector128<Byte>>() / sizeof(Byte);

        private static Byte[] _data = new Byte[Op1ElementCount];

        private static Vector128<Byte> _clsVar;

        private Vector128<Byte> _fld;

        private SimdScalarUnaryOpTest__DataTable<Byte> _dataTable;

        static SimdScalarUnaryOpConvertTest__MoveMaskVector128Byte()
        {
            for (var i = 0; i < Op1ElementCount; i++) { _data[i] = TestLibrary.Generator.GetByte(); }
            Unsafe.CopyBlockUnaligned(ref Unsafe.As<Vector128<Byte>, byte>(ref _clsVar), ref Unsafe.As<Byte, byte>(ref _data[0]), (uint)Unsafe.SizeOf<Vector128<Byte>>());
        }

        public SimdScalarUnaryOpConvertTest__MoveMaskVector128Byte()
        {
            Succeeded = true;

            for (var i = 0; i < Op1ElementCount; i++) { _data[i] = TestLibrary.Generator.GetByte(); }
            Unsafe.CopyBlockUnaligned(ref Unsafe.As<Vector128<Byte>, byte>(ref _fld), ref Unsafe.As<Byte, byte>(ref _data[0]), (uint)Unsafe.SizeOf<Vector128<Byte>>());

            for (var i = 0; i < Op1ElementCount; i++) { _data[i] = TestLibrary.Generator.GetByte(); }
            _dataTable = new SimdScalarUnaryOpTest__DataTable<Byte>(_data, LargestVectorSize);
        }

        public bool IsSupported => Sse2.IsSupported;

        public bool Succeeded { get; set; }

        public void RunBasicScenario_UnsafeRead()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunBasicScenario_UnsafeRead));

            var result = Sse2.MoveMask(
                Unsafe.Read<Vector128<Byte>>(_dataTable.inArrayPtr)
            );

            ValidateResult(_dataTable.inArrayPtr, result);
        }

        public void RunBasicScenario_Load()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunBasicScenario_Load));

            var result = Sse2.MoveMask(
                Sse2.LoadVector128((Byte*)(_dataTable.inArrayPtr))
            );

            ValidateResult(_dataTable.inArrayPtr, result);
        }

        public void RunBasicScenario_LoadAligned()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunBasicScenario_LoadAligned));

            var result = Sse2.MoveMask(
                Sse2.LoadAlignedVector128((Byte*)(_dataTable.inArrayPtr))
            );

            ValidateResult(_dataTable.inArrayPtr, result);
        }

        public void RunReflectionScenario_UnsafeRead()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunReflectionScenario_UnsafeRead));

            var result = typeof(Sse2).GetMethod(nameof(Sse2.MoveMask), new Type[] { typeof(Vector128<Byte>) })
                                     .Invoke(null, new object[] {
                                        Unsafe.Read<Vector128<Byte>>(_dataTable.inArrayPtr)
                                     });

            ValidateResult(_dataTable.inArrayPtr, (Int32)(result));
        }

        public void RunReflectionScenario_Load()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunReflectionScenario_Load));

            var result = typeof(Sse2).GetMethod(nameof(Sse2.MoveMask), new Type[] { typeof(Vector128<Byte>) })
                                     .Invoke(null, new object[] {
                                        Sse2.LoadVector128((Byte*)(_dataTable.inArrayPtr))
                                     });

            ValidateResult(_dataTable.inArrayPtr, (Int32)(result));
        }

        public void RunReflectionScenario_LoadAligned()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunReflectionScenario_LoadAligned));

            var result = typeof(Sse2).GetMethod(nameof(Sse2.MoveMask), new Type[] { typeof(Vector128<Byte>) })
                                     .Invoke(null, new object[] {
                                        Sse2.LoadAlignedVector128((Byte*)(_dataTable.inArrayPtr))
                                     });

            ValidateResult(_dataTable.inArrayPtr, (Int32)(result));
        }

        public void RunClsVarScenario()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunClsVarScenario));

            var result = Sse2.MoveMask(
                _clsVar
            );

            ValidateResult(_clsVar, result);
        }

        public void RunLclVarScenario_UnsafeRead()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunLclVarScenario_UnsafeRead));

            var firstOp = Unsafe.Read<Vector128<Byte>>(_dataTable.inArrayPtr);
            var result = Sse2.MoveMask(firstOp);

            ValidateResult(firstOp, result);
        }

        public void RunLclVarScenario_Load()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunLclVarScenario_Load));

            var firstOp = Sse2.LoadVector128((Byte*)(_dataTable.inArrayPtr));
            var result = Sse2.MoveMask(firstOp);

            ValidateResult(firstOp, result);
        }

        public void RunLclVarScenario_LoadAligned()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunLclVarScenario_LoadAligned));

            var firstOp = Sse2.LoadAlignedVector128((Byte*)(_dataTable.inArrayPtr));
            var result = Sse2.MoveMask(firstOp);

            ValidateResult(firstOp, result);
        }

        public void RunClassLclFldScenario()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunClassLclFldScenario));

            var test = new SimdScalarUnaryOpConvertTest__MoveMaskVector128Byte();
            var result = Sse2.MoveMask(test._fld);

            ValidateResult(test._fld, result);
        }

        public void RunClassFldScenario()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunClassFldScenario));

            var result = Sse2.MoveMask(_fld);

            ValidateResult(_fld, result);
        }

        public void RunStructLclFldScenario()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunStructLclFldScenario));

            var test = TestStruct.Create();
            var result = Sse2.MoveMask(test._fld);

            ValidateResult(test._fld, result);
        }

        public void RunStructFldScenario()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunStructFldScenario));

            var test = TestStruct.Create();
            test.RunStructFldScenario(this);
        }

        public void RunUnsupportedScenario()
        {
            TestLibrary.TestFramework.BeginScenario(nameof(RunUnsupportedScenario));

            bool succeeded = false;

            try
            {
                RunBasicScenario_UnsafeRead();
            }
            catch (PlatformNotSupportedException)
            {
                succeeded = true;
            }

            if (!succeeded)
            {
                Succeeded = false;
            }
        }

        private void ValidateResult(Vector128<Byte> firstOp, Int32 result, [CallerMemberName] string method = "")
        {
            Byte[] inArray = new Byte[Op1ElementCount];
            Unsafe.WriteUnaligned(ref Unsafe.As<Byte, byte>(ref inArray[0]), firstOp);
            ValidateResult(inArray, result, method);
        }

        private void ValidateResult(void* firstOp, Int32 result, [CallerMemberName] string method = "")
        {
            Byte[] inArray = new Byte[Op1ElementCount];
            Unsafe.CopyBlockUnaligned(ref Unsafe.As<Byte, byte>(ref inArray[0]), ref Unsafe.AsRef<byte>(firstOp), (uint)Unsafe.SizeOf<Vector128<Byte>>());
            ValidateResult(inArray, result, method);
        }

        private void ValidateResult(Byte[] firstOp, Int32 result, [CallerMemberName] string method = "")
        {
            bool succeeded = true;

            if (((firstOp[0] & 128) == 0) != ((result & 1) == 0))
            {
                succeeded = false;
            }

            if (!succeeded)
            {
                TestLibrary.TestFramework.LogInformation($"{nameof(Sse2)}.{nameof(Sse2.MoveMask)}<Int32>(Vector128<Byte>): {method} failed:");
                TestLibrary.TestFramework.LogInformation($"  firstOp: ({string.Join(", ", firstOp)})");
                TestLibrary.TestFramework.LogInformation($"   result: result");
                TestLibrary.TestFramework.LogInformation(string.Empty);

                Succeeded = false;
            }
        }
    }
}
