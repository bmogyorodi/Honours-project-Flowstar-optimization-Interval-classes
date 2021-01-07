Honors project material

Implementation:
Contains 3 folders with 3 Interval cpp and header files
Each is modified version of original Flow* interval.ccp and interval.h
( under double, most of the code was rewritten by Kristian Liiva, my contribution is methods: sin(), cos() and other minor debugging.)

accuracy_comparison_test:

Testing different outputs of different versions
to use type "make" to compile tests after entering each folder except outputs.
use Accuracy_test.py to run each version for comparison
outputs - contains output from functions dump(), tostring(), and output() for all versions
./Tester command can be used to run test one specific version (print outs in hex format)

operation_runtime_test

ModeSwitchTest - gives average runtime for intermediate operations like mode switching and sse shuffling etc.
type "make" to compile tests in other directories to run tests
After that using Runtimetest.py will run all operation testing (+,-,*,/,sin,cos)

flowstar_runtime_test

Contains 4 versions of Flowstar using different interval classes (originaltest,doubleinttest,minusdoubleinttest(opposite trick), and sse_version)
type "make" to compile flowstar (type command "scl enable devtoolset-7 bash" before using "make")
run flowstar of model by typing /wantedverion/./flowstar < models/wantedmodelfilename.model
run all versions on all files in models by using flowtimes.py (returns user runtime of each run of flowstar for each version)
outputs - contain output plotfiles for each run (seperated by version for comparison)
