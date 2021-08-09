set(FIFO_SRCS
shmfifo.cc
)

add_library(SHMFIFO ${FIFO_SRCS})
install(TARGETS SHMFIFO DESTINATION lib)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/LinuxNetworkCoding/shmfifo)

if(CPPCOURSES_BUILD_EXAMPLES)
    add_subdirectory(tests)
endif()
