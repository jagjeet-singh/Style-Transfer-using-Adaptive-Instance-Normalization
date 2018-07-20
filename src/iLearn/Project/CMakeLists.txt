add_executable(Proj MACOSX_BUNDLE main.cpp)
add_subdirectory(utils)
target_link_libraries(Proj fslazywindow simplebitmap ysbitmapfont utility utils GL GLU X11)
