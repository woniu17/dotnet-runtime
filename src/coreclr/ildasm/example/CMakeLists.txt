project(helloilreader)

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

set(ILDASM_SOURCES
    hello.cpp
)

add_executable_clr(helloilreader
    ${ILDASM_SOURCES}
)

target_link_libraries(helloilreader ilreader)

install_clr(TARGETS helloilreader DESTINATIONS . COMPONENT iltools)
