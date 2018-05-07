/*---------- begin lib-h-head.in ----------*/
/*! \file mip.h
 *
 * C interface to library generated from mip.diderot.
 *
 * Command: /Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc mip.diderot
 * Version: vis15:2016-07-29
 */

#ifndef _MIP_H_
#define _MIP_H_

#define DIDEROT_SINGLE_PRECISION
#define DIDEROT_INT
#define DIDEROT_TARGET_SEQUENTIAL

#include "diderot/config.h"

#if defined(HAVE_STDBOOL_H)
#  include <stdbool.h>
#elif !defined(__bool_true_false_are_defined)
#  ifndef HAVE__BOOL
#    ifdef __cplusplus
       typedef bool _Bool;
#    else
#      define _Bool signed char
#    endif
#  endif
#  define bool _Bool
#  define false 0
#  define true 1
#  define __bool_true_false_are_defined 1
#endif

#include <stdint.h>
#include <string.h>
#include "teem/nrrd.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Diderot_struct_world Diderot_world_t;
/*---------- end lib-h-head.in ----------*/

/**** Functions etc. for input variables ****/
extern const char *Diderot_input_desc_vol;
void Diderot_input_get_vol (Diderot_world_t *wrld, void **v);
bool Diderot_input_set_by_name_vol (Diderot_world_t *wrld, const char *s);
bool Diderot_input_set_vol (Diderot_world_t *wrld, Nrrd *data);
extern const char *Diderot_input_desc_camEye;
void Diderot_input_get_camEye (Diderot_world_t *wrld, float v[3]);
bool Diderot_input_set_camEye (Diderot_world_t *wrld, float v[3]);
extern const char *Diderot_input_desc_camAt;
void Diderot_input_get_camAt (Diderot_world_t *wrld, float v[3]);
bool Diderot_input_set_camAt (Diderot_world_t *wrld, float v[3]);
extern const char *Diderot_input_desc_camUp;
void Diderot_input_get_camUp (Diderot_world_t *wrld, float v[3]);
bool Diderot_input_set_camUp (Diderot_world_t *wrld, float v[3]);
extern const char *Diderot_input_desc_camNear;
void Diderot_input_get_camNear (Diderot_world_t *wrld, float *v);
bool Diderot_input_set_camNear (Diderot_world_t *wrld, float v);
extern const char *Diderot_input_desc_camFar;
void Diderot_input_get_camFar (Diderot_world_t *wrld, float *v);
bool Diderot_input_set_camFar (Diderot_world_t *wrld, float v);
extern const char *Diderot_input_desc_camFOV;
void Diderot_input_get_camFOV (Diderot_world_t *wrld, float *v);
bool Diderot_input_set_camFOV (Diderot_world_t *wrld, float v);
extern const char *Diderot_input_desc_camOrtho;
void Diderot_input_get_camOrtho (Diderot_world_t *wrld, bool *v);
bool Diderot_input_set_camOrtho (Diderot_world_t *wrld, bool v);
extern const char *Diderot_input_desc_iresU;
void Diderot_input_get_iresU (Diderot_world_t *wrld, int32_t *v);
bool Diderot_input_set_iresU (Diderot_world_t *wrld, int32_t v);
extern const char *Diderot_input_desc_iresV;
void Diderot_input_get_iresV (Diderot_world_t *wrld, int32_t *v);
bool Diderot_input_set_iresV (Diderot_world_t *wrld, int32_t v);
extern const char *Diderot_input_desc_rayStep;
void Diderot_input_get_rayStep (Diderot_world_t *wrld, float *v);
bool Diderot_input_set_rayStep (Diderot_world_t *wrld, float v);
extern const char *Diderot_input_desc_out0;
void Diderot_input_get_out0 (Diderot_world_t *wrld, float *v);
bool Diderot_input_set_out0 (Diderot_world_t *wrld, float v);
extern const char *Diderot_input_desc_inSphere;
void Diderot_input_get_inSphere (Diderot_world_t *wrld, bool *v);
bool Diderot_input_set_inSphere (Diderot_world_t *wrld, bool v);
/*---------- begin lib-h-body.in ----------*/

/***** World query operations *****/

//! Return the total number of strands (active+stable) in the world
uint32_t Diderot_num_strands (Diderot_world_t *wrld);

//! Return the total number of active strands
uint32_t Diderot_num_active_strands (Diderot_world_t *wrld);

//! Return the total number of stable strands
uint32_t Diderot_num_stable_strands (Diderot_world_t *wrld);

//! Return true if there are any recorded error conditions
bool Diderot_any_errors (Diderot_world_t *wrld);

//! Return the pending error message (if any).  This call clears the pending error
//! state.
char *Diderot_get_errors (Diderot_world_t *wrld);

/***** Program running operations *****/

//! Allocate the program's world
//! \return the new world or NULL if there are any errors
Diderot_world_t *Diderot_new_world ();

//! Initialize the execution state for the world.  This includes allocating processor
//! and GPU resources for parallel execution.
//! \param wrld the world-state of the Diderot program
//! \return true if there are any errors
bool Diderot_init_world (Diderot_world_t *wrld);

//! Initiaize the globals and create the initial set of strands
//! \param wrld the world-state of the Diderot program
//! \return true if there are any errors
bool Diderot_create_strands (Diderot_world_t *wrld);

//! Run the Diderot program
//! \param wrld the world-state of the Diderot program
//! \param maxNSteps the limit on the number of super steps; 0 means unlimited
//! \return the number of steps taken.
uint32_t Diderot_run (Diderot_world_t *wrld, uint32_t maxNSteps);

//! shutdown and deallocate the world
void Diderot_shutdown (Diderot_world_t *wrld);

/***** Runtime options *****/

//! Set verbose mode
void Diderot_set_verbose (Diderot_world_t *wrld, bool mode);

//! Get verbose mode
bool Diderot_get_verbose (Diderot_world_t *wrld);
/*---------- end lib-h-body.in ----------*/

/**** Getters for output values ****/
bool Diderot_output_get_out (Diderot_world_t *wrld, Nrrd *data);
/*---------- begin lib-h-foot.in ----------*/

#ifdef __cplusplus
}
#endif

#endif /* !_MIP_H_ */
/*---------- end lib-h-foot.in ----------*/
