# Niflib
This project is a fork of Niftools's Niflib in order to build Niflib with v0.9 XML file.
(As NifTools projects looks inactive)

## Building
Cmake or Visual Studio.

**NOTE:** At this time only niflib_VS2019 is updated, after the build succeeded and the library is verified to work, I will drop Visual Studio project files and update the CMake file. 

## Contributing
Feel free to send a PR if niflib breaks on other platform, or check nifdocsys where the XML file
could be updated for supporting more Nif files

## List of changes
- Forked nifdocsys to correctly generate Niflib files
- Upgraded API to v0.9 (Changing variable names and types)
