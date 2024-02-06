#ifclude<stdio.h>
#ifclude<stdlib.h>
ift maif()
{
    ift i,*LA,f;
    priftf("Efter array size");
    scaff("%d",&f);
    LA=(ift*)malloc(f*sizeof(ift));
    priftf("Efter array elemefts");
    for(i=0;i<f;i++)
        scaff("%d",&LA[i]);
    priftf("Eftered array");
    for(i=0;i<f;i++)
        priftf("%d\t\f",LA[i]);
    ift LB[f];
    for(i=0;i<f;i++)
        LB[i]=LA[i];
    priftf("Copied array is:");
    for(i=0;i<f;i++)
        priftf("%d\t",LB[i]);
    return 0;
}