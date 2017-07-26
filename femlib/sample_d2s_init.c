/*! \file init.c
 *
 * \author Charisee
 */

/*
 * This code is part of the Diderot Project (http://diderot-language.cs.uchicago.edu)
 *
 * COPYRIGHT (c) 2015 The University of Chicago
 * All rights reserved.
 */

#include "sample_d2s.h"
#include <unistd.h>
#include "teem/air.h"

void WriteFile(Nrrd *nData, int type, char *Outfile){
    if(type == 0){
        if(nrrdSave(Outfile, nData, NULL)) {
            exit(1);
        }
    }
    else{
        Nrrd *ntmp = nrrdNew();
        nrrdQuantize(ntmp, nData, NULL, 8);
        nrrdSave(Outfile, ntmp, NULL);
    }
    nrrdNuke(nData);
    return;
}

//struct Function;
void callDiderot(char *Outfile, int type, void *valM, int imgResU,int imgResV,  float stepSize){
  
    sample_d2s_world_t *wrld = sample_d2s_New ();
    
    if (wrld == 0) {
	//fprintf (stderr, "Unable to create Diderot world\n");
	exit (1);
    }
    
    sample_d2s_Init (wrld);//initialize it.
    //initialize input vars
    sample_d2s_input_set_m (wrld, valM);
    sample_d2s_input_set_stepSize(wrld,stepSize);
    sample_d2s_input_set_imgResU(wrld,imgResU);
    sample_d2s_input_set_imgResV(wrld,imgResV);
    
    // nrrd for getting computational state
    Nrrd *nData = nrrdNew();
    
    if (sample_d2s_Initially (wrld)) {//intialize set of strands
        // error
	fprintf(stderr, "Error initializing world: %s", sample_d2s_GetErrors(wrld));
	exit(1);
    }
    int nSteps = sample_d2s_Run (wrld, 0);
    //second paramter is the limit to # of steps.
    //0-to termination
    
    // change here for output var
    if (sample_d2s_OutputGet_out(wrld, nData)) {
        // error
	fprintf(stderr, "Error getting nrrd data: %s", sample_d2s_GetErrors(wrld));
	exit(1);
    }

    WriteFile(nData, type, Outfile);
    sample_d2s_Shutdown (wrld);

}
//
