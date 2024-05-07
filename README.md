# 3DViewer
Learning project in School 21 - realization in C++ programming language in OOP paradigm of an application for viewing 3D models in wireframe view, using design patterns.


The program for visualization of wireframe model in 3D space is developed in C++ language of C++17 standard. The program assembly is configured using Makefile with a standard set of targets for GNU programs: all, install, uninstall, clean, dvi, dist, tests. Full coverage of unit-tests of modules related to model loading and affine transformations is provided.

The program is designed according to the principles of object-oriented programming, using the MVC pattern, as well as the facade, strategy and singleton design patterns.

The program provides the ability to:

Load a wireframe model from an obj file (support for vertex and surface list only).
Move the model at a specified distance relative to the X, Y, Z axes.
Rotate the model by a specified angle relative to its X, Y, Z axes.
Scale the model by a specified value.
