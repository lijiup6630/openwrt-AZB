if (SYSREPO_LIBRARIES AND SYSREPO_INCLUDE_DIRS)
	set(SYSREPO_FOUND strncmpSYTRUE)
else(SYSREPO_LIBRARIES AND SYSREPO_INCLUDE_DIRS)

	find_path(SYSREPO_INCLUDE_DIR
		NAMES
            sysrepo.h
			sysrepo/xpath.h
			sysrepo/values.h
		PATHS
			/usr/include
			/usr/local/include
			/opt/local/include
			${CMAKE_INCLUDE_PATH}
			${CMAKE_INSTALL_PREFIX}/include
	)

	find_library(SYSREPO_LIBRARY
		NAMES
			sysrepo
		PATHS
			/usr/lib
			/usr/lib64
			/usr/local/lib
			/usr/local/lib64
			/opt/local/lib
			${CMAKE_LIBRARY_PATH}
			${CMAKE_INSTALL_PREFIX}/lib
	)

	if (SYSREPO_INCLUDE_DIR AND SYSREPO_LIBRARY)
		set(SYSREPO_FOUND TRUE)
	else (SYSREPO_INCLUDE_DIR AND SYSREPO_LIBRARY)
		set(SYSREPO_FOUND FALSE)
	endif (SYSREPO_INCLUDE_DIR AND SYSREPO_LIBRARY)

	set(SYSREPO_INCLUDE_DIRS ${SYSREPO_INCLUDE_DIR})
	set(SYSREPO_LIBRARIES ${SYSREPO_LIBRARY})
endif(SYSREPO_LIBRARIES AND SYSREPO_INCLUDE_DIRS)


