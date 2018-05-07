/*---------- begin cxx-head.in ----------*/
/*! \file mip.cxx
 *
 * Generated from mip.diderot.
 *
 * Command: /Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec mip.diderot
 * Version: vis15:2016-07-29
 */
/*---------- end cxx-head.in ----------*/

#define DIDEROT_STRAND_HAS_CONSTR
#define DIDEROT_STRAND_ARRAY
/*---------- begin exec-incl.in ----------*/
#define DIDEROT_STANDALONE_EXEC
#define DIDEROT_SINGLE_PRECISION
#define DIDEROT_INT
#define DIDEROT_TARGET_SEQUENTIAL
#include "diderot/diderot.hxx"

#ifdef DIDEROT_ENABLE_LOGGING
#define IF_LOGGING(...)         __VA_ARGS__
#else
#define IF_LOGGING(...)
#endif
/*---------- end exec-incl.in ----------*/

// ***** Begin synthesized types *****

namespace Diderot {
    typedef float vec3 __attribute__ ((vector_size (16)));
    typedef float vec4 __attribute__ ((vector_size (16)));
    struct tensor_ref_3 : public diderot::tensor_ref<float,3> {
        tensor_ref_3 (const float *src);
        tensor_ref_3 (struct tensor_3 const & ten);
        tensor_ref_3 (tensor_ref_3 const & ten);
    };
    struct tensor_ref_3_3 : public diderot::tensor_ref<float,9> {
        tensor_ref_3_3 (const float *src);
        tensor_ref_3_3 (struct tensor_3_3 const & ten);
        tensor_ref_3_3 (tensor_ref_3_3 const & ten);
        tensor_ref_3 last (uint32_t i)
        {
            return &this->_data[i];
        }
    };
    struct tensor_3 : public diderot::tensor<float,3> {
        tensor_3 ()
            : diderot::tensor<float,3>()
        { }
        tensor_3 (std::initializer_list< float > const & il)
            : diderot::tensor<float,3>(il)
        { }
        tensor_3 (const float *src)
            : diderot::tensor<float,3>(src)
        { }
        tensor_3 (tensor_3 const & ten)
            : diderot::tensor<float,3>(ten._data)
        { }
        ~tensor_3 () { }
        tensor_3 & operator= (tensor_3 const & src);
        tensor_3 & operator= (tensor_ref_3 const & src);
        tensor_3 & operator= (std::initializer_list< float > const & il);
        tensor_3 & operator= (const float *src);
    };
    struct tensor_3_3 : public diderot::tensor<float,9> {
        tensor_3_3 ()
            : diderot::tensor<float,9>()
        { }
        tensor_3_3 (std::initializer_list< float > const & il)
            : diderot::tensor<float,9>(il)
        { }
        tensor_3_3 (const float *src)
            : diderot::tensor<float,9>(src)
        { }
        tensor_3_3 (tensor_3_3 const & ten)
            : diderot::tensor<float,9>(ten._data)
        { }
        ~tensor_3_3 () { }
        tensor_3_3 & operator= (tensor_3_3 const & src);
        tensor_3_3 & operator= (tensor_ref_3_3 const & src);
        tensor_3_3 & operator= (std::initializer_list< float > const & il);
        tensor_3_3 & operator= (const float *src);
        tensor_ref_3 last (uint32_t i)
        {
            return &this->_data[i];
        }
    };
    inline tensor_ref_3::tensor_ref_3 (const float *src)
        : diderot::tensor_ref<float,3>(src)
    { }
    inline tensor_ref_3::tensor_ref_3 (struct tensor_3 const & ten)
        : diderot::tensor_ref<float,3>(ten._data)
    { }
    inline tensor_ref_3::tensor_ref_3 (tensor_ref_3 const & ten)
        : diderot::tensor_ref<float,3>(ten._data)
    { }
    inline tensor_ref_3_3::tensor_ref_3_3 (const float *src)
        : diderot::tensor_ref<float,9>(src)
    { }
    inline tensor_ref_3_3::tensor_ref_3_3 (struct tensor_3_3 const & ten)
        : diderot::tensor_ref<float,9>(ten._data)
    { }
    inline tensor_ref_3_3::tensor_ref_3_3 (tensor_ref_3_3 const & ten)
        : diderot::tensor_ref<float,9>(ten._data)
    { }
    inline tensor_3 & tensor_3::operator= (tensor_3 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_3 & tensor_3::operator= (tensor_ref_3 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_3 & tensor_3::operator= (std::initializer_list< float > const & il)
    {
        this->copy(il);
        return *this;
    }
    inline tensor_3 & tensor_3::operator= (const float *src)
    {
        this->copy(src);
        return *this;
    }
    inline tensor_3_3 & tensor_3_3::operator= (tensor_3_3 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_3_3 & tensor_3_3::operator= (tensor_ref_3_3 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_3_3 & tensor_3_3::operator= (std::initializer_list< float > const & il)
    {
        this->copy(il);
        return *this;
    }
    inline tensor_3_3 & tensor_3_3::operator= (const float *src)
    {
        this->copy(src);
        return *this;
    }
} // namespace Diderot
// ***** End synthesized types *****

/*---------- begin namespace-open.in ----------*/
namespace Diderot {

static std::string ProgramName = "mip";

struct world;
struct raycast_strand;
/*---------- end namespace-open.in ----------*/

/*---------- begin nrrd-save-helper.in ----------*/
/* helper function for saving output to nrrd file */
inline bool nrrd_save_helper (std::string const &file, Nrrd *nrrd)
{
    if (nrrdSave (file.c_str(), nrrd, nullptr)) {
        std::cerr << "Error saving \"" << file << "\":\n" << biffGetDone(NRRD) << std::endl;
        return true;
    }
    else {
        return false;
    }
}
/*---------- end nrrd-save-helper.in ----------*/

struct globals {
    diderot::image3d< float, float > gv_vol;
    tensor_3 gv_camEye;
    tensor_3 gv_camAt;
    tensor_3 gv_camUp;
    float gv_camNear;
    float gv_camFar;
    float gv_camFOV;
    bool gv_camOrtho;
    int32_t gv_iresU;
    int32_t gv_iresV;
    float gv_rayStep;
    float gv_out0;
    bool gv_inSphere;
    tensor_3 gv_camN;
    tensor_3 gv_camU;
    tensor_3 gv_camV;
    float gv_camDist;
    float gv_camVmax;
    float gv_camUmax;
    float gv_camNearVsp;
    float gv_camFarVsp;
    ~globals ()
    {
        this->gv_vol.free_data();
    }
};
struct raycast_strand {
    float sv_rayN;
    tensor_3 sv_UV;
    tensor_3 sv_rayOrig;
    tensor_3 sv_rayVec;
    float sv_out;
};
/*---------- begin seq-sarr.in ----------*/
// forward declarations of strand methods
#ifdef DIDEROT_HAS_START_METHOD
static diderot::strand_status raycast_start (raycast_strand *self);
#endif // DIDEROT_HAS_START_METHOD
static diderot::strand_status raycast_update (globals *glob, raycast_strand *self);
#ifdef DIDEROT_HAS_STABILIZE_METHOD
static void raycast_stabilize (raycast_strand *self);
#endif // DIDEROT_HAS_STABILIZE_METHOD

// if we have both communication and "die", then we need to track when strands die
// so that we can rebuild the list of strands use to construct the kd-tree
#if defined(DIDEROT_HAS_STRAND_COMMUNICATION) && !defined(DIDEROT_HAS_STRAND_DIE)
#  define TRACK_STRAND_DEATH
#endif

// strand_array for SEQUENTIAL/NO BSP/SINGLE STATE/DIRECT ACCESS
//
struct strand_array {
    typedef raycast_strand strand_t;
    typedef uint32_t index_t;
    typedef index_t sid_t;              // strand ID (index into strand-state storage)

    uint8_t             *_status;       // the array of status information for the strands
    char                *_storage;      // points to array of raycast_strand structs
    uint32_t            _nItems;        // number of items in the _storage and _status arrays
    uint32_t            _nStable;       // number of stable strands
    uint32_t            _nActive;       // number of active strands
    uint32_t            _nFresh;        // number of fresh strands (new strands from create_strands)
#ifdef TRACK_STRAND_DEATH
    bool                _died;          // a strand died in the current superstep.
#endif

    strand_array () : _status(nullptr), _storage(nullptr), _nItems(0) { }
    ~strand_array ();

    uint32_t in_state_index () const { return 0; /* dummy */ }

    uint32_t num_active () const { return this->_nActive; }
    uint32_t num_stable () const { return this->_nStable; }
    uint32_t num_alive () const { return this->_nActive+this->_nStable; }

  // return the ID of a strand, which is the same as the ix index
    sid_t id (index_t ix) const
    {
        assert (ix < this->_nItems);
        return ix;
    }
  // return a pointer to the strand with the given ID
    raycast_strand *id_to_strand (sid_t id) const
    {
        assert (id < this->_nItems);
        return reinterpret_cast<raycast_strand *>(this->_storage + id * sizeof(raycast_strand));
    }

  // return a strand's status
    diderot::strand_status status (index_t ix) const
    {
        assert (ix < this->_nItems);
        return static_cast<diderot::strand_status>(this->_status[ix]);
    }
  // return a pointer to the given strand
    raycast_strand *strand (index_t ix) const
    {
        return this->id_to_strand(this->id(ix));
    }
  // return a pointer to the local state of strand ix
    raycast_strand *local_state (index_t ix) const
    {
        return this->strand(ix);
    }
  // return a pointer to the local state of strand with the given ID
    raycast_strand *id_to_local_state (sid_t id) const
    {
        return this->id_to_strand(id);
    }

  // is an index valid for the strand array?
    bool validIndex (index_t ix) const { return (ix < this->_nItems); }

  // is a given strand alive?
    bool isAlive (index_t ix) const
    {
#ifdef DIDEROT_HAS_STRAND_DIE
        return aliveSts(this->status(ix));
#else
        return true;
#endif
    }

  // allocate space for nItems
    bool alloc (uint32_t nItems)
    {
        this->_storage = static_cast<char *>(std::malloc (nItems * sizeof(raycast_strand)));
        if (this->_storage == nullptr) {
            return true;
        }
        this->_status = static_cast<uint8_t *>(std::malloc (nItems * sizeof(uint8_t)));
        if (this->_status == nullptr) {
            std::free (this->_storage);
            return true;
        }
        this->_nItems = nItems;
        this->_nActive = 0;
        this->_nStable = 0;
        this->_nFresh = 0;
        return false;
    }

  // initialize the first nStrands locations as new active strands
    void create_strands (uint32_t nStrands)
    {
        assert (this->_nActive == 0);
        assert (this->_nItems == nStrands);
        for (index_t ix = 0;  ix < nStrands;  ix++) {
            this->_status[ix] = diderot::kActive;
            new (this->strand(ix)) raycast_strand;
        }
        this->_nActive = nStrands;
        this->_nFresh = nStrands;
#ifdef TRACK_STRAND_DEATH
        this->_died = false;
#endif
    }

  // swap in and out states (NOP for this version)
    void swap () { }

#ifdef DIDEROT_HAS_START_METHOD
  // invoke strand's start method
    diderot::strand_status strand_start (index_t ix)
    {
        return raycast_start(this->strand(ix));
    }
#endif // DIDEROT_HAS_START_METHOD

  // invoke strand's update method
    diderot::strand_status strand_update (globals *glob, index_t ix)
    {
        return raycast_update(glob, this->strand(ix));
    }

  // invoke strand's stabilize method
    index_t strand_stabilize (index_t ix)
    {
#ifdef DIDEROT_HAS_STABILIZE_METHOD
        raycast_stabilize (this->strand(ix));
#endif // DIDEROT_HAS_STABILIZE_METHOD
        this->_status[ix] = diderot::kStable;
        this->_nActive--;
        this->_nStable++;
      // skip to next active strand
        do {
            ix++;
        } while ((ix < this->_nItems) && notActiveSts(this->status(ix)));
        return ix;
    }

  // mark the given strand as dead
    index_t kill (index_t ix)
    {
#ifdef TRACK_STRAND_DEATH
        this->_died = true;
#endif
        this->_status[ix] = diderot::kDead;
        this->_nActive--;
      // skip to next active strand
        do {
            ix++;
        } while ((ix < this->_nItems) && notActiveSts(this->status(ix)));
        return ix;
    }

  // finish the local-phase of a superstep (NOP)
#ifdef TRACK_STRAND_DEATH
    bool finish_step ()
    {
        bool res = this->_died;
        this->_died = false;
        return res;
    }
#else
    bool finish_step () { return false; }
#endif

  // finish a kill_all operation (NOP)
    void finish_kill_all () { }

  // finish a stabilize_all operation (NOP)
    void finish_stabilize_all () { }

    index_t begin_alive () const
    {
        index_t ix = 0;
#ifdef DIDEROT_HAS_STRAND_DIE
        while ((ix < this->_nItems) && notAliveSts(this->status(ix))) {
            ix++;
        }
#endif
        return ix;
    }
    index_t end_alive () const { return this->_nItems; }
    index_t next_alive (index_t &ix) const
    {
        ix++;
#ifdef DIDEROT_HAS_STRAND_DIE
        while ((ix < this->_nItems) && notAliveSts(this->status(ix))) {
            ix++;
        }
#endif
        return ix;
    }

  // iterator over active strands
    index_t begin_active () const
    {
        index_t ix = 0;
        while ((ix < this->_nItems) && notActiveSts(this->status(ix))) {
            ix++;
        }
        return ix;
    }
    index_t end_active () const { return this->_nItems; }
    index_t next_active (index_t &ix) const
    {
        do {
            ix++;
        } while ((ix < this->_nItems) && notActiveSts(this->status(ix)));
        return ix;
    }

  // iterator over stable strands
    index_t begin_stable () const
    {
        index_t ix = 0;
        while ((ix < this->_nItems) && (this->status(ix) != diderot::kStable)) {
            ix++;
        }
        return ix;
    }
    index_t end_stable () const { return this->_nItems; }
    index_t next_stable (index_t &ix) const
    {
        do {
            ix++;
        } while ((ix < this->_nItems) && (this->status(ix) != diderot::kStable));
        return ix;
    }

  // iterator over fresh strands; since the only new strands were created by create_strand
  // we iterate over all of them
    index_t begin_fresh () const { return 0; }
    index_t end_fresh () const { return this->_nFresh; }
    index_t next_fresh (index_t &ix) const { return ++ix; }

}; // struct strand_array

strand_array::~strand_array ()
{
  // run destructors to reclaim any dynamic memory attached to the strand state
    for (auto ix = this->begin_alive();  ix != this->end_alive();  ix = this->next_alive(ix)) {
        this->strand(ix)->~raycast_strand();
    }
    if (this->_status != nullptr) std::free (this->_status);
    if (this->_storage != nullptr) std::free (this->_storage);
}
/*---------- end seq-sarr.in ----------*/

struct world : public diderot::world_base {
    strand_array _strands;
    globals *_globals;
    world ();
    ~world ();
    bool init ();
    bool alloc (int32_t base[2], uint32_t size[2]);
    bool create_strands ();
    uint32_t run (uint32_t max_nsteps);
    void swap_state ();
};
// ***** Begin synthesized operations *****

inline vec3 vfloor3 (vec3 v)
{
    return __extension__ (vec3){diderot::floor(v[0]), diderot::floor(v[1]), diderot::floor(v[2]), 0.0f};
}
inline diderot::array< int, 3 > vtoi3 (vec3 src)
{
    diderot::array< int, 3 > res = {int32_t(src[0]),int32_t(src[1]),int32_t(src[2]),};
    return res;
}
template <typename TY>
inline bool inside3Ds2 (vec3 x0, diderot::image3d< float, TY > img)
{
    return 1 < x0[0] && x0[2] < img.size(2) - 2 && 1 < x0[2] && x0[1] < img.size(1) - 2 && 1 < x0[1] && x0[0] < img.size(
        0) - 2;
}
inline vec3 vload3 (const float *vp)
{
    return __extension__ (vec3){vp[0], vp[1], vp[2], 0.0f};
}
inline vec3 vcons3 (float r0, float r1, float r2)
{
    return __extension__ (vec3){r0, r1, r2, 0.0f};
}
inline vec4 vcons4 (float r0, float r1, float r2, float r3)
{
    return __extension__ (vec4){r0, r1, r2, r3};
}
inline void vpack3 (tensor_3 &dst, vec3 v0)
{
    dst._data[0] = v0[0];
    dst._data[1] = v0[1];
    dst._data[2] = v0[2];
}
inline vec3 vscale3 (float s, vec3 v)
{
    return __extension__ (vec3){s, s, s, 0.0f} * v;
}
template <typename TY>
inline tensor_ref_3_3 world2image (diderot::image3d< float, TY > const & img)
{
    return tensor_ref_3_3(img.world2image());
}
inline float vdot3 (vec3 u, vec3 v)
{
    vec3 w = u * v;
    return w[0] + w[1] + w[2];
}
template <typename TY>
inline tensor_ref_3 translate (diderot::image3d< float, TY > const & img)
{
    return tensor_ref_3(img.translate());
}
inline float vdot4 (vec4 u, vec4 v)
{
    vec4 w = u * v;
    return w[0] + w[1] + w[2] + w[3];
}
// ***** End synthesized operations *****

typedef struct {
    std::string gv_vol;
    tensor_3 gv_camEye;
    tensor_3 gv_camAt;
    tensor_3 gv_camUp;
    float gv_camNear;
    float gv_camFar;
    float gv_camFOV;
    bool gv_camOrtho;
    int32_t gv_iresU;
    int32_t gv_iresV;
    float gv_rayStep;
    float gv_out0;
    bool gv_inSphere;
} cmd_line_inputs;
static void init_defaults (cmd_line_inputs *inp)
{
    inp->gv_camEye[0] = 0.6e1f;
    inp->gv_camEye[1] = 0.9e1f;
    inp->gv_camEye[2] = 0.2e1f;
    inp->gv_camAt[0] = 0.0f;
    inp->gv_camAt[1] = 0.0f;
    inp->gv_camAt[2] = 0.0f;
    inp->gv_camUp[0] = 0.0f;
    inp->gv_camUp[1] = 0.0f;
    inp->gv_camUp[2] = 0.1e1f;
    inp->gv_camNear = -0.3e1f;
    inp->gv_camFar = 0.3e1f;
    inp->gv_camFOV = 0.15e2f;
    inp->gv_camOrtho = false;
    inp->gv_iresU = 640;
    inp->gv_iresV = 480;
    inp->gv_rayStep = 0.1e0f;
    inp->gv_out0 = -HUGE_VALF;
    inp->gv_inSphere = false;
}
static void register_inputs (cmd_line_inputs *inp, diderot::options *opts)
{
    opts->add("vol", "volume dataset to MIP", &inp->gv_vol, false);
    opts->add("camEye", "camera look-from point", 3, inp->gv_camEye._data, true);
    opts->add("camAt", "camera look-at point", 3, inp->gv_camAt._data, true);
    opts->add("camUp", "camera pseudo-up vector", 3, inp->gv_camUp._data, true);
    opts->add("camNear", "relative to look-at point, distance to near clipping plane (where rays start from)",
        &inp->gv_camNear, true);
    opts->add("camFar", "relative to look-at point, distance to far clipping plane", &inp->gv_camFar, true);
    opts->add("camFOV", "field-of-view angle (in degrees) subtended vertically by view plane", &inp->gv_camFOV, true);
    opts->add("camOrtho", "whether to use orthographic, instead of perspective, projection", &inp->gv_camOrtho, true);
    opts->add("iresU", "# samples on horizontal axis of image", &inp->gv_iresU, true);
    opts->add("iresV", "# samples on vertical axis of image", &inp->gv_iresV, true);
    opts->add("rayStep", "inter-sample distance along view direction", &inp->gv_rayStep, true);
    opts->add("out0",
        "value at which to initilize output max accumulator; using -inf ensures that output will stay -inf if ray misses volume entirely",
        &inp->gv_out0, true);
    opts->add("inSphere", "only render samples inside a unit sphere", &inp->gv_inSphere, true);
}
static bool init_inputs (world *wrld, cmd_line_inputs *inp)
{
    globals *glob = wrld->_globals;
    if (glob->gv_vol.load(wrld, inp->gv_vol)) {
        return true;
    }
    glob->gv_camEye = inp->gv_camEye;
    glob->gv_camAt = inp->gv_camAt;
    glob->gv_camUp = inp->gv_camUp;
    glob->gv_camNear = inp->gv_camNear;
    glob->gv_camFar = inp->gv_camFar;
    glob->gv_camFOV = inp->gv_camFOV;
    glob->gv_camOrtho = inp->gv_camOrtho;
    glob->gv_iresU = inp->gv_iresU;
    glob->gv_iresV = inp->gv_iresV;
    glob->gv_rayStep = inp->gv_rayStep;
    glob->gv_out0 = inp->gv_out0;
    glob->gv_inSphere = inp->gv_inSphere;
    return false;
}
static std::string OutputFile = "out.nrrd";
static void register_outputs (diderot::options *opts)
{
    opts->add("o,output", "specify output file", &OutputFile, true);
}
static bool init_globals (world *wrld)
{
    globals *glob = wrld->_globals;
    vec3 v_3 = vload3(tensor_ref_3(glob->gv_camAt).addr(0)) - vload3(tensor_ref_3(glob->gv_camEye).addr(0));
    float l_op1_e3_l_7_4 = std::sqrt(vdot3(v_3, v_3));
    float l_op1_e3_l_9_5 = 0.1e1f / l_op1_e3_l_7_4;
    vpack3(glob->gv_camN, vscale3(l_op1_e3_l_9_5, v_3));
    float l_r_7 = tensor_ref_3(glob->gv_camUp)[0];
    float l_r_8 = 0.0f * l_r_7;
    float l_r_9 = tensor_ref_3(glob->gv_camUp)[1];
    float l_r_10 = 0.0f * l_r_9;
    float l_r_11 = tensor_ref_3(glob->gv_camUp)[2];
    float l_r_12 = 0.0f * l_r_11;
    float l_r_13 = l_r_8 + l_r_10;
    float l_r_14 = l_r_13 + l_r_12;
    float l_vdot_15 = vdot3(v_3, vcons3(l_r_14, l_r_13 + 0.1e1f * l_r_11, l_r_8 + -0.1e1f * l_r_9 + l_r_12));
    float l_vdot_16 = vdot3(v_3, vcons3(l_r_13 + -0.1e1f * l_r_11, l_r_14, 0.1e1f * l_r_7 + l_r_10 + l_r_12));
    float l_vdot_17 = vdot3(v_3, vcons3(l_r_8 + 0.1e1f * l_r_9 + l_r_12, -0.1e1f * l_r_7 + l_r_10 + l_r_12, l_r_14));
    vec3 v_18 = vcons3(l_vdot_15, l_vdot_16, l_vdot_17);
    float l_op1_e3_l_38_19 = 0.1e1f / std::sqrt(l_op1_e3_l_9_5 * l_op1_e3_l_9_5 * vdot3(v_18, v_18));
    vpack3(glob->gv_camU, vscale3(l_op1_e3_l_38_19, vscale3(l_op1_e3_l_9_5, v_18)));
    float l_r_21 = 0.0f * l_vdot_15;
    float l_r_22 = 0.0f * l_vdot_16;
    float l_r_23 = 0.0f * l_vdot_17;
    float l_r_24 = l_r_21 + l_r_22;
    float l_r_25 = l_r_24 + l_r_23;
    vec3 v_26 = vscale3(l_op1_e3_l_9_5,
        vcons3(vdot3(v_3, vcons3(l_r_25, l_r_24 + 0.1e1f * l_vdot_17, l_r_21 + -0.1e1f * l_vdot_16 + l_r_23)),
            vdot3(v_3, vcons3(l_r_24 + -0.1e1f * l_vdot_17, l_r_25, 0.1e1f * l_vdot_15 + l_r_22 + l_r_23)),
            vdot3(v_3, vcons3(l_r_21 + 0.1e1f * l_vdot_16 + l_r_23, -0.1e1f * l_vdot_15 + l_r_22 + l_r_23, l_r_25))));
    float l_r_27 = l_op1_e3_l_9_5 * l_op1_e3_l_38_19;
    glob->gv_camV[0] = l_r_27 * v_26[0];
    glob->gv_camV[1] = l_r_27 * v_26[1];
    glob->gv_camV[2] = l_r_27 * v_26[2];
    glob->gv_camDist = l_op1_e3_l_7_4;
    float l_op1_e3_l_10_29 = std::tan(glob->gv_camFOV * 0.314159265358979323846264338328e1f / 0.360e3f);
    glob->gv_camVmax = l_op1_e3_l_10_29 * l_op1_e3_l_7_4;
    glob->gv_camUmax = static_cast<float>(glob->gv_iresU) * l_op1_e3_l_10_29 * l_op1_e3_l_7_4 / static_cast<float>(glob->gv_iresV);
    glob->gv_camNearVsp = glob->gv_camNear + l_op1_e3_l_7_4;
    glob->gv_camFarVsp = glob->gv_camFar + l_op1_e3_l_7_4;
    return false;
}
static void raycast_init (globals *glob, raycast_strand *self, float p_rayU_30, float p_rayV_31)
{
    vec3 v_35;
    vec3 v_37;
    vec3 v_32 = vscale3(p_rayU_30, vload3(tensor_ref_3(glob->gv_camU).addr(0))) + vscale3(p_rayV_31,
        vload3(tensor_ref_3(glob->gv_camV).addr(0)));
    float l_rayN_33 = glob->gv_camNearVsp - glob->gv_rayStep;
    vec3 v_34 = v_32;
    if (glob->gv_camOrtho) {
        v_35 = v_34;
    }
    else {
        v_35 = vcons3(0.0f, 0.0f, 0.0f);
    }
    vec3 v_36 = vload3(tensor_ref_3(glob->gv_camEye).addr(0)) + v_35;
    if (glob->gv_camOrtho) {
        v_37 = vcons3(0.0f, 0.0f, 0.0f);
    }
    else {
        float l_r_38 = 0.1e1f / glob->gv_camDist;
        v_37 = vcons3(l_r_38 * v_34[0], l_r_38 * v_34[1], l_r_38 * v_34[2]);
    }
    self->sv_rayN = l_rayN_33;
    vpack3(self->sv_UV, v_34);
    vpack3(self->sv_rayOrig, v_36);
    vpack3(self->sv_rayVec, vload3(tensor_ref_3(glob->gv_camN).addr(0)) + v_37);
    self->sv_out = glob->gv_out0;
}
static diderot::strand_status raycast_update (globals *glob, raycast_strand *self)
{
    bool l__t_48;
    float l_rayN_42 = self->sv_rayN + glob->gv_rayStep;
    if (l_rayN_42 > glob->gv_camFarVsp) {
        self->sv_rayN = l_rayN_42;
        return diderot::kStabilize;
    }
    vec3 v_43 = vload3(tensor_ref_3(self->sv_rayOrig).addr(0)) + vscale3(l_rayN_42,
        vload3(tensor_ref_3(self->sv_rayVec).addr(0)));
    tensor_ref_3_3 l_Mtransform_44 = world2image(glob->gv_vol);
    vec3 v_45 = vcons3(vdot3(vload3(l_Mtransform_44.last(0).addr(0)), v_43),
        vdot3(vload3(l_Mtransform_44.last(3).addr(0)), v_43), vdot3(vload3(l_Mtransform_44.last(6).addr(0)), v_43)) + vload3(
        translate(glob->gv_vol).addr(0));
    vec3 v_46 = v_43;
    vec3 v_47 = v_45;
    if (!inside3Ds2(v_45, glob->gv_vol)) {
        l__t_48 = true;
    }
    else {
        bool l__t_49;
        if (glob->gv_inSphere) {
            l__t_49 = std::sqrt(vdot3(v_46, v_46)) > 0.1e1f;
        }
        else {
            l__t_49 = false;
        }
        l__t_48 = l__t_49;
    }
    if (l__t_48) {
        self->sv_rayN = l_rayN_42;
        return diderot::kActive;
    }
    vec3 v_50 = vfloor3(v_47);
    vec3 v_51 = v_47 - v_50;
    diderot::array< int32_t, 3 > l_n_52 = vtoi3(v_50);
    float l_vZ__53 = v_51[2];
    vec4 v_54 = vcons4(l_vZ__53 + 0.1e1f, l_vZ__53, l_vZ__53 - 0.1e1f, l_vZ__53 - 0.2e1f);
    vec4 v_55 = vcons4(0.2e1f, 0.1e1f, 0.1e1f, 0.2e1f);
    vec4 v_56 = vcons4(-0.4e1f, 0.0f, 0.0f, 0.4e1f);
    vec4 v_57 = vcons4(0.25e1f, -0.25e1f, -0.25e1f, 0.25e1f);
    vec4 v_58 = vcons4(-0.5e0f, 0.15e1f, -0.15e1f, 0.5e0f);
    float l_vY__59 = v_51[1];
    vec4 v_60 = vcons4(l_vY__59 + 0.1e1f, l_vY__59, l_vY__59 - 0.1e1f, l_vY__59 - 0.2e1f);
    vec4 v_61 = v_55 + v_60 * (v_56 + v_60 * (v_57 + v_60 * v_58));
    float l_vX__62 = v_51[0];
    vec4 v_63 = vcons4(l_vX__62 + 0.1e1f, l_vX__62, l_vX__62 - 0.1e1f, l_vX__62 - 0.2e1f);
    vec4 v_64 = vcons4(0.133333333333e1f, 0.666666666667e0f, 0.666666666667e0f, 0.133333333333e1f) + v_63 * (vcons4(
        -0.2e1f, 0.0f, 0.0f, 0.2e1f) + v_63 * (vcons4(0.1e1f, -0.1e1f, -0.1e1f, 0.1e1f) + v_63 * vcons4(
        -0.166666666667e0f, 0.5e0f, -0.5e0f, 0.166666666667e0f)));
    int32_t l_idx_65 = l_n_52[0] + -1;
    int32_t l_idx_66 = l_n_52[1] + -1;
    int32_t l_idx_67 = l_n_52[2] + -1;
    int32_t l_sz_68 = glob->gv_vol.size(0);
    int32_t l_sz_69 = glob->gv_vol.size(1);
    int32_t l_mulRes_70 = l_sz_69 * l_idx_67;
    int32_t l_mulRes_71 = l_sz_68 * (l_idx_66 + l_mulRes_70);
    int32_t l_addRes_72 = l_idx_65 + 1;
    int32_t l_addRes_73 = l_idx_65 + 2;
    int32_t l_addRes_74 = l_idx_65 + 3;
    int32_t l_addRes_75 = l_idx_66 + 1;
    int32_t l_mulRes_76 = l_sz_68 * (l_addRes_75 + l_mulRes_70);
    int32_t l_addRes_77 = l_idx_66 + 2;
    int32_t l_mulRes_78 = l_sz_68 * (l_addRes_77 + l_mulRes_70);
    int32_t l_addRes_79 = l_idx_66 + 3;
    int32_t l_mulRes_80 = l_sz_68 * (l_addRes_79 + l_mulRes_70);
    int32_t l_mulRes_81 = l_sz_69 * (l_idx_67 + 1);
    int32_t l_mulRes_82 = l_sz_68 * (l_idx_66 + l_mulRes_81);
    int32_t l_mulRes_83 = l_sz_68 * (l_addRes_75 + l_mulRes_81);
    int32_t l_mulRes_84 = l_sz_68 * (l_addRes_77 + l_mulRes_81);
    int32_t l_mulRes_85 = l_sz_68 * (l_addRes_79 + l_mulRes_81);
    int32_t l_mulRes_86 = l_sz_69 * (l_idx_67 + 2);
    int32_t l_mulRes_87 = l_sz_68 * (l_idx_66 + l_mulRes_86);
    int32_t l_mulRes_88 = l_sz_68 * (l_addRes_75 + l_mulRes_86);
    int32_t l_mulRes_89 = l_sz_68 * (l_addRes_77 + l_mulRes_86);
    int32_t l_mulRes_90 = l_sz_68 * (l_addRes_79 + l_mulRes_86);
    int32_t l_mulRes_91 = l_sz_69 * (l_idx_67 + 3);
    int32_t l_mulRes_92 = l_sz_68 * (l_idx_66 + l_mulRes_91);
    int32_t l_mulRes_93 = l_sz_68 * (l_addRes_75 + l_mulRes_91);
    int32_t l_mulRes_94 = l_sz_68 * (l_addRes_77 + l_mulRes_91);
    int32_t l_mulRes_95 = l_sz_68 * (l_addRes_79 + l_mulRes_91);
    self->sv_rayN = l_rayN_42;
    self->sv_out = std::max(self->sv_out,
        vdot4(v_55 + v_54 * (v_56 + v_54 * (v_57 + v_54 * v_58)),
            vcons4(
                vdot4(v_61,
                    vcons4(
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_71], glob->gv_vol[l_addRes_72 + l_mulRes_71],
                                glob->gv_vol[l_addRes_73 + l_mulRes_71], glob->gv_vol[l_addRes_74 + l_mulRes_71])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_76], glob->gv_vol[l_addRes_72 + l_mulRes_76],
                                glob->gv_vol[l_addRes_73 + l_mulRes_76], glob->gv_vol[l_addRes_74 + l_mulRes_76])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_78], glob->gv_vol[l_addRes_72 + l_mulRes_78],
                                glob->gv_vol[l_addRes_73 + l_mulRes_78], glob->gv_vol[l_addRes_74 + l_mulRes_78])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_80], glob->gv_vol[l_addRes_72 + l_mulRes_80],
                                glob->gv_vol[l_addRes_73 + l_mulRes_80], glob->gv_vol[l_addRes_74 + l_mulRes_80])))),
                vdot4(v_61,
                    vcons4(
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_82], glob->gv_vol[l_addRes_72 + l_mulRes_82],
                                glob->gv_vol[l_addRes_73 + l_mulRes_82], glob->gv_vol[l_addRes_74 + l_mulRes_82])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_83], glob->gv_vol[l_addRes_72 + l_mulRes_83],
                                glob->gv_vol[l_addRes_73 + l_mulRes_83], glob->gv_vol[l_addRes_74 + l_mulRes_83])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_84], glob->gv_vol[l_addRes_72 + l_mulRes_84],
                                glob->gv_vol[l_addRes_73 + l_mulRes_84], glob->gv_vol[l_addRes_74 + l_mulRes_84])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_85], glob->gv_vol[l_addRes_72 + l_mulRes_85],
                                glob->gv_vol[l_addRes_73 + l_mulRes_85], glob->gv_vol[l_addRes_74 + l_mulRes_85])))),
                vdot4(v_61,
                    vcons4(
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_87], glob->gv_vol[l_addRes_72 + l_mulRes_87],
                                glob->gv_vol[l_addRes_73 + l_mulRes_87], glob->gv_vol[l_addRes_74 + l_mulRes_87])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_88], glob->gv_vol[l_addRes_72 + l_mulRes_88],
                                glob->gv_vol[l_addRes_73 + l_mulRes_88], glob->gv_vol[l_addRes_74 + l_mulRes_88])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_89], glob->gv_vol[l_addRes_72 + l_mulRes_89],
                                glob->gv_vol[l_addRes_73 + l_mulRes_89], glob->gv_vol[l_addRes_74 + l_mulRes_89])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_90], glob->gv_vol[l_addRes_72 + l_mulRes_90],
                                glob->gv_vol[l_addRes_73 + l_mulRes_90], glob->gv_vol[l_addRes_74 + l_mulRes_90])))),
                vdot4(v_61,
                    vcons4(
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_92], glob->gv_vol[l_addRes_72 + l_mulRes_92],
                                glob->gv_vol[l_addRes_73 + l_mulRes_92], glob->gv_vol[l_addRes_74 + l_mulRes_92])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_93], glob->gv_vol[l_addRes_72 + l_mulRes_93],
                                glob->gv_vol[l_addRes_73 + l_mulRes_93], glob->gv_vol[l_addRes_74 + l_mulRes_93])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_94], glob->gv_vol[l_addRes_72 + l_mulRes_94],
                                glob->gv_vol[l_addRes_73 + l_mulRes_94], glob->gv_vol[l_addRes_74 + l_mulRes_94])),
                        vdot4(v_64,
                            vcons4(glob->gv_vol[l_idx_65 + l_mulRes_95], glob->gv_vol[l_addRes_72 + l_mulRes_95],
                                glob->gv_vol[l_addRes_73 + l_mulRes_95], glob->gv_vol[l_addRes_74 + l_mulRes_95])))))));
    return diderot::kActive;
}
bool output_get_out (world *wrld, Nrrd *nData)
{
    // Compute sizes of nrrd file
    size_t sizes[2];
    sizes[0] = wrld->_size[1];
    sizes[1] = wrld->_size[0];
    // Allocate nData nrrd
    if (nrrdMaybeAlloc_nva(nData, nrrdTypeFloat, 2, sizes) != 0) {
        char *msg = biffGetDone(NRRD);
        biffMsgAdd(wrld->_errors, msg);
        std::free(msg);
        return true;
    }
    // copy data to output nrrd
    char *cp = reinterpret_cast<char *>(nData->data);
    for (auto ix = wrld->_strands.begin_alive(); ix != wrld->_strands.end_alive(); ix = wrld->_strands.next_alive(ix)) {
        memcpy(cp, &wrld->_strands.strand(ix)->sv_out, 1 * sizeof(float));
        cp += 1 * sizeof(float);
    }
    nData->axis[0].kind = nrrdKindSpace;
    nData->axis[1].kind = nrrdKindSpace;
    return false;
}
static void write_output (world *wrld)
{
    Nrrd *nData;
    nData = nrrdNew();
    if (output_get_out(wrld, nData)) {
        std::cerr << "Error getting nrrd data:\n" << biffMsgStrGet(wrld->_errors) << std::endl;
        delete wrld;
        exit(1);
    }
    else if (nrrd_save_helper(OutputFile, nData)) {
        exit(1);
    }
    nrrdNuke(nData);
}
/*---------- begin world-methods.in ----------*/
// Allocate the program's world
//
world::world ()
    : diderot::world_base (ProgramName, true, 2)
{
#ifndef DIDEROT_NO_GLOBALS
    this->_globals = new globals;
#endif

#ifdef DIDEROT_HAS_STRAND_COMMUNICATION
    this->_tree = nullptr;
#endif
} // world constructor

// shutdown and deallocate the world
//
world::~world ()
{
#ifndef DIDEROT_NO_GLOBALS
    delete this->_globals;
#endif

#ifdef DIDEROT_HAS_STRAND_COMMUNICATION
    delete this->_tree;
#endif

} // world destructor

// Initialize the program's world
//
bool world::init ()
{
    assert (this->_stage == diderot::POST_NEW);

#if !defined(DIDEROT_STANDALONE_EXEC) && !defined(DIDEROT_NO_INPUTS)
  // initialize the defined flags for the input globals
    init_defined_inputs (this);
#endif

#ifdef DIDEROT_TARGET_PARALLEL
  // get CPU info
    if (this->_sched->get_cpu_info (this)) {
        return true;
    }
#endif

    this->_stage = diderot::POST_INIT;

    return false;

}

// allocate the initial strands and initialize the rest of the world structure.
//
bool world::alloc (int32_t base[2], uint32_t size[2])
{
    size_t numStrands = 1;
    for (uint32_t i = 0;  i < 2;  i++) {
        numStrands *= size[i];
        this->_base[i] = base[i];
        this->_size[i] = size[i];
    }

    if (this->_verbose) {
        std::cerr << "world::alloc: " << size[0];
        for (uint32_t i = 1;  i < 2;  i++) {
            std::cerr << " x " << size[i];
        }
        std::cerr << std::endl;
    }

#ifdef DIDEROT_TARGET_PARALLEL
  // determine the block size based on the initial number of strands and the
  // number of workers
    this->_strands.set_block_size (this->_sched->_numWorkers, numStrands);
#endif

  // allocate the strand array
    if (this->_strands.alloc (numStrands)) {
        biffMsgAdd (this->_errors, "unable to allocate strand-state array\n");
        return true;
    }

  // initialize strand state pointers etc.
    this->_strands.create_strands (numStrands);

#ifdef DIDEROT_HAS_STRAND_COMMUNICATION
    this->_tree = new diderot::kdtree<0, float, strand_array> (&this->_strands);
#endif

    return false;

} // world::alloc

// swap input and output states
//
inline void world::swap_state ()
{
    this->_strands.swap ();
}

#ifdef DIDEROT_HAS_KILL_ALL
void world::kill_all ()
{
    if (this->_strands.num_active() > 0) {
        for (auto ix = this->_strands.begin_active();
            ix != this->_strands.end_active();
            )
        {
            assert (this->_strands.status(ix) == diderot::kActive);
            ix = this->_strands.kill (ix);
        }
        this->_strands.finish_kill_all();
    }
    assert (this->_strands.num_active() == 0);
}
#endif

#ifdef DIDEROT_HAS_STABILIZE_ALL
void world::stabilize_all ()
{
#ifndef DIDEROT_NO_GLOBALS
    globals *glob = this->_globals;
#endif

    if (this->_strands.num_active() > 0) {
        for (auto ix = this->_strands.begin_active();
            ix != this->_strands.end_active();
            )
        {
            assert (this->_strands.status(ix) == diderot::kActive);
            this->_strands._status[ix] = diderot::kStable;
            ix = this->_strands.strand_stabilize (ix);
        }
        this->_strands.finish_stabilize_all();
    }
    assert (this->_strands.num_active() == 0);
}
#endif
/*---------- end world-methods.in ----------*/

bool world::create_strands ()
{
    if (init_globals(this)) {
        return true;
    }
    globals *glob = this->_globals;
    int lo_0 = 0;
    int hi_1 = glob->gv_iresV - 1;
    int lo_2 = 0;
    int hi_3 = glob->gv_iresU - 1;
    int32_t base[2] = {lo_0,lo_2,};
    uint32_t size[2] = {static_cast<uint32_t>(hi_1 - lo_0 + 1),static_cast<uint32_t>(hi_3 - lo_2 + 1),};
    if (this->alloc(base, size)) {
        return true;
    }
    uint32_t ix = 0;
    for (int i_vi_96 = lo_0; i_vi_96 <= hi_1; i_vi_96++) {
        for (int i_ui_97 = lo_2; i_ui_97 <= hi_3; i_ui_97++) {
            float l_op1_e3_l_9_98 = -glob->gv_camUmax;
            float l_op1_e3_l_9_99 = -glob->gv_camVmax;
            raycast_init(this->_globals, this->_strands.strand(ix),
                l_op1_e3_l_9_98 + (static_cast<float>(i_ui_97) - (-0.5e0f)) / (static_cast<float>(glob->gv_iresU) - 0.5e0f - (-0.5e0f)) * (glob->gv_camUmax - l_op1_e3_l_9_98),
                l_op1_e3_l_9_99 + (static_cast<float>(i_vi_96) - (-0.5e0f)) / (static_cast<float>(glob->gv_iresV) - 0.5e0f - (-0.5e0f)) * (glob->gv_camVmax - l_op1_e3_l_9_99));
            ++ix;
        }
    }
    this->swap_state();
    this->_stage = diderot::POST_CREATE;
    return false;
}
/*---------- begin seq-run-nobsp.in ----------*/
//! Run the Diderot program (sequential version without BSP semantics)
//! \param max_nsteps the limit on the number of super steps; 0 means unlimited
//! \return the number of steps taken, or 0 on error.
uint32_t world::run (uint32_t max_nsteps)
{
    if (this->_stage == diderot::POST_CREATE) {
#ifdef DIDEROT_HAS_GLOBAL_START
        this->global_start();
#endif
        this->_stage = diderot::RUNNING;
    }
    assert (this->_stage == diderot::RUNNING);

#ifndef DIDEROT_NO_GLOBALS
    globals *glob = this->_globals;
#endif

    if (max_nsteps == 0) {
        max_nsteps = 0xffffffff;  // essentially unlimited
    }

    double t0 = airTime();

    if (this->_verbose) {
        std::cerr << "run with " << this->_strands.num_alive() << " strands ..." << std::endl;
    }

#ifdef DIDEROT_HAS_START_METHOD
    this->run_start_methods();
#endif

  // iterate until all strands are stable
    uint32_t maxSteps = 0;
    for (auto ix = this->_strands.begin_active();
         ix != this->_strands.end_active();
         )
    {
        diderot::strand_status sts = this->_strands.status(ix);
        uint32_t nSteps = 0;
        while ((! sts) && (nSteps < max_nsteps)) {
            nSteps++;
            sts = this->_strands.strand_update(glob, ix);
        }
        switch (sts) {
          case diderot::kStabilize:
          // stabilize the strand's state.
            ix = this->_strands.strand_stabilize (ix);
            break;
#ifdef DIDEROT_HAS_STRAND_DIE
          case diderot::kDie:
            ix = this->_strands.kill (ix);
            break;
#endif
          default:
            assert (sts == this->_strands.status(ix));
	    ix = this->_strands.next_active(ix);
            break;
        }
        if (maxSteps < nSteps) maxSteps = nSteps;
    }

    this->_run_time += airTime() - t0;

    if (this->_strands.num_active() == 0)
        this->_stage = diderot::DONE;

    return maxSteps;

} // world::run
/*---------- end seq-run-nobsp.in ----------*/

/*---------- begin namespace-close.in ----------*/

} // namespace Diderot
/*---------- end namespace-close.in ----------*/

/*---------- begin seq-main.in ----------*/
using namespace Diderot;

//! Main function for standalone sequential C target
//
int main (int argc, const char **argv)
{
    bool        timingFlg = false;      //! true if timing computation
    uint32_t    stepLimit = 0;          //! limit on number of execution steps (0 means unlimited)
    std::string printFile = "-";        //! file to direct printed output into
#ifdef DIDEROT_EXEC_SNAPSHOT
    uint32_t    snapshotPeriod = 0;     //! supersteps per snapshot; 0 means no snapshots
#endif
    uint32_t    nSteps = 0;             //! number of supersteps taken

  // create the world
    world *wrld = new (std::nothrow) world();
    if (wrld == nullptr) {
        std::cerr << "unable to create world" << std::endl;
        exit(1);
    }

#ifndef DIDEROT_NO_INPUTS
  // initialize the default values for the inputs
    cmd_line_inputs inputs;
    init_defaults (&inputs);
#endif

  // handle command-line options
    {
        diderot::options *opts = new diderot::options ();
        opts->add ("l,limit", "specify limit on number of super-steps (0 means unlimited)",
            &stepLimit, true);
#ifdef DIDEROT_EXEC_SNAPSHOT
        opts->add ("s,snapshot",
            "specify number of super-steps per snapshot (0 means no snapshots)",
            &snapshotPeriod, true);
#endif
        opts->add ("print", "specify where to direct printed output", &printFile, true);
        opts->addFlag ("v,verbose", "enable runtime-system messages", &(wrld->_verbose));
        opts->addFlag ("t,timing", "enable execution timing", &timingFlg);
#ifndef DIDEROT_NO_INPUTS
      // register options for setting global inputs
        register_inputs (&inputs, opts);
#endif
        register_outputs (opts);
        opts->process (argc, argv);
        delete opts;
    }

  // redirect printing (if necessary)
    if (printFile.compare("-") != 0) {
        wrld->_printTo = new std::ofstream (printFile);
        if (wrld->_printTo->fail()) {
            std::cerr << "Error opening print file" << std::endl;
            delete wrld;
            exit(1);
        }
    }

  // initialize scheduler stuff
    if (wrld->_verbose) {
        std::cerr << "initializing world ..." << std::endl;
    }
    if (wrld->init()) {
        std::cerr << "Error initializing world:\n" << wrld->get_errors() << std::endl;
        delete wrld;
        exit(1);
    }

#ifndef DIDEROT_NO_INPUTS
  // initialize the input globals
    if (init_inputs (wrld, &inputs)) {
        std::cerr << "Error initializing inputs:\n" << wrld->get_errors() << std::endl;
        delete wrld;
        exit(1);
    }
#endif

  // run the generated global initialization code
    if (wrld->_verbose) {
        std::cerr << "initializing globals and creating strands ...\n";
    }
    if (wrld->create_strands()) {
        std::cerr << "Error in global initialization:\n"
            << wrld->get_errors() << std::endl;
        delete wrld;
        exit(1);
    }

#ifdef DIDEROT_EXEC_SNAPSHOT

    if (snapshotPeriod > 0) {
     // write initial state as snapshot 0
        write_snapshot (wrld, "-0000");
     // run the program for `snapshotPeriod` steps at a time with a snapshot after each run
        while (true) {
            uint32_t n, limit;
          // determine a step limit for the next run
            if (stepLimit > 0) {
                if (stepLimit <= nSteps) {
                    break;
                }
                limit = std::min(stepLimit - nSteps, snapshotPeriod);
            }
            else {
                limit = snapshotPeriod;
            }
          // run the program for upto limit steps
            if ((n = wrld->run (limit)) == 0) {
                break;
            }
            nSteps += n;
            if ((wrld->_errors->errNum > 0) || (wrld->_strands.num_alive() == 0)) {
                break;
            }
          // write a snapshot with the step count as a suffix
            std::string suffix = std::to_string(nSteps);
            if (suffix.length() < 4) {
                suffix = std::string("0000").substr(0, 4 - suffix.length()) + suffix;
            }
            suffix = "-" + suffix;
            write_snapshot (wrld, suffix);
        }
    }
    else {
        nSteps = wrld->run (stepLimit);
    }

#else // !DIDEROT_EXEC_SNAPSHOT

    nSteps = wrld->run (stepLimit);

#endif // DIDEROT_EXEC_SNAPSHOT

    if (wrld->_errors->errNum > 0) {
        std::cerr << "Error during execution:\n" << wrld->get_errors() << std::endl;
        delete wrld;
        exit(1);
    }

    if ((stepLimit != 0) && (wrld->_strands.num_active() > 0)) {
#ifdef DIDEROT_STRAND_ARRAY
        if (wrld->_verbose) {
            std::cerr << "Step limit expired; "
                << wrld->_strands.num_active() << " active strands remaining" << std::endl;
        }
#else
      // step limit expired, so kill remaining strands
        if (wrld->_verbose) {
            std::cerr << "Step limit expired. Killing remaining "
                << wrld->_strands.num_active() << " active strands" << std::endl;
        }
        wrld->kill_all();
#endif
    }

    if (wrld->_verbose) {
        std::cerr << "done: " << nSteps << " steps, in " << wrld->_run_time << " seconds";
#ifndef DIDEROT_STRAND_ARRAY
        std::cerr << "; " << wrld->_strands.num_stable() << " stable strands" << std::endl;
#else
        std::cerr << std::endl;
#endif
    }
    else if (timingFlg) {
        std::cout << "usr=" << wrld->_run_time << std::endl;
    }

  // output the final strand states
    write_output (wrld);

    delete wrld;

    return 0;

} // main
/*---------- end seq-main.in ----------*/

