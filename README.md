# DPP-UE-CodeGen
This is a C++ executable that will pre-generate all the code for DPP-UE.

## How does this work?

This reads all the D++ code located in the `include/DPP` directory and begins to create a function, for Unreal Engine, from that code.
The function that is creates is then inserted into `gencode/`. A GitHub Action for DPP-UE will then automatically the DPP-UE repository.

## Is the code unit-tested?

No. The code that is generated from this script is not tested by GitHub Actions, nor Jenkins. This is because it would require too much work.

It is expected that the code, that is generated from this, will work straight out the box. An initial Proof Of Concept was done before this,
allowing me to understand what exactly needed to be different. From here, it should be as simple as that (and quite possibly refining).

## How to generate the code

**You should only execute this on Linux.**

Clone the project and then run `cmake -B build`. Then run `cmake --build build`. Once that's done, do `cd build`, you should see `CodeGen`.
You can now do `./CodeGen` to run the program.

The program expects to be ran the build directory, if it is not, then it will simply abort.

DPP-UE-CodeGen will seek to regenerate all the code, which could take a bit. This is just the easiest way to do this, otherwise more problems get introduced
if the program needs to start checking if something already exists,  if the data isn't valid anymore, etc.

## Other notes

This project uses the C++17 standard and will only ever update if Unreal Engine updates.

If D++ updates to C++20 before Unreal Engine (which is very likely, but will not happen for the next few years),
then DPP-UE will simply not function anymore until Unreal Engine updates.