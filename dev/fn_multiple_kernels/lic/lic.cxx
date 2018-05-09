/*---------- begin cxx-head.in ----------*/
/*! \file lic.cxx
 *
 * Generated from lic.diderot.
 *
 * Command: /Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec lic.diderot
 * Version: vis15:2016-07-29
 */
/*---------- end cxx-head.in ----------*/

#define DIDEROT_HAS_STABILIZE_METHOD
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
    typedef float vec2 __attribute__ ((vector_size (8)));
    typedef float vec6 __attribute__ ((vector_size (32)));
    typedef float vec3 __attribute__ ((vector_size (16)));
    typedef float vec4 __attribute__ ((vector_size (16)));
    struct tensor_ref_2 : public diderot::tensor_ref<float,2> {
        tensor_ref_2 (const float *src);
        tensor_ref_2 (struct tensor_2 const & ten);
        tensor_ref_2 (tensor_ref_2 const & ten);
    };
    struct tensor_ref_3 : public diderot::tensor_ref<float,3> {
        tensor_ref_3 (const float *src);
        tensor_ref_3 (struct tensor_3 const & ten);
        tensor_ref_3 (tensor_ref_3 const & ten);
    };
    struct tensor_ref_3_2 : public diderot::tensor_ref<float,6> {
        tensor_ref_3_2 (const float *src);
        tensor_ref_3_2 (struct tensor_3_2 const & ten);
        tensor_ref_3_2 (tensor_ref_3_2 const & ten);
        tensor_ref_2 last (uint32_t i)
        {
            return &this->_data[i];
        }
    };
    struct tensor_ref_2_2 : public diderot::tensor_ref<float,4> {
        tensor_ref_2_2 (const float *src);
        tensor_ref_2_2 (struct tensor_2_2 const & ten);
        tensor_ref_2_2 (tensor_ref_2_2 const & ten);
        tensor_ref_2 last (uint32_t i)
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
    struct tensor_2 : public diderot::tensor<float,2> {
        tensor_2 ()
            : diderot::tensor<float,2>()
        { }
        tensor_2 (std::initializer_list< float > const & il)
            : diderot::tensor<float,2>(il)
        { }
        tensor_2 (const float *src)
            : diderot::tensor<float,2>(src)
        { }
        tensor_2 (tensor_2 const & ten)
            : diderot::tensor<float,2>(ten._data)
        { }
        ~tensor_2 () { }
        tensor_2 & operator= (tensor_2 const & src);
        tensor_2 & operator= (tensor_ref_2 const & src);
        tensor_2 & operator= (std::initializer_list< float > const & il);
        tensor_2 & operator= (const float *src);
    };
    struct tensor_3_2 : public diderot::tensor<float,6> {
        tensor_3_2 ()
            : diderot::tensor<float,6>()
        { }
        tensor_3_2 (std::initializer_list< float > const & il)
            : diderot::tensor<float,6>(il)
        { }
        tensor_3_2 (const float *src)
            : diderot::tensor<float,6>(src)
        { }
        tensor_3_2 (tensor_3_2 const & ten)
            : diderot::tensor<float,6>(ten._data)
        { }
        ~tensor_3_2 () { }
        tensor_3_2 & operator= (tensor_3_2 const & src);
        tensor_3_2 & operator= (tensor_ref_3_2 const & src);
        tensor_3_2 & operator= (std::initializer_list< float > const & il);
        tensor_3_2 & operator= (const float *src);
        tensor_ref_2 last (uint32_t i)
        {
            return &this->_data[i];
        }
    };
    struct tensor_2_2 : public diderot::tensor<float,4> {
        tensor_2_2 ()
            : diderot::tensor<float,4>()
        { }
        tensor_2_2 (std::initializer_list< float > const & il)
            : diderot::tensor<float,4>(il)
        { }
        tensor_2_2 (const float *src)
            : diderot::tensor<float,4>(src)
        { }
        tensor_2_2 (tensor_2_2 const & ten)
            : diderot::tensor<float,4>(ten._data)
        { }
        ~tensor_2_2 () { }
        tensor_2_2 & operator= (tensor_2_2 const & src);
        tensor_2_2 & operator= (tensor_ref_2_2 const & src);
        tensor_2_2 & operator= (std::initializer_list< float > const & il);
        tensor_2_2 & operator= (const float *src);
        tensor_ref_2 last (uint32_t i)
        {
            return &this->_data[i];
        }
    };
    inline tensor_ref_2::tensor_ref_2 (const float *src)
        : diderot::tensor_ref<float,2>(src)
    { }
    inline tensor_ref_2::tensor_ref_2 (struct tensor_2 const & ten)
        : diderot::tensor_ref<float,2>(ten._data)
    { }
    inline tensor_ref_2::tensor_ref_2 (tensor_ref_2 const & ten)
        : diderot::tensor_ref<float,2>(ten._data)
    { }
    inline tensor_ref_3::tensor_ref_3 (const float *src)
        : diderot::tensor_ref<float,3>(src)
    { }
    inline tensor_ref_3::tensor_ref_3 (struct tensor_3 const & ten)
        : diderot::tensor_ref<float,3>(ten._data)
    { }
    inline tensor_ref_3::tensor_ref_3 (tensor_ref_3 const & ten)
        : diderot::tensor_ref<float,3>(ten._data)
    { }
    inline tensor_ref_3_2::tensor_ref_3_2 (const float *src)
        : diderot::tensor_ref<float,6>(src)
    { }
    inline tensor_ref_3_2::tensor_ref_3_2 (struct tensor_3_2 const & ten)
        : diderot::tensor_ref<float,6>(ten._data)
    { }
    inline tensor_ref_3_2::tensor_ref_3_2 (tensor_ref_3_2 const & ten)
        : diderot::tensor_ref<float,6>(ten._data)
    { }
    inline tensor_ref_2_2::tensor_ref_2_2 (const float *src)
        : diderot::tensor_ref<float,4>(src)
    { }
    inline tensor_ref_2_2::tensor_ref_2_2 (struct tensor_2_2 const & ten)
        : diderot::tensor_ref<float,4>(ten._data)
    { }
    inline tensor_ref_2_2::tensor_ref_2_2 (tensor_ref_2_2 const & ten)
        : diderot::tensor_ref<float,4>(ten._data)
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
    inline tensor_2 & tensor_2::operator= (tensor_2 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_2 & tensor_2::operator= (tensor_ref_2 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_2 & tensor_2::operator= (std::initializer_list< float > const & il)
    {
        this->copy(il);
        return *this;
    }
    inline tensor_2 & tensor_2::operator= (const float *src)
    {
        this->copy(src);
        return *this;
    }
    inline tensor_3_2 & tensor_3_2::operator= (tensor_3_2 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_3_2 & tensor_3_2::operator= (tensor_ref_3_2 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_3_2 & tensor_3_2::operator= (std::initializer_list< float > const & il)
    {
        this->copy(il);
        return *this;
    }
    inline tensor_3_2 & tensor_3_2::operator= (const float *src)
    {
        this->copy(src);
        return *this;
    }
    inline tensor_2_2 & tensor_2_2::operator= (tensor_2_2 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_2_2 & tensor_2_2::operator= (tensor_ref_2_2 const & src)
    {
        this->copy(src._data);
        return *this;
    }
    inline tensor_2_2 & tensor_2_2::operator= (std::initializer_list< float > const & il)
    {
        this->copy(il);
        return *this;
    }
    inline tensor_2_2 & tensor_2_2::operator= (const float *src)
    {
        this->copy(src);
        return *this;
    }
} // namespace Diderot
// ***** End synthesized types *****

/*---------- begin namespace-open.in ----------*/
namespace Diderot {

static std::string ProgramName = "lic";

struct world;
struct LIC_strand;
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
    int32_t gv_sizeX;
    int32_t gv_sizeY;
    float gv_h0;
    tensor_2 gv_xymin;
    tensor_2 gv_xymax;
    float gv_vortmax;
    float gv_velomax;
    int32_t gv_ovsmp;
    int32_t gv_stepnum;
    float gv_stdv;
    diderot::image2d< float, float > gv_imgXXX;
    diderot::image2d< float, float > gv_imgXXXX;
    diderot::image1d< float, float > gv_imgXXXXX;
    ~globals ()
    {
        this->gv_imgXXX.free_data();
        this->gv_imgXXXX.free_data();
        this->gv_imgXXXXX.free_data();
    }
};
struct LIC_strand {
    float sv_h;
    tensor_2 sv_x;
    float sv_sum;
    int32_t sv_step;
    tensor_3 sv_rgb;
    tensor_2 sv_x0;
};
/*---------- begin seq-sarr.in ----------*/
// forward declarations of strand methods
#ifdef DIDEROT_HAS_START_METHOD
static diderot::strand_status LIC_start (LIC_strand *self);
#endif // DIDEROT_HAS_START_METHOD
static diderot::strand_status LIC_update (globals *glob, LIC_strand *self);
#ifdef DIDEROT_HAS_STABILIZE_METHOD
static void LIC_stabilize (globals *glob, LIC_strand *self);
#endif // DIDEROT_HAS_STABILIZE_METHOD

// if we have both communication and "die", then we need to track when strands die
// so that we can rebuild the list of strands use to construct the kd-tree
#if defined(DIDEROT_HAS_STRAND_COMMUNICATION) && !defined(DIDEROT_HAS_STRAND_DIE)
#  define TRACK_STRAND_DEATH
#endif

// strand_array for SEQUENTIAL/NO BSP/SINGLE STATE/DIRECT ACCESS
//
struct strand_array {
    typedef LIC_strand strand_t;
    typedef uint32_t index_t;
    typedef index_t sid_t;              // strand ID (index into strand-state storage)

    uint8_t             *_status;       // the array of status information for the strands
    char                *_storage;      // points to array of LIC_strand structs
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
    LIC_strand *id_to_strand (sid_t id) const
    {
        assert (id < this->_nItems);
        return reinterpret_cast<LIC_strand *>(this->_storage + id * sizeof(LIC_strand));
    }

  // return a strand's status
    diderot::strand_status status (index_t ix) const
    {
        assert (ix < this->_nItems);
        return static_cast<diderot::strand_status>(this->_status[ix]);
    }
  // return a pointer to the given strand
    LIC_strand *strand (index_t ix) const
    {
        return this->id_to_strand(this->id(ix));
    }
  // return a pointer to the local state of strand ix
    LIC_strand *local_state (index_t ix) const
    {
        return this->strand(ix);
    }
  // return a pointer to the local state of strand with the given ID
    LIC_strand *id_to_local_state (sid_t id) const
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
        this->_storage = static_cast<char *>(std::malloc (nItems * sizeof(LIC_strand)));
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
            new (this->strand(ix)) LIC_strand;
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
        return LIC_start(this->strand(ix));
    }
#endif // DIDEROT_HAS_START_METHOD

  // invoke strand's update method
    diderot::strand_status strand_update (globals *glob, index_t ix)
    {
        return LIC_update(glob, this->strand(ix));
    }

  // invoke strand's stabilize method
    index_t strand_stabilize (globals *glob, index_t ix)
    {
#ifdef DIDEROT_HAS_STABILIZE_METHOD
        LIC_stabilize (glob, this->strand(ix));
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
        this->strand(ix)->~LIC_strand();
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
    bool alloc (int32_t base[3], uint32_t size[3]);
    bool create_strands ();
    uint32_t run (uint32_t max_nsteps);
    void swap_state ();
};
// ***** Begin synthesized operations *****

template <typename TY>
inline bool inside2Ds1 (vec2 x0, diderot::image2d< float, TY > img)
{
    return 0 < x0[0] && x0[1] < img.size(1) - 1 && 0 < x0[1] && x0[0] < img.size(0) - 1;
}
inline float vdot6 (vec6 u, vec6 v)
{
    vec6 w = u * v;
    return w[0] + w[1] + w[2] + w[3] + w[4] + w[5];
}
inline diderot::array< int, 2 > vtoi2 (vec2 src)
{
    diderot::array< int, 2 > res = {int32_t(src[0]),int32_t(src[1]),};
    return res;
}
inline float clamp (float lo, float hi, float x)
{
    return x <= lo ? lo : hi <= x ? hi : x;
}
inline vec2 vload2 (const float *vp)
{
    return __extension__ (vec2){vp[0], vp[1]};
}
inline vec2 vcons2 (float r0, float r1)
{
    return __extension__ (vec2){r0, r1};
}
inline vec3 vcons3 (float r0, float r1, float r2)
{
    return __extension__ (vec3){r0, r1, r2, 0.0f};
}
inline void vpack2 (tensor_2 &dst, vec2 v0)
{
    dst._data[0] = v0[0];
    dst._data[1] = v0[1];
}
template <typename TY>
inline float world2image (diderot::image1d< float, TY > const & img)
{
    return img.world2image();
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
template <typename TY>
inline tensor_ref_2_2 world2image (diderot::image2d< float, TY > const & img)
{
    return tensor_ref_2_2(img.world2image());
}
inline vec3 vscale3 (float s, vec3 v)
{
    return __extension__ (vec3){s, s, s, 0.0f} * v;
}
template <typename TY>
inline float translate (diderot::image1d< float, TY > const & img)
{
    return img.translate();
}
inline float vdot2 (vec2 u, vec2 v)
{
    vec2 w = u * v;
    return w[0] + w[1];
}
template <typename TY>
inline tensor_ref_2 translate (diderot::image2d< float, TY > const & img)
{
    return tensor_ref_2(img.translate());
}
inline vec6 vcons6 (float r0, float r1, float r2, float r3, float r4, float r5)
{
    return __extension__ (vec6){r0, r1, r2, r3, r4, r5, 0.0f, 0.0f};
}
inline float vdot4 (vec4 u, vec4 v)
{
    vec4 w = u * v;
    return w[0] + w[1] + w[2] + w[3];
}
inline vec2 vfloor2 (vec2 v)
{
    return __extension__ (vec2){diderot::floor(v[0]), diderot::floor(v[1])};
}
// ***** End synthesized operations *****

typedef struct {
    int32_t gv_sizeX;
    int32_t gv_sizeY;
    float gv_h0;
    tensor_2 gv_xymin;
    tensor_2 gv_xymax;
    float gv_vortmax;
    float gv_velomax;
    int32_t gv_ovsmp;
    int32_t gv_stepnum;
} cmd_line_inputs;
static void init_defaults (cmd_line_inputs *inp)
{
    inp->gv_sizeX = 800;
    inp->gv_sizeY = 200;
    inp->gv_h0 = 0.4e-1f;
    inp->gv_xymin[0] = -0.119167e2f;
    inp->gv_xymin[1] = -0.39375e1f;
    inp->gv_xymax[0] = 0.19917e2f;
    inp->gv_xymax[1] = 0.39375e1f;
    inp->gv_vortmax = 0.4e1f;
    inp->gv_velomax = 0.1e1f;
    inp->gv_ovsmp = 1;
    inp->gv_stepnum = 30;
}
static void register_inputs (cmd_line_inputs *inp, diderot::options *opts)
{
    opts->add("sizeX", "faster size of LIC output, before oversampling", &inp->gv_sizeX, true);
    opts->add("sizeY", "slower size of LIC output, before oversampling", &inp->gv_sizeY, true);
    opts->add("h0", "step size of streamline integration", &inp->gv_h0, true);
    opts->add("xymin", "X,Y at lower corner of bounding box", 2, inp->gv_xymin._data, true);
    opts->add("xymax", "X,Y at upper corner of bounding box", 2, inp->gv_xymax._data, true);
    opts->add("vortmax", "vorticity to map to ends of colormap", &inp->gv_vortmax, true);
    opts->add("velomax", "velocity that produces maximal contrast", &inp->gv_velomax, true);
    opts->add("ovsmp", "amount of image oversampling (for anti-aliasing)", &inp->gv_ovsmp, true);
    opts->add("stepnum", "# steps in each streamline half", &inp->gv_stepnum, true);
}
static bool init_inputs (world *wrld, cmd_line_inputs *inp)
{
    globals *glob = wrld->_globals;
    glob->gv_sizeX = inp->gv_sizeX;
    glob->gv_sizeY = inp->gv_sizeY;
    glob->gv_h0 = inp->gv_h0;
    glob->gv_xymin = inp->gv_xymin;
    glob->gv_xymax = inp->gv_xymax;
    glob->gv_vortmax = inp->gv_vortmax;
    glob->gv_velomax = inp->gv_velomax;
    glob->gv_ovsmp = inp->gv_ovsmp;
    glob->gv_stepnum = inp->gv_stepnum;
    return false;
}
static std::string OutputFile = "rgb.nrrd";
static void register_outputs (diderot::options *opts)
{
    opts->add("o,output", "specify output file", &OutputFile, true);
}
static bool init_globals (world *wrld)
{
    diderot::image2d< float, float > l_img_2;
    diderot::image2d< float, float > l_img_3;
    diderot::image1d< float, float > l_img_4;
    globals *glob = wrld->_globals;
    glob->gv_stdv = std::sqrt(0.5e0f + static_cast<float>(glob->gv_stepnum));
    if (l_img_2.load(wrld, "flow.nrrd")) {
        return true;
    }
    if (l_img_3.load(wrld, "rand.nrrd")) {
        return true;
    }
    if (l_img_4.load(wrld, "cmap.nrrd")) {
        return true;
    }
    glob->gv_imgXXX = l_img_3;
    glob->gv_imgXXXX = l_img_2;
    glob->gv_imgXXXXX = l_img_4;
    return false;
}
static void LIC_init (globals *glob, LIC_strand *self, tensor_ref_2 p_x0_5, float p_sign_6)
{
    tensor_ref_2_2 l_Mtransform_7 = world2image(glob->gv_imgXXX);
    vec2 v_8 = vcons2(vdot2(vload2(l_Mtransform_7.last(0).addr(0)), vload2(p_x0_5.addr(0))),
        vdot2(vload2(l_Mtransform_7.last(2).addr(0)), vload2(p_x0_5.addr(0)))) + vload2(
        translate(glob->gv_imgXXX).addr(0));
    vec2 v_9 = vfloor2(v_8);
    vec2 v_10 = v_8 - v_9;
    diderot::array< int32_t, 2 > l_n_11 = vtoi2(v_9);
    float l_vY__12 = v_10[1];
    vec2 v_13 = vcons2(0.1e1f, 0.1e1f);
    vec2 v_14 = vcons2(-0.1e1f, 0.1e1f);
    float l_vX__15 = v_10[0];
    vec2 v_16 = v_13 + vcons2(l_vX__15, l_vX__15 - 0.1e1f) * v_14;
    int32_t l_nX__17 = l_n_11[0];
    int32_t l_nY__18 = l_n_11[1];
    int32_t l_ix_19 = glob->gv_imgXXX.wrap(0, l_nX__17);
    int32_t l_mulRes_20 = 800 * glob->gv_imgXXX.wrap(1, l_nY__18);
    int32_t l_ix_21 = glob->gv_imgXXX.wrap(0, l_nX__17 + 1);
    int32_t l_mulRes_22 = 800 * glob->gv_imgXXX.wrap(1, l_nY__18 + 1);
    self->sv_h = p_sign_6 * glob->gv_h0;
    self->sv_x = p_x0_5;
    self->sv_sum = vdot2(v_13 + vcons2(l_vY__12, l_vY__12 - 0.1e1f) * v_14,
        vcons2(vdot2(v_16, vcons2(glob->gv_imgXXX[l_ix_19 + l_mulRes_20], glob->gv_imgXXX[l_ix_21 + l_mulRes_20])),
            vdot2(v_16, vcons2(glob->gv_imgXXX[l_ix_19 + l_mulRes_22], glob->gv_imgXXX[l_ix_21 + l_mulRes_22])))) / 0.2e1f;
    self->sv_step = 0;
    self->sv_rgb[0] = 0.0f;
    self->sv_rgb[1] = 0.0f;
    self->sv_rgb[2] = 0.0f;
    self->sv_x0 = p_x0_5;
}
static diderot::strand_status LIC_update (globals *glob, LIC_strand *self)
{
    bool l__t_143;
    tensor_ref_2_2 l_Mtransform_24 = world2image(glob->gv_imgXXXX);
    tensor_ref_2 l_projParam_25 = l_Mtransform_24.last(0);
    tensor_ref_2 l_projParam_26 = l_Mtransform_24.last(2);
    tensor_ref_2 l_Ttranslate_27 = translate(glob->gv_imgXXXX);
    vec2 v_28 = vcons2(vdot2(vload2(l_projParam_25.addr(0)), vload2(tensor_ref_2(self->sv_x).addr(0))),
        vdot2(vload2(l_projParam_26.addr(0)), vload2(tensor_ref_2(self->sv_x).addr(0)))) + vload2(
        l_Ttranslate_27.addr(0));
    vec2 v_29 = vfloor2(v_28);
    vec2 v_30 = v_28 - v_29;
    diderot::array< int32_t, 2 > l_n_31 = vtoi2(v_29);
    float l_vY__32 = v_30[1];
    vec6 v_33 = vcons6(l_vY__32 + 0.2e1f, l_vY__32 + 0.1e1f, l_vY__32, l_vY__32 - 0.1e1f, l_vY__32 - 0.2e1f,
        l_vY__32 - 0.3e1f);
    vec6 v_34 = vcons6(0.961875e1f, 0.1875e-1f, 0.8625e0f, 0.8625e0f, 0.1875e-1f, 0.961875e1f);
    vec6 v_35 = vcons6(-0.23625e2f, 0.4375e1f, 0.0f, 0.0f, -0.4375e1f, 0.23625e2f);
    vec6 v_36 = vcons6(0.2334375e2f, -0.1065625e2f, -0.14375e1f, -0.14375e1f, -0.1065625e2f, 0.2334375e2f);
    vec6 v_37 = vcons6(-0.12e2f, 0.10e2f, 0.0f, 0.0f, -0.10e2f, 0.12e2f);
    vec6 v_38 = vcons6(0.340625e1f, -0.459375e1f, 0.11875e1f, 0.11875e1f, -0.459375e1f, 0.340625e1f);
    vec6 v_39 = vcons6(-0.508333333333e0f, 0.104166666667e1f, -0.583333333333e0f, 0.583333333333e0f,
        -0.104166666667e1f, 0.508333333333e0f);
    vec6 v_40 = vcons6(0.3125e-1f, -0.9375e-1f, 0.625e-1f, 0.625e-1f, -0.9375e-1f, 0.3125e-1f);
    vec6 v_41 = v_34 + v_33 * (v_35 + v_33 * (v_36 + v_33 * (v_37 + v_33 * (v_38 + v_33 * (v_39 + v_33 * v_40)))));
    float l_vX__42 = v_30[0];
    vec4 v_43 = vcons4(l_vX__42 + 0.1e1f, l_vX__42, l_vX__42 - 0.1e1f, l_vX__42 - 0.2e1f);
    vec4 v_44 = vcons4(0.2e1f, 0.1e1f, 0.1e1f, 0.2e1f);
    vec4 v_45 = vcons4(-0.4e1f, 0.0f, 0.0f, 0.4e1f);
    vec4 v_46 = vcons4(0.25e1f, -0.25e1f, -0.25e1f, 0.25e1f);
    vec4 v_47 = vcons4(-0.5e0f, 0.15e1f, -0.15e1f, 0.5e0f);
    vec4 v_48 = v_44 + v_43 * (v_45 + v_43 * (v_46 + v_43 * v_47));
    int32_t l_idx_49 = l_n_31[0] + -1;
    int32_t l_idx_50 = l_n_31[1] + -2;
    int32_t l_ix_51 = glob->gv_imgXXXX.clamp(0, l_idx_49);
    int32_t l_mulRes_52 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_50);
    int32_t l_offp_53 = 2 * (l_ix_51 + l_mulRes_52);
    int32_t l_ix_54 = glob->gv_imgXXXX.clamp(0, l_idx_49 + 1);
    int32_t l_offp_55 = 2 * (l_ix_54 + l_mulRes_52);
    int32_t l_ix_56 = glob->gv_imgXXXX.clamp(0, l_idx_49 + 2);
    int32_t l_offp_57 = 2 * (l_ix_56 + l_mulRes_52);
    int32_t l_ix_58 = glob->gv_imgXXXX.clamp(0, l_idx_49 + 3);
    int32_t l_offp_59 = 2 * (l_ix_58 + l_mulRes_52);
    int32_t l_mulRes_60 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_50 + 1);
    int32_t l_offp_61 = 2 * (l_ix_51 + l_mulRes_60);
    int32_t l_offp_62 = 2 * (l_ix_54 + l_mulRes_60);
    int32_t l_offp_63 = 2 * (l_ix_56 + l_mulRes_60);
    int32_t l_offp_64 = 2 * (l_ix_58 + l_mulRes_60);
    int32_t l_mulRes_65 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_50 + 2);
    int32_t l_offp_66 = 2 * (l_ix_51 + l_mulRes_65);
    int32_t l_offp_67 = 2 * (l_ix_54 + l_mulRes_65);
    int32_t l_offp_68 = 2 * (l_ix_56 + l_mulRes_65);
    int32_t l_offp_69 = 2 * (l_ix_58 + l_mulRes_65);
    int32_t l_mulRes_70 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_50 + 3);
    int32_t l_offp_71 = 2 * (l_ix_51 + l_mulRes_70);
    int32_t l_offp_72 = 2 * (l_ix_54 + l_mulRes_70);
    int32_t l_offp_73 = 2 * (l_ix_56 + l_mulRes_70);
    int32_t l_offp_74 = 2 * (l_ix_58 + l_mulRes_70);
    int32_t l_mulRes_75 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_50 + 4);
    int32_t l_offp_76 = 2 * (l_ix_51 + l_mulRes_75);
    int32_t l_offp_77 = 2 * (l_ix_54 + l_mulRes_75);
    int32_t l_offp_78 = 2 * (l_ix_56 + l_mulRes_75);
    int32_t l_offp_79 = 2 * (l_ix_58 + l_mulRes_75);
    int32_t l_mulRes_80 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_50 + 5);
    int32_t l_offp_81 = 2 * (l_ix_51 + l_mulRes_80);
    int32_t l_offp_82 = 2 * (l_ix_54 + l_mulRes_80);
    int32_t l_offp_83 = 2 * (l_ix_56 + l_mulRes_80);
    int32_t l_offp_84 = 2 * (l_ix_58 + l_mulRes_80);
    float l_vdot_85 = vdot6(v_41,
        vcons6(
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_53], glob->gv_imgXXXX[l_offp_55], glob->gv_imgXXXX[l_offp_57],
                    glob->gv_imgXXXX[l_offp_59])),
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_61], glob->gv_imgXXXX[l_offp_62], glob->gv_imgXXXX[l_offp_63],
                    glob->gv_imgXXXX[l_offp_64])),
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_66], glob->gv_imgXXXX[l_offp_67], glob->gv_imgXXXX[l_offp_68],
                    glob->gv_imgXXXX[l_offp_69])),
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_71], glob->gv_imgXXXX[l_offp_72], glob->gv_imgXXXX[l_offp_73],
                    glob->gv_imgXXXX[l_offp_74])),
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_76], glob->gv_imgXXXX[l_offp_77], glob->gv_imgXXXX[l_offp_78],
                    glob->gv_imgXXXX[l_offp_79])),
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_81], glob->gv_imgXXXX[l_offp_82], glob->gv_imgXXXX[l_offp_83],
                    glob->gv_imgXXXX[l_offp_84]))));
    float l_vdot_86 = vdot6(v_41,
        vcons6(
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_53 + 1], glob->gv_imgXXXX[l_offp_55 + 1],
                    glob->gv_imgXXXX[l_offp_57 + 1], glob->gv_imgXXXX[l_offp_59 + 1])),
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_61 + 1], glob->gv_imgXXXX[l_offp_62 + 1],
                    glob->gv_imgXXXX[l_offp_63 + 1], glob->gv_imgXXXX[l_offp_64 + 1])),
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_66 + 1], glob->gv_imgXXXX[l_offp_67 + 1],
                    glob->gv_imgXXXX[l_offp_68 + 1], glob->gv_imgXXXX[l_offp_69 + 1])),
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_71 + 1], glob->gv_imgXXXX[l_offp_72 + 1],
                    glob->gv_imgXXXX[l_offp_73 + 1], glob->gv_imgXXXX[l_offp_74 + 1])),
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_76 + 1], glob->gv_imgXXXX[l_offp_77 + 1],
                    glob->gv_imgXXXX[l_offp_78 + 1], glob->gv_imgXXXX[l_offp_79 + 1])),
            vdot4(v_48,
                vcons4(glob->gv_imgXXXX[l_offp_81 + 1], glob->gv_imgXXXX[l_offp_82 + 1],
                    glob->gv_imgXXXX[l_offp_83 + 1], glob->gv_imgXXXX[l_offp_84 + 1]))));
    vec2 v_87 = vcons2(l_vdot_85, l_vdot_86);
    float l_op1_e3_l_13_88 = 0.1e1f / std::sqrt(vdot2(v_87, v_87));
    float l_r_89 = 0.5e0f * self->sv_h;
    vec2 v_90 = vload2(tensor_ref_2(self->sv_x).addr(0)) + vcons2(l_r_89 * l_vdot_85 * l_op1_e3_l_13_88,
        l_r_89 * l_vdot_86 * l_op1_e3_l_13_88);
    vec2 v_91 = vcons2(vdot2(vload2(l_projParam_25.addr(0)), v_90), vdot2(vload2(l_projParam_26.addr(0)), v_90)) + vload2(
        l_Ttranslate_27.addr(0));
    vec2 v_92 = vfloor2(v_91);
    vec2 v_93 = v_91 - v_92;
    diderot::array< int32_t, 2 > l_n_94 = vtoi2(v_92);
    float l_vY__95 = v_93[1];
    vec6 v_96 = vcons6(l_vY__95 + 0.2e1f, l_vY__95 + 0.1e1f, l_vY__95, l_vY__95 - 0.1e1f, l_vY__95 - 0.2e1f,
        l_vY__95 - 0.3e1f);
    vec6 v_97 = v_34 + v_96 * (v_35 + v_96 * (v_36 + v_96 * (v_37 + v_96 * (v_38 + v_96 * (v_39 + v_96 * v_40)))));
    float l_vX__98 = v_93[0];
    vec4 v_99 = vcons4(l_vX__98 + 0.1e1f, l_vX__98, l_vX__98 - 0.1e1f, l_vX__98 - 0.2e1f);
    vec4 v_100 = v_44 + v_99 * (v_45 + v_99 * (v_46 + v_99 * v_47));
    int32_t l_idx_101 = l_n_94[0] + -1;
    int32_t l_idx_102 = l_n_94[1] + -2;
    int32_t l_ix_103 = glob->gv_imgXXXX.clamp(0, l_idx_101);
    int32_t l_mulRes_104 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_102);
    int32_t l_offp_105 = 2 * (l_ix_103 + l_mulRes_104);
    int32_t l_ix_106 = glob->gv_imgXXXX.clamp(0, l_idx_101 + 1);
    int32_t l_offp_107 = 2 * (l_ix_106 + l_mulRes_104);
    int32_t l_ix_108 = glob->gv_imgXXXX.clamp(0, l_idx_101 + 2);
    int32_t l_offp_109 = 2 * (l_ix_108 + l_mulRes_104);
    int32_t l_ix_110 = glob->gv_imgXXXX.clamp(0, l_idx_101 + 3);
    int32_t l_offp_111 = 2 * (l_ix_110 + l_mulRes_104);
    int32_t l_mulRes_112 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_102 + 1);
    int32_t l_offp_113 = 2 * (l_ix_103 + l_mulRes_112);
    int32_t l_offp_114 = 2 * (l_ix_106 + l_mulRes_112);
    int32_t l_offp_115 = 2 * (l_ix_108 + l_mulRes_112);
    int32_t l_offp_116 = 2 * (l_ix_110 + l_mulRes_112);
    int32_t l_mulRes_117 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_102 + 2);
    int32_t l_offp_118 = 2 * (l_ix_103 + l_mulRes_117);
    int32_t l_offp_119 = 2 * (l_ix_106 + l_mulRes_117);
    int32_t l_offp_120 = 2 * (l_ix_108 + l_mulRes_117);
    int32_t l_offp_121 = 2 * (l_ix_110 + l_mulRes_117);
    int32_t l_mulRes_122 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_102 + 3);
    int32_t l_offp_123 = 2 * (l_ix_103 + l_mulRes_122);
    int32_t l_offp_124 = 2 * (l_ix_106 + l_mulRes_122);
    int32_t l_offp_125 = 2 * (l_ix_108 + l_mulRes_122);
    int32_t l_offp_126 = 2 * (l_ix_110 + l_mulRes_122);
    int32_t l_mulRes_127 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_102 + 4);
    int32_t l_offp_128 = 2 * (l_ix_103 + l_mulRes_127);
    int32_t l_offp_129 = 2 * (l_ix_106 + l_mulRes_127);
    int32_t l_offp_130 = 2 * (l_ix_108 + l_mulRes_127);
    int32_t l_offp_131 = 2 * (l_ix_110 + l_mulRes_127);
    int32_t l_mulRes_132 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_102 + 5);
    int32_t l_offp_133 = 2 * (l_ix_103 + l_mulRes_132);
    int32_t l_offp_134 = 2 * (l_ix_106 + l_mulRes_132);
    int32_t l_offp_135 = 2 * (l_ix_108 + l_mulRes_132);
    int32_t l_offp_136 = 2 * (l_ix_110 + l_mulRes_132);
    float l_vdot_137 = vdot6(v_97,
        vcons6(
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_105], glob->gv_imgXXXX[l_offp_107], glob->gv_imgXXXX[l_offp_109],
                    glob->gv_imgXXXX[l_offp_111])),
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_113], glob->gv_imgXXXX[l_offp_114], glob->gv_imgXXXX[l_offp_115],
                    glob->gv_imgXXXX[l_offp_116])),
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_118], glob->gv_imgXXXX[l_offp_119], glob->gv_imgXXXX[l_offp_120],
                    glob->gv_imgXXXX[l_offp_121])),
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_123], glob->gv_imgXXXX[l_offp_124], glob->gv_imgXXXX[l_offp_125],
                    glob->gv_imgXXXX[l_offp_126])),
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_128], glob->gv_imgXXXX[l_offp_129], glob->gv_imgXXXX[l_offp_130],
                    glob->gv_imgXXXX[l_offp_131])),
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_133], glob->gv_imgXXXX[l_offp_134], glob->gv_imgXXXX[l_offp_135],
                    glob->gv_imgXXXX[l_offp_136]))));
    float l_vdot_138 = vdot6(v_97,
        vcons6(
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_105 + 1], glob->gv_imgXXXX[l_offp_107 + 1],
                    glob->gv_imgXXXX[l_offp_109 + 1], glob->gv_imgXXXX[l_offp_111 + 1])),
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_113 + 1], glob->gv_imgXXXX[l_offp_114 + 1],
                    glob->gv_imgXXXX[l_offp_115 + 1], glob->gv_imgXXXX[l_offp_116 + 1])),
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_118 + 1], glob->gv_imgXXXX[l_offp_119 + 1],
                    glob->gv_imgXXXX[l_offp_120 + 1], glob->gv_imgXXXX[l_offp_121 + 1])),
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_123 + 1], glob->gv_imgXXXX[l_offp_124 + 1],
                    glob->gv_imgXXXX[l_offp_125 + 1], glob->gv_imgXXXX[l_offp_126 + 1])),
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_128 + 1], glob->gv_imgXXXX[l_offp_129 + 1],
                    glob->gv_imgXXXX[l_offp_130 + 1], glob->gv_imgXXXX[l_offp_131 + 1])),
            vdot4(v_100,
                vcons4(glob->gv_imgXXXX[l_offp_133 + 1], glob->gv_imgXXXX[l_offp_134 + 1],
                    glob->gv_imgXXXX[l_offp_135 + 1], glob->gv_imgXXXX[l_offp_136 + 1]))));
    vec2 v_139 = vcons2(l_vdot_137, l_vdot_138);
    float l_op1_e3_l_12_140 = 0.1e1f / std::sqrt(vdot2(v_139, v_139));
    vec2 v_141 = vload2(tensor_ref_2(self->sv_x).addr(0)) + vcons2(self->sv_h * l_vdot_137 * l_op1_e3_l_12_140,
        self->sv_h * l_vdot_138 * l_op1_e3_l_12_140);
    vec2 v_142 = v_141;
    if (self->sv_step == glob->gv_stepnum) {
        l__t_143 = true;
    }
    else {
        tensor_ref_2_2 l_Mtransform_144 = world2image(glob->gv_imgXXX);
        l__t_143 = !inside2Ds1(
            vcons2(vdot2(vload2(l_Mtransform_144.last(0).addr(0)), v_142),
                vdot2(vload2(l_Mtransform_144.last(2).addr(0)), v_142)) + vload2(translate(glob->gv_imgXXX).addr(0)),
            glob->gv_imgXXX);
    }
    if (l__t_143) {
        vpack2(self->sv_x, v_142);
        self->sv_rgb = tensor_ref_3(self->sv_rgb);
        return diderot::kStabilize;
    }
    tensor_ref_2_2 l_Mtransform_146 = world2image(glob->gv_imgXXX);
    vec2 v_147 = vcons2(vdot2(vload2(l_Mtransform_146.last(0).addr(0)), v_142),
        vdot2(vload2(l_Mtransform_146.last(2).addr(0)), v_142)) + vload2(translate(glob->gv_imgXXX).addr(0));
    vec2 v_148 = vfloor2(v_147);
    vec2 v_149 = v_147 - v_148;
    diderot::array< int32_t, 2 > l_n_150 = vtoi2(v_148);
    float l_vY__151 = v_149[1];
    vec2 v_152 = vcons2(0.1e1f, 0.1e1f);
    vec2 v_153 = vcons2(-0.1e1f, 0.1e1f);
    float l_vX__154 = v_149[0];
    vec2 v_155 = v_152 + vcons2(l_vX__154, l_vX__154 - 0.1e1f) * v_153;
    int32_t l_nX__156 = l_n_150[0];
    int32_t l_nY__157 = l_n_150[1];
    int32_t l_ix_158 = glob->gv_imgXXX.wrap(0, l_nX__156);
    int32_t l_mulRes_159 = 800 * glob->gv_imgXXX.wrap(1, l_nY__157);
    int32_t l_ix_160 = glob->gv_imgXXX.wrap(0, l_nX__156 + 1);
    int32_t l_mulRes_161 = 800 * glob->gv_imgXXX.wrap(1, l_nY__157 + 1);
    vpack2(self->sv_x, v_142);
    self->sv_sum = self->sv_sum + vdot2(v_152 + vcons2(l_vY__151, l_vY__151 - 0.1e1f) * v_153,
        vcons2(
            vdot2(v_155, vcons2(glob->gv_imgXXX[l_ix_158 + l_mulRes_159], glob->gv_imgXXX[l_ix_160 + l_mulRes_159])),
            vdot2(v_155, vcons2(glob->gv_imgXXX[l_ix_158 + l_mulRes_161], glob->gv_imgXXX[l_ix_160 + l_mulRes_161]))));
    self->sv_step = self->sv_step + 1;
    self->sv_rgb = tensor_ref_3(self->sv_rgb);
    return diderot::kActive;
}
static void LIC_stabilize (globals *glob, LIC_strand *self)
{
    tensor_3_2 l_voxels_246;
    tensor_ref_2_2 l_Mtransform_163 = world2image(glob->gv_imgXXXX);
    vec2 v_164 = vcons2(vdot2(vload2(l_Mtransform_163.last(0).addr(0)), vload2(tensor_ref_2(self->sv_x0).addr(0))),
        vdot2(vload2(l_Mtransform_163.last(2).addr(0)), vload2(tensor_ref_2(self->sv_x0).addr(0)))) + vload2(
        translate(glob->gv_imgXXXX).addr(0));
    vec2 v_165 = vfloor2(v_164);
    vec2 v_166 = v_164 - v_165;
    diderot::array< int32_t, 2 > l_n_167 = vtoi2(v_165);
    vec2 v_168 = vcons2(l_Mtransform_163[0], l_Mtransform_163[2]);
    vec2 v_169 = vcons2(l_Mtransform_163[1], l_Mtransform_163[3]);
    float l_vY__170 = v_166[1];
    vec6 v_171 = vcons6(l_vY__170 + 0.2e1f, l_vY__170 + 0.1e1f, l_vY__170, l_vY__170 - 0.1e1f, l_vY__170 - 0.2e1f,
        l_vY__170 - 0.3e1f);
    vec6 v_172 = vcons6(-0.23625e2f, 0.4375e1f, 0.0f, 0.0f, -0.4375e1f, 0.23625e2f);
    vec6 v_173 = vcons6(0.961875e1f, 0.1875e-1f, 0.8625e0f, 0.8625e0f, 0.1875e-1f, 0.961875e1f) + v_171 * (v_172 + v_171 * (vcons6(
        0.2334375e2f, -0.1065625e2f, -0.14375e1f, -0.14375e1f, -0.1065625e2f, 0.2334375e2f) + v_171 * (vcons6(-0.12e2f,
        0.10e2f, 0.0f, 0.0f, -0.10e2f, 0.12e2f) + v_171 * (vcons6(0.340625e1f, -0.459375e1f, 0.11875e1f, 0.11875e1f,
        -0.459375e1f, 0.340625e1f) + v_171 * (vcons6(-0.508333333333e0f, 0.104166666667e1f, -0.583333333333e0f,
        0.583333333333e0f, -0.104166666667e1f, 0.508333333333e0f) + v_171 * vcons6(0.3125e-1f, -0.9375e-1f, 0.625e-1f,
        0.625e-1f, -0.9375e-1f, 0.3125e-1f))))));
    vec6 v_174 = v_172 + v_171 * (vcons6(0.466875e2f, -0.213125e2f, -0.2875e1f, -0.2875e1f, -0.213125e2f, 0.466875e2f) + v_171 * (vcons6(
        -0.36e2f, 0.30e2f, 0.0f, 0.0f, -0.30e2f, 0.36e2f) + v_171 * (vcons6(0.13625e2f, -0.18375e2f, 0.475e1f,
        0.475e1f, -0.18375e2f, 0.13625e2f) + v_171 * (vcons6(-0.254166666667e1f, 0.520833333333e1f, -0.291666666667e1f,
        0.291666666667e1f, -0.520833333333e1f, 0.254166666667e1f) + v_171 * vcons6(0.1875e0f, -0.5625e0f, 0.375e0f,
        0.375e0f, -0.5625e0f, 0.1875e0f)))));
    float l_vX__175 = v_166[0];
    vec4 v_176 = vcons4(l_vX__175 + 0.1e1f, l_vX__175, l_vX__175 - 0.1e1f, l_vX__175 - 0.2e1f);
    vec4 v_177 = vcons4(-0.4e1f, 0.0f, 0.0f, 0.4e1f);
    vec4 v_178 = vcons4(0.2e1f, 0.1e1f, 0.1e1f, 0.2e1f) + v_176 * (v_177 + v_176 * (vcons4(0.25e1f, -0.25e1f, -0.25e1f,
        0.25e1f) + v_176 * vcons4(-0.5e0f, 0.15e1f, -0.15e1f, 0.5e0f)));
    vec4 v_179 = v_177 + v_176 * (vcons4(0.5e1f, -0.5e1f, -0.5e1f, 0.5e1f) + v_176 * vcons4(-0.15e1f, 0.45e1f,
        -0.45e1f, 0.15e1f));
    int32_t l_idx_180 = l_n_167[0] + -1;
    int32_t l_idx_181 = l_n_167[1] + -2;
    int32_t l_ix_182 = glob->gv_imgXXXX.clamp(0, l_idx_180);
    int32_t l_mulRes_183 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_181);
    int32_t l_offp_184 = 2 * (l_ix_182 + l_mulRes_183);
    int32_t l_ix_185 = glob->gv_imgXXXX.clamp(0, l_idx_180 + 1);
    int32_t l_offp_186 = 2 * (l_ix_185 + l_mulRes_183);
    int32_t l_ix_187 = glob->gv_imgXXXX.clamp(0, l_idx_180 + 2);
    int32_t l_offp_188 = 2 * (l_ix_187 + l_mulRes_183);
    int32_t l_ix_189 = glob->gv_imgXXXX.clamp(0, l_idx_180 + 3);
    int32_t l_offp_190 = 2 * (l_ix_189 + l_mulRes_183);
    vec4 v_191 = vcons4(glob->gv_imgXXXX[l_offp_184], glob->gv_imgXXXX[l_offp_186], glob->gv_imgXXXX[l_offp_188],
        glob->gv_imgXXXX[l_offp_190]);
    int32_t l_mulRes_192 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_181 + 1);
    int32_t l_offp_193 = 2 * (l_ix_182 + l_mulRes_192);
    int32_t l_offp_194 = 2 * (l_ix_185 + l_mulRes_192);
    int32_t l_offp_195 = 2 * (l_ix_187 + l_mulRes_192);
    int32_t l_offp_196 = 2 * (l_ix_189 + l_mulRes_192);
    vec4 v_197 = vcons4(glob->gv_imgXXXX[l_offp_193], glob->gv_imgXXXX[l_offp_194], glob->gv_imgXXXX[l_offp_195],
        glob->gv_imgXXXX[l_offp_196]);
    int32_t l_mulRes_198 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_181 + 2);
    int32_t l_offp_199 = 2 * (l_ix_182 + l_mulRes_198);
    int32_t l_offp_200 = 2 * (l_ix_185 + l_mulRes_198);
    int32_t l_offp_201 = 2 * (l_ix_187 + l_mulRes_198);
    int32_t l_offp_202 = 2 * (l_ix_189 + l_mulRes_198);
    vec4 v_203 = vcons4(glob->gv_imgXXXX[l_offp_199], glob->gv_imgXXXX[l_offp_200], glob->gv_imgXXXX[l_offp_201],
        glob->gv_imgXXXX[l_offp_202]);
    int32_t l_mulRes_204 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_181 + 3);
    int32_t l_offp_205 = 2 * (l_ix_182 + l_mulRes_204);
    int32_t l_offp_206 = 2 * (l_ix_185 + l_mulRes_204);
    int32_t l_offp_207 = 2 * (l_ix_187 + l_mulRes_204);
    int32_t l_offp_208 = 2 * (l_ix_189 + l_mulRes_204);
    vec4 v_209 = vcons4(glob->gv_imgXXXX[l_offp_205], glob->gv_imgXXXX[l_offp_206], glob->gv_imgXXXX[l_offp_207],
        glob->gv_imgXXXX[l_offp_208]);
    int32_t l_mulRes_210 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_181 + 4);
    int32_t l_offp_211 = 2 * (l_ix_182 + l_mulRes_210);
    int32_t l_offp_212 = 2 * (l_ix_185 + l_mulRes_210);
    int32_t l_offp_213 = 2 * (l_ix_187 + l_mulRes_210);
    int32_t l_offp_214 = 2 * (l_ix_189 + l_mulRes_210);
    vec4 v_215 = vcons4(glob->gv_imgXXXX[l_offp_211], glob->gv_imgXXXX[l_offp_212], glob->gv_imgXXXX[l_offp_213],
        glob->gv_imgXXXX[l_offp_214]);
    int32_t l_mulRes_216 = 192 * glob->gv_imgXXXX.clamp(1, l_idx_181 + 5);
    int32_t l_offp_217 = 2 * (l_ix_182 + l_mulRes_216);
    int32_t l_offp_218 = 2 * (l_ix_185 + l_mulRes_216);
    int32_t l_offp_219 = 2 * (l_ix_187 + l_mulRes_216);
    int32_t l_offp_220 = 2 * (l_ix_189 + l_mulRes_216);
    vec4 v_221 = vcons4(glob->gv_imgXXXX[l_offp_217], glob->gv_imgXXXX[l_offp_218], glob->gv_imgXXXX[l_offp_219],
        glob->gv_imgXXXX[l_offp_220]);
    vec4 v_222 = vcons4(glob->gv_imgXXXX[l_offp_184 + 1], glob->gv_imgXXXX[l_offp_186 + 1],
        glob->gv_imgXXXX[l_offp_188 + 1], glob->gv_imgXXXX[l_offp_190 + 1]);
    vec4 v_223 = vcons4(glob->gv_imgXXXX[l_offp_193 + 1], glob->gv_imgXXXX[l_offp_194 + 1],
        glob->gv_imgXXXX[l_offp_195 + 1], glob->gv_imgXXXX[l_offp_196 + 1]);
    vec4 v_224 = vcons4(glob->gv_imgXXXX[l_offp_199 + 1], glob->gv_imgXXXX[l_offp_200 + 1],
        glob->gv_imgXXXX[l_offp_201 + 1], glob->gv_imgXXXX[l_offp_202 + 1]);
    vec4 v_225 = vcons4(glob->gv_imgXXXX[l_offp_205 + 1], glob->gv_imgXXXX[l_offp_206 + 1],
        glob->gv_imgXXXX[l_offp_207 + 1], glob->gv_imgXXXX[l_offp_208 + 1]);
    vec4 v_226 = vcons4(glob->gv_imgXXXX[l_offp_211 + 1], glob->gv_imgXXXX[l_offp_212 + 1],
        glob->gv_imgXXXX[l_offp_213 + 1], glob->gv_imgXXXX[l_offp_214 + 1]);
    vec4 v_227 = vcons4(glob->gv_imgXXXX[l_offp_217 + 1], glob->gv_imgXXXX[l_offp_218 + 1],
        glob->gv_imgXXXX[l_offp_219 + 1], glob->gv_imgXXXX[l_offp_220 + 1]);
    vec6 v_228 = vcons6(vdot4(v_178, v_191), vdot4(v_178, v_197), vdot4(v_178, v_203), vdot4(v_178, v_209),
        vdot4(v_178, v_215), vdot4(v_178, v_221));
    vec2 v_229 = vcons2(
        vdot6(v_173,
            vcons6(vdot4(v_179, v_191), vdot4(v_179, v_197), vdot4(v_179, v_203), vdot4(v_179, v_209),
                vdot4(v_179, v_215), vdot4(v_179, v_221))), vdot6(v_174, v_228));
    vec6 v_230 = vcons6(vdot4(v_178, v_222), vdot4(v_178, v_223), vdot4(v_178, v_224), vdot4(v_178, v_225),
        vdot4(v_178, v_226), vdot4(v_178, v_227));
    vec2 v_231 = vcons2(
        vdot6(v_173,
            vcons6(vdot4(v_179, v_222), vdot4(v_179, v_223), vdot4(v_179, v_224), vdot4(v_179, v_225),
                vdot4(v_179, v_226), vdot4(v_179, v_227))), vdot6(v_174, v_230));
    vec3 v_232 = vcons3(0.5e0f, 0.5e0f, 0.5e0f);
    vec2 v_233 = vcons2(vdot6(v_173, v_228), vdot6(v_173, v_230));
    float l_op1_e3_l_14_234 = -0.2e1f * glob->gv_stdv;
    float l_imgPos_235 = world2image(glob->gv_imgXXXXX) * ((0.0f * vdot2(v_229, v_168) + 0.1e1f * vdot2(v_231, v_168) + -0.1e1f * vdot2(
        v_229, v_169) + 0.0f * vdot2(v_231, v_169)) / glob->gv_vortmax) + translate(glob->gv_imgXXXXX);
    float l_nd_236 = std::floor(l_imgPos_235);
    float l_f_237 = l_imgPos_235 - l_nd_236;
    int32_t l_n_238 = std::lround(l_nd_236);
    vec2 v_239 = vcons2(0.1e1f, 0.1e1f) + vcons2(l_f_237, l_f_237 - 0.1e1f) * vcons2(-0.1e1f, 0.1e1f);
    vec3 v_240 = v_232;
    float l__t_241 = std::min(0.1e1f, std::sqrt(std::sqrt(vdot2(v_233, v_233)) / glob->gv_velomax));
    float l_op1_e3_l_22_242 = 0.0f + (self->sv_sum - l_op1_e3_l_14_234) / (0.2e1f * glob->gv_stdv - l_op1_e3_l_14_234) * (0.1e1f - 0.0f);
    vec2 v_243 = v_239;
    if (glob->gv_imgXXXXX.inside(l_n_238, 2)) {
        int32_t l_offp_244 = 3 * l_n_238;
        int32_t l_offp_245 = 3 * (l_n_238 + 1);
        l_voxels_246[0] = glob->gv_imgXXXXX[l_offp_244];
        l_voxels_246[1] = glob->gv_imgXXXXX[l_offp_245];
        l_voxels_246[2] = glob->gv_imgXXXXX[l_offp_244 + 1];
        l_voxels_246[3] = glob->gv_imgXXXXX[l_offp_245 + 1];
        l_voxels_246[4] = glob->gv_imgXXXXX[l_offp_244 + 2];
        l_voxels_246[5] = glob->gv_imgXXXXX[l_offp_245 + 2];
    }
    else {
        int32_t l_offp_247 = 3 * glob->gv_imgXXXXX.clamp(0, l_n_238);
        int32_t l_offp_248 = 3 * glob->gv_imgXXXXX.clamp(0, l_n_238 + 1);
        l_voxels_246[0] = glob->gv_imgXXXXX[l_offp_247];
        l_voxels_246[1] = glob->gv_imgXXXXX[l_offp_248];
        l_voxels_246[2] = glob->gv_imgXXXXX[l_offp_247 + 1];
        l_voxels_246[3] = glob->gv_imgXXXXX[l_offp_248 + 1];
        l_voxels_246[4] = glob->gv_imgXXXXX[l_offp_247 + 2];
        l_voxels_246[5] = glob->gv_imgXXXXX[l_offp_248 + 2];
    }
    self->sv_x = tensor_ref_2(self->sv_x);
    vpack3(self->sv_rgb,
        v_240 + vscale3(l__t_241,
            vscale3(clamp(0.0f, 0.1e1f, l_op1_e3_l_22_242),
                vcons3(vdot2(vload2(l_voxels_246.last(0).addr(0)), v_243),
                    vdot2(vload2(l_voxels_246.last(2).addr(0)), v_243),
                    vdot2(vload2(l_voxels_246.last(4).addr(0)), v_243))) - v_240));
}
bool output_get_rgb (world *wrld, Nrrd *nData)
{
    // Compute sizes of nrrd file
    size_t sizes[4];
    sizes[0] = 3;
    sizes[1] = wrld->_size[2];
    sizes[2] = wrld->_size[1];
    sizes[3] = wrld->_size[0];
    // Allocate nData nrrd
    if (nrrdMaybeAlloc_nva(nData, nrrdTypeFloat, 4, sizes) != 0) {
        char *msg = biffGetDone(NRRD);
        biffMsgAdd(wrld->_errors, msg);
        std::free(msg);
        return true;
    }
    // copy data to output nrrd
    char *cp = reinterpret_cast<char *>(nData->data);
    for (auto ix = wrld->_strands.begin_alive(); ix != wrld->_strands.end_alive(); ix = wrld->_strands.next_alive(ix)) {
        memcpy(cp, &wrld->_strands.strand(ix)->sv_rgb, 3 * sizeof(float));
        cp += 3 * sizeof(float);
    }
    nData->axis[0].kind = nrrdKind3Vector;
    nData->axis[1].kind = nrrdKindSpace;
    nData->axis[2].kind = nrrdKindSpace;
    nData->axis[3].kind = nrrdKindSpace;
    return false;
}
static void write_output (world *wrld)
{
    Nrrd *nData;
    nData = nrrdNew();
    if (output_get_rgb(wrld, nData)) {
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
    : diderot::world_base (ProgramName, true, 3)
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
bool world::alloc (int32_t base[3], uint32_t size[3])
{
    size_t numStrands = 1;
    for (uint32_t i = 0;  i < 3;  i++) {
        numStrands *= size[i];
        this->_base[i] = base[i];
        this->_size[i] = size[i];
    }

    if (this->_verbose) {
        std::cerr << "world::alloc: " << size[0];
        for (uint32_t i = 1;  i < 3;  i++) {
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
            ix = this->_strands.strand_stabilize (glob, ix);
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
    int32_t l__t_250 = glob->gv_ovsmp * glob->gv_sizeY;
    int32_t l__t_252 = glob->gv_ovsmp * glob->gv_sizeX;
    int lo_0 = 0;
    int hi_1 = l__t_250 - 1;
    int lo_2 = 0;
    int hi_3 = l__t_252 - 1;
    int lo_4 = 0;
    int hi_5 = 1;
    int32_t base[3] = {lo_0,lo_2,lo_4,};
    uint32_t size[3] = {static_cast<uint32_t>(hi_1 - lo_0 + 1),static_cast<uint32_t>(hi_3 - lo_2 + 1),static_cast<uint32_t>(hi_5 - lo_4 + 1),};
    if (this->alloc(base, size)) {
        return true;
    }
    uint32_t ix = 0;
    for (int i_yi_251 = lo_0; i_yi_251 <= hi_1; i_yi_251++) {
        for (int i_xi_253 = lo_2; i_xi_253 <= hi_3; i_xi_253++) {
            for (int i_si_254 = lo_4; i_si_254 <= hi_5; i_si_254++) {
                float l_r_255 = tensor_ref_2(glob->gv_xymin)[0];
                float l_r_256 = tensor_ref_2(glob->gv_xymin)[1];
                tensor_2 _arg_257 = {l_r_255 + (static_cast<float>(i_xi_253) - (-0.5e0f)) / (static_cast<float>(l__t_252) - 0.5e0f - (-0.5e0f)) * (tensor_ref_2(
                        glob->gv_xymax)[0] - l_r_255),l_r_256 + (static_cast<float>(i_yi_251) - (-0.5e0f)) / (static_cast<float>(l__t_250) - 0.5e0f - (-0.5e0f)) * (tensor_ref_2(
                        glob->gv_xymax)[1] - l_r_256),};
                LIC_init(this->_globals, this->_strands.strand(ix), _arg_257,
                    -0.1e1f + (static_cast<float>(i_si_254) - 0.0f) / (0.1e1f - 0.0f) * (0.1e1f - (-0.1e1f)));
                ++ix;
            }
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
            ix = this->_strands.strand_stabilize (glob, ix);
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

