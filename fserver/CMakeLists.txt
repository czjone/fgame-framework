cmake_minimum_required(VERSION 3.5)
project(Fserver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(Core ../fserver Core/3Libs/yaml/include )

set(SOURCE_FILES main.cpp core/fsys.h Message/Message.cpp core/Buffer.cpp core/Event.cpp core/Ref.cpp server/Server.cpp core/Buffer.h core/Serialization.cpp core/Serialization.h core/Thread.cpp core/Thread.h core/IO.cpp core/IO.h core/Base64.cpp core/Base64.h core/MD5.cpp core/MD5.h Server/HandlerFilter.cpp Server/HandlerFilter.h core/Socket.cpp core/Socket.h)
add_executable(Fserver ${SOURCE_FILES})