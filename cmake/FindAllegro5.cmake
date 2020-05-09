#[=======================================================================[.rst
FindAllegro5
------------

Locates the Allegro 5 library installed on the system. Supports optional
selection of individual modules.

Imported targets
^^^^^^^^^^^^^^^^

This module defines the following :prop_tgt:`IMPORTED` targets:

``Allegro5::Allegro5``
  The Allegro 5 library, if found.

``Allegro5::YYY``
The Allegro 5 YYY component, if requested component is found. Defined for each
individual component.

If no individual component is specified, all of them will be searched for by
default.

Result variables
^^^^^^^^^^^^^^^^

This module will set the following variables in your project:

``Allegro5_INCLUDE_DIRS``
  Where to find allegro.h, etc.
``Allegro5_LIBRARIES``
  The libraries to link against to use Allegro.
``Allegro5_ROOT_DIR``
  Base directory to find standard Unix Allegro structure.
``Allegro5_FOUND``
  If false, do not try to use Allegro.
``Allegro5_VERSION_STRING``
  The version of the Allegro library found.

Configuration flags
^^^^^^^^^^^^^^^^^^^

This module's behavior can be modified with the following flags:

NONE at the moment. Maybe include monolith here

# TODO: 
	FindGTK2.cmake has very good usage examples of MODULE component handling and detection.

 #]=======================================================================]

# Include this early to provide failure message signature capability.
include(FindPackageHandleStandardArgs)

# find_package(Allegro5 CONFIG QUIET)
# if(Allegro5_FOUND)
# 	find_package_handle_standard_args(Allegro5 DEFAULT_MSG Allegro5_CONFIG)
# 	return()
# endif()

# List of standard Add-ons as of 5.2.6
set(Allegro5_ADDON_LIST
	acodec
	audio
	color
	dialog
	font
	image
	main
	memfile
	physfs
	primitives
	ttf
	video)

# Find include directory and main module.
find_path(Allegro5_INCLUDE_DIR
	NAMES allegro5/allegro.h allegro5/allegro5.h
	DOC "Include directory for the Allegro 5 multimedia frameword.")
find_library(Allegro5_LIBRARY
	NAMES allegro allegro5 allegro-5
	DOC "Main library file for the Allegro 5 multimedia framework.")

if(NOT TARGET Allegro5::Allegro5) # TODO: Missing check to see if we really found PATHS! See commit dbe8e135b85a6ff37cf62c6660273ebf429fc1a2
	add_library(Allegro5::Allegro5 UNKNOWN IMPORTED)
	target_include_directories(Allegro5::Allegro5
	INTERFACE ${Allegro5_INCLUDE_DIR})

	set_target_properties(Allegro5::Allegro5 PROPERTIES
		IMPORTED_LOCATION ${Allegro5_LIBRARY}
		IMPORTED_IMPLIB ${Allegro5_LIBRARY})
endif()

# Find Add-ons
if(${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS) # This should be Allegro5
	foreach(Allegro5_ADDON IN LISTS ${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS)
		find_library(Allegro5_${Allegro5_ADDON}_LIBRARY
			NAMES allegro_${Allegro5_ADDON} liballegro_${Allegro5_ADDON}
					allegro5_${Allegro5_ADDON} liballegro5_${Allegro5_ADDON}
			DOC "${Allegro5_ADDON} library file.")

		if(NOT TARGET Allegro5::${Allegro5_ADDON}) # TODO: Missing check to see if we really found PATHS! See commit dbe8e135b85a6ff37cf62c6660273ebf429fc1a2

			set(Allegro5_${Allegro_ADDON}_FOUND TRUE)
			message("Found ${Allegro5_${Allegro5_ADDON}_LIBRARY}")

			add_library(Allegro5::${Allegro5_ADDON} UNKNOWN IMPORTED)
			target_include_directories(Allegro5::${Allegro5_ADDON}
				INTERFACE ${Allegro5_INCLUDE_DIR})

			set_target_properties(Allegro5::${Allegro5_ADDON} PROPERTIES
				IMPORTED_LOCATION ${Allegro5_${Allegro5_ADDON}_LIBRARY}
				IMPORTED_IMPLIB ${Allegro5_${Allegro5_ADDON}_LIBRARY})
		endif()
	endforeach()
else() # Load all the known Add-ons
	foreach(Allegro5_ADDON IN LISTS Allegro5_ADDON_LIST)
		find_library(Allegro5_${Allegro5_ADDON}_LIBRARY
			NAMES allegro_${Allegro5_ADDON} liballegro_${Allegro5_ADDON}
					allegro5_${Allegro5_ADDON} liballegro5_${Allegro5_ADDON}
			DOC "${Allegro5_ADDON} library file.")

		if(NOT TARGET Allegro5::${Allegro5_ADDON}) # TODO: Missing check to see if we really found PATHS! See commit dbe8e135b85a6ff37cf62c6660273ebf429fc1a2

			set(${CMAKE_FIND_PACKAGE_NAME}_${Allegro5_ADDON}_FOUND TRUE) # TODO: Find out why components are currently not being recognized.

			add_library(Allegro5::${Allegro5_ADDON} UNKNOWN IMPORTED)
			target_include_directories(Allegro5::${Allegro5_ADDON}
				INTERFACE ${Allegro5_INCLUDE_DIR})

			set_target_properties(Allegro5::${Allegro5_ADDON} PROPERTIES
				IMPORTED_LOCATION ${Allegro5_${Allegro5_ADDON}_LIBRARY}
				IMPORTED_IMPLIB ${Allegro5_${Allegro5_ADDON}_LIBRARY})
		endif()
	endforeach()
endif()

find_package_handle_standard_args(Allegro5
	REQUIRED_VARS Allegro5_INCLUDE_DIR Allegro5_LIBRARY)
