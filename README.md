# stb cmake wrapper

The popular [stb libraries](https://github.com/nothings/stb) are a set of header-only libraries which are very easy to just copy and paste into existing codebases.
However, if you have already set up a cmake based project is sometimes convenient to have proper cmake targets for the individual libraries.
This wrapper creates cmake targets for each library that takes care of adding the actual implementation for the libraries, i.e., adding the proper `STB_(...)_IMPLEMENTATION` define.

## Fork

This is a fork to update the version of `stb`, fix some minor documentation issues, and update the cmake min target in the era of CMake 4.0 deprecating older versions.

## Consuming this library in cmake

After adding this wrapper to your project you have access to the `stb::LIBRARY_NAME` targets.
For example, to use the image library you simply add this to your cmake script:

```cmake
target_link_libraries(YOUR_TARGET PUBLIC stb::image)
```

## Adding the wrapper to your project

1. Via [CPM](https://github.com/cpm-cmake/CPM.cmake): simply add `CPMAddPackage("gh:vikhik/stb-cmake-wrapper@0.2")` to your cmake script.
2. Via git submodules: add a submodule to your repository and add `add_subdirectory(path/to/stb-cmake-wrapper)`.
3. Alternatively you can also copy and paste the contents of this repository.

## Library support

This list gives an overview of the currently supported libraries.
The libraries currently not supported by the wrapper are the ones needing additional defines to work (textedit, voxel_render, tilemap_editor, connected_components).

- [x] [stb::vorbis](https://github.com/nothings/stb/blob/master/stb_vorbis.c)
- [x] [stb::hexwave](https://github.com/nothings/stb/blob/master/stb_hexwave.h)
- [x] [stb::image](https://github.com/nothings/stb/blob/master/stb_image.h)
- [x] [stb::truetype](https://github.com/nothings/stb/blob/master/stb_truetype.h)
- [x] [stb::image_write](https://github.com/nothings/stb/blob/master/stb_image_write.h)
- [x] [stb::image_resize](https://github.com/nothings/stb/blob/master/stb_image_resize.h)
- [x] [stb::rect_pack](https://github.com/nothings/stb/blob/master/stb_rect_pack.h)
- [x] [stb::perlin](https://github.com/nothings/stb/blob/master/stb_perlin.h)
- [x] [stb::ds](https://github.com/nothings/stb/blob/master/stb_ds.h)
- [x] [stb::sprintf](https://github.com/nothings/stb/blob/master/stb_sprintf.h)
- [ ] [stb::textedit](https://github.com/nothings/stb/blob/master/stb_textedit.h)
- [ ] [stb::voxel_render](https://github.com/nothings/stb/blob/master/stb_voxel_render.h)
- [x] [stb::dxt](https://github.com/nothings/stb/blob/master/stb_dxt.h)
- [x] [stb::easy_font](https://github.com/nothings/stb/blob/master/stb_easy_font.h)
- [ ] [stb::tilemap_editor](https://github.com/nothings/stb/blob/master/stb_tilemap_editor.h)
- [x] [stb::herringbone_wang_tile](https://github.com/nothings/stb/blob/master/stb_herringbone_wang_tile.h)
- [x] [stb::c_lexer](https://github.com/nothings/stb/blob/master/stb_c_lexer.h)
- [x] [stb::divide](https://github.com/nothings/stb/blob/master/stb_divide.h)
- [ ] [stb::connected_components](https://github.com/nothings/stb/blob/master/stb_connected_components.h)
- [x] [stb::leakcheck](https://github.com/nothings/stb/blob/master/stb_leakcheck.h)
- [x] [stb::include](https://github.com/nothings/stb/blob/master/stb_include.h)

## License

[MIT](LICENSE)
