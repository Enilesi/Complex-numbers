Set-Location ./build &&
cmake --build . &&
ctest --verbose &&
Set-Location ../