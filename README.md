# MCdata_fakes

This directory contains the code necessary to perform the MC data comparison for the background component of the low-pt electron identification algorithm output. The background component is represented by particles incorrectly classified as electrons (fake electrons), so the process B->J/Ψ(&mu;&mu;)K is studied and each particle identified as electron is considered a fake electron.

**MCfakes.C** studies a cut based selection to identify the process B->J/Ψ(&mu;&mu;)K and computes the distribution of the background component of the low-pt electron identification algorithm output.

**SIGfakes.C** implements the cut based selection studied on the MC and computes the distribution of the background component of the low-pt electron identification algorithm output.

To compile **SIGfakes.C** or **MCfakes.C** :

```
g++ -c SIGfakes.h $ROOTSYS/bin/root-config --libs --cflags
g++ -o SIGfakes.exe SIGfakes.cpp SIGfakes.C $ROOTSYS/bin/root-config --libs --cflags
./SIGfakes.exe name_of_the_ntupla
```
