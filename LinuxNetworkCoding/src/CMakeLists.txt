set(SRCS
temp.cc
sysutil.cc
)

add_library(NetworkCoding ${SRCS})
install(TARGETS NetworkCoding DESTINATION lib)


file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/NetworkCoding/src)

if(CPPCOURSES_BUILD_EXAMPLES)
    add_subdirectory(tests)
    add_subdirectory(socket)
    add_subdirectory(IPC)
    add_subdirectory(POSIXIPC)
    add_subdirectory(pthread)
endif()
