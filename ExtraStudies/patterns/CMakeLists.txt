set(pattern_SRCS
Factory.cc
)

add_library(ExtraStudies ${pattern_SRCS})
install(TARGETS ExtraStudies DESTINATION lib)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/ExtraStudies/patterns)

#if(CPPCOURSES_BUILD_EXAMPLES)
#	add_subdirectory(tests)
#endif()
