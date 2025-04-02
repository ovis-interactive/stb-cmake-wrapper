// This file is used to define the implementation of the libraries.
// E.g., stb_image requires that at least one source file includes the header "stb_image.h" with STB_IMAGE_IMPLEMENTATION
// defined. This wrapper would generate a target that includes this source file with STB_IMAGE_IMPLEMENTATION defined and
// STB_CMAKE_WRAPPER_LIBRARY_INCLUDE set to "stb_image.h"

// The library dxt needs memcpy but does not include it, so we include it here
#include "string.h"

#include STB_CMAKE_WRAPPER_LIBRARY_INCLUDE
