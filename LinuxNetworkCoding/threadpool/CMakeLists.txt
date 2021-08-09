set(THREADPOOL_SRCS
condition.c
threadpool.c
)

add_library(THREADPOOL ${THREADPOOL_SRCS})
target_link_libraries(THREADPOOL pthread rt)
install(TARGETS THREADPOOL DESTINATION lib)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/LinuxNetworkCoding/threadpool)

if(CPPCOURSES_BUILD_EXAMPLES)
    add_subdirectory(tests)
endif()
