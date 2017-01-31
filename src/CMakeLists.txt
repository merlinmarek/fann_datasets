add_executable(sin sin.cc)
add_executable(cos cos.cc)
set_target_properties(sin PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../bin)
set_target_properties(cos PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../bin)
