# libDataStructures
A C data structures library. This is not a comprehensive library, it only
contains structures I have needed in my projects.

# Build and installation
The default installation path is ~/lib and ~/lib/include/libDataStructures,
this can be changed in the Makefile.
```
make clean all
make install
```

# Using in a project
Create `include` and `lib` directories in your project, copy the headers and
their parent folder into `include` and `libDataStructures.a` into the `lib`
directory.

Add the following to your gcc commands
```
-Llibs -Iinclude -lDataStructures
```
