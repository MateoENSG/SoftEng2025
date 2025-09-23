set(target_name simtown)
add_library(${target_name} STATIC "")
target_sources(${target_name}
	PRIVATE "${PROJECT_SOURCE_DIR}/src/simtown/Building.cpp"
	PRIVATE "${PROJECT_SOURCE_DIR}/src/simtown/Rock.cpp"
	PRIVATE "${PROJECT_SOURCE_DIR}/include/simtown/building.h"
	PRIVATE "${PROJECT_SOURCE_DIR}/include/simtown/dyn_array.h"
	PRIVATE "${PROJECT_SOURCE_DIR}/include/simtown/rock.h"
)
target_include_directories(${target_name}
	PUBLIC
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
		$<INSTALL_INTERFACE:include>
)
export(TARGETS ${target_name} FILE ${PROJECT_BINARY_DIR}/${target_name}_target.cmake)

#install target lib
install(TARGETS ${target_name}
	EXPORT ${target_name}
	DESTINATION lib
)
#install target export
install(EXPORT ${target_name}
	FILE ${target_name}_target.cmake
	DESTINATION cmake/
)
#install includes
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION include/
)
#generated include
install(FILES ${PROJECT_BINARY_DIR}/HelloProjectConfig.h
	DESTINATION include/
)
