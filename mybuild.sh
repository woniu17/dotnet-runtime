#!/usr/bin/env bash
DATA_PATH="/runtime/.nuget/packages/optimization.linux-x64.pgo.coreclr/99.99.99-master-20200806.6"
/runtime/eng/native/gen-buildsys.sh "/runtime/src/coreclr" \
    "/runtime/src/coreclr" "/runtime/artifacts/obj/coreclr/Linux.x64.Debug" \
    x64 clang "9" "" Debug ""  -DCLR_ENG_NATIVE_DIR="/runtime/eng/native" \
    -DCLR_CMAKE_PGO_INSTRUMENT=0 \
    -DCLR_CMAKE_OPTDATA_PATH=${DATA_PATH} \
    -DCLR_CMAKE_PGO_OPTIMIZE=1 -DCLR_REPO_ROOT_DIR="/runtime"

# cmake --build "/runtime/artifacts/obj/coreclr/Linux.x64.Debug" --verbose --target install -- -j 1
cmake --build "/runtime/artifacts/obj/coreclr/Linux.x64.Debug" --target install -- -j 4
# find / -name errno.h 2>/dev/null