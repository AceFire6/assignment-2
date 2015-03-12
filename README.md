CSC3022H - Assignment 2: Binary File Reading & Vector Manipulation
----
---

**Name**: Jethro Muller  
**Student Number**: MLLJET001  
**Date**: 12/03/2015  

---

### Installation:

1. Navigate to the root `assignment-2` directory.
2. Run `make` to build the executable.


### Usage:

Run `make run ARGS="<args>"` to run the program.

`<args>` = <basename> [-x sliceId outputName] [-d sliceI sliceJ outputName] [-g rowIndex]

* `<basename>` is compulsory and you can use it to set the folder the files are in. Eg. `mri_raws/MRI`.

***NOTE: Only one of these flags can be run at a time.*** 

* For `[-x sliceId outputName]`  
    * `-x` extracts a single slice (image at `sliceId` in `slices`).
    * `sliceId` specifies which image to extract from `slices`.
    * `outputName` is the basename of the output raw and `.dat` file.
* For `[-d sliceI sliceJ outputName]`
    * `-d` creates a diffmap between two slices.
    * `sliceI` and `sliceJ` specify which two slices to do the diffmap between.
    * `outputName` is the basename of the output raw and `.dat` file.
* For `[-g rowIndex]`
    * `-g` creates a cross-section of the image in a certain row. It extracts a specified row of bytes from every image.
    * `rowIndex` specifies which row to take from each image.

Run `make clean` to delete all artifacts of `make` and `make run`.


### File Definitions

* `src/main.cpp`
    * The driver file for the program. It creates an instance of `Volimage` that calls `readImages()`. It also parses
    the command line arguments.
* `src/volimage.h`
    * Defines the `Volimage` class and its functions.
* `src/volimage.cpp`
    * Implements all the functions defined the volimage header file.
* `build/mri_raws/*.raw`
    * Given raw files from an MRI scan.
* `build/mri_raws/MRI.dat`
    * .dat file that specifies the width and height of all the MRI raw files and the number of raw files in `mri_raws/`.
* `diffmap.py`
    * Provided python code to create a diffmap to debug.
* `viewer.py`
    * Provided python code to view the raw files.
