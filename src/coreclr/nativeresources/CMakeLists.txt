project(nativeresourcestring)

add_library_clr(nativeresourcestring STATIC resourcestring.cpp)
add_library_clr(nativeresourcestring_obj OBJECT resourcestring.cpp)

install_clr (TARGETS nativeresourcestring DESTINATIONS lib)
