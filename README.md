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

Run `make run ARGS="<args>"`

<args> = <basename> [-x sliceId outputName] [-d sliceI sliceJ outputIJ] []

`basename` is compulsory and you can use it to set the folder the files are in. Eg. `mri_raws/MRI`.  
`-x` extracts a single slice (image at `sliceId` in `slices`)
