#include <stdio.h>

int main() {
    int ax = 1;
    int cx = 0;
    int dx = 0;
    asm ("cpuid\n\t":
         "=a" (ax),
         "=c" (cx),
         "=d" (dx):
         "a" (1): "ebx"
    );
    int Model = (ax >> 4) & 15;
    int FamilyID = (ax >> 8) & 15;
    int ExtendedModelID = (ax >> 16) & 15;
    int ExtendedFamilyID = (ax >> 20) & 255;
    if (FamilyID == 6 || FamilyID == 15){
        Model = Model + (ExtendedModelID << 4);
    }
    if (FamilyID == 15){
        FamilyID = FamilyID + ExtendedFamilyID;
    }
    printf("family=%d model=%d ecx=0x%x edx=0x%x\n", FamilyID, Model, cx, dx);
    return 0;
}