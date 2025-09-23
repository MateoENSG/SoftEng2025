#add the executable target named HelloWorld
add_executable(HelloWorld hello.cpp)
target_link_libraries(HelloWorld PRIVATE basic)
install(TARGETS HelloWorld DESTINATION bin)

#add the executable target named SimTown2025
add_executable(SimTown2025 SimTown_main.cpp)
target_link_libraries(SimTown2025 PUBLIC simtown)
install(TARGETS SimTown2025 DESTINATION bin)