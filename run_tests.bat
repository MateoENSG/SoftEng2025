IF NOT EXIST ".\Build" (
	mkdir .\Build
)
cd Build
cmake ..
cmake --build . Debug
ctest -C Debug
cd ..