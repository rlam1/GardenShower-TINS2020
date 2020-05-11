# GardenShower-TINS2020
Entry for the Allegro.cc community TINS event for 2020

To build, make an **INPLACE** cmake build, using your favorite generator.

For a Windows build, you need to have:

1. A copy of [vcpkg](https://github.com/Microsoft/vcpkg) installed on your x64 VS DevEv.
2. The allegro5 package compiled from your x64 VS DevEnv.
3. `VCPKG_ROOT` environment variable defined in your system.
4. After compilation, copy the following DLLs from the `${VCPKG_ROOT}\installed\x64-windows\bin` directory:
	* zlib1.dll
	* libpng16.dll
	* freetype.dll
	* bz2.dll
	* allegro-5.2.dll
	* allegro_ttf-5.2.dll
	* allegro_primitives-5.2.dll
	* allegro_images-5.2.dll
	* allegro_font-5.2.dll
	* allegro_color-5.2.dll
	* allegro_audio-5.2.dll
	* allegro_acodec-5.2.dll
5. Run game.exe
6. Cry at how unbaked this is.

There is a scrolling prompt at the begining.

There are some flower sprites in the `/data` folder.

Windows binaries are here: [github.com/rlam1](https://github.com/rlam1/GardenShower-TINS2020/releases/tag/v0.0.1-alpha) 
