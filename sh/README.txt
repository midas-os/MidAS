When running a script like setup-cross-build.sh make sure to test if it worked correctly.
This document will help you test the various Shell Scripts found in this folder.

setup-cross-build.sh
The script exports 3 variables, $PREFIX (creates), $TARGET (creates) and $PATH (modifies).
In order to run this script run:

echo $PREFIX

or

echo $TARGET

if you run the tests and the values are empty, you may have ran the script incorrectly.
Most-likely what happened is that you ran "./setup-cross-build.sh", which doesn't keep the exports persistent.
Instead what you should run is "source ./setup-cross-build.sh", that way the exported variables exist even after the script finishes running.

add-cross-cmp.sh
The script just adds a value to $PATH.
To test this, run the script and run:

$TARGET-gcc --version

afterwards.
If your terminal returns with an error, you need to run "source ./add-cross-cmp.sh" and try again.
