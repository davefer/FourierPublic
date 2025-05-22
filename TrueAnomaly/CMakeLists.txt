project(CFE_NEOCFS C)

set(APP_SRC_FILES
  fsw/src/neocfs.c
  fsw/src/neocfs_cmds.c
  fsw/src/neocfs_utils.c
)

if (CFE_EDS_ENABLED_BUILD)
  list(APPEND APP_SRC_FILES
    fsw/src/neocfs_eds_dispatch.c
  )
else()
  list(APPEND APP_SRC_FILES
    fsw/src/neocfs_dispatch.c
  )
endif()

# Create the app module
add_cfe_app(neocfs ${APP_SRC_FILES})

target_include_directories(neocfs PUBLIC fsw/inc)
# Include the public API from sample_lib to demonstrate how
# to call library-provided functions
add_cfe_app_dependency(neocfs sample_lib)

# Add table
add_cfe_tables(neocfs fsw/tables/neocfs_tbl.c)

# If UT is enabled, then add the tests from the subdirectory
# Note that this is an app, and therefore does not provide
# stub functions, as other entities would not typically make
# direct function calls into this application.
if (ENABLE_UNIT_TESTS)
  add_subdirectory(unit-test)
endif (ENABLE_UNIT_TESTS)
