find_library(LUA_STATIC lua_static  PATHS ${PROJECT_SOURCE_DIR}/../external/lib/lua)
find_library(LUA_SOCKET luasocket  PATHS ${PROJECT_SOURCE_DIR}/../external/lib/lua)

set(SRC_CPP_FILES 
Debugger.cpp
Debugger.h
defines.h
main.cpp
test_asio.cpp
test_asio.h
)

add_executable(${PROJECT_NAME}
${SRC_CPP_FILES}
)

if(WIN32)
set(LUA_SOCKET_LINK_LIB ws2_32)
endif(WIN32)

target_link_libraries(${PROJECT_NAME}
${LUA_SOCKET} ${LUA_STATIC}  ${LUA_SOCKET_LINK_LIB}
)
