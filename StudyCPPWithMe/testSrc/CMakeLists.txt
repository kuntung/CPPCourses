set(base_SRCS
Complex.cpp
Shape.cpp
)

add_library(StudyCPPWithMe ${base_SRCS})
install(TARGETS StudyCPPWithMe  DESTINATION lib)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/StudyCPPWithMe/testSrc)

if(CPPCOURSES_BUILD_EXAMPLES)
  add_subdirectory(tests)
endif()
